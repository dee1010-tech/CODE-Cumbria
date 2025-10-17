import math

class Shape:
    def __init__(self):
        pass

    def area(self):
        pass

    def perimeter(self):
        pass

    class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self)
        print("Area of a function.")

    def perimeter(self)
        print("Perimeter of a circle.")
    
    class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        print("Area of a function.")

    def perimeter(self):
        print("Perimeter of a rectangle.")

    class Triangle(Shape):
    def __init__(self, base, height, side1, side2):
        self.base = base
        self.height = height
        self.side1 = side1
        self.side2 = side2

    def area(self):
        print("Area of a function.")

    def perimeter(self):
         print("Perimeter of a triangle.")