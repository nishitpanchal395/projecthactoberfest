import java.util.Date;
import java.util.Scanner;
 
public class BmiCal {
 
    public static void main(String[] args) {
        
        Scanner console = new Scanner(System.in);
        System.out.println("Enter next person's information:");
        System.out.print("height (in inches)? ");
        double height = console.nextDouble();
 
        System.out.print("weight (in pounds)? ");		
        double weight = console.nextDouble();
        System.out.println();
        
       double bmi = weight / Math.pow(height, 2) * 703;
       System.out.println("BMI:"+bmi);
 
        if (bmi < 18.5) {
            System.out.print("You are in underweight");
        } else if (bmi < 25) {
            System.out.print("You are in normal");
        } else if (bmi < 30) {
            System.out.print("You are in overweight");
        } else {
            System.out.print("You are in obese");
        }
  
    }  
}