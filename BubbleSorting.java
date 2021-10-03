class BubbleSort{
	
	void BubbleSortFunc(int a[]) {
		for(int i=0;i<a.length-1;i++) {
			for(int j=0;j<a.length-i-1;j++) {
				if(a[j]>a[j+1]) {
					   int temp = a[j+1];  
                       a[j+1] = a[j];  
                       a[j] = temp;  
				}
			}
		}
			}
	
void display(int a[]) {
	for(int i=0;i<a.length;i++) {
	System.out.println(a[i]);
	}
}
}

public class BubbleSorting {

	public static void main(String[] args) {
    BubbleSort BS = new BubbleSort();
    int a[]= {1,11,5,6,2,3};
    BS.BubbleSortFunc(a);
    BS.display(a);
	}

}
