public class PrChck {
 
 public static void main(String[] args) {
  int rem;
  boolean isPrime=true;
  int numberToCheck=23423; 
        
  //whether the numberr is divisible 
  for(int i=2;i<=numberToCheck/2;i++)
  {
   //numberToCheckber is divided by itself
            rem=numberToCheck%i;
         
       //if rem is 0 than numberToCheckber is not prime
     if(rem==0)
     {
        isPrime=false;
        break;
     }
  }
  // Check value true or false
  if(isPrime)
     System.out.println(numberToCheck + " is a Prime");
  else
     System.out.println(numberToCheck + " is not a Prime");
    }
  }
