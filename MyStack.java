package Array_Implementation;

public class MyStack {
	int arr[];
	int toss=-1;
	MyStack(int x){
		arr=new int[x];
	}
	void push(int x) {
		arr[++toss]=x;
	}
	int pop() {
		return arr[toss--];
	}
	int peek() {
		return arr[toss];
	}
	boolean isEmpty() {
		if(toss==-1)return true;
		else return false;
	}
	boolean isFull() {
		if(toss==arr.length-1)return true;
		else
			return false;
	}
//	public static void main(String[] args) {
//		// TODO Auto-generated method stub
////		MyStack st=new MyStack(3);
////		System.out.println(st.isFull()+" "+st.isEmpty());
////		st.push(5);
////		st.push(6);
////		System.out.println(st.isFull()+" "+st.isEmpty());
////		st.push(9);
////		System.out.println(st.isFull()+" "+st.isEmpty());
////		System.out.println(st.pop()+" "+st.pop()+" "+st.peek()+" "+st.pop());
////		System.out.println(st.isFull()+" "+st.isEmpty());
//	}

}
