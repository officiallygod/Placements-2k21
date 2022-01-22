import random

fp = open('./fileHandlingPython/abx.txt', 'r')
vals = fp.readlines()

num = random.randrange(0, len(vals), 1)
print(vals[num])
