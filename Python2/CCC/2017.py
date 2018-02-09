def J4():
    duration = input()
    dayMinutes = 24 * 60
    hours = 12
    minutes = 0
    sequenceCount = 0
    days = duration / dayMinutes
    loopHours = 0
    loopMinutes = 0
    daySequenceCount = 0
    for i in xrange(dayMinutes):
        arithmeticSequence = True
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
        for j in xrange(1, len(strTime)):
            if int(strTime[j]) - int(strTime[j-1]) != difference:
                isSequence = False
        if isSequence:
            daySequenceCount += 1
        loopMinutes += 1
    for i in xrange((duration+1) % dayMinutes):
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
        for j in xrange(1, len(strTime)):
            if int(strTime[j]) - int(strTime[j-1]) != difference:
                isSequence = False
        if isSequence:
            sequenceCount += 1
        minutes += 1
    sequenceCount += days * daySequenceCount
    print sequenceCount
J4()
