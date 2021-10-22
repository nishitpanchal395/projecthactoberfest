
// a simple algo to find the hcf of two numbers

public class GCD {
    public static void main(String[] args) {
        int a = 15, b = 27;
        int hcf = gcd(a, b);
        System.out.println(hcf);
    }

    public static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}
