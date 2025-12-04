name = input("name :")
age = input("age :")
city = input("city :")

print("Hello ,",name,"! You are ",age,"years old and lives in ",city)

x = 5
y = 'hello'
z = 7.5
a = True

print(type(x),type(y),type(z),type(a))

import math

r1 = float(input("enter radius of circle 1 : "))
r2 = float(input("enter radius of circle 2 : "))

a1 = (math.pi * r1 * r1)
a2 = (math.pi * r2 * r2)
p1 = (2 * math.pi * r1)
p2 = (2 * math.pi * r2)

print(f"area of circle 1 is :  {a1} and perimeter is  {p1}")
print(f"area of circle 2 is :  {a2} and perimeter is  {p2}")

s1 = float(input("Enter marks of s1 : "))
s2 = float(input("Enter marks of s2 : "))
s3 = float(input("Enter marks of s3 : "))
s4 = float(input("Enter marks of s4 : "))
s5 = float(input("Enter marks of s5 : "))

t = (s1+s2+s3+s4+s5)
p = (t/500)*100

print(f"You got a total of {t} and scored {p}%")

p = float(input("Enter the principal amount : "))
t = float(input("Enter the time period : "))
r = float(input("Enter the rate of interest : "))

s = (p*t*r)/100

print("You got a  total simple interest of : ", s)



