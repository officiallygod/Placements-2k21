def productSubArray(nums):
    arr=nums[:]
    max_h=arr[0]
    mini_h=arr[0]
    temp=arr[0]
    maxi=arr[0]
    n=len(arr)
    for i in range(1,n):
        temp=max_h
        max_h=max(arr[i],arr[i]*max_h,arr[i]*mini_h)
        mini_h=min(arr[i],arr[i]*temp,arr[i]*mini_h)
            
        maxi=max(maxi,max_h)
            
    return maxi

def productSubsetArray(a):
    n = len(a)
    
    if n == 1:
        return a[0]

    max_neg = -999999999999
    count_neg = 0
    count_zero = 0
    prod = 1
    for i in range(n):
        if a[i] == 0:
            count_zero += 1
            continue
        if a[i] < 0:
            count_neg += 1
            max_neg = max(max_neg, a[i])
        prod = prod * a[i]

    if count_zero == n:
        return 0
    
    if count_neg & 1:
        if (count_neg == 1 and count_zero > 0 and
            count_zero + count_neg == n):
            return 0
        prod = int(prod / max_neg)
    return prod

def sol(arr):
    return productSubArray(arr) + productSubsetArray(arr)

arr1 = [ 1, -2, -3, 4, -5, 6 ]
arr2 = [ 100, 0, 0, 1, 5, -2, -500, 0, 1, 1 ]
ans = sol(arr2)
print(ans)