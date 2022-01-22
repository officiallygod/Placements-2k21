n=int(input())
arr=list(map(int,input().split()))

lst=[]
i=1
for x in arr:
    lst.append([x,i])
    i+=1
    
def compare(x):
    return x[0]
    
lst.sort(key=compare)

for v in lst:
    print(v[1], end=" ")