a = input("enter string : ")

vowel = 0
space = 0
const = 0

for i in a:
	if i in ("aeiouAEIOU") :
		vowel +=1
	elif i in (" "):
		space += 1
	else :
		const += 1

print("vowels : ",vowel)
print("spaces : ",space)
print("consonants :",const)
