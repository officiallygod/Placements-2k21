fp = open('./fileHandlingPython/abx.txt', 'r')
vals = fp.readlines()

mx = -1
ans = 0
count = 1

for val in vals:
    if mx < len(val):
        mx = len(val)
        ans = count
    count = count + 1

print(ans)
