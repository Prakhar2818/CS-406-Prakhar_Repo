class c1{
    public int a=10;
    private int b=5;
    protected int cs=15;
    
    public void get(){
        System.out.println("Value of a: "+a);
        System.out.println("Value of b: "+b);
        System.out.println("Value of c: "+cs);
    }
}
public class Access{
    public static void main(String[] args) {
        c1 c=new c1();
        c.get();
        System.out.println(c.a);
        System.out.println(c.cs);
    }
}
