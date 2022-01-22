def fourSum(nums, target):
    ans, n = [], len(nums)
    nums.sort()
    for a in range(n):
        for b in range(a+1, n):
            c = b+1; d = n-1
            while c<d:
                sums = nums[a]+nums[b]+nums[c]+nums[d]
                if sums < target: c += 1
                elif sums > target: d -= 1
                else:
                    to_append = [nums[a],nums[b],nums[c],nums[d]]
                    if to_append not in ans:
                        ans.append(to_append)
                    c +=1; d-=1
    return ans
    
listt = list(map(int, input().split(', ')))
n = len(listt)
X = 50

print(fourSum(listt, X))

