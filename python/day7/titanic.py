import pandas as pd
x = pd.read_csv('titanic.csv')
pd.options.display.max_rows = 9999

print("EntireDataSet\n",x)
print("MaleCount : ",len(x.query("Sex == 'male'")))
print("FemaleCount : ",len(x.query("Sex == 'female'")))
print("\nOnly Females\n",x.query("Sex == 'female'"))
print("Survived :",len(x.query("Survived == 1")))
print("Survived LIst \n",x.query("Survived == 1"))
