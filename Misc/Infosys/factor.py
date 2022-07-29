def get_factors(x):
    lst = []
    for i in range(1, x + 1):
        if x % i == 0:
            if i < 10:
               lst.append(i)
    return lst

def minNumber(N):
    ans = []
    while N > 1:
        temp = get_factors(N)
        ans.append(temp[len(temp) - 1])
        N = N//temp[len(temp) - 1]
    if len(ans) == 1:
        ans.append(1)
    ans.sort()
    res = ""
    for a in ans:
        res += str(a)
    return res
        

print(minNumber(120))