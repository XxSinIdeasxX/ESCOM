package escom.repaso;

public class Factorial {
    private int num;
    
    public Factorial(){}

    public int getNum(){
        return this.num;
    }
    
    public void setNum(int numero){
        this.num = numero;
    }
    
    public int factorial(int n){
        if (n<=1){
            return 1;
        }return n*factorial(n-1);
    }

    public static void main(String[] args){
        Factorial f = new Factorial();
        f.setNum(4);
        System.out.println(f.factorial(f.getNum()));
    }
}