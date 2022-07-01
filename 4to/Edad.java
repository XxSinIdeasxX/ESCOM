import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Edad extends JFrame implements ActionListener{
    JButton cal;
    JTextField año;
    JLabel tex;
    Edad(){
        this.setTitle("Cálculo de una edad");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(200,140);
        this.setLayout(new FlowLayout());

        JLabel tex1 = new JLabel();
        tex1.setText("Año de nacimiento: ");
        tex1.setHorizontalAlignment(JLabel.RIGHT);

        año = new JTextField();
        año.setPreferredSize(new Dimension(50,25));
        año.setHorizontalAlignment(JTextField.CENTER);

        JLabel tex2 = new JLabel();
        tex2.setText("Edad:");
        tex2.setHorizontalAlignment(JLabel.RIGHT);
        
        tex = new JLabel();
        tex.setText("         ");
        tex.setHorizontalAlignment(JLabel.CENTER);

        cal = new JButton("Calcular edad");
        cal.addActionListener(this);
        
        this.add(tex1);
        this.add(año);
        this.add(tex2);
        this.add(tex);
        this.add(cal);
        this.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==cal){
            tex.setText((String.valueOf(2021-Integer.parseInt(año.getText(),10))+" años"));
            tex.setHorizontalAlignment(JLabel.CENTER);
        }
        
    }
    public static void main (String[] args){
        new Edad();
    }
}