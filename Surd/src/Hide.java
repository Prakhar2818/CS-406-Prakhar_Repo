class Hide {
    private class InnerClass{
       public void give(){
        System.out.println("Inner Claas");
       }
    }    
    public static void main(String[] args) {
        Hide h=new Hide();
        InnerClass i=h.new InnerClass();
        i.give();
    }
}
