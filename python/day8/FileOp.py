import pandas as pd
import matplotlib.pyplot as plt
f1 = pd.read_csv('sales.csv')

#DataCleaning
f1['Quantity']=f1['Quantity'].fillna(f1['Quantity'].median())
f1['Unit Price'] = f1['Unit Price'].fillna(f1['Unit Price'].median())

#SalesAnalyss
f1['Total sales'] = f1['Unit Price'] * f1['Quantity']
RegionSales = f1.groupby('Region')['Total sales'].sum()
print(f"RegionalSales:\n{RegionSales}\n")
HighSalesCat = f1.groupby('Product category')['Total sales'].sum().sort_values(ascending = False)
print(f"Top3HighSalesCAtegory:\n{HighSalesCat.head(3)}\n")

#TimeSeriesAnalysis
f1['Order Date'] = pd.to_datetime(f1['Order Date'], format = "%d-%m-%Y")
MonthlySales = f1.groupby(pd.Grouper(key='Order Date', freq='M'))['Total sales'].sum()
print(f"Monthly Sales:\n{MonthlySales}\n")

#Visualization Bar Graph
plt.bar(RegionSales.index, RegionSales.values)
plt.xlabel('Region')
plt.ylabel('TotalSales')
plt.show()
#Visualization Line Graph
plt.plot(MonthlySales)
plt.xlabel('Month')
plt.ylabel('TotalSales')
plt.show()

# Export to CSV
RegionSales.to_csv('region_sales.csv')
MonthlySales.to_csv('monthly_sales.csv')
