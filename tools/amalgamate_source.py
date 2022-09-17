import re
from constants import SRC, AMALGAMATION_NAME
from util import get_libs_stripping_str, trim_whitespaces_and_new_lines, save_amalgamation_as_file

def amalgamate_src(srcs: list[str]) -> list[str]:
  sources_map = dict()
  dependency_graph = dict()
  includes_set = set()
  for src in srcs:
    source, module_name = __file_as_str(src)
    source = __get_deps_stripping_str(source, module_name, dependency_graph)
    source = get_libs_stripping_str(source, includes_set)
    source = trim_whitespaces_and_new_lines(source)
    sources_map[module_name] = source
  deps_order = __get_deps_order(dependency_graph)
  
  amalgamation = __amalgamate(sources_map, deps_order, includes_set)
  save_amalgamation_as_file(amalgamation, "c")
  
  return deps_order

def __file_as_str(filename: str) -> tuple[str, str]:
  source_file = open("%s/%s" % (SRC, filename))
  source = source_file.read()
  source_file.close()
  module_name = filename.split(".")[0]
  
  return source, module_name

def __get_deps_stripping_str(source: str, module_name: str, dependency_graph: dict[str, list[str]]):
  deps_includes = re.findall("#include[\s]*\"([A-Za-z0-9_]*)\.[A-Za-z0-9_\.]*\"[\s]*", source)
  dependency_graph[module_name] = [inc for inc in deps_includes if inc != module_name]

  stripped = re.sub("#include[\s]*\"[A-Za-z_\.]*\"[\s]*[\n\r]*", "", source)
  
  return stripped

def __get_deps_order(dependency_graph: dict[str, list[str]]) -> list[str]:
  ordered = list()
  inserted = set()
  
  for lib in dependency_graph:
    __get_root_dep(lib, dependency_graph, ordered, inserted)
  
  return ordered

def __get_root_dep(lib: str, dependency_graph: dict[str, list[str]], ordered: list[str], inserted: set[str]):
  if(lib in inserted): return
  deps = dependency_graph[lib]
  if len(deps) != 0:
    for dep in deps: __get_root_dep(dep, dependency_graph, ordered, inserted)

  ordered.append(lib)
  inserted.add(lib)

def __amalgamate(sources_map: dict[str, str], deps_order: list[str], includes_set: set[str]):
  amalgamated = "#include \"%s.h\"" % AMALGAMATION_NAME
  
  for inc in includes_set:
    amalgamated = "%s\n#include <%s>" % (amalgamated, inc)
  
  amalgamated += "\n\n\n"
  
  for lib in deps_order:
    amalgamated = "%s%s\n\n" % (amalgamated, sources_map[lib])
  
  return amalgamated
