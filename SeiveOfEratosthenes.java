package algorithm;
import java.util.*;
public class SeiveOfEratosthenes {

	public static void main(String[] args) {
		//finding prime no.s..o(nlogn)
		Scanner sc = new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
	      int num = sc.nextInt();
	      boolean[] bool = new boolean[num+1];
	     
	      for (int i = 0; i< bool.length; i++) {
	         bool[i] = true;
	      }
	      for (int i = 2; i< Math.sqrt(num); i++) {
	         if(bool[i] == true) {
	            for(int j = (i*i); j<num; j = j+i) {
	               bool[j] = false;
	            }
	         }
	      }
	     // System.out.println("List of prime numbers upto given number are : ");
	      for (int i = 2; i< bool.length; i++) {
	         if(bool[i]==true) {
	            System.out.print(i+" ");
	         }
	      }
		}
	}

}
