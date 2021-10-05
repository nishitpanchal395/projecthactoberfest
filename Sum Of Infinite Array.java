/*
    Time Complexity:O(Q*(R-L))
    Space Complexity:O(1).
    Where Q is the number of given queries, and L and R are the given two indexes in each query.
*/

import java.util.List;
import java.util.ArrayList;

public class Solution {

    private static int mod = (int) 1e9 + 7;

    public static List<Integer> sumInRanges(int[] arr, int n, List<List<Long>> queries, int q) {

        // It stores answer for each query.
        List<Integer> ans = new ArrayList<>();

        // Traversing the given queries
        for (List<Long> range : queries) {

            // Substract 1 from both L and R to use it as 0-based indexing
            long l = range.get(0) - 1;
            long r = range.get(1) - 1;

            // It stores the sum
            long sum = 0;

            for (long i = l; i <= r; i++) {
                int index = (int) (i % n);
                sum = (sum + arr[index]) % mod;
            }
            sum %= mod;
            // Add answer to each query
            ans.add((int) sum);
        }

        return ans;

    }
}
