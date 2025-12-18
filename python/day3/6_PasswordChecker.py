a = input("Enter your password :")

length = len(a)
lower = False
upper = False
digit = False
spec = False

for i in a:
	if i.islower():
		lower = True
	if i.isupper():
		upper = True
	if i.isdigit():
		digit = True
	if i in ("@#$%^&*{}_+-;'.,/?><"):
		spec = True

if lower and upper and digit and spec and length>8 :
	print("Strong password")
else :
	print ("weak password !")
