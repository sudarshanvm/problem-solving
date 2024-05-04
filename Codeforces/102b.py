n = int(input())
count = 0
sum = n
if n<10:
	print(0)
else:
	while True:
		# count += 1
		n = str(sum)
		sum = 0
		for ch in n:
			sum += int(ch)

		# calc sum
		count += 1
		if sum < 10:
			break
		

	print(count)