package covid.pkg19.VRS;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
public class Page3ppl extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        int i = 0;
        if(e.getSource()== Back){
            setVisible(false);
            COVID19VRS.first.setVisible(true);
        }
        else if(e.getSource()==Register){
            Appointment apt = null;
             for(i=0;i<Dataio1.allAppointment.size();i++){
                 apt = Dataio1.allAppointment.get(i);
                if(COVID19VRS.loginPpl.getIDnumber().equals(apt.getPeople().getIDnumber())){
                    break;
                } 
             }
             if (COVID19VRS.loginPpl.getMyAppointment()==null){
                 JOptionPane.showMessageDialog(null, "You Have't Registered For Vaccination !");
             }
             
             else if (!COVID19VRS.loginPpl.getMyAppointment().getDate1().equals("-")){
                 JOptionPane.showMessageDialog(null, "You Have Already Registered For Appointment!");
             }else{
                String[] days = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                    "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22",
                    "23", "24", "25", "26", "27", "28", "29", "30", "31" };
                String[] months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July",
                "Aug", "Sep", "Oct", "Nov", "Dec"};
                String[] years = {"2021", "2022"};
                String[] times = {"8:00", "8:30", "9:00", "9:30", "10:00", "10:30", "11:00", "11:30",
                    "12:00", "12:30", "13:00", "13:30", "14:00", "14:30", "15:00", "15:30", "16:00",
                    "16:30", "17:00", "17:30", "18:00"};
                JComboBox day = new JComboBox(days);
                JComboBox month = new JComboBox(months);
                JComboBox year = new JComboBox(years);
                JComboBox time = new JComboBox(times);

                JPanel myPanel = new JPanel();
                myPanel.setLayout(new BorderLayout());
                JPanel pm = new JPanel();
                pm.setLayout(new GridLayout(4,1));
                JPanel pb = new JPanel();
                pb.setLayout(new GridLayout(2,1));
                Label title = new Label("Select your appointment date and time:");  
                Label date = new Label("Date: ");
                pm.add(date);
                pm.add(day);
                pm.add(month);
                pm.add(year);
                Label timeL = new Label("Time: ");
                pb.add(timeL);
                pb.add(time);
                myPanel.add(pm, BorderLayout.CENTER);
                myPanel.add(title, BorderLayout.NORTH);
                myPanel.add(pb, BorderLayout.SOUTH);

                String Date1;
                String Time1;
                if(true){
                    try{
                        int result = JOptionPane.showConfirmDialog(null, myPanel, "Message", JOptionPane.OK_CANCEL_OPTION);
                        if(result == JOptionPane.OK_OPTION){
                            Date1 = (String)day.getSelectedItem()+"/"+(String)month.getSelectedItem()+"/"+(String)year.getSelectedItem();
                            Time1 = (String)time.getSelectedItem();
                            int confirm = JOptionPane.showConfirmDialog(null, "Confirm the following Appointment:\n- Date: "+Date1+"\n- Time: "+Time1, "Message", JOptionPane.OK_CANCEL_OPTION);
                            if(confirm == JOptionPane.OK_OPTION){
                                Dataio1.allAppointment.get(i).setDate1(Date1);
                                Dataio1.allAppointment.get(i).setTime1(Time1);
                                Dataio1.write();
                                Centre c = new Centre("-","-");
                                Appointment p = new Appointment(Dataio1.allAppointment.get(i).getId(),Dataio1.allAppointment.get(i).getCurrentaddress(),
                                        Dataio1.allAppointment.get(i).getState(),Dataio1.allAppointment.get(i).getHealthstatus(),Dataio1.allAppointment.get(i).getAgreestatement(),
                                        Date1,Time1,"-","-",false,false,false,"-",c,Dataio1.allAppointment.get(i).getPeople());
                                COVID19VRS.loginPpl.setMyAppointment(p); 
                                JOptionPane.showMessageDialog(null, "Register Appointment Successfully!");
                            }
                        }
                    }catch(Exception e1){
                        //Do Nothing
                    }
                }
             }    
        }
        else if (e.getSource()==Cancel){
            Appointment apt = null;
             for(i=0;i<Dataio1.allAppointment.size();i++){
                 apt = Dataio1.allAppointment.get(i);
                if(COVID19VRS.loginPpl.getIDnumber().equals(apt.getPeople().getIDnumber())){
                    break;
                } 
             }
             if (COVID19VRS.loginPpl.getMyAppointment()==null){
                 JOptionPane.showMessageDialog(null, "You Have't Registered For Vaccination !");
             }
             
             else if (COVID19VRS.loginPpl.getMyAppointment().getDate1().equals("-")){
                 JOptionPane.showMessageDialog(null, "You Have Not Any Appointment !");
             }else if(COVID19VRS.loginPpl.getMyAppointment().getDose1()){
                 JOptionPane.showMessageDialog(null, "You Have Completed Dose1\nYou Are Not Allowed To Cancel Dose2 Appointment");
             }else{
                 Centre c = new Centre("-","-");
                 int confirmation = JOptionPane.showConfirmDialog(null,"You Want To Cancel Appointment??\nDate : "
                    + ""+COVID19VRS.loginPpl.getMyAppointment().getDate1()+"\nTime : "+COVID19VRS.loginPpl.getMyAppointment().getTime1(), "Message",  JOptionPane.YES_NO_OPTION);
                 if(confirmation == JOptionPane.YES_OPTION){
                     Dataio1.allAppointment.get(i).setDate1("-");
                     Dataio1.allAppointment.get(i).setTime1("-");
                     Dataio1.allAppointment.get(i).setVaccine("-");
                     Dataio1.allAppointment.get(i).setCenter(c);
                     Dataio1.allAppointment.get(i).setStatus(false);
                     Dataio1.write();
                      Appointment p = new Appointment(Dataio1.allAppointment.get(i).getId(),Dataio1.allAppointment.get(i).getCurrentaddress(),
                      Dataio1.allAppointment.get(i).getState(),Dataio1.allAppointment.get(i).getHealthstatus(),Dataio1.allAppointment.get(i).getAgreestatement(),
                      "-","-","-",Dataio1.allAppointment.get(i).getTime2(),false,false,false,"-",c,Dataio1.allAppointment.get(i).getPeople());
                      COVID19VRS.loginPpl.setMyAppointment(p);
                }
             }
        }else if(e.getSource()== View){
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
                String Date1 = COVID19VRS.loginPpl.getMyAppointment().getDate1();
                String Time1 =COVID19VRS.loginPpl.getMyAppointment().getTime1();
                String Date2 = COVID19VRS.loginPpl.getMyAppointment().getDate2();
                String Time2 =COVID19VRS.loginPpl.getMyAppointment().getTime2();
                String Vaccine = COVID19VRS.loginPpl.getMyAppointment().getVaccine();
                String Center = COVID19VRS.loginPpl.getMyAppointment().getCenter().getName();
                Boolean d1 = COVID19VRS.loginPpl.getMyAppointment().getDose1();
                Boolean s = COVID19VRS.loginPpl.getMyAppointment().getStatus();
                String Dose1;
                if (d1){
                    Dose1 = "Completed";
                 }
                else {
                    Dose1 = "Uncompleted ";
                }
                Boolean d2 = COVID19VRS.loginPpl.getMyAppointment().getDose2();
                String Dose2;
                if (d2){
                    Dose2 = "Completed";
                 }
                else {
                    Dose2 = "Uncompleted ";
                }
                Boolean ss = COVID19VRS.loginPpl.getMyAppointment().getStatus();
                String Status;
                if (ss){
                    Status = "Approve";
                 }
                else {
                    Status = "Waiting To Approve";
                }
                JOptionPane.showMessageDialog(null,"Your Vaccination Appointment Details \n             Dose 1 : "+Dose1+"\nDate (DD/MM/YYYY) : "
                        + ""+ Date1+"\nTime : "+Time1+"\nVaccine Type : "+Vaccine+"\nCenter : "+Center+"\nVaccine Status : "+Status+"\n\n             Dose 2 : "+Dose2+"\nDate (DD/MM/YY)"
                                +  " : " +Date2+"\nTime : "+Time2+"\nVaccine Type : "+Vaccine+"\nCenter : "+Center);
            }
        }
    }   
    private Button Register,Cancel,View,Back;
    private Label title;
    public Page3ppl(){
        setSize(400,300);
        setLocationRelativeTo(null);
        setLayout(null);
        setTitle("Covid-19 Vaccine Registration System");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Register = new Button("• Register For Appointment");
        Cancel = new Button("• Cancel Appointment");
        View = new Button("• View Appointment");
        Back = new Button("• Back");
        Register.setBounds(40,130,300,30);
        Cancel.setBounds(40,160,300,30);
        View.setBounds(40,190,300,30);
        Back.setBounds(40,220,300,30);
        Register.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        Cancel.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        View.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        Back.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        Register.setBackground(new Color(220,220,220));
        Cancel.setBackground(new Color(220,220,220));
        View.setBackground(new Color(220,220,220));
        Back.setForeground(Color.white);
        Back.setBackground(Color.black);
        title = new Label("\nSubmit vaccination appointment", Label.CENTER);
        title.setBounds(0, 30, 400, 60);
        title.setFont(new Font(Font.DIALOG,Font.BOLD,18));
        Register.addActionListener(this);
        Cancel.addActionListener(this);
        View.addActionListener(this);
        Back.addActionListener(this);
        add(Register);
        add(Cancel);
        add(View);
        add(Back);  
        add(title);
//        setVisible(true);
    }
}