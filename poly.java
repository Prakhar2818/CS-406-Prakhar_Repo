class Helper{
    int m1(int a, int b){
        return a*b;
    }
    double m1(double a, double b){
        return a*b;
    }
}
class poly{
    public static void main(String[] args) {
        Helper h=new Helper();
        System.out.println(h.m1(5, 10));
        System.out.println(h.m1(10.2, 6.8));
    }
}