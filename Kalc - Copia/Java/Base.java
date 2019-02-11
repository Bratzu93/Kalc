import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Base extends Object{
	private ArrayList<Punto> v = new ArrayList<Punto>();
	public Base() {}
	public Base(Base B) {
	    for (int i=0; i<B.v.size(); ++i){
	        Punto x = new Punto(B.v.get(i));
	           v.add(x);
	       }
	}
	public ArrayList<Punto> getVect(){
	    return v;
	}
	public Base appendVect(Base B){
		v.addAll(B.v);
		return this;
		}
	public void add(Punto p){
	    v.add(p);
	}
	public void remove(Punto p){
	    for(int i = 0;i<v.size();++i){
	        if (v.get(i).equal(p))
	            v.remove(i);
	    }
	}
	public void stampa() {
		for(int i = 0;i<v.size();++i)
            System.out.print(v.get(i));
		System.out.println();
	}
	public void traslaAsseX(double _x) {
	    for(int i = 0;i<v.size();++i)
	            v.set(i,new Punto((v.get(i).get_x())+_x,v.get(i).get_y()));
	}
	public void traslaAsseY(double _y) {
	    for(int i = 0;i<v.size();++i)
	            v.set(i,new Punto(v.get(i).get_x(),(v.get(i).get_y()) + _y));
	}
	public void trasla(double x,double y) {
	    	traslaAsseX(x);
	    	if(y!=0) traslaAsseY(y);
	}
	public void clear() {
		v.clear();
	}
	public static ArrayList<Punto> convexHull(Base P){				
		if (P.v.size() > 1) {
			int n = P.v.size(), k = 0;
			ArrayList<Punto> H = new ArrayList<Punto>(2*n);
			Collections.sort(P.v, new Comparator<Punto>() {
			    public int compare(Punto one, Punto other) {
			         if (one.get_x() == other.get_x()) {
						return (int) (one.get_y() - other.get_y());
					} else {
						return (int) (one.get_x() - other.get_x());
					}
			    }
			}); 
			// Build lower hull
			for (int i = 0; i < n; ++i) {
				while (k >= 2 && Punto.cross(H.get(k-2), H.get(k-1), P.v.get(i)) <= 0)
					k--;
				H.add(k++, P.v.get(i));
			}
			// Build upper hull
			for (int i = n - 2, t = k + 1; i >= 0; i--) {
				while (k >= t && Punto.cross(H.get(k-2), H.get(k-1), P.v.get(i)) <= 0)
					k--;
				H.add(k++, P.v.get(i));
			}
			if (k > 1) {
				H = new ArrayList<Punto>(H.subList(0, k-1));
			}
			return H;
		} else if (P.v.size()<=1) {
			return P.v;
		} else{
			return null;
		}
	}

	
}