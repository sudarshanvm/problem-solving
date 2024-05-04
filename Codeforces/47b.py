s1 = input()
s2 = input()
s3 = input()

def modify(s):
	if ">" in s:
		s = s[2] + "<" + s[0]
		
	return s


def checkimp(s1,s2,s3):
	if s1[1] == "<":
		temp = s1[0] + ">" + s1[2]
		if temp == s2 or temp == s3:
			return True

	else:
		temp = s1[0] + "<" + s1[2]
		if temp == s2 or temp == s3:
			return True

	return False


if checkimp(s1,s2,s3) or checkimp(s2,s1,s3) or checkimp(s3,s1,s2):
	print("Impossible")

else:
	d = {"A":0,"B":0,"C":0}

	s1 = modify(s1)
	# print(s1)
	s2 = modify(s2)
	# print(s2)
	s3 = modify(s3)
	# print(s3)

	d[s1[2]] += 1
	d[s2[2]] += 1
	d[s3[2]] += 1

	# print(d)

	sorted_d = dict(sorted(d.items(), key=lambda item: item[1]))
	# print(sorted_d)

	res = ""
	a = [0,0,0]
	flag = False
	for p in sorted_d:
		# print(p)
		res += p
		if a[sorted_d[p]] :
			flag = True
			break
		a[sorted_d[p]] += 1

	if flag:
		print("Impossible")
	else:
		print(res)




	

