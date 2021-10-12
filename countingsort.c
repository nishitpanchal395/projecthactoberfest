#include<stdio.h>
#include<string.h>
void countsort(int arr[], int n)
{
   int output[n], max=arr[0] ;
   int i,j ;
   for ( i = 1; i < n; i++)
   {
       if (max<arr[i])
       {
           max=arr[i];
       }   
   }
   int  count[max+1] ;
   memset(count, 0, sizeof(count));
   for ( i = 0; i <n; i++)
   {
       ++count[arr[i]] ;
   }
  
//    i=0 ;
//    j=-1 ;
//    while (j<=n)
//    {
//        if (count[i]>0)
//        {
//            output[++j]=i;
//            count[i]--;
//        }
//        else
//        {
//            i++;
//        }     
//    }
//method - 2 
 for ( i = 1; i <max+1; i++)
   {
       count[i]=count[i]+count[i-1] ;
   }
   for ( i = n-1; i >=0; i--)
   {
       output[count[arr[i]]-1]=arr[i];
       count[arr[i]]=count[arr[i]]-1 ;
   }
   for ( i = 0; i < n; i++)
   {
       arr[i]=output[i] ;
   } 
}
int main()
{
    int arr[]={1,4,2,6,8,12,9,5,7,9}, n=sizeof(arr)/sizeof(int) ;
     for (int i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    
    countsort(arr, n);
    printf("\n Sorted array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    
}