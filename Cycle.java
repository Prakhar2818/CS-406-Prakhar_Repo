//Showing life cycle of Thread
class Cycle extends Thread {
    public void run(){
        try{
            Thread.sleep(150);
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }
        System.out.println("State After completion"+Thread.currentThread().getState());
    }
    public static void main(String[] args){
        Cycle c=new Cycle();
        System.out.println("State When created "+c.getState());
        c.start();
        System.out.println("State When started "+c.getState());
        // c.join();
        System.out.println("State After thread ended itd task "+c.getState());
    }
}
