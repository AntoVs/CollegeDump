val = {"name":"Denji","region":"mumbai","rank":"b1","main":"chamber","weapon":"outlow"}
print("---printing current value in dictionary---")
for key,value in val.items():
    print (key,value)
print("---changing value in dictionary---")
val["rank"] = "s1"
print(val)
print("---adding value in dictionary---")
val["category"] = "sentinel"
print(val)
