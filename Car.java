interface Vehicle{
    void run();
}
class Bike implements Vehicle{
    public void run(){
        System.out.println("Bike runs on two wheels using gears");
    }
}
class Cycle implements Vehicle{
    public void run(){
        System.out.println("Cycle is a vehicle which is paddled");
    }
} 
public class Car{
    public static void main(String[] args) {
        Bike b=new Bike();
        Cycle c=new Cycle();
        b.run();
        c.run();
    }
}