package covid.pkg19.VRS;
import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
public class Page2ppl extends JFrame implements ActionListener{
    private TextField n, p;
    private Panel y1;
    int i;
    public void actionPerformed (ActionEvent e){
        if(e.getSource()== Back){
            setVisible(false);
            COVID19VRS.first.setVisible(true);
        }
        else if (e.getSource()==Register){ 
            boolean found = false;
            Appointment apt = null;
            for(i=0; i<Dataio1.allAppointment.size(); i++){
                apt = Dataio1.allAppointment.get(i);
                if(COVID19VRS.loginPpl.getIDnumber().equals(apt.getPeople().getIDnumber())){
                    found = true;
                    break;
                }
            }
            if(found){
                JOptionPane.showMessageDialog(null, "You have already registered for vaccination!");
                
            }else{
                int id;
                int size = Dataio1.allAppointment.size();
                if(size==0){
                    id= 1001;
                }else {
                     id = Dataio1.allAppointment.get(size-1).getId()+1;
                    
                }
                
                String currentaddress =JOptionPane.showInputDialog("Enter your latest current address ");   
                String[] states = {"Johor", "Kedah", "Kelatan", "Kuala Lumpur", "Malacca", "Negeri Sembilan",
                                   "Pahang", "Penang", "Perak", "Perlis", "Sabah", "Sarawak", "Selangor", "Terengganu"};
                String State = (String)JOptionPane.showInputDialog(null,"Select Your State",
                                "Message", JOptionPane.PLAIN_MESSAGE,null,states,states[0]);
                String healthstatus;
                int health = JOptionPane.showConfirmDialog(null, "Are you exhibing 2 or more symptoms as list below? \n• Chill \n• Fever\n• Shivering(rigor)\n• Body ache\n• Headache\n• Sore throat\n• Nausea or Vomiting\n• Diarrhea\n• Fatigue\n• Runny nose or nasal congestion", "Message", JOptionPane.YES_NO_OPTION);
                if(health == JOptionPane.YES_OPTION ){
                    healthstatus = "Yes";
                }else{
                    healthstatus = "No";
                }
                String agreestatement;
                int agree = JOptionPane.showConfirmDialog(null,"Agree With The Above Queation? ", "Message",  JOptionPane.YES_NO_OPTION);
                if(agree == JOptionPane.YES_OPTION){
                    agreestatement = "Yes";
                }else{
                    agreestatement = "No";
                }
                Centre c = new Centre("-","-");
                Appointment p = new Appointment (id,currentaddress,State,healthstatus,agreestatement,"-","-","-","-",false,false,false,"-",c,COVID19VRS.loginPpl);
                COVID19VRS.loginPpl.setMyAppointment(p);
                Dataio1.allAppointment.add(p);
                Dataio1.write();
                JOptionPane.showMessageDialog(null, "Register Successfully!");
            }
             
        }else if(e.getSource()==Modify){
            boolean found = false;
            Appointment apt = null;
            for(i=0; i<Dataio1.allAppointment.size(); i++){
                apt = Dataio1.allAppointment.get(i);
                if(COVID19VRS.loginPpl.getIDnumber().equals(apt.getPeople().getIDnumber())){
                    found = true;
                    break;
                }
            }
            if(!found){
                JOptionPane.showMessageDialog(null, "You Haven't Register For The Vaccination !");
            }else if(COVID19VRS.loginPpl.getMyAppointment().getStatus()){
                JOptionPane.showMessageDialog(null, "Your Vaccination Have Been Approved !");
            }else{
                String currentaddress =JOptionPane.showInputDialog("Enter Your Latest Current Address ");
                String[] states = {"Johor", "Kedah", "Kelatan", "Kuala Lumpur", "Malacca", "Negeri Sembilan",
                                   "Pahang", "Penang", "Perak", "Perlis", "Sabah", "Sarawak", "Selangor", "Terengganu"};
                String State = (String)JOptionPane.showInputDialog(null,"Select Your State",
                                "Message", JOptionPane.PLAIN_MESSAGE,null,states,states[0]);
                String healthstatus;
                int health = JOptionPane.showConfirmDialog(null, "Are you exhibing 2 or more symptoms as list below? \n• Chill \n• Fever\n• Shivering(rigor)\n• Body ache\n• Headache\n• Sore throat\n• Nausea or Vomiting\n• Diarrhea\n• Fatigue\n• Runny nose or nasal congestion", "Message", JOptionPane.YES_NO_OPTION);
                if(health == JOptionPane.YES_OPTION ){
                    healthstatus = "Yes";
                }else{
                    healthstatus = "No";
                }
                String agreestatement;
                int agree = JOptionPane.showConfirmDialog(null,"Agree With The Above Queation ? ", "Message",  JOptionPane.YES_NO_OPTION);
                if(agree == JOptionPane.YES_OPTION){
                    agreestatement = "Yes";
                }else{
                    agreestatement = "No";
                }
                Centre c = new Centre("-","-");
                int change = JOptionPane.showConfirmDialog(null,"Confirm To Save Change?","Message", JOptionPane.YES_NO_OPTION);
                if(change == JOptionPane.YES_OPTION){
                    Dataio1.allAppointment.get(i).setCurrentaddress(currentaddress);
                    Dataio1.allAppointment.get(i).setState(State);
                    Dataio1.allAppointment.get(i).setHealthstatus(healthstatus);
                    Dataio1.allAppointment.get(i).setAgreestatement(agreestatement);
                    Appointment p =new Appointment(Dataio1.allAppointment.get(i).getId(),currentaddress,State,healthstatus,agreestatement,
                            Dataio1.allAppointment.get(i).getDate1(),Dataio1.allAppointment.get(i).getTime1(),"-","-",false,false,false,"-",c,
                            Dataio1.allAppointment.get(i).getPeople());
                    COVID19VRS.loginPpl.setMyAppointment(p);
                    Dataio1.write();
                    JOptionPane.showMessageDialog(null, "Edit Successfully!");
                }
            }
        }else if (e.getSource()==View){
            boolean found = false;
            Appointment apt = null;
            for(i=0; i<Dataio1.allAppointment.size(); i++){
                apt = Dataio1.allAppointment.get(i);
                if(COVID19VRS.loginPpl.getIDnumber().equals(apt.getPeople().getIDnumber())){
                    found = true;
                    break;
                }
            }
            if(!found){
                JOptionPane.showMessageDialog(null, "You Haven't Register For The Vaccination!");
                
            }else{
                int id = COVID19VRS.loginPpl.getMyAppointment().getId();
                String curradd = COVID19VRS.loginPpl.getMyAppointment().getCurrentaddress();
                String State = COVID19VRS.loginPpl.getMyAppointment().getState();
                String healthstatus=COVID19VRS.loginPpl.getMyAppointment().getHealthstatus();
                String agree=COVID19VRS.loginPpl.getMyAppointment().getAgreestatement();
                JOptionPane.showMessageDialog(null,"Your Register Detail\n Register ID: "+id+"\nCurrent Address: "+curradd+
                        "\nState: "+State+"\nExhibiting2++ Symptoms: "+healthstatus+"\nAgree With Above Question? "+agree);
            }
        } 
    }
    
