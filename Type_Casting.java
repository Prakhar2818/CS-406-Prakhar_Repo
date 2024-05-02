public class Type_Casting {
    public static void main(String[] args) {
        int i=99;
        //Implicit Type Casting
        double d=i;
        System.out.println("Value of i: "+i);
        System.out.println("Value of d: "+d);
        double d1=16.6;
        //Explicit Type Casting
        int it=(int) d1;
        System.out.println("Value of d1: "+d1);
        System.out.println("Value of i1: "+it);
    }
}
