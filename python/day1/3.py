import math

r1 = float(input("enter radius of circle 1 : "))
r2 = float(input("enter radius of circle 2 : "))

a1 = (math.pi * r1 * r1)
a2 = (math.pi * r2 * r2)
p1 = (2 * math.pi * r1)
p2 = (2 * math.pi * r2)

print(f"area of circle 1 is :  {a1} and perimeter is  {p1}")
print(f"area of circle 2 is :  {a2} and perimeter is  {p2}")
