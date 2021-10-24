// Largest sum contiguous sub array using divide and conqure

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll max(ll a, ll b, ll c)
{
	int res;

	if(a>b && a>c)
		return a;
	else if(b>c && b>a)
		return b;
	else
		return c;
}

ll maxCrossing(int arr[], int n, int l, int h, int m)
{
	ll left_sum=INT_MIN, right_sum=INT_MIN, sum=0;

	for(int i=m ; i>=l ; i--)
	{
		sum+=arr[i];

		if(sum > left_sum)
			left_sum = sum;
	}

	sum = 0;

	for(int i=m+1 ; i<=h ; i++)
	{
		sum+=arr[i];

		if(sum > right_sum)
			right_sum = sum;
	}

	return max(right_sum, left_sum, left_sum+right_sum);
}

ll maxSum(int arr[], int n, int l, int h)
{
	if(l == h)
		return arr[l];

	int m = (l+h)/2;

	return max(maxSum(arr, n, l, m), maxSum(arr, n, m+1, h), maxCrossing(arr, n, l, h, m));
}

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i<n ; i++)
		cin>>arr[i];

	cout<<maxSum(arr, n, 0, n-1)<<endl;
}

int main()
{
	solve();
	return 0;
}