package covid.pkg19.VRS;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
public class Page1ppl extends JFrame implements ActionListener{
    public void actionPerformed (ActionEvent e){
        if(e.getSource()==register){
          setVisible(false);
          COVID19VRS.second.setVisible(true);
           
        }else if (e.getSource()==submit){
            setVisible(false);
            COVID19VRS.third.setVisible(true);
            
        }else if(e.getSource()==view){
            setVisible(false);
            COVID19VRS.fourth.setVisible(true);
        }
        else if (e.getSource()==logout){
             int out = JOptionPane.showConfirmDialog(null, "Sure To Logout?", "Message", JOptionPane.YES_NO_OPTION);
            if(out == JOptionPane.YES_OPTION){
               // System.exit(0);
                setVisible(false);
                COVID19VRS.login.setVisible(true);
            }
        }
    }   
    private Button register,submit,view,logout;
    private Label title; 
    Label name;
    public Page1ppl(){
        setSize(400,300);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        register = new Button("•  Register to the vaccination programme  ");
        submit = new Button("•  	Submit vaccination appointment ");
        view = new Button("•	 View Vaccination status ");
        logout = new Button("•	 Logout ");
        setTitle("Covid-19 Vaccine Registration System");
        title = new Label("<<< Welcome >>>", Label.CENTER);
        name = new Label("Name", Label.CENTER);
        register.setBounds(40,130,300,30);
        submit.setBounds(40,160,300,30);
        view.setBounds(40,190,300,30);
        logout.setBounds(40,220,300,30);
        title.setBounds(0, 30, 400, 30);
        name.setBounds(0, 80, 400, 30);
        register.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        submit.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        view.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        register.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        title.setFont(new Font(Font.DIALOG,Font.BOLD,18));
        name.setFont(new Font(Font.DIALOG,Font.BOLD,14));
        register.setBackground(new Color(220,220,220));
        submit.setBackground(new Color(220,220,220));
        view.setBackground(new Color(220,220,220));
        logout.setForeground(Color.white);
        logout.setBackground(Color.black);
        register.addActionListener(this);    
        submit.addActionListener(this);    
        view.addActionListener(this);
        logout.addActionListener(this);
        add(register);
        add(submit);
        add(view);
        add(logout);
        add(title);
        add(name);
//        setVisible(true);
    }
     
}

