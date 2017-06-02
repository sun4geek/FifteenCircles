from collections import Counter

def fifteenCircles():
	print("input the number -> ", end = " ")
	target = int(input())
	count = 0
	print("Calculating...")
	for bottomFirst in range(target):
		for bottomSecond in range(target):
			for bottomThird in range(target):
				for bottomFourth in range(target):
					for bottomFifth in range(target):
						firstLine = [bottomFirst, bottomSecond, bottomThird, bottomFourth, bottomFifth]
						secondLine = [bottomFirst + bottomSecond, bottomSecond + bottomThird, bottomThird + bottomFourth, bottomFourth + bottomFifth]
						thirdLine = [secondLine[0] + secondLine[1], secondLine[1] + secondLine[2], secondLine[2] + secondLine[3]]
						fourthLine = [thirdLine[0] + thirdLine[1], thirdLine[1] + thirdLine[2]]
						result = fourthLine[0] + fourthLine[1]
						if(result != target):
							firstLine = []
							secondLine = []
							thirdLine = []
							fourthLine = []
						else:
							countFirst = Counter(firstLine)
							countSecond = Counter(secondLine)
							countThird = Counter(thirdLine)
							countFourth = Counter(fourthLine)
							counter = countFirst + countSecond + countThird + countFourth
							if(len(counter) == 14):
								count += 1
								print("result: < %d >" % count)
								print(str(result))
								print(fourthLine[0], fourthLine[1])
								print(thirdLine[0], thirdLine[1], thirdLine[2])
								print(secondLine[0], secondLine[1], secondLine[2], secondLine[3])
								print(firstLine[0], firstLine[1], firstLine[2], firstLine[3], firstLine[4])
								print()
							else:
								countFirst = ()
								countSecond = ()
								countThird = ()
								countFourth = ()
								couner = Counter()
	if (count == 0):
		print("false")
	else:
		print("finish")
	return

def main():
	fifteenCircles()

if __name__ == '__main__':
	main()
