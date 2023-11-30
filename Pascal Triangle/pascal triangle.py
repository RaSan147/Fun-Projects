for i in range(1,13,2):
	print((i*"*").center(14))

line= int(input('line num: '))
base=[0,1,0]

if line<=0:
	print("can't do that")
else:
	for i in range(line):
		distance=line+10*(line-1)
		# print(distance)
		new_base=[0,]
		s=''
		ind=0
		for x in base[:len(base)-1]:
			new_base.append(x+base[ind+1])
			if x==0:
				pass
			else:
				if len(str(x))>5:
					space='|'
				else:
					space=' '*(6-len(str(x)))
				s+=str(x)
				if base.index(x)<len(base)-1:
					s+=space
			ind+=1
		#print(base[7])
		# print(new_base)
		print(s.center(distance))
		new_base.append(0)
		base=new_base
		#print(base)
