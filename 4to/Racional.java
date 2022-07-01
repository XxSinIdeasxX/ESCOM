public class Racional{
	int den, num;

	public Racional(int num, int den){
		this.den=den; 
		this.num=num;
	}

	Racional sum(Racional r){
		return new Racional((num*r.den) + (den*r.num), den*r.den);
	}

    Racional res(Racional r){
		return new Racional((num*r.den) - (den*r.num), den*r.den);
	}

	void imprime(){
		System.out.println(this.num+" / "+ this.den);
	}
}

