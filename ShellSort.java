/*
ShellSort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. When an element
has to be moved far ahead, many movements are involved. The idea of shellSort is to allow exchange of far items.
In shellSort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1.
An array is said to be h-sorted if all sublists of every h’th element is sorted.
Time complexity of below implementation of shellsort is O(n2)
*/
import java.util.Arrays;
class ShellSort {
  void shellSort(int array[], int n) {
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
    int temp = array[i];
    int j;
    for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
      array[j] = array[j - interval];
    }
    array[j] = temp;
    }
  }
  }
  public static void main(String args[]) {
  int[] data = { 9, 8, 3, 7, 5, 6, 4, 1 };
  int size = data.length;
  ShellSort ss = new ShellSort();
  ss.shellSort(data, size);
  System.out.println("Sorted Array in Ascending Order: ");
  System.out.println(Arrays.toString(data));
  }
}
