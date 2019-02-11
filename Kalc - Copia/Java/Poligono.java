import java.util.ArrayList;

public class Poligono extends Base{
	private ArrayList<Punto> l = new ArrayList<Punto>();
	public Poligono(Base B) {
		super((Base)B);
		l = Base.convexHull(B);
	}
	public Poligono(Poligono pol){
		super((Base)pol);
		l=pol.l;
	}
	public void stampa() {
		for(int i=0;i<l.size();++i)
			System.out.print(l.get(i));
		System.out.println();
	}
	public Punto pointFromPolygon(int i){
		return l.get(i);
	}
	public ArrayList<Punto> getList(){
		return l;
	}
	public double area() {
		double area=0;
		int n = l.size();
		for(int k=0;k<n-1;++k) {
			area+= ((l.get(k)).get_x() * (l.get(k+1)).get_y()) - ((l.get(k)).get_y() * (l.get(k+1)).get_x());
		}
		area+= ((l.get(n-1)).get_x() * (l.get(0)).get_y()) - ((l.get(n-1)).get_y() * (l.get(0)).get_x());
		return area/2;
	}
	public double perimetro() {
		double perimetro=0;
	    int n = l.size();
	    for(int k=0;k<n-1;k++){
	        perimetro +=  Punto.distance(l.get(k),l.get(k+1));
	    }
	    perimetro += Punto.distance(l.get(0),l.get(n-1));
	    return perimetro;
	}
	public boolean equilatero() {
		double n = l.size();
		int k=1;
        double d = Punto.distance(l.get(0),l.get(1));
    while(k<n-1){
        if(d != (Punto.distance(l.get(k),l.get(k+1))  ))
            return false;
		   k++;
		    }
		return true;	
			}
	public void trasla(double _x,double _y) {
		for(int i=0;i<l.size();++i)
			l.get(i).trasla(_x, _y);
	}
	public boolean minor(Poligono p) {
		return (area()<p.area());
	}
	public boolean major(Poligono p) {
		return (area()>p.area());
	}
	public boolean equal(Poligono p) {
		return (area()==p.area());
	}
	public boolean notEqual(Poligono p) {
		return (area()!=p.area());
	}
	public Poligono sum(Poligono pol2) {
	Poligono aux = new Poligono(this.appendVect(pol2));
	return aux;
	}
	public Poligono sum(Punto p) {
		Base aux=new Base(this);
		aux.add(p);
		Poligono aus=new Poligono(aux);
		return aus;
	}
	public Poligono sum(Segmento s) {
		Base aux = new Base(this);
		aux.add(s.getFirstPoint());
		aux.add(s.getSecondPoint());
		Poligono aus= new Poligono(aux);
		return aus;
	}
	public Poligono difference(Poligono pol2) {
		Base aux = new Base();
	    if(l.size()>pol2.l.size()){
	        for(int i=0; i<pol2.l.size();++i)
	            if(l.get(i).notEqual(pol2.l.get(i)))
	            aux.add(l.get(i).difference(pol2.l.get(i)));
	        for(int i=pol2.l.size();i<l.size();++i)
	            aux.add(l.get(i));
	    }else{
	        for(int i=0; i<l.size();++i)
	            if(l.get(i).notEqual(pol2.l.get(i)))
	            aux.add(pol2.l.get(i).difference(l.get(i)));
	        for(int i=l.size();i<pol2.l.size();++i)
	            aux.add(pol2.l.get(i));
	    }
	    Poligono aus = new Poligono(aux);
	    return aus;
	}
	public Poligono difference(Punto p) {
		Base aux = new Base(this);
		aux.remove(p);
		Poligono aus = new Poligono(aux);
		return aus;
	}
	public Poligono difference(Segmento s) {
		Base aux = new Base(this);
		aux.remove(s.getFirstPoint());
		aux.remove(s.getSecondPoint());
		Poligono aus = new Poligono(aux);
		return aus;
	}
	public Poligono multiplication(Poligono pol2) {
		Base aux = new Base();
	    if(l.size()>pol2.l.size()){
	        for(int i=0; i<pol2.l.size();++i)
	            aux.add(l.get(i).multiplication(pol2.l.get(i)));
	    }else{
	        for(int i=0; i<l.size();++i)
	            aux.add((pol2.l.get(i)).multiplication(l.get(i)));
	    }
	    Poligono aus = new Poligono(aux);
	    return aus;
	}
	public Poligono multiplication(Punto p) {
		Punto test = new Punto(0,0);
		Base aux = new Base();
		    if(p.equal(test) && l.size()>2)return this;
		for(int i=0; i<l.size();++i){
		    aux.add(l.get(i).multiplication(p));
		}
		Poligono aus = new Poligono(aux);
		return aus;
	}
	public Poligono multiplication(Segmento s) {
		Base aux = new Base();
		double dist = s.lunghezza();
		if(dist==0) return this;
		for(int i=0; i<l.size();++i){
			Punto z= new Punto(l.get(i).multiplicationDouble(dist));
			aux.add(z);
		}
		Poligono aus = new Poligono(aux);
		return aus;
		}
	public Poligono division(Poligono pol2) {
		Base aux = new Base();
	    if(l.size()>pol2.l.size()){
	        for(int i=0; i<pol2.l.size();++i) 
	            aux.add((l.get(i).division(pol2.l.get(i))));
	    }else{
	        for(int i=0; i<l.size();++i)
	            aux.add(pol2.l.get(i).division(l.get(i)));
	    }
	    Poligono aus = new Poligono(aux);
	    return aus;
	}
	public Poligono division(Punto p) {
		Base aux= new Base();
		for(int i=0; i<l.size();++i){
		    aux.add(l.get(i).division(p));
		    }
		Poligono aus = new Poligono(aux);
		return aus;
	}
	public Poligono division(Segmento s) {
		Base aux = new Base();
		double dist = s.lunghezza();
		if(dist==0)return this;
		for(int i=0; i<l.size();++i){
		    Punto x = new Punto(l.get(i).get_x()/dist,l.get(i).get_y()/dist);
		    aux.add(x);
		}
		Poligono aus = new Poligono(aux);
		return aus;
	}
	public boolean interno(Punto p) {
		int intersections = 0;
		   for ( int i=0; i <l.size(); ++i ) {
		      Punto p1 = l.get(i);
		      Punto p2 = new Punto();
		      if ( i+1 < l.size() )
		         p2 = l.get(i+1);
		      else
		         p2 = l.get(0);

		      if ( ( p.get_x() < p1.get_x() && p.get_x() < p2.get_x() ) ||
		           ( p.get_x() > p1.get_x() && p.get_x() > p2.get_x() ) )
		               continue;
		      double y_int = p1.get_y() + ( p2.get_y() - p1.get_y() ) * ( p.get_x() - p1.get_x()) / ( p2.get_x() - p1.get_x() );
		      if ( p.get_y() <= y_int  )
		         intersections++;
		   }
		   if ( intersections % 2 != 0)
		      return true;
		   else
		      return false;
	}
	public Punto puntoPiuVicino(Punto p) {
		if(interno(p))return p;
	    Punto x = new Punto();
	    int k=1;
	    double distanza_minima = 0;
	    while(k<l.size()){
	    Segmento s= new Segmento(l.get(k-1),l.get(k));
	    if(k==1){
	        x = s.puntoPiuVicino(p);
	        distanza_minima = Punto.distance(p,s.puntoPiuVicino(p));
	    }
	    if(Punto.distance(p,s.puntoPiuVicino(p))<= distanza_minima)
	    x=s.puntoPiuVicino(p);
	    ++k;
	        }
	    Segmento s = new Segmento(l.get(0),l.get(l.size()));
	    if(Punto.distance(p,s.puntoPiuVicino(p))<= distanza_minima)
	    x=s.puntoPiuVicino(p);
	return x;
	}
	
	
}



