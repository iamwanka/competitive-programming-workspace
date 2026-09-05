a = int(input())
x = int(input())
b = int(input())
y = int(input())
T = int(input())

priceOfUseA = 0
if T > 30:
	priceOfUseA = 21 * (T - 30) * x
print(a + priceOfUseA)
priceOfUseB = 0
if T > 45:
	priceOfUseB = 21 * (T - 45) * y
print(b + priceOfUseB)
