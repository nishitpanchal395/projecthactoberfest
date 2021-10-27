// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum
// number of elements to be removed
// satisfying the conditions
int minimumDeletions(int arr[], int N)
{
	// Stores the final answer
	int ans = 0;

	// Map to store frequency
	// of each element
	map<int, int> mp;

	// Traverse the array arr[]
	for (int i = 0; i < N; i++)
		mp[arr[i]]++;

	// Traverse the array arr[]
	for (int i = 0; i < N; i++) {
		// Stores whether current
		// element needs to be
		// removed or not
		int flag = 0;

		// Iterate over the range
		// [0, 30]
		for (int j = 0; j < 31; j++) {

			// Stores 2^j
			int pw = (1 << j);

			// If 2^j -arr[i] equals
			// to the arr[i]
			if (pw - arr[i] == arr[i]) {

				// If count of arr[i]
				// is greater than 1
				if (mp[arr[i]] > 1) {
					flag = 1;
					break;
				}
			}
			// Else if count of 2^j-arr[i]
			// is greater than 0
			else if (mp[pw - arr[i]] > 0) {
				flag = 1;
				break;
			}
		}
		// If flag is 0
		if (flag == 0)
			ans++;
	}
	// Return ans
	return ans == N ? -1 : ans;
}
// Driver Code
int main()
{

	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << minimumDeletions(arr, N) << endl;

	int arr1[] = { 1, 5, 10, 25, 50 };
	N = sizeof(arr) / sizeof(arr[0]);
	cout << minimumDeletions(arr1, N) << endl;

	return 0;
}
