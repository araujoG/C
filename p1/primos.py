stop = int(input())
cont = 2
if stop<2:
	print("2")
elif stop <3:
	print("2")
	print("3")
primo = 5
while (cont<stop):
	parou = 0
	div = 3
	while (div<primo) and (parou==0):
		if ((primo%div)==0):
			parou = 1
		else:
			div+=2
	if (parou==0):
		print(primo)
		cont+=1
	primo+=2