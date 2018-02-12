#Programming Challenges
riceballNumber = 0
maximum = 400
solutionList = [[-1 for x in range(maximum)] for y in range(maximum)]
riceballList = [0 for x in range(maximum)]


#Programming Challenges


def set_solution(startIndex, endIndex, ballCount):
	global riceballNumber
	global riceballList
	solutionList[startIndex][endIndex] = ballCount


def possible_combine_range(startIndex, endIndex): #Check if a solution has been found for a range
	global riceballNumber
	global riceballList
	if startIndex == endIndex: #A single index wide (single number) is always a possible solution
		return True
	else:
		return solutionList[startIndex][endIndex] != -1 #Returns True if there is already a solution there. Returns false if there is -1


def range_count(startIndex, endIndex): #Returns number of rice balls in a range
	global riceballNumber
	global riceballList
	if startIndex == endIndex:
		return riceballList[startIndex] #Returns a rice ball size if the range is one index wide
	else:
		return solutionList[startIndex][endIndex] #Returns an already known solution or -1


def search_two(firstStartIndex, lastEndIndex): #Looks for two blocks that can be combined with equal number of rice balls
	global riceballNumber
	global riceballList
	for lastStartIndex in range(firstStartIndex + 1, lastEndIndex + 1):
		firstEndIndex = lastStartIndex - 1
		if possible_combine_range(firstStartIndex, firstEndIndex) == False:
			continue
		if possible_combine_range(lastStartIndex, lastEndIndex) == False:
			continue
		firstCount = range_count(firstStartIndex, firstEndIndex)
		lastCount = range_count(lastStartIndex, lastEndIndex)
		if firstCount != lastCount:
			continue
		rangeCount = firstCount + lastCount
		set_solution(firstStartIndex, lastEndIndex, rangeCount)
		return True
	return False


def search_three(firstStartIndex, lastEndIndex):
	global riceballNumber
	global riceballList
	for middleStartIndex in range(firstStartIndex + 1, lastEndIndex):
		firstEndIndex = middleStartIndex - 1
		if possible_combine_range(firstStartIndex, firstEndIndex) == False:
			continue
		firstCount = range_count(firstStartIndex, firstEndIndex)
		for lastStartIndex in range(middleStartIndex + 1, lastEndIndex + 1):
			middleEndIndex = lastStartIndex - 1
			if range_count(middleStartIndex, middleEndIndex) == False:
				continue
			if range_count(lastStartIndex, lastEndIndex) == False:
				continue
			lastCount = range_count(lastStartIndex, lastEndIndex)
			if firstCount != lastCount:
				continue
			middleCount = range_count(middleStartIndex, middleEndIndex)
			rangeCount = firstCount + middleCount + lastCount
			set_solution(firstStartIndex, lastEndIndex, rangeCount)
			return


def find_largest_combination():
	global riceballNumber
	global riceballList
	maxAmount = 0
	start = 0
	for start in range(riceballNumber):
		for end in range(start, riceballNumber):
			maxAmount = max(maxAmount, range_count(start, end))
	return maxAmount


def solve():
	global riceballNumber
	global riceballList
	riceballNumber = 7
	inputList = [int(x) for x in "47 12 12 3 9 9 3".split()]
	#riceballNumber = int(input())
	#inputList = [int(x) for x in input().split()]
	for i in range(riceballNumber):
		riceballList[i] = inputList[i]
	for blockRange in range(2, riceballNumber + 1):
		maxStart = riceballNumber - blockRange + 1
		for firstStartIndex in range(maxStart):
			lastEndIndex = firstStartIndex + blockRange - 1
			found = search_two(firstStartIndex, lastEndIndex)
			if found:
				continue
			if blockRange > 2:
				search_three(firstStartIndex, lastEndIndex)
	largest = find_largest_combination()
	print(largest)


solve()