package fib;
//DP-@2
import java.util.Arrays;

public class longestcommonsubseq {
    static int[][] memo;
    public static int longest(String s,String s1,int m,int n)
    {
        for(int[] a:memo)
        Arrays.fill(a,-1);
        if(memo[m][n]!=-1)
            return memo[m][n];
        else {
            if (m == 0 || n == 0)
                return 0;
            if (s.charAt(m - 1) == s1.charAt(n - 1))
                memo[m][n] = 1 + longest(s, s1, m - 1, n - 1);
            else
                memo[m][n] = Math.max(longest(s, s1, m - 1, n), longest(s, s1, m, n - 1));
        }
        return memo[m][n];
    }

    public static void main(String[] args) {
        int m = 15,n=15;
        memo = new int[m+1][n+1];
        System.out.println(longest("ABIFRGTYGFRTYDE","AGCFDERFGTYHDED",m,n));
    }
}
