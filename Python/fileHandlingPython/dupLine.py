
fp = open('./fileHandlingPython/abx.txt', 'r')

myData = []
for i in fp:
    myData.append(i.rstrip("\n"))

print(myData)

f = open('./fileHandlingPython/abx1.txt', 'w')
for val in myData:
    f.write(val+'\n')
