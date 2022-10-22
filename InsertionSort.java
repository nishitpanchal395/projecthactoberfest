public class insertionsort {
    public  static void sort(int arr[])
    {
        for (int i = 1; i < arr.length; ++i) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j --;
            }
            arr[j + 1] = temp;
        }
    }
    public static void main(String args[])
    {
        int arr[] = { 8,4,1,5,9,2 };
        sort(arr);
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    }


