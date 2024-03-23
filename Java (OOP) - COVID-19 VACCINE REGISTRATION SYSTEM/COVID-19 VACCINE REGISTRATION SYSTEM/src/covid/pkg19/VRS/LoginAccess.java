package covid.pkg19.VRS;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
public class LoginAccess extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == Login){
            String usrID = u.getText();
            String admin = "admin";
            String Password = new String(p.getPassword());
            String adminPass = "letmein";
            Committee foundComt = DataIO.checkComt(usrID);
            People foundPpl = DataIO.checkPpl(usrID);
            if(usrID.equals(admin) && Password.equals(adminPass)){
                setVisible(false);
                COVID19VRS.comtPeopleInfo.setVisible(true);
            }
            else if(foundComt != null || foundPpl != null){
                if(foundComt != null){
                    if(foundComt.getPassword().equals(Password)){
                        COVID19VRS.loginComt = foundComt;
                        setVisible(false);
                        COVID19VRS.comtPeopleInfo.setVisible(true);
                    }else{
                        JOptionPane.showMessageDialog(null,"Incorrect Password!");
                    }
                }else if(foundPpl != null){
                    if(foundPpl.getPassword().equals(Password)){
                        COVID19VRS.loginPpl = foundPpl;
                        COVID19VRS.first.name.setText(COVID19VRS.loginPpl.getName());
                        COVID19VRS.first.setVisible(true);
                        setVisible(false);
                    }else{
                        JOptionPane.showMessageDialog(null,"Incorrect Password!");
                    }
                }
            }else{
                JOptionPane.showMessageDialog(null,"User ID not found!");
            }
            u.setText("");
            p.setText("");
        }else if(e.getSource() == Register){
            COVID19VRS.registerPeople.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == ShowPass){
            if (ShowPass.isSelected()) {
                p.setEchoChar((char) 0);
            } else {
                p.setEchoChar('*');
            }
        }
    }
    private Button Login, Register;
    private Panel pc;
    private Label title, userID, pass;
    private TextField u;
    private JPasswordField p;
    private JCheckBox ShowPass;
    public LoginAccess(){
        DataIO.read();
        Dataio1.read();
        setSize(500, 350);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Covid-19 Vaccine Regiatration System");
        pc = new Panel();
        pc.setLayout(null);
        title = new Label("Covid-19 Vaccine Registration System", Label.CENTER);
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setBounds(0, 50, 500, 40);
        userID = new Label("User ID (IC/Passport No.)");
        userID.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        userID.setBounds(150, 108, 150, 20);
        pass = new Label("Password");
        pass.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        pass.setBounds(150, 156, 70, 20);
        u = new TextField(15);
        u.setBounds(150, 128, 193, 28);
        p = new JPasswordField(15);
        p.setBounds(150, 176, 193, 28);
        ShowPass = new JCheckBox("Show Password");
        ShowPass.setBounds(150, 205, 150, 25);
        Login = new Button("Login");
        Login.setForeground(Color.white);
        Login.setBackground(Color.black);
        Login.setBounds(150, 235, 95, 25);
        Register = new Button("Register");
        Register.setForeground(Color.white);
        Register.setBackground(Color.black);
        Register.setBounds(245, 235, 95, 25);
        pc.add(title);
        pc.add(userID);
        pc.add(u);
        pc.add(pass);
        pc.add(p);
        pc.add(ShowPass);
        pc.add(Login);
        pc.add(Register);
        ShowPass.addActionListener(this);
        Login.addActionListener(this);
        Register.addActionListener(this);;
        add(pc, BorderLayout.CENTER);
        setVisible(true);
        setResizable(false);
    }
}
