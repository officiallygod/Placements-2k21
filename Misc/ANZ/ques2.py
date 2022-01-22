def longestSubarray(A, N, X):

	maxLen = 0
	beginning = 0
	window = {}
	start = 0

	for end in range(N):
     
		if A[end] in window:
			window[A[end]] += 1
		else:
			window[A[end]] = 1

		minimum = min(list(window.keys()))
		maximum = max(list(window.keys()))

		if maximum - minimum <= X:
			if maxLen < end - start + 1:
				maxLen = end - start + 1
				beginning = start
		else:
			while start < end:

				window[A[start]] -= 1

				if window[A[start]] == 0:
					window.pop(A[start])

				start += 1

				minimum = min(list(window.keys()))
				maximum = max(list(window.keys()))

				if maximum - minimum <= X:
					break

	for i in range(beginning, beginning + maxLen):
		print(A[i], end = ' ')

arr3 = [2, 4, 3, 6, 6, 3]
arr = [8, 1, 3, 11, 5, 18, 18, 1, 14, 11]
arr1 = [1, 2, 1, 2, 2, 1, 3, 1, 1, 2, 2, 2, 2]
X = 1
n = len(arr1)
longestSubarray(arr1, n, X)