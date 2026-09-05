n = int(input())
A = list(map(int, input().split()))
D = {}

A.sort()
# print(A)
for item in A:
	D[item]	= D.get(item, 0) + 1

# print(D)	
ans = 0
for item in D:
	if item < D[item]: ans += D[item] - item
	elif item > D[item]: ans += D[item]
	
	# print(item, D[item])

print(ans)