import java.util.Scanner;

public class ABCDERIAN {
    public static void main(String[] args) {
        Scanner masuk = new Scanner(System.in);
        String kata;
        int panjangkata;
        int panjangalpha;
        int a = 0;
        String alphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

        System.out.println("==ABCDERIAN Program==");
        System.out.print("Input word : ");
            kata = masuk.nextLine();
            masuk.close();

        panjangkata = kata.length();
        panjangalpha = alphabet.length();

        //System.out.println(panjangalpha);

        for(int i = 0; i < panjangalpha; i++){
            if(kata.charAt(a) == alphabet.charAt(i)){
                a++;
                if(a == panjangkata){
                    System.out.println("Word '"+kata+"' is ABCDERIAN");
                    return;
                }
            }
        }
        System.out.println("Word '"+kata+"' is not ABCDERIAN");
    }
}
