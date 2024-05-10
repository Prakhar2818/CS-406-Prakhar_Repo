import java.awt.*;
import java.awt.event.*;
public class AWT_EX extends Frame{
    AWT_EX(){
        Button b=new Button("CLick Me");
        b.setBounds(30,100,80,30);
        add(b);
        setSize(300,30);
        setLayout(null);
        setVisible(true);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e){
                dispose();
            }
        });
    }
    public static void main(String[] args) {
        new AWT_EX();
    }
}