    private Button Register, Modify, View,Back;
    private Panel panel;
    private Label title;
    public Page2ppl(){
        setSize(400,300);
        setLocationRelativeTo(null);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Covid-19 Vaccine Registration System");
        Register = new Button("• Register for vaccine");
        Modify = new Button("• Modify information");
        View = new Button("• View Vaccine Registration");
        Back = new Button("• Back");
        Register.setBounds(40,130,300,30);
        Modify.setBounds(40,160,300,30);
        View.setBounds(40,190,300,30);
        Back.setBounds(40,220,300,30);
        Register.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        Modify.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        View.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        Back.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        Register.setBackground(new Color(220,220,220));
        Modify.setBackground(new Color(220,220,220));
        View.setBackground(new Color(220,220,220));
        Back.setForeground(Color.white);
        Back.setBackground(Color.black);
        title = new Label("\nRegister to the vaccination programme", Label.CENTER);
        title.setBounds(0, 30, 400, 60);
        title.setFont(new Font(Font.DIALOG,Font.BOLD,18));
        Register.addActionListener(this);
        Modify.addActionListener(this); 
        View.addActionListener(this);
        Back.addActionListener(this);
        add(Register);
        add(Modify);
        add(View);
        add(Back);
        add(title);
//        setVisible(true);
    }
}


