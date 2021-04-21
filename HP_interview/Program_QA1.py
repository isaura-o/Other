import pandas as pd
import numpy as np

#load dataset
df1 = pd.DataFrame({'Start.Date': ['01/01/2019', '01/01/2019', '02/15/2019'], 'End.Date': ['01/16/2019', '01/21/2019', '02/20/2019'], 'Product_ID': ['A', 'B', 'A'], 'Price': [100, 150, 150], 'Org.Price': [200, 300, 200]})

# convert columns 'Start.Date' and 'End.Date' into datetime.
df1['Start.Date'] = pd.to_datetime(df1['Start.Date'])
df1['End.Date'] = pd.to_datetime(df1['End.Date'])

# set the new range of dates throught the first day to the last, and take into account an offset.
ts = pd.tseries.frequencies.to_offset('W-SAT')
idx = pd.date_range(df1['Start.Date'].min(), (df1['End.Date'].max() +ts), freq= 'W-SAT')
dfInd = pd.concat([pd.DataFrame({'Saturday_Dt': idx})])
dfIndB = dfInd.copy()
# Fixed Variables: Product_ID and Original Price
dfInd['Product_ID'] = 'A'
dfInd['Price'] = np.zeros(len(dfInd))
dfInd['Org.Price'] = np.zeros(len(dfInd))
dfIndB['Product_ID'] = 'B'
dfIndB['Price'] = np.zeros(len(dfIndB))
dfIndB['Org.Price'] = np.zeros(len(dfIndB))

df2 = pd.concat([pd.DataFrame({'Saturday_Dt': pd.date_range(row['Start.Date'], row['End.Date'], freq='W-SAT'), 'Product_ID': row['Product_ID'], 'Price': row['Price'], 'Org.Price': row['Org.Price']}, columns= ['Saturday_Dt','Product_ID', 'Price', 'Org.Price']) for i, row in df1.iterrows()], ignore_index = True)

df3 = df2.append([dfInd,dfIndB], ignore_index=True)
df3.reset_index()
df3 = df3.drop_duplicates(subset=['Saturday_Dt', 'Product_ID'], keep='first').sort_values('Saturday_Dt', ignore_index = True)#.sort_values('Product_ID', ignore_index= True)

t = pd.to_timedelta(np.single(7), unit='d')

for i, row in df3.iterrows():
    for j, r2 in df1.iterrows():    
        if( row['Price'] == np.zeros(1)):
            if(row['Product_ID'] == r2['Product_ID'] ):
                if abs(r2['End.Date'] - row['Saturday_Dt']) < t :
                    df3.loc[i,'Price'] = (r2['Price']+r2['Org.Price'])/2
                    df3.loc[i,'Org.Price'] = r2['Org.Price']
                elif (r2['End.Date'] < row['Saturday_Dt']) :
                    df3.loc[i,'Price'] = r2['Org.Price']
                    df3.loc[i,'Org.Price'] = r2['Org.Price']

df3 = df3.sort_values('Product_ID',ignore_index=True)
print(df3)
