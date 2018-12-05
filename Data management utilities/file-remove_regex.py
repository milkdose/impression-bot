#scan directory and delete files

import os, re
import glob
from os import rename

root = '.'
for item in os.listdir(root):
    fullpath = os.path.join(root, item)
    os.rename(fullpath, fullpath.replace(' ', ''))

myregex = re.compile(r'BCK|RGT|LFT|BOT|GBO|INS|3D135')

def purge(dir, pattern):
    for f in os.listdir(dir):
        if re.search(pattern, f):
            os.remove(os.path.join(dir, f))

purge('.', myregex)
