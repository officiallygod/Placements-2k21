 n=int(input())
str1=input()
str2=input()
str3=input()

b='YES'
for i in range(n):
    if (str1[i]!=str2[i]) and (str1[i]!=str3[i]) and (str2[i]!=str3[i]):
        b='NO'
        break
print(b)
        
