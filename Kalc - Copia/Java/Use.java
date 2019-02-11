class Use{
public static void main(String [ ] args){

Punto p = new Punto(0,0);
Punto p1 = new Punto(2,2);

Punto p2 = new Punto(0,2);
Punto p3 = new Punto(2,0);
Punto p4 = new Punto(6,4);

p.sum(p1);
p.difference(p2);
p.multiplication(p3);
p.division(p4);

Segmento s1= new Segmento(p,p1);
Segmento s2= new Segmento(p2,p3);
s1.sum(s2);
s2.difference(s1);
s1.multiplication(s2);
s2.division(s1);

Base b = new Base();
b.add(p);
b.add(p1);
b.add(p2);
b.add(p3);
Base.convexHull(b);
b.stampa();
//b.trasla(-3, +5);

Poligono poly=new Poligono(b);
//poly.trasla(4, -3);
poly.stampa();
if(poly.interno(p4))
	 System.out.println(poly.perimetro());
else 	System.out.println(poly.area());
if(poly.equilatero())
	poly.sum(poly);


}
}