from collections import deque

def computeLongestSubarray(arr, k):
    maxLength = 0

    maxHeap = []
    minHeap = []
    beg = 0
    end = 0
    ans = []

    while (end < len(arr)):
        currEl = arr[end]
        while (len(maxHeap) > 0 and arr[maxHeap[-1]] <= currEl):
            del maxHeap[-1]

        maxHeap.append(end)
        while (len(minHeap) > 0 and arr[minHeap[-1]] >= currEl):
            del minHeap[-1]

        minHeap.append(end)
        ans.append(arr[end])
        maxOfSub = arr[maxHeap[0]]
        minOfSub = arr[minHeap[0]]

        if (maxOfSub - minOfSub <= k):
            currLength = end - beg + 1

            if (maxLength < currLength):
                maxLength = currLength
                
        else:
            beg += 1
            while (len(minHeap) > 0 and minHeap[0] < beg):
                del minHeap[0]

            while (len(maxHeap) > 0 and maxHeap[0] < beg):
                del maxHeap[0]

        end += 1
    return ans

if __name__ == '__main__':
    arr3 = [2, 4, 3, 6, 6, 3]
    arr = [8, 1, 3, 11, 5, 18, 18, 1, 14, 11]
    arr1 = [1, 2, 1, 2, 2, 1, 3, 1, 1, 2, 2, 2, 2]
    k = 0

    ans = computeLongestSubarray(arr, k)
    print(ans)
    # print(maxLength)