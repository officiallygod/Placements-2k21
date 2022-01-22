
def knapSack(W, wt, val, n):
    dp = [0 for i in range(W+1)]  # Making the dp array
 
    for i in range(1, n+1):  # taking first i elements
        for w in range(W, 0, -1):  # starting from back,so that we also have data of
                                # previous computation when taking i-1 items
            if wt[i-1] <= w:
                # finding the maximum value
                dp[w] = max(dp[w], dp[w-wt[i-1]]+val[i-1])
    #print(dp)
    return dp[W]  # returning the maximum value of knapsack
 
 

f=[]
x = list(map(int, input().split()))
n = x[0]
W = x[1]
arr = list(map(int, input().split()))
m = int(input())
for i in range(m):
    f.append(list(map(int,input().split())))

wt=[]
val=[]
already_taken=[]

for x in f:
    s=0
    for i in x:
        s+=arr[i-1]
    wt.append(s)
    val.append(len(x))
    for i in x:
        already_taken.append(i)
for i in range(1,n+1):
    if i not in already_taken:
        wt.append(arr[i-1])
        val.append(1)
print(knapSack(W, wt, val, len(wt)))