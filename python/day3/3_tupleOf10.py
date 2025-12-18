import random

radiant = (10, 10, 7, 2, 2, 8, 3, 5, 6, 1)

print("tuple : ",radiant)
print("sum of tuple is :",sum(radiant))

p = 1
for i in radiant :
	p = p * i

print("product is :",p)
a = int(input("Enter Number to check :"))

for i in radiant :
	if(a == i):
		print("Element found in the list :) ")
		break
	else :
		flag = 1
if(flag == 1) :
	print("element not found !")

bronze = [*radiant]

for i in range (0,2):
	a = int(input("enter number to append :"))
	bronze.append(a)
print(bronze)
