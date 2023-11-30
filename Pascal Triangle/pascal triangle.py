"""
 * @file Pascal_triangle.c
 * @brief This program generates Pascal's triangle up to a given number of rows.
 * @author Ratul Hasan (RaSan147)
 * @date December 1, 2023
"""


for i in range(1,13,2):
	print((i*"*").center(14))

line= int(input('line num: '))
base=[0,1,0]

def intLen(n):
	i = 0
	j = 1
	while n >= j:
		i += 1
		j *= 10
	return i


def printLine(base, distance):
	s=''

	for n, x in enumerate(base):
		if x==0:
			continue
		
		if intLen(x)>5 and n != 0:
			space='|'
		else:
			space=' '*(6-intLen(x))
		s+=str(x)
		if base.index(x)<len(base)-1:
			s+=space

	print(s.center(distance))

if line<1:
	print("can't do that")
else:
	distance=line+10*(line-1)
	printLine(base, distance)
	for i in range(1, line):
		distance=line+10*(line-1)

		new_base=[0,]
		ind=0
		for x in base[:len(base)-1]:
			new_base.append(x+base[ind+1])

			ind+=1

		new_base.append(0)
		base=new_base

		printLine(new_base, distance)
