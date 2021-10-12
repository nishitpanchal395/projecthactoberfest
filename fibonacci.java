package recursion;

public class fibonacci {
//    O(2^n)
public int fib(int n)
{
   if(n==0)
   {
//       System.out.print(0+" ");
       return 0;
   }
   if(n==1)
   {
//       System.out.print(1+" ");
       return 1;
   }
   return fib(n-1)+fib(n-2);
}
public int pow(int n,int base)
{
    if(base==0)
        return 1;
    return n*pow(n,base-1);
}
public int gcd(int a,int b)
{
    if(a==0 ||b==0)
    {
        if(a==0)
            return b;
        else
            return a;
    }
    if( a>b)
    return gcd(a-b,b);
    else
        return gcd(a,b-a);
}
public int minnoofways(int n,int m)
{
    if(n==1 || m==1)
        return 1;
    return minnoofways(n-1,m)+ minnoofways(n,m-1);
}
public int joseph(int n,int k)
{
    if(n==1)
        return 0;
    return (joseph(n-1,k)+k)%n;
}
public boolean isPallindrome(String s,int l,int r)
{
    if(l>=r)
        return true;
    if(s.charAt(l)!=s.charAt(r))
        return false;
    return isPallindrome(s,l+1,r-1);
}
public void powersetOfString(String s,int i,String curr)
{
    if(i==s.length()){
        System.out.print(curr+",");
        return;
    }
    powersetOfString(s,i+1,curr+s.charAt(i));
    powersetOfString(s,i+1,curr);
}
}
