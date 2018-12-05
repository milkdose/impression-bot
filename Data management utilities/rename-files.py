#scan directory and delete files

import os, re
import glob
from os import rename

root = "."
for item in os.listdir(root):
    fullpath = os.path.join(root, item)
    os.rename(fullpath, fullpath.replace(item, item[2:]))
    #print(item)
