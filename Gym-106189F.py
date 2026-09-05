n = int(input())

# Puntuacion
point_one_row, point_two_rows, point_three_rows, point_tretis_rows = 760, 1900, 5700, 22800

# Increasing rate
one, two, three, four = 40, 100, 300, 1200

# Level required
level = 130 

# count of rows and points

count_actual_level = 0
puntuation = 0
actual_level = 18

for i in range(n):
	strike = input()
	if strike == 'single':
		count_actual_level += 1
		puntuation += point_one_row	
	elif strike == 'double':
		count_actual_level += 2
		puntuation += point_two_rows
	elif strike == 'triple': 
		count_actual_level += 3
		puntuation += point_three_rows
	else:
		count_actual_level += 4
		puntuation += point_tretis_rows
		
	if count_actual_level >= level:
		actual_level += 1
		# count_actual_level = 0
		level += 10
		point_one_row += one
		point_two_rows += two
		point_three_rows += three
		point_tretis_rows += four

print(puntuation, actual_level)
	