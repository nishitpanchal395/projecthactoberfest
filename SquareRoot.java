import java.util.Scanner;

public class SquareRoot {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
        System.out.println("Enter a number to find the Square Root:");
        int number = scan.nextInt();
        
		System.out.print("Square Root of "+number+" = "+ squareRoot(number));
	}

	public static double squareRoot(int value) {
		double num;
		double half = (double) value / 2;
		do {
			num = half;
			half = (num + (value / num)) / 2;
		} while ((num - half) != 0);
		return half;
	}
}