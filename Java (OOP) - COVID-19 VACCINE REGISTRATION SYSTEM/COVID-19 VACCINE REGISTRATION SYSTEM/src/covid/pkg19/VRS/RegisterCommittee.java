package covid.pkg19.VRS;
import static covid.pkg19.VRS.RegisterPeople.onlyDigits;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Font;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JRadioButton;
import javax.swing.table.DefaultTableModel;
public class RegisterCommittee extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource()==ShowPass){
            if (ShowPass.isSelected()) {
                pass1.setEchoChar((char) 0);
                pass2.setEchoChar((char) 0);
            } else {
                pass1.setEchoChar('*');
                pass2.setEchoChar('*');
            }
        }else if(e.getSource()==submit){
            String def = "";
            String Name = nameText.getText();
            String Gender = "Male";
            if(female.isSelected()){
                Gender = "Female";
            }
            String Phone = phoneText.getText();
            String Pass1 = new String(pass1.getPassword());
            String Pass2 = new String(pass2.getPassword());
            if(Name.equals(def) || Pass1.equals(def) || Pass2.equals(def)){
                JOptionPane.showMessageDialog(null, "Incomplete information!");
            }else if(!Pass1.equals(Pass2)){
                JOptionPane.showMessageDialog(null, "Incorrect Password!");
            }else if(onlyDigits(Phone,Phone.length()) == false){
                JOptionPane.showMessageDialog(null, "Phone number cannot contain characters and symbol!");
            }else{
                String ID;
                int size = DataIO.allCommittee.size();
                if(size==0){
                    ID = "CP"+10001;
                }else{
                    int num = Integer.parseInt(DataIO.allCommittee.get(size-1).getId().substring(2))+1;
                    ID = "CP"+num;
                }
                int out = JOptionPane.showConfirmDialog(null, "Confirm the Following Information:\n\nID: "+ID+"\nName: "
                        +Name+"\n", "Message", JOptionPane.YES_NO_OPTION);
                if(out == JOptionPane.YES_OPTION){
                    Committee c = new Committee(ID, Name, Gender, Phone, Pass1);
                    DataIO.allCommittee.add(c);
                    DataIO.write();
                    if(COVID19VRS.comtInfo.flag){
                        COVID19VRS.comtInfo.model = (DefaultTableModel) COVID19VRS.comtInfo.table.getModel();
                        COVID19VRS.comtInfo.model.addRow(new Object[]{c.getId(),c.getName(), c.getGender(), c.getPhone(), c.getPassword()}); 
                        COVID19VRS.comtInfo.flag = false;
                    }
                    JOptionPane.showMessageDialog(null, "Register Successfully!");
                    setVisible(false);
                    COVID19VRS.comtInfo.setEnabled(true);
                    nameText.setText(def);
                    pass1.setText(def);
                    pass2.setText(def);
                }
            }
        }else if(e.getSource()==clear){
            nameText.setText("");
            pass1.setText("");
            pass2.setText("");
        }else if(e.getSource()==cancel){
            setVisible(false);
            COVID19VRS.comtInfo.setEnabled(true);
            nameText.setText("");
            pass1.setText("");
            pass2.setText("");
        }
    }
    private Panel panel;
    private Button submit, clear, cancel;
    private Label title, name, gender, phone, pass, conPass;
    private TextField nameText, phoneText;
    private JPasswordField pass1, pass2; 
    private JCheckBox ShowPass;
    private JRadioButton male, female;
    private ButtonGroup genderG;
    public RegisterCommittee(){
        setSize(500, 350);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setTitle("Covid-19 Vaccine Regiatration System");
        panel = new Panel();
        panel.setLayout(null);
        title = new Label("New Personnel of Committee", Label.CENTER);
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setBounds(0, 20, 500, 30);
        name = new Label("Name");
        name.setBounds(95, 90, 100, 20);
        nameText = new TextField();
        nameText.setBounds(200, 90, 200, 23);
        gender = new Label("Gender");
        gender.setBounds(95, 120, 100, 20);
        male = new JRadioButton("Male", true);
        male.setBounds(200, 120, 80, 20);
        female = new JRadioButton("Female");
        female.setBounds(280, 120, 80, 20);
        genderG = new ButtonGroup();
        genderG.add(male);
        genderG.add(female);
        phone = new Label("Phone Number");
        phone.setBounds(95, 150, 100, 20);
        phoneText = new TextField();
        phoneText.setBounds(200, 150, 200, 23);
        pass = new Label("Password");
        pass.setBounds(95, 180, 100, 20);
        pass1 = new JPasswordField();
        pass1.setBounds(200, 180, 200, 23);
        conPass = new Label("Confirm Password");
        conPass.setBounds(95, 210, 100, 20);
        pass2 = new JPasswordField();
        pass2.setBounds(200, 210, 200, 23);
        ShowPass = new JCheckBox("Show Password");
        ShowPass.setFont(new Font(Font.DIALOG, Font.PLAIN, 10));
        ShowPass.setBounds(200, 233, 150, 20);
        submit = new Button("Submit");
        submit.setBounds(200, 270, 70, 25);
        clear = new Button("Clear");
        clear.setBounds(275, 270, 70, 25);
        cancel = new Button("Cancel");
        cancel.setBounds(350, 270, 70, 25);
        panel.add(title);
        panel.add(name);
        panel.add(gender);
        panel.add(male);
        panel.add(female);
        panel.add(phone);
        panel.add(pass);
        panel.add(conPass);
        panel.add(nameText);
        panel.add(phoneText);
        panel.add(pass1);
        panel.add(pass2);
        panel.add(ShowPass);
        panel.add(submit);
        panel.add(clear);
        panel.add(cancel);
        ShowPass.addActionListener(this);
        submit.addActionListener(this);
        clear.addActionListener(this);
        cancel.addActionListener(this);
        add(panel, BorderLayout.CENTER);
        setResizable(false);
    }
}
