import java.util.*;
//Code to sahi hai but base case kind ka thing nhi mila raha hai

public class MedianOfTwoSortedArray {
	public static void main(String[] args) {
		// BINARY SEARCH
		int[] nums1 = {1,2};
		int[]nums2 = {3};
		double solution = solution(nums1, nums2);
		System.out.println(solution);

	}

	private static double solution(int[] nums1, int[] nums2) {
		if (nums1.length > nums2.length) {
			int[] temp = nums1;
			nums1 = nums2;
			nums1 = temp;
		}
		int lo = 0;
		int hi = nums1.length;
		int combinedLength = nums1.length + nums2.length;
		while (lo <= hi) {
			int partX = (lo + hi)/2;
			int partY  = (combinedLength + 1)/2 - partX;
			
			int leftX = getMax(nums1,partX);
			int rightX = getMin(nums1,partX);
			
			int leftY = getMax(nums2,partY);
			int rightY = getMin(nums2,partY);
			
			if(leftX<=rightX && leftY <= rightX) {
				if(combinedLength % 2 == 0) {
					return (Math.max(leftX, leftY) + Math.min(rightX,rightY))/2.0;
				}
				
					return Math.max(leftX,leftY);
				
			}
			else if(leftX>rightX) {
				hi = partX - 1;
			}
			else {
				lo = partX + 1;
			}

		}
		return 0.0;
	}
	
	private static int getMax(int[] nums,int partition) {
		if(partition == 0) {
			return Integer.MIN_VALUE;
		}
		return nums[partition  - 1];
	}
	private static int getMin(int[] nums,int partition) {
		if(partition == nums.length) {
			return Integer.MAX_VALUE;
		}
		return nums[partition];
	}
}
