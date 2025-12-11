import cmath

a = int(input("enter the value of a:"))
b = int(input("enter the value of b:"))
c = int(input("enter the value of c:"))

r = ((b*b)-4*a*c)

root1 = (-b + cmath.sqrt(r))/2*a
root2 = (-b - cmath.sqrt(r))/2*a

if r>=0 :
	print("real and discrete roots")
if r<=0 :
	print("complex roots")

print("value of root 1 :",root1)
print("value of root 2 :",root2)
