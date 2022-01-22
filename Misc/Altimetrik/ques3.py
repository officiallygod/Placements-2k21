def isComposite(n):
    if (n <= 1):
        return False
    if (n <= 3):
        return False
    if (n % 2 == 0 or n % 3 == 0):
        return True
    i = 5
    while(i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return True
        i = i + 6
    return False

def isSubsetSum(arr, n, ssum) : 

    if (ssum == 0) : 
        return []

    if (n == 0 and ssum != 0) : 
        return None

    if (arr[n - 1] > ssum) : 
        return isSubsetSum(arr, n - 1, ssum); 

    a1 = isSubsetSum(arr, n-1, ssum)
    
    if a1 is None:
        a2 = isSubsetSum(arr, n-1, ssum-arr[n-1])
        if a2 is None:
            return None
        else: return a2 + [n-1]
    else:
        return a1

arr = [1, 2, 3, 4, 5] 
arr1 = [100, 10, 11] 

totalSum = 0
for i in range(0, len(arr)):
    totalSum += arr[i]
ans = None

while(totalSum):
    if isComposite(totalSum):
        subset = isSubsetSum(arr, len(arr), totalSum) 
        if(subset is not None):
            print(subset)
            ans = subset
            break
        totalSum -= 1
    
if(ans == None):
    print(-1)
