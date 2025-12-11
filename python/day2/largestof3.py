a = int(input("enter the number 1 :"))
b = int(input("enter the number 2 :"))
c = int(input("enter the number 3 :"))

if (a == b):
	if b>c :
		print(b ,"is larger")
if (b == c):
	if b>a :
		print(b ,"is larger")
if (a == c):
	if a>b :
		print(a ,"is larger")

if (a > b) and (a > c):
	print(a,"is greater")
if (b > a) and (b > c):
	print(b,"is greater")
if (c > b) and (c > a):
	print(c,"is greater")
