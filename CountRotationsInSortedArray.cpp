#include<iostream>
using namespace std;
int numRotations(int arr[],int left,int right,int N)
{
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        int next=(mid+1)%N;
        int prev=(mid+N-1)%N;
        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev])
        {
            return mid;
        }
        if(arr[left]<=arr[mid])
        {
            left=mid+1;
        }
        if(arr[mid]<=arr[right])
        {
            right=mid-1;
        }
        
    }
}
int main()
{
    int output;
   int size;
   cin>>size;
   int myarr[size];
   cout<<"enter the array elements:";
   for(int i=0;i<size;i++)
   {
       cin>>myarr[i];
   }
   numRotations(myarr,0,size-1,size);
   output= numRotations(myarr,0,size-1,size);
   cout<<"the num of rotations /rotation count is:"<<output<<endl;
   
}
