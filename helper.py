def createString(listOfList):
    s = ''
    for lis in listOfList:
        s += ''.join(lis)
    return s

s = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
print(createString(s))