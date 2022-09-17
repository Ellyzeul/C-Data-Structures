import re
from constants import SRC, AMALGAMATION_HEADER_MACRO
from util import get_libs_stripping_str, trim_whitespaces_and_new_lines, save_amalgamation_as_file

def amalgamate_header(srcs: list[str], deps_order: list[str]):
  sources_map = dict()
  includes_set = set()
  for src in srcs:
    source, module_name = __file_as_str(src)
    source = get_libs_stripping_str(source, includes_set)
    source = trim_whitespaces_and_new_lines(source)
    source = __trim_header_guards_and_deps(source)
    sources_map[module_name] = source
  
  amalgamation = __amalgamate(sources_map, deps_order, includes_set)
  save_amalgamation_as_file(amalgamation, "h")

def __file_as_str(filename: str) -> tuple[str, str]:
  source_file = open("%s/%s" % (SRC, filename))
  source = source_file.read()
  source_file.close()
  module_name = filename.split(".")[0]
  
  return source, module_name

def __trim_header_guards_and_deps(source: str):
  trimmed = re.sub("#(ifndef|define|endif)[\s/]*[A-Za-z_]*[\n\r]*", "", source)
  trimmed = re.sub("#include[\s]*\"[A-Za-z_\.]*\"[\s]*[\n\r]*", "", trimmed)
  
  return trimmed

def __get_root_dep(lib: str, dependency_graph: dict[str, list[str]], ordered: list[str], inserted: set[str]):
  if(lib in inserted): return
  deps = dependency_graph[lib]
  if len(deps) != 0:
    for dep in deps: __get_root_dep(dep, dependency_graph, ordered, inserted)

  ordered.append(lib)
  inserted.add(lib)

def __amalgamate(sources_map: dict[str, str], deps_order: list[str], includes_set: set[str]):
  amalgamated = "#ifndef %s\n#define %s\n\n" % tuple([AMALGAMATION_HEADER_MACRO for _ in range(2)])
  
  for inc in includes_set:
    amalgamated = "%s\n#include <%s>" % (amalgamated, inc)

  if len(includes_set) != 0: amalgamated += "\n\n\n"
  
  for lib in deps_order:
    amalgamated = "%s%s" % (amalgamated, sources_map[lib])
  
  amalgamated += "#endif\n"
  
  return amalgamated
