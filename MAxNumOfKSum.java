import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class MAxNumOfKSum {
    public static int maxOperations(int[] nums, int k) {
        // ArrayList<Integer>arr=new ArrayList<>();
        Arrays.sort(nums);
        // for(int i:nums){
        //     arr.add(i);
        //         }
                int ans=0;
        //         Collections.sort(arr);  

        //         System.out.println(arr);
                int i=0;
                int j=nums.length-1;
                while(i<j){
                    if(nums[i]+nums[j]==k){
                        ans++;
                        i++;
                        j--;
                    }
                    else if(nums[i]+nums[j]>k){
                        j--;
                    }
                    else{
                        i++;
                    }
                }
                return ans;
    }

    public static void main(String[] args) {
        int arr[]={3,1,3,4,3};
System.out.println(maxOperations(arr,6));
    }


}
