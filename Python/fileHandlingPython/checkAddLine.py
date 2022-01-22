fp = open('./fileHandlingPython/abx.txt', 'r')
vals = fp.readlines()
fp.close()

present = False
data = "HOLAAA MADRIDD!"

for val in vals:
    if(data in val):
        present = True

if present == False:
    f = open('./fileHandlingPython/abx.txt', 'a')
    f.write('\n' + data)
    f.close()
