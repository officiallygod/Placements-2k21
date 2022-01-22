import collections

def find(s):
    indices = [collections.deque() for _ in range(26)]
    start = 0
    min_length = float('inf')
    best = -1

    def idx(c):
        return ord(c.lower()) - ord('a')

    def check(indices):
        for i in range(25):
            if not indices[i]:
                return False
            while indices[i+1] and indices[i+1][0] < indices[i][0]:
                indices[i+1].popleft()
            if not indices[i+1]:
                return False
        return True

    for end in range(len(s)):
        if s[end].isalpha():
            indices[idx(s[end])].append(end)

        while end - start + 1 >= 26 and check(indices):
            if end - start + 1 < min_length:
                min_length = end - start + 1
                best = start
            if s[start].isalpha():
                if start == indices[idx(s[start])][0]:
                    indices[idx(s[start])].popleft()
            start += 1

    return "" if best == -1 else s[best:best + min_length]

s = str(input())
m = find(s.lower())
# print(m)
print(len(m))