public class aplicacion{
    public static void main(String[] args) throws Exception{
        Complejo A , B;
        A = new Complejo(3, 4);
        B = new Complejo(1, 2);
        A.imprime();
        B.imprime();
        (A.sum(B)).imprime();
        (A.res(B)).imprime();
        (A.mult(B)).imprime();
        (A.div(B)).imprime();
        (A.mod(B)).imprime();
        if (!A.esIgual(B)){
            System.out.println("A no es igual que B");
        }
    }
}