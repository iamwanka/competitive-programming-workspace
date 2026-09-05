s = input().split(':')
# print(s)
ans = []
count_blank = 1

for segment in s:
	# print(segment)
	if segment == '' and count_blank == 1:
		for i in range(8 - len(s) + 1):
			ans.append('0000')
		count_blank += 1
	else:
		new = segment.lower()
		
		for i in range(4 -len(segment)):
			new = '0' + new
		ans.append(new)

print(f"{ans[0]}:{ans[1]}:{ans[2]}:{ans[3]}:{ans[4]}:{ans[5]}:{ans[6]}:{ans[7]}")
			
	