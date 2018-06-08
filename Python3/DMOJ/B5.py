str = input()
length = int(input())

distinctCount = 0
j = 1
for i in range(len(str)-1):
    if str[i] != str[i+1]:
        while j >= length:
            j -= 1
            distinctCount += 1
        j = 1
    elif i == len(str)-2:
        while j + 1 >= length:
            j -= 1
            distinctCount += 1
    else:
        j += 1

print(distinctCount)

# distincts = []
# def isDistinct(substr):
#     if substr in distincts:
#         print("Already found", substr)
#     for i in range(len(substr)-1):
#         if substr[i] != substr[i+1]:
#             return False
#     distincts.append(substr)
#     return True
#
#
# for i in range(len(str)-length+1):
#     if isDistinct(str[i:i+length]):
#         distinctCount += 1