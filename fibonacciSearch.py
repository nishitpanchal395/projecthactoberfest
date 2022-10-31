
from bisect import bisect_left



def fibMonaccianSearch(arr, x, n):

	fibMMm2 = 0 # (m-2)'th Fibonacci No.
	fibMMm1 = 1 # (m-1)'th Fibonacci No.
	fibM = fibMMm2 + fibMMm1 # m'th Fibonacci


	while (fibM < n):
		fibMMm2 = fibMMm1
		fibMMm1 = fibM
		fibM = fibMMm2 + fibMMm1


	offset = -1


	while (fibM > 1):


		i = min(offset+fibMMm2, n-1)



		if (arr[i] < x):
			fibM = fibMMm1
			fibMMm1 = fibMMm2
			fibMMm2 = fibM - fibMMm1
			offset = i


		elif (arr[i] > x):
			fibM = fibMMm2
			fibMMm1 = fibMMm1 - fibMMm2
			fibMMm2 = fibM - fibMMm1


		else:
			return i


	if(fibMMm1 and arr[n-1] == x):
		return n-1


	return -1



arr = [10, 22, 35, 40, 45, 50,
	80, 82, 85, 90, 100,235]
n = len(arr)
x = 235
ind = fibMonaccianSearch(arr, x, n)
if ind>=0:
print("Found at index:",ind)
else:
print(x,"isn't present in the array");

