//TO Search a number from a given shorted array using the binary search

import java.util.Scanner;

public class binarySearch {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int ans = bin(arr, num);
        if (ans == -1) {
            System.out.println("Number not matched");
        } else
            System.out.println(num + " is at the index " + ans);
        sc.close();
    }

    static int bin(int[] arr, int target) {
        int st = 0;

        int end = arr.length - 1;
        // for the dessending shorted array
        if (arr[st] > arr[end]) {
            while (st <= end) {
                int mid = st + (end - st) / 2;
                // if (arr[st] > arr[end]) {
                if (target < arr[mid]) {
                    st = mid + 1;
                } else if (target > arr[mid]) {
                    end = mid - 1;
                } else {
                    // number found (target==arr[mid])
                    return mid;
                }
            }
        }
        // for the assending shorted array
        if (arr[st] < arr[end]) {
            while (st <= end) {
                int mid = st + (end - st) / 2;
                // if (arr[st] > arr[end]) {
                if (target < arr[mid]) {
                    end = mid - 1;
                } else if (target > arr[mid]) {
                    st = mid + 1;
                } else {
                    // number found (target==arr[mid])
                    return mid;
                }
            }

        }
        // number not found!!
        return -1;

    }
}