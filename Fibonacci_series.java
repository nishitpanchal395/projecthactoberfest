import java.util.*;
public class Fibonacci_series{
	public static void foo(int a, int b, int n){
		System.out.print(a + ", " + b + ", ");
		for(int i = 1; i <= n - 2; i++){
			int c = a + b;
			a = b;
			b = c;
			if(i < n - 2)
				System.out.print(c + ", ");
			else
				System.out.print(c);
		}
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = 1;
		int b = 1;
		System.out.println("Enter the total number of terms:");
		int n = sc.nextInt();
		foo(a, b, n);
	}
}