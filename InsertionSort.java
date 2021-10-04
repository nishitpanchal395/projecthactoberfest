
import java.util.Arrays;
import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array!");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements of array");
        for (int c = 0; c <= n - 1; c++) {
            arr[c] = sc.nextInt();
        }
        sc.close();
        InsSort(arr);
        System.out.println("the shorted array is :");
        System.out.println(Arrays.toString(arr));
    }

    private static void InsSort(int[] arr) {
        for (int i = 1; i <= arr.length - 1; i++) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
}
