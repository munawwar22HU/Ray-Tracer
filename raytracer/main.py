import os
import sys
import time 
from PIL import Image
import subprocess

def main():
    """
    Entry point... You enter here.
    """
    t = time.time()
    
    input_image = "scene.ppm"
    output_place = "1000_Without.png"
    print(input_image)
    print(output_place)

    with open(input_image) as f:
        lines = [line.rstrip() for line in f]
    width,height = lines[1].split()
    width = int(width)
    height = int(height)
    
    data = []
    for j in range(3,len(lines)):
        values  = lines[j].split()
        rgb = [tuple(values[i:i+3]) for i in range(0, len(values)-1, 3)]
        data.append(rgb)
    new_img = Image.new("RGB", (int(width), int(height)))
    for i in range(height):
        for j in range(width):
            r,g,b = data[i][j]

            new_img.putpixel((j, i), (int(r), int(g), int(b)))
    new_img.save(output_place) 
    print ("Running the program took %s seconds." % (time.time() - t))
      
    new_img.show()  
   
    
    
    
            
if "__main__" == __name__:
   main()
        