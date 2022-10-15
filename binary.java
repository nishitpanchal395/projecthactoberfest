public class binarysearch {
    public static int binary(int n[],int key) {
        int start = 0;
        int end = n.length - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if(n[mid]==key){
                return mid;//found
            }
            if(n[mid]<key){
                start=mid+1;//right
            }
            else{
                end=mid-1;//left
            }

        }
        return -1;
    }
    public static void main(String[] args) {
        int n[]={2,4,8,10,12,14,16};
        int key=16;
        int index=binary(n,key);
        if(index==-1){
            System.out.println("ELEMENT NOT FOUND");
        }
        else
        System.out.println("element found at index "+ index);
    }
}
