public class Scope {
	private static int x=22;
	private static int y=5;
	public static void main(String[] args) {
		System.out.println("Value of x:"+x);
		System.out.println("Value of y:"+y);
		M1();
	}
	public static void M1(){
		System.out.println("Class Variable of x:"+x);
		System.out.println("Class Variable of y:"+y);
	}
}