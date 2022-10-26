import java.util.Scanner;

public class FibSeries {

 public static void main(String[] args) {
  int FibLength;
  Scanner sc = new Scanner(System.in); //create object

  System.out.print("Please enter length: ");
  FibLength = sc.nextInt();

  int[] num = new int[FibLength];
  //initialized first element to 0
  num[0] = 0;
  //initialized second element to 1
  num[1] = 1;
  
  //New number should be the sum of the last two numbers of the series.
  for (int i = 2; i < FibLength; i++) {
   num[i] = num[i - 1] + num[i - 2];
  }

  //Print Fibonacci Series
  System.out.println("Fibonacci Series: ");
  for (int i = 0; i < FibLength; i++) {
   System.out.print(num[i] + " ");
  }
 }

}
