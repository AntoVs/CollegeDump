def fact(n):
    fact = 1
    for x in range (1,n+1):
        fact *= x
    print (fact)

n = int(input("enter the number :"))
fact(n)
