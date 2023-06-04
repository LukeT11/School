#Luke Talcott
#CS101 lab
#Friday 1-3:30
#Lab Week 14- Inheritance

#Class Point- Uses def draw() to place the pen based off of x and y and calls the draw action
#Class Box- Calls variables from parent class "Point" to draw a box and run draw()
#Class BoxFilled- Calls variable from parent class "Box" to fill the box with a color
#Class Circle- Calls variables from parent class "Point" to draw a circle and run draw()
#Class CircleFilled- Calls variables from parent class "Circle" to fill the circle with a color

import turtle

class Point(object):
    '''Set variables, calls draw() to place the pen and call draw_action() for turtle import'''
    def __init__(self, x, y, color):
        '''Initial values for location x and y with a color'''
        self.x = x
        self.y = y
        self.color = color

    def draw(self):
        '''In turtle, picks up the pen and goes to x and y location with a color and calls draw_action()'''
        turtle.penup()
        turtle.goto(self.x, self.y)
        turtle.pendown()
        turtle.color(self.color)
        turtle.setheading(0)
        self.draw_action()

    def draw_action(self):
        '''Places a dot in turtle'''
        turtle.dot()

class Box(Point):
    '''Calls parent class Point and draws a box'''
    def __init__(self, x1, y1, width, height, color):
        '''Initial variables from point and ones just for box'''
        super().__init__(x1, y1, color)
        self.width = width
        self.height = height

    def draw_action(self):
        '''Draws a Box'''
        turtle.forward(self.width)
        turtle.right(90)
        turtle.forward(self.height)
        turtle.right(90)
        turtle.forward(self.width)
        turtle.right(90)
        turtle.forward(self.height)

class BoxFilled(Box):
    '''Calls parent class Box and fills the box with a colr'''
    def __init__(self, x1, y1, width, height, color, fillcolor):
        '''Initial variables from Box and ones just for BoxFilled'''
        super().__init__(x1, y1, width, height, color)
        self.fillcolor = fillcolor

    def draw_action(self):
        '''Fills the box with a color'''
        turtle.fillcolor(self.fillcolor)
        turtle.begin_fill()
        super().draw_action()
        turtle.end_fill()
        
class Circle(Point):
    '''Calls the parent class Point and draws a cirlce'''
    def __init__(self, x1, y1, radius, color):
        '''Initial variables from Point and ones just for Circle'''
        super().__init__(x1, y1, color)
        self.radius = radius

    def draw_action(self):
        '''Draws a Circle'''
        turtle.circle(self.radius)

class CircleFilled(Circle):
    '''Calls the parent class Circle and fills teh circle with a color'''
    def __init__(self, x1, y1, radius, color, fillcolor):
        '''Initial variables from Circle and ones just for CircleFilled'''
        super().__init__(x1, y1, radius, color)
        self.fillcolor = fillcolor
        
    def draw_action(self):
        '''Fills the circle with a color'''
        turtle.fillcolor(self.fillcolor)
        turtle.begin_fill()
        super().draw_action()
        turtle.end_fill()
