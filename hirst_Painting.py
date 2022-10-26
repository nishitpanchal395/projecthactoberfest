
import random
color_list =[ (211, 154, 97), (52, 107, 132), (176, 78, 34), (200, 142, 33), (116, 155, 171), (124, 79, 98), (122, 175, 157), (229, 197, 128), (231, 238, 242), (190, 88, 109), (55, 38, 19), (11, 51, 65), (44, 168, 125), (197, 122, 141), (50, 125, 120), (167, 21, 29), (225, 94, 80)]
from turtle import Turtle, Screen, colormode
raju = Turtle()
raju.hideturtle()
colormode(255)
dist = 50
row = -2
currx = -100
curry = -100
raju.penup()
raju.goto(currx, curry)

for dots in range(0,100):


    raju.dot(15, color_list[random.randint(0,len(color_list)-1)])
    raju.penup()
    raju.fd(dist)
    raju.pendown()
    if raju.xcor() == dist*9:
        row += 1
        raju.penup()
        raju.goto(currx, row*50)


screen = Screen()
screen.exitonclick()
