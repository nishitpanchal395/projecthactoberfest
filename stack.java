import java.util.*;
class Stack {
    static final int MAX = 1000;
    int top;
    int a[] = new int[MAX]; 
 
    boolean isEmpty()
    {
        return (top < 0);
    }
    Stack()
    {
        top = -1;
    }
 
    boolean push(int x)
    {
        if (top >= (MAX - 1)) {
            return false;
        }
        else {
            a[++top] = x;
            return true;
        }
    }
 
    int pop()
    {
        if (top < 0) {
            System.out.println("Stack Underflow");
            return 0;
        }
        else {
            int x = a[top--];
            return x;
        }
    }
 
    int peek()
    {
        if (top < 0) {
            return 0;
        }
        else {
            int x = a[top];
            return x;
        }
    }
    
    void print(){
  }
}
class stack {
    public static void main(String args[])
    {
        
        Scanner sc=new Scanner(System.in);
        Stack s = new Stack();
        int first_number=sc.nextInt();
        int second_number=sc.nextInt();
        int third_number=sc.nextInt();
        s.push(first_number);
        s.push(second_number);
        s.push(third_number);
        System.out.println(s.pop());
        s.print();
    }
}