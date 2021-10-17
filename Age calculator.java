import java.util.Scanner;

class MyClass {

    public static void main(String[ ] args) {

//age Calculator in java

        System.out.println("Enter your birth year");

        Scanner myVar = new Scanner(System.in);

        System.out.println("Your are " +( 2021 - myVar.nextInt() ) + " years old");        

    }

}
