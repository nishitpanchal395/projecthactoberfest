public class ReduceNumber {
    public static void main(String[] args) {
        System.out.println(numberOfSteps(123));
    }

    public  static int numberOfSteps(int num) {
        int ans=0;

        while(num!=0){
            if(num==0) return ans;
            else{
                if(num%2==0){
                    num=num/2;
                    ans++;
                }
                else if(num%2!=0){
                    num-=1;
                    ans++;
                }
            }
        }
        return ans;
    }
}
