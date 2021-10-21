#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int hoarePartition(int arr[], int l, int r){
    int i=l-1;
    int j=r+1;
    int pivot = arr[l];

    while(true){
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);

        if(i >= j){
            return j;
        }
        swap(arr[i],arr[j]);
    }
}

// int lomutoPartition(int arr[], int l, int r){

//     int pivot = r;
//     int i = l-1;
//     for(int j = l;j < r;j++){
//         if(arr[j] < arr[pivot]){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i+1],arr[pivot]);
//     return i+1;
// }
void qSort(int arr[], int l, int r){
    if(l < r){
        // int pivot = lomutoPartition(arr,l,r);
        // qSort(arr,l,pivot-1);
        // qSort(arr,pivot+1,r);

        int pivot = hoarePartition(arr,l,r);
        qSort(arr,l,pivot);
        qSort(arr,pivot+1,r);
    }
}

int main(){
    
    cout<<"Enter size of array : ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    qSort(arr,0,n-1);

    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}