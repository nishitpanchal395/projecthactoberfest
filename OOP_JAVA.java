public class belajar_final {
    
    int angka = 23;
    int bilangan = 4;
    
    public final void MethodeFinal(){
     System.out.println("ini methode MethodeFinal dari kelas belajar_final");
    }
    
    public void VariableFinal() {
     System.out.println("ini methode VariableFinal dari kelas belajar_final");
    }
    
    public static void main(String[] args){
     belajar_final f = new belajar_final();
     f.VariableFinal(); // memanggil methode variabelFinal()
     System.out.println("Angka : " + f.angka);
     System.out.println("Bilangan : " + f.bilangan);
     f.MethodeFinal(); // memanggil methode MethodeFinal()
    }    
}
