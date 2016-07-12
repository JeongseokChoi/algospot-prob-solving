KG_TO_LB = 2.2046   # 1 kilogram = 2.2046 pounds
LB_TO_KG = 0.4536   # 1 pound = 0.4536 kilograms
L_TO_G = 0.2642     # 1 liter = 0.2642 gallons
G_TO_L = 3.7854     # 1 gallon = 3.7854 liters
dicUnitConv = {
    'kg': [KG_TO_LB, 'lb'],
    'lb': [LB_TO_KG, 'kg'],
    'l': [L_TO_G, 'g'],
    'g': [G_TO_L, 'l']
}

nCase = int(input())
for case in range(nCase):
    splitInputList = input().split()
    value, unit = float(splitInputList[0]), splitInputList[1]
    convertedValue = value * dicUnitConv[unit][0]
    print("%d %.4f %s"%(case + 1, convertedValue, dicUnitConv[unit][1]))
