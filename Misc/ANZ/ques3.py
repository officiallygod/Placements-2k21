def cntDisPairs(arr, N, K):
	
	cntPairs = 0
	arr = sorted(arr)
	i = 0
	j = N - 1

	while (i < j):
		if (arr[i] + arr[j]%100 == 0):
			while (i < j and arr[i] == arr[i + 1]):
				i += 1

			while (i < j and arr[j] == arr[j - 1]):
				j -= 1
    
			cntPairs += 1
			i += 1
			j -= 1

		elif (arr[i] + arr[j] < K):
			i += 1
		else:
			j -= 1
			
	return cntPairs

if __name__ == '__main__':
	
	arr = [ 5, 6, 5, 7, 7, 8 ]
	N = len(arr)
	K = 13
	
	print(cntDisPairs(arr, N, K))
