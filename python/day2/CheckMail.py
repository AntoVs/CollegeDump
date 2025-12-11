a = input("Enter you email : ")

b = '@' in a and '.' in a
if b == True :
	print("email is valid :",a)
else :
	print("email is not valid !")
