import java.util.Scanner;

class AccountDetails{
	
	 public  int balance=0;
	public  void setBalance(int n) {
		balance=n;
	}
	
	public void withdraw(int b)
	{
		balance=balance-b;
	}
	
	public void deposit(int c)
	{
		balance=balance+c;
	}
	public void show()
	{
		System.out.println("Balance="+balance);
	}

	
	
}



public class bankapplication{

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		AccountDetails a =new AccountDetails();
		System.out.println("Enter your initial balance");
		int balance=sc.nextInt();
		a.setBalance(balance);
		while(true) {
			System.out.println("Enter your choice");
			System.out.println("1 - Withdraw ");
			System.out.println("2 - Deposit");
			System.out.println("3 - Show remaining balance");
			System.out.println("0-Exit");
			System.out.println();
			int choice=sc.nextInt();
			switch(choice)
			{
			case 0: System.exit(0);
			break;
			
			case 1:System.out.println("Enter amount to withdraw");
			int withdraw = sc.nextInt();
			a.withdraw(withdraw);
			break;
			
			case 2:System.out.println("Enter amount to deposit");
			int deposit = sc.nextInt();
			a.deposit(deposit);
			break;
			
			case 3:
			
			a.show();
			break;
			}
			
			
		}
		
		
		
	}
		
		
		

	}
