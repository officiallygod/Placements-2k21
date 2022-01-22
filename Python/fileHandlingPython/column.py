fp = open('./input.txt', 'r')

myData = []
for i in fp:
    temp = i.rstrip("\n").split()
    temp = list(map(int, temp))
    myData.append(temp)
    
m = len(myData[0])
n = len(myData)

ans = ''
for i in range(0, m):
    sum = 0
    for j in range(0, n):
        sum = sum + myData[j][i]
    ans = ans + str(sum) + ' '

fp = open('./output.txt', 'w')
fp.write(ans)