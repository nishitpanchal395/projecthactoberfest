
// link https://www.pepcoding.com/resources/online-java-foundation/introduction-to-recursion/toh-official/ojquestion
import java.io.*;
import java.util.*;

public class Tower_Of_Hanoi {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t1id = sc.nextInt();
        int t2id = sc.nextInt();
        int t3id = sc.nextInt();
        toh(n,t1id,t2id,t3id);
    }

    public static void toh(int n, int t1id, int t2id, int t3id){
        if(n == 0){
            return;
        }
        toh(n-1,t1id,t3id,t2id);
        System.out.println(n + "[" + t1id + " -> " + t2id + "]");
        toh(n-1,t3id,t2id,t1id);
        
    }

}