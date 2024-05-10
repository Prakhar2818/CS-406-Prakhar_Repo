    class Info{
    public String Name;
    public int RollNo;

    public Info(String Name, int RollNo){    //Constructor Called
        this.Name=Name;
        this.RollNo=RollNo;
    }
    public void get(){
        System.out.println("Name: "+Name+" Roll No: "+RollNo);
    }
}
 public class construct {
    public static void main(String[] args) {
        Info i=new Info("Prakhar",201);
        i.get();
    }
}
