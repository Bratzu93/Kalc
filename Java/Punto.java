public class Punto extends Object{
	private  double x;
	private  double y;

	public Punto(){
		 x=0;
		 y=0;
	}
	public Punto(double _x, double _y){
		 x=_x;
		 y=_y;
	}
	public Punto(Punto p){
		x=p.x;
		y=p.y;
	}
	public boolean minor(Punto p){
	return (x<p.x || (x==p.x && y<p.y));
	}	
	public boolean major(Punto p){
		return x>p.x || (x==p.x && y>p.y);
	}	
	public boolean equal(Punto p){
		return (x==p.x &&  y==p.y);
	}	
	public boolean notEqual(Punto p){
		return (x!=p.x &&  y!=p.y);
	}	
	public Punto sum(Punto p){
		Punto aux = new Punto();
		aux.x = x+p.x;
		aux.y = y+p.y;
		return aux;
	}
	public Punto difference(Punto p){
		Punto aux = new Punto();
		aux.x = x-p.x;
		aux.y = y-p.y;
		return aux;
	}
	public Punto multiplication(Punto p){
		Punto aux = new Punto();
		aux.x = x*p.x;
		aux.y = y*p.y;
		return aux;
	}
	public Punto division(Punto p){
		Punto aux = new Punto();
		aux.x = x/p.x;
		aux.y = y/p.y;
		return aux;
	}
	public Punto multiplicationDouble(double p){
		Punto aux = new Punto();
		aux.x= x*p;
		aux.y= y*p;
		return aux;
	}	
	public Punto divisionDouble(double p){
		Punto aux= new Punto();
		if(p==0)return this;
		aux.x = x/p;
		aux.y = y/p;
		return aux;
	}
	 public final void set_x(double _x){
		x=_x;
	}
	public final void set_y(double _y){
		y=_y;
	}
	 public final double get_x(){
		return x;
	}
	public final double get_y(){
		return y;
	}
	@Override public String toString(){
    return "("+x+", "+y+")";
	}
	public void stampa(){
		System.out.println(this);
	}
	public static double distance(Punto p1, Punto p2) {
         return Math.sqrt((p1.x - p2.x) *  (p1.x - p2.x) + 
                          (p1.y - p2.y) *  (p1.y - p2.y));
    }
	public void traslaAscissa(double _x){
		x= x+_x;
	}
	public void traslaOrdinata(double _y){
		y= y+_y;
	}
	public void trasla(double _x, double _y){
		traslaAscissa(_x);
		traslaOrdinata(_y);
	}
	public static double cross(Punto O, Punto A, Punto B) {
		return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
	}

}
