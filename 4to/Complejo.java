public class Complejo{
	int Re, Im;

	public Complejo(int Re, int Im){
		this.Re=Re; 
		this.Im=Im;
	}

	Complejo sum(Complejo c){
		return new Complejo(Re+c.Re, Im+c.Im);
	}

    Complejo res(Complejo c){
		return new Complejo(Re-c.Re, Im-c.Im);
	}

    Complejo mult(Complejo c){
        return new Complejo(Re*c.Re-Im*c.Im, Re*c.Im+Im*c.Re);
    }

    Complejo div(Complejo c){
        return new Complejo((Re*c.Re+Im*c.Im)/(c.Re*c.Re+c.Im*c.Im), (Im*c.Re-Re*c.Im)/(c.Re*c.Re+c.Im*c.Im));
    }

    Complejo mod(Complejo c){
        return this.res(c.mult(this.div(c)));
    }

    Boolean esIgual(Complejo c){
        return Re==c.Re && Im==c.Im;
    }

	void imprime(){
		System.out.println(this.Re + "+" + this.Im + "i");
	}
}
