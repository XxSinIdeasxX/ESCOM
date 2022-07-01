public class Cuenta{
    int balance;

    public Cuenta(int bal){
        this.balance=bal;
    }

    void retiro(int n){
        this.balance=this.balance-n;
    }

    void deposito(int n){
        this.balance=this.balance+n;
    }

    int consulta(){
        return this.balance;
    }
}