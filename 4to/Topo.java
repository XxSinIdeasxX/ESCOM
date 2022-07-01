// Fernando Rodríguez Calderón
// Practica 5
// Opcion 5. Juego de Golpear al Topo (Whack a Mole)
// Paradigmas de Programacion - 3CM2
// 17/12/2021

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Topo extends JFrame implements ActionListener{
	JButton[] b = new JButton[20];
	Label puntos;
	static int puntuacion = 0;
	Topo(){
		int alto = 0;
		int ancho = 0;
		int numX = 0;
		int numY = 0;
		for(int i = 0; i < 20; i++){
			b[i] = new JButton(new ImageIcon("topo.png"));
			b[i].setBorderPainted( false );
			b[i].addActionListener(this);
			numX++;
			if(numX == 5){
				numX = 0;
				numY++;
			}
			if(numY == 4){
				numY = 0;
			}
			ancho = numX * 100;
			alto = numY * 100;
			b[i].setBounds(ancho,alto,100,100);
			int min = 0;
		    int max = 1;
			int random_int = (int)Math.floor(Math.random()*(max-min+1)+min);
			if(random_int == 1){
				this.add(b[i]);
			}
		}
		puntos = new Label("Puntuacion: ");   
		puntos.setBounds(175,400,200,50);
		puntos.setText("Puntuación: " + String.valueOf(puntuacion));
		puntos.setFont(new Font("Abadi", Font.BOLD, 20));
		puntos.setAlignment(JLabel.CENTER);

		this.add(puntos);
	    this.setSize(520,500);    
	    this.setTitle("Dale al topo");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    this.setLayout(null);    
	    this.setVisible(true);
	}	

	public void actionPerformed(ActionEvent e){
		for(int i = 0; i < 20; i++){
			if (e.getSource() == b[i]){
				b[i].setVisible(false);
				puntuacion++;
				puntos.setText("Puntuación: " + String.valueOf(puntuacion));				
				puntos.setFont(new Font("Abadi", Font.BOLD, 20));
			}
		}
	}
	
	public static void main(String args[]) throws InterruptedException{
		while (true){
			Topo play=new Topo();
			Thread.sleep(2000);
			play.dispose();;
		}
	}
}


