def solve(N, A):
    dp = [0]*N
    dp[0] = A[0]
    for i in range(1, N):
        dp[i] = max(dp[i - 1] + A[i], dp[i - 1] - A[i])
    return dp[N-1]

N = int(input())
A = list(map(int, input().split()))
out = solve(N, A)
print(out)