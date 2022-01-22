def func(i,arr,x=[],last=-1):
    global res
    if i==len(arr):
        res=(res+1)%(998244353)
        return
    
    for j in range(arr[i]):
        if j+1==last:
            continue
        x.append(j+1)
        func(i+1,arr,x,j+1)
        x.pop()

n=int(input())  
global res
res=0      
arr=list(map(int,input().split()))
func(0,arr)
print(res%(998244353))

