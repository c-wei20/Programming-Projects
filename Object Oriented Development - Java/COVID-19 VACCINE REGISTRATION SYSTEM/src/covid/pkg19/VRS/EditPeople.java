package covid.pkg19.VRS;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Font;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Calendar;
import javax.swing.ButtonGroup;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JRadioButton;
import javax.swing.table.DefaultTableModel;
public class EditPeople extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == save){
            String def = "";
            String Name = nameText.getText();
            boolean Nationality = true;
            String n = "Citizen";
            if(nCit.isSelected()){
                Nationality = false;
                n = "Non Citizen";
            }
            String DOB = (String)day.getSelectedItem() 
                    + "/" + (String)month.getSelectedItem()
                    + "/" + (String)year.getSelectedItem();
            int age = Calendar.getInstance().get(Calendar.YEAR) - Integer.parseInt((String)year.getSelectedItem());
            String Gender = "Male";
            if(female.isSelected()){
                Gender = "Female";
            }
            String Address = addressText.getText();
            String State = (String)stateBox.getSelectedItem();
            String Phone = phoneText.getText();
            String Email = emailText.getText();
            if(Name.equals(def) || Address.equals(def) || State.equals(def) ||
                    Phone.equals(def) || Email.equals(def)){
                JOptionPane.showMessageDialog(null, "Incomplete information!");
            }else if(onlyDigits(Phone,Phone.length()) == false){
                JOptionPane.showMessageDialog(null, "Phone number cannot contain special characters!");
            }else{
                int change = JOptionPane.showConfirmDialog(null, "Confirm to save change?", "Message", JOptionPane.YES_NO_OPTION);
                if(change == JOptionPane.YES_OPTION){
                    int i = COVID19VRS.comtPeopleInfo.arrayCount;
                    int j = COVID19VRS.comtPeopleInfo.tableCount;
                    if(COVID19VRS.comtPeopleInfo.flag){
                        DataIO.allPeople.get(i).setName(Name);
                        DataIO.allPeople.get(i).setNationality(Nationality);
                        DataIO.allPeople.get(i).setBirthDate(DOB);
                        DataIO.allPeople.get(i).setAge(age);
                        DataIO.allPeople.get(i).setGender(Gender);
                        DataIO.allPeople.get(i).setAddress(Address);
                        DataIO.allPeople.get(i).setState(State);
                        DataIO.allPeople.get(i).setPhoneNumber(Phone);
                        DataIO.allPeople.get(i).setEmail(Email);
                        COVID19VRS.comtPeopleInfo.flag = false;
                    }else{
                        COVID19VRS.comtPeopleInfo.model = (DefaultTableModel) COVID19VRS.comtPeopleInfo.table.getModel();
                        COVID19VRS.comtPeopleInfo.model.setValueAt(Name, j, 1);
                        DataIO.allPeople.get(i).setName(Name);
                        COVID19VRS.comtPeopleInfo.model.setValueAt(n, j, 2);
                        DataIO.allPeople.get(i).setNationality(Nationality);
                        COVID19VRS.comtPeopleInfo.model.setValueAt(DOB, j, 3);
                        DataIO.allPeople.get(i).setBirthDate(DOB);
                        COVID19VRS.comtPeopleInfo.model.setValueAt(age, j, 4);
                        DataIO.allPeople.get(i).setAge(age);
                        COVID19VRS.comtPeopleInfo.model.setValueAt(Gender, j, 5);
                        DataIO.allPeople.get(i).setGender(Gender);
                        COVID19VRS.comtPeopleInfo.model.setValueAt(Address, j, 6);
                        DataIO.allPeople.get(i).setAddress(Address);
                        COVID19VRS.comtPeopleInfo.model.setValueAt(State, j, 7);
                        DataIO.allPeople.get(i).setState(State);
                        COVID19VRS.comtPeopleInfo.model.setValueAt(Phone, j, 8);
                        DataIO.allPeople.get(i).setPhoneNumber(Phone);
                        COVID19VRS.comtPeopleInfo.model.setValueAt(Email, j, 9);
                        DataIO.allPeople.get(i).setEmail(Email);
                    }
                    DataIO.write();
                    setVisible(false);
                    COVID19VRS.comtPeopleInfo.setEnabled(true);
                }        
            }
        }else if(e.getSource() == cancel){
            setVisible(false);
            COVID19VRS.comtPeopleInfo.setEnabled(true);
        }  
    }
    
    public static boolean onlyDigits(String str, int n){
        for (int i = 0; i < n; i++) {
            if (str.charAt(i) >= '0'
                && str.charAt(i) <= '9') {
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }

    private Panel panel;
    private Button save, cancel;
    private Label title, name, dob, phone, address, state, pass, conPass, IDNum, email, gender, nationality;
    TextField nameText, IDNumText, addressText, phoneText, emailText;
    JComboBox day, month, year, stateBox;
    private ButtonGroup genderG, nationalG;
    JRadioButton male, female, cit, nCit;
    JPasswordField pass1, pass2;
    private String[] days,months,states;
    public EditPeople(){
        setSize(650, 350);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setTitle("Covid-19 Vaccine Regiatration System"); 
        panel = new Panel();
        panel.setLayout(null);
        title = new Label("Edit People Information", Label.CENTER);
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setBounds(0, 20, 630, 24);
        name = new Label("Name");
        name.setBounds(50, 80, 100, 20);
        nameText = new TextField();
        nameText.setBounds(150, 80, 150, 22);
        nationality = new Label("Nationality");
        nationality.setBounds(50, 110, 100, 20);
        cit = new JRadioButton("Citizen", true);
        cit.setBounds(150, 110, 80, 20);
        nCit = new JRadioButton("Non");
        nCit.setBounds(230, 110, 80, 20);
        nationalG = new ButtonGroup();
        nationalG.add(cit);
        nationalG.add(nCit);
        IDNum = new Label("IC/Passport No.");
        IDNum.setBounds(50, 140, 100, 20);
        IDNumText = new TextField();
        IDNumText.setBounds(150, 140, 150, 22);
        IDNumText.setEditable(false);
        dob = new Label("Date of Birth");
        dob.setBounds(50, 170, 100, 20);
        days = new String[]{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", 
            "22", "23", "24", "25", "26", "27", "28", "29", "30", "31" };
        day = new JComboBox(days);
        day.setBounds(150, 170, 40, 22);
        months = new String[]{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July",
            "Aug", "Sep", "Oct", "Nov", "Dec"};
        month = new JComboBox(months);
        month.setBounds(190, 170, 50, 22);
        ArrayList<String> years_tmp = new ArrayList<String>();
        for(int years = 1920; years<=Calendar.getInstance().get(Calendar.YEAR); years++) {
            years_tmp.add(years+"");
        }
        year = new JComboBox(years_tmp.toArray());
        year.setBounds(240, 170, 60, 22);
        gender = new Label("Gender");
        gender.setBounds(50, 200, 100, 20);
        male = new JRadioButton("Male", true);
        male.setBounds(150, 200, 80, 20);
        female = new JRadioButton("Female");
        female.setBounds(230, 200, 80, 20);
        genderG = new ButtonGroup();
        genderG.add(male);
        genderG.add(female);
        address = new Label("Address");
        address.setBounds(50, 230, 100, 20);
        addressText = new TextField();
        addressText.setBounds(150, 230, 150, 22);
        state = new Label("State");
        state.setBounds(320, 80, 100, 20);
        states = new String[]{"Johor", "Kedah", "Kelatan", "Kuala Lumpur", "Malacca", "Negeri Sembilan",
            "Pahang", "Penang", "Perak", "Perlis", "Sabah", "Sarawak", "Selangor", "Terengganu"};
        stateBox = new JComboBox(states);
        stateBox.setBounds(430, 80, 150, 22);
        phone = new Label("Phone Number");
        phone.setBounds(320, 110, 100, 20);
        phoneText = new TextField();
        phoneText.setBounds(430, 110, 150, 22);
        email = new Label("Email Address");
        email.setBounds(320, 140, 100, 20);
        emailText = new TextField();
        emailText.setBounds(430, 140, 150, 22);
        pass = new Label("Password");
        pass.setBounds(320, 170, 100, 20);
        pass1 = new JPasswordField();
        pass1.setBounds(430, 170, 150, 22);
        conPass = new Label("Confirm Password");
        conPass.setBounds(320, 200, 100, 20);
        pass2 = new JPasswordField();
        pass2.setBounds(430, 200, 150, 22);
        pass1.setEnabled(false);
        pass2.setEnabled(false);
        save = new Button("Save");
        save.setBounds(415, 260, 80, 25);
        cancel = new Button("Cancel");
        cancel.setBounds(500, 260, 80, 25);
        save.addActionListener(this);
        cancel.addActionListener(this);
        panel.add(title);
        panel.add(name);
        panel.add(nameText);
        panel.add(nationality);
        panel.add(cit);
        panel.add(nCit);
        panel.add(IDNum);
        panel.add(IDNumText);
        panel.add(dob);
        panel.add(day);
        panel.add(month);
        panel.add(year);
        panel.add(gender);
        panel.add(male);
        panel.add(female);
        panel.add(address);
        panel.add(addressText);        
        panel.add(state);
        panel.add(stateBox);
        panel.add(phone);
        panel.add(phoneText);
        panel.add(email);
        panel.add(emailText);
        panel.add(pass);
        panel.add(pass1);
        panel.add(conPass);
        panel.add(pass2);
        panel.add(save);
        panel.add(cancel);
        add(panel, BorderLayout.CENTER);
        setResizable(false);
    }
}
