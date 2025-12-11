b = int(input("enter the number 1 :"))
sum = 0

while(b != 0):
	d = b%10
	sum += d
	b= b//10
print ("sum of digits is : ",sum)
