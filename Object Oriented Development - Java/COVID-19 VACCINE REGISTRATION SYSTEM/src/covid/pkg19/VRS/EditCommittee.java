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
public class EditCommittee extends JFrame implements ActionListener{
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
            String ID = idText.getText();
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
                int change = JOptionPane.showConfirmDialog(null, "Confirm to save change?", "Message", JOptionPane.YES_NO_OPTION);
                if(change == JOptionPane.YES_OPTION){
                    int i = COVID19VRS.comtInfo.arrayCount;
                    int j = COVID19VRS.comtInfo.tableCount;
                    if(COVID19VRS.comtInfo.flag){
                        DataIO.allCommittee.get(i).setName(Name);
                        DataIO.allCommittee.get(i).setGender(Gender);
                        DataIO.allCommittee.get(i).setPhone(Phone);
                        DataIO.allCommittee.get(i).setPassword(Phone);
                        COVID19VRS.comtInfo.flag = false;
                    }else{
                        COVID19VRS.comtInfo.model = (DefaultTableModel) COVID19VRS.comtInfo.table.getModel();
                        COVID19VRS.comtInfo.model.setValueAt(Name, j, 1);
                        DataIO.allCommittee.get(i).setName(Name);
                        COVID19VRS.comtInfo.model.setValueAt(Gender, j, 2);
                        DataIO.allCommittee.get(i).setGender(Gender);
                        COVID19VRS.comtInfo.model.setValueAt(Phone, j, 3);
                        DataIO.allCommittee.get(i).setPhone(Phone);
                        COVID19VRS.comtInfo.model.setValueAt(Pass1, j, 4);
                        DataIO.allCommittee.get(i).setPassword(Pass1);
                    }
                    DataIO.write();
                    setVisible(false);
                    COVID19VRS.comtInfo.setEnabled(true);
                }
            }
        }else if(e.getSource()==clear){
            nameText.setText("");
            pass1.setText("");
            pass2.setText("");
        }else if(e.getSource()==cancel){
            setVisible(false);
            COVID19VRS.comtInfo.setEnabled(true);
        }
    }
    private Panel panel;
    private Button submit, clear, cancel;
    private Label title, id, name, gender, phone, pass, conPass;
    TextField idText, nameText, phoneText;
    JPasswordField pass1, pass2; 
    private JCheckBox ShowPass;
    JRadioButton male, female;
    private ButtonGroup genderG;
    public EditCommittee(){
        setSize(500, 350);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setTitle("Covid-19 Vaccine Regiatration System");
        panel = new Panel();
        panel.setLayout(null);
        title = new Label("Edit Personnel of Committee", Label.CENTER);
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setBounds(0, 20, 500, 30);
        id = new Label("ID Number");
        id.setBounds(95, 60, 100, 20);
        idText = new TextField();
        idText.setBounds(200, 60, 200, 23);
        idText.setEnabled(false);
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
        panel.add(id);
        panel.add(name);
        panel.add(gender);
        panel.add(male);
        panel.add(female);
        panel.add(phone);
        panel.add(pass);
        panel.add(conPass);
        panel.add(idText);
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
