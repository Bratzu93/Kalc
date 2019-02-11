public class Segmento{
	private  Punto p1;
	private  Punto p2;

	public Segmento(){
		 p1= new Punto();
		 p2= new Punto();
		 if(p1.major(p2))
			 scambia();
	}
	public Segmento(Punto _p1, Punto _p2){
		 p1=new Punto(_p1);
		 p2=new Punto(_p2);
		 if(p1.major(p2))
		 scambia();
	}
	public Segmento(Punto _p){
		p1=new Punto();
		p2=new Punto(_p);
		if(p1.minor(p2))
		{	 scambia();}
	}
	public Punto findMidpoint() {
        return new Punto((p1.get_x() + p2.get_x()) / 2, (p1.get_y() + p2.get_y()) / 2);
    }
	public void scambia(){
		Punto point = p1;
		p1=p2;
		p2=point;
	}
	public boolean minor(Segmento s){
	return p1.minor(s.p1) ;
	}	
	public boolean major(Segmento s){
		return p2.major(s.p2);
	}	
	public boolean equal(Segmento s){
		return (p1.equal(s.p1) && p2.equal(s.p2));
	}	
	public boolean notEqual(Segmento s){
		return (p1.notEqual(s.p1) || p2.notEqual(s.p2));
	}	
	public Segmento sum(Segmento s){
		Segmento temporaneo = new Segmento();
        if(this.equal(s)){
        temporaneo=this;
        }else if(this.minor(s)){
        if(this.major(s)){
        Segmento temp = new Segmento(p1,p2);
        temporaneo=temp;}
        else{
        Segmento temp = new Segmento(p1, s.p2);
        temporaneo=temp;}
    }else if(s.minor(this)){
        if(this.major(s)){
            Segmento temp = new Segmento(s.p1,p2);
            temporaneo=temp;}
        else{
            Segmento temp = new Segmento(s.p1,s.p2);
            temporaneo=temp;
        }
    }
    return temporaneo;
	}
	public Segmento difference(Segmento s){
    Segmento temporaneo = new Segmento();
        if(this.equal(s)){
        temporaneo=this;
        }else if(this.major(s)){
        if(this.minor(s)){
        Segmento temp = new Segmento(p1,p2);
        temporaneo=temp;}
        else{
        Segmento temp = new Segmento(p1,s.p2);
        temporaneo=temp;}
    }else if(s.major(this)){
        if(this.minor(s)){
            Segmento temp = new Segmento(s.p1,p2);
            temporaneo=temp;}
        else{
            Segmento temp = new Segmento(s.p1,s.p2);
            temporaneo=temp;
        }
    }
    return temporaneo;
	}
	public Segmento multiplication(Segmento s){
		double dist = s.lunghezza();
		Punto point = new Punto(p2.multiplicationDouble(dist));
		Segmento temporaneo = new Segmento(p1,point);
		return temporaneo;
		}
	public Segmento division(Segmento s){
			double dist = s.lunghezza();
			if(dist==0)
				return this;
			Punto point = new Punto((p2).divisionDouble(dist));
			Segmento temporaneo = new Segmento(s.p1,point);
			return temporaneo;
	}
	 public final Punto getFirstPoint(){
		return p1;
	}
	public final Punto getSecondPoint(){
		return p2;
	}
	@Override public String toString(){
    return p1+","+p2;
	}
	public void stampa(){
		System.out.println(this);
	}
	public double lunghezza() {
         return Punto.distance(p1,p2);
    }
	public void trasla(double _x, double _y){
		p1.trasla(_x,_y);
		p2.trasla(_x,_y);
	}
	public double coefficenteAngolare() {
		if(p2.get_x()-p1.get_x()==0) return 100000; 
	    else return (p2.get_y()-p1.get_y())/(p2.get_x()-p1.get_x());
	}
	public Punto puntoPiuVicino(Punto p) {
		//segmento verticale
	    if(p2.get_x()-p1.get_x()==0){
	     if(p2.major(p1)){
	        if(p.get_y()>p2.get_y()) return p2;
	        else if(p.get_y()<p1.get_y()) return p1;}
	    if(p1.major(p2)){
	        if(p.get_y()>p1.get_y()) return p1;
	        else if(p.get_y()<p2.get_y()) return p2;}
	        return new Punto(p1.get_x(),p.get_y());
	    }
	    //segmento orizzontale
	    else if(p2.get_y()-p1.get_y()==0){
	        if(p2.major(p1)){
	           if(p.get_x()>p2.get_x()) return p2;
	           else if(p.get_x()<p1.get_x()) return p1;}
	       if(p1.major(p2)){
	           if(p.get_x()>p1.get_x()) return p1;
	           else if(p.get_x()<p2.get_x()) return p2;}
	           return new Punto(p.get_x(),p1.get_y());
	    }
	    //altri casi
	    double m1 = coefficenteAngolare();
	    double q=p1.get_y()-(m1*p1.get_x());
	    double m2 = -1/m1;
	    double q2= (p.get_y()-m2*p.get_x());
	    double x= (q2-q)/(m1-m2);
	    double y= m1*x+q;
	    return new Punto(x,y);
	}
	
	
}
