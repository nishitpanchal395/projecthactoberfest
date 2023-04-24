public class CountVowel {
    public static int countVowelStrings(int n) {
        int a=1, e=1, i=1, o=1, u=1;
        
        while(--n>0){
            o += u;
            i += o;
            e += i;
            a += e;
        }
        
        return a+e+i+o+u;
    }
    
    public static void main(String[] args) {
        System.out.println(countVowelStrings(3));
    }
}
