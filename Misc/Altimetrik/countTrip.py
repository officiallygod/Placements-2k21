def findTriplets(arr, sum):
    cnt = 0
    arr.sort()
    n = len(arr)
    for i in range(0, n - 1):
        l = i + 1
        r = n - 1
        x = arr[i]
        while (l < r) :
            if (x + arr[l] + arr[r] == sum) :
                cnt += 1
                l = l + 1
                r = r - 1
            elif (x + arr[l] + arr[r] < sum):
                l = l + 1
            else:
                r = r - 1
    return cnt

arr1 = [ 0, -1, 2, -3, 1 ]
arr2 = [ 10, 13, 15, 17, 19 ]
arr3 = [ 1, 3, 4, 6, 9, 12 ]
sum1 = -2
sum2 = 38
sum3 = 24
n = len(arr3)
ans = findTriplets(arr3, n, sum3)
print(ans)
