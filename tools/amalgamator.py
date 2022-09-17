from os import listdir
import re
from amalgamate_source import amalgamate_src
from amalgamate_header import amalgamate_header
from constants import SRC

files = listdir(SRC)

src_re =    re.compile("^[a-z_]*.c$")
header_re = re.compile("^[a-z_]*.h$")

sources = [src for src in files if src_re.match(src)]
headers = [header for header in files if header_re.match(header)]

deps_order = amalgamate_src(sources)
amalgamate_header(headers, deps_order)
