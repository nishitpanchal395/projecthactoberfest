# -*- coding: utf-8 -*-
"""
Created on Sat Oct  9 21:06:40 2021

@author: DHIRAJ 
"""


# Import the turtle library for beautiful graphics

import turtle as tur

# Set the background color as black,
# pensize as 2 and speed of drawing
# curve as 10(relative)
tur.bgcolor('black')
tur.pensize(2)
tur.speed(10)
x=0
# Iterate for six times 
for i in range(6):
    if(i>x):
	# Choose your color combination
	    for color in ('red', 'magenta', 'blue',
				'cyan', 'green', 'white',
				'yellow'):
		    tur.color(color)
		
		# Draw a circle of 100 size
		    tur.circle(100)
		
		# Move 10 pixels left to draw another circle and keep drawing till a beautiful graphics get formed
		    tur.left(10)
		    i=i-1 #to reduce the value for i so that the for loop gets terminated
	# Hide the turtle cursor which drew the circle
	    tur.hideturtle()
