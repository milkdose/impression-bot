#Resizes an image and keeps aspect ratio. Set mywidth to the desired with in pixels.

import re
import os
import PIL
from PIL import Image

mywidth = 800 #px to re-size images to

root = "/Users/pamwelsh/Desktop/Impression_bot/Impression2018_temp"

for item in os.listdir(root):
	if(str.endswith(item, ".jpg")):
		fullpath = os.path.join(root, item)
		
		img = Image.open(root+"/"+item)
		wpercent = (mywidth/float(img.size[0]))
		hsize = int((float(img.size[1])*float(wpercent)))
		img = img.resize((mywidth,hsize), PIL.Image.ANTIALIAS)
		img.save("/Users/pamwelsh/Desktop/Impression_bot/Impression2018_high/"+item)
	else:
		continue
