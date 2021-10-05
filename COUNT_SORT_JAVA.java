//RUN THIS CODE IN INTELLIJ IDEA

package com.sorting;

import java.util.Arrays;

public class count_sort {
    public static void main(String[] args) {

    int [] arr={9,6,3,5,3,4,3,9,6,5,8,9,9};
    int max=0,min=0;
        //finding max and min elements
        for(int i=0;i<arr.length;i++){
           max= Math.max(arr[i],max);
           min= Math.min(arr[i],min);

        }
    CountSort(arr,max,min);
        System.out.println(Arrays.toString(arr));
    }

    private static void CountSort(int[] arr,int max,int min) {

    //creating an array of size max-min+1
        int [] appear=new int[max-min+1];

    //storing no. of count each value appeared
    for(int i=0;i<arr.length;i++){
        int index=arr[i]-min;
        appear[index]+=1;
    }
    //finding cumulative sequence
        for(int j=0;j<appear.length-1;j++){
            appear[j+1]+=appear[j];
        }

    //creating a temporary array to sort value according to values stored in appeared array
    int [] temp=new int[arr.length];

        for(int i=arr.length-1;i>=0;i--){
            // running from backward to maintain its stableness
            temp[appear[arr[i]-min] -1]=arr[i];
            appear[arr[i]-min]-=1;
        }

        for(int i=0;i< arr.length;i++){
            arr[i]=temp[i];
        }
    }
}
