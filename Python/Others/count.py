dic = dict()
n = int(input())

for i in range(0, n):
    keyV = str(input())
    num = int(input())
    lis = []
    for j in range(0, num):
        val = str(input())
        lis.append(val)
    dic[keyV] = lis

pos = -1
ans = ''

for val in dic:
    if "c" in dic[val]:
        if pos < dic[val].index("c"):
            pos = dic[val].index("c")
            ans = val

print("Ans: " + val)
