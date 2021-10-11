#include<bits/stdc++.h>
using namespace std ;
void heapify(int arr[], int n, int i)
{
    int largest= i;
    int l=2*i+1;
    int r= 2*i+2 ;
    if (l<n&& arr[l]>arr[largest])
    {
        largest= l;
    }
    if (r<n && arr[r]> arr[largest])
    {
        largest= r;
    }
    if (largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[], int n )
{
    int i;
    for ( i = n/2-1; i >=0; i--)
    {
        heapify(arr,n,i);
    }
    for ( i = n-1 ; i> 0; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main()
{
    int arr[]={24,44,65,5,52,5,24}, n= sizeof(arr)/sizeof(int);
     int i ;
    cout<<"Array inserted :  ";
    for ( i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    heapsort(arr, n);
cout<<"\n Array after heapsort :  ";
    for ( i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    
}