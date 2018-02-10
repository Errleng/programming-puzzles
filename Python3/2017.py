#CCC 2017

#Find arithmetic sequences in the format of HH:MM during a specific time range
def J4():
    duration = int(input())
    dayMinutes = 24 * 60
    hours = 12
    minutes = 0
    sequenceCount = 0
    days = int(duration / dayMinutes)
    loopHours = 0
    loopMinutes = 0
    daySequenceCount = 0
    for i in range(dayMinutes):
        strMins = ""
        if loopMinutes >= 60:
            loopMinutes -= 60
            loopHours += 1
        if loopMinutes < 10:
            strMins += "0" + str(loopMinutes)
        else:
            strMins = str(loopMinutes)
        if loopHours > 12:
            loopHours -= 12
        if loopHours == 0:
            loopHours = 12
        strHours = str(loopHours)
        strTime = strHours + strMins
        difference = int(strTime[1]) - int(strTime[0])
        isSequence = True
        for j in range(1, len(strTime)):
            if int(strTime[j]) - int(strTime[j-1]) != difference:
                isSequence = False
        if isSequence:
            daySequenceCount += 1
        loopMinutes += 1
    for i in range((duration+1) % dayMinutes):
        arithmeticSequence = True
        strMins = ""
        if minutes >= 60:
            minutes -= 60
            hours += 1
        if minutes < 10:
            strMins += "0" + str(minutes)
        else:
            strMins = str(minutes)
        if hours > 12:
            hours -= 12
        if hours == 0:
            hours = 12
        strHours = str(hours)
        strTime = strHours + strMins
        difference = int(strTime[1]) - int(strTime[0])
        isSequence = True
        for j in range(1, len(strTime)):
            if int(strTime[j]) - int(strTime[j-1]) != difference:
                isSequence = False
        if isSequence:
            sequenceCount += 1
        minutes += 1
    sequenceCount += days * daySequenceCount
    print(sequenceCount)

def S1():
    days = int(input())
    teamOneScores = [int(x) for x in input().split()]
    teamTwoScores = [int(x) for x in input().split()]
    teamOneSum = 0
    teamTwoSum = 0
    equalDay = 0
    for i in range(days):
        teamOneSum += teamOneScores[i]
        teamTwoSum += teamTwoScores[i]
        if teamOneSum == teamTwoSum:
            equalDay = i + 1
    print(equalDay)

def S2():
    #measurementCount = 8
    #measurements = [10, 50, 40, 7, 3, 110, 90, 2]
    measurementCount = int(input())
    measurements = [int(x) for x in input().split()]
    measurements.sort()
    lowTides, highTides= [], []
    for i in range(int(measurementCount)):
        if i < measurementCount/2:
            lowTides.append(measurements[i])
        else:
            highTides.append(measurements[i])
    lowTides.sort(reverse=True)
    highTides.sort()
    #print("HIGH:", highTides)
    #print("LOW:", lowTides)
    combinedTides = ""
    lowIndex = 0
    highIndex = 0
    for i in range(int(measurementCount)):
        if i % 2 == 0:
            combinedTides += str(lowTides[lowIndex]) + " "
            lowIndex += 1
        else:
            combinedTides += str(highTides[highIndex]) + " "
            highIndex += 1
    print(combinedTides)

S1()
