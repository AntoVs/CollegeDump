import random

radiant = []
for x in range(0,10):
	a = random.randint(1, 100)
	radiant.append(a)
print(radiant)

print("min element is :",min(radiant))
print("max element is :",max(radiant))
print("avg of list is :",sum(radiant)/10)
print("reveresed : ", radiant[::-1])

iron = []
for i in radiant:
	if (i%2 == 0) :
		iron.append(i**2)
print ("Squared Even Number list :",iron)
