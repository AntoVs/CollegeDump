a = input("Enter the numbrs with spaces : ")

lst = []
for i in a.split():
	lst.append(int(i))
print("appended list : ",lst)

print("sum of inputted string is : ",sum(lst))

