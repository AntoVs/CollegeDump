import pandas as pd
import plotly.express as px

df = pd.read_csv('sales.csv')
Sales = df.groupby("Product category")["Total Revenue"].sum() #Cleaning/category

#BarGRaph
px.bar(
    x = Sales.index,
    y = Sales.values,
    labels={'x':'Category','y':'TotalRevenue'}).show()
#LineGRaph
px.line(
    x = Sales.index,
    y = Sales.values,
    labels={'x':'Category','y':'TotalRevenue'}).show()
#pIeCHart
px.pie(
    names = Sales.index,
    values = Sales.values).show()
#HeatMAp
px.density_heatmap(Sales.to_frame()).show()
