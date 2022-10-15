class Solution {
    public int countNumberofDigits(int n) {
        int ans=0;
        if (n >= 0) {
            ans= (int) Math.log10(n) + 1;
        } else {
            // To handle the case of negative number
            ans= Math.log10(Math.abs(n)) + 1;
        }
        return ans;
    }
}
