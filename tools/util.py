import re
from constants import BUILD, AMALGAMATION_NAME

def get_libs_stripping_str(source: str, includes_set: set[str]) -> str:
  includes = re.findall("#include[\s]*<([A-Za-z_\.]*)>[\s]*", source)
  for inc in includes: includes_set.add(inc)
  
  stripped = re.sub("#include[\s]*<[A-Za-z_\.]*>[\s]*[\n\r]*", "", source)
  
  return stripped

def trim_whitespaces_and_new_lines(source: str) -> str:
  pattern = "[\n\s]*"
  trimmed = re.sub("^%s" % pattern, "", source)
  trimmed = re.sub("%s$" % pattern, "", source)
  
  return trimmed

def save_amalgamation_as_file(amalgamation: str, extension: str):
  file = open("%s/%s.%s" % (BUILD, AMALGAMATION_NAME, extension), "w")
  
  file.write(amalgamation)
  file.close()