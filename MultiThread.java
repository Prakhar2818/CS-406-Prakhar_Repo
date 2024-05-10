class Printer extends Thread{
    private String message;
    public Printer(String msg){
        this.message=msg;
    }
    public void run(){
        for(int i=0;i<3;i++){
            System.out.println(message);
            try{
                Thread.sleep(200);
            }
            catch(InterruptedException e){
                System.out.println("Thread Interrupted");
            }
        }
    }
}
public class MultiThread{
    public static void main(String[] args) {
        Printer p1=new Printer("Thread 1 is running");
        Printer p2=new Printer("Thread 2 is running");
        p1.run();
        p2.run();
    }
}