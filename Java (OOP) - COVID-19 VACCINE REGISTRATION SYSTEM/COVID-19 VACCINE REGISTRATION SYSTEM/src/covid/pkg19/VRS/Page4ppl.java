package covid.pkg19.VRS;
import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
class Page4ppl extends JFrame implements ActionListener {
    int i=0;
    public void actionPerformed(ActionEvent e){
        if(e.getSource()== Back){
            setVisible(false);
            COVID19VRS.first.setVisible(true);
        }
        else if(e.getSource()==View){
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
            String name= COVID19VRS.loginPpl.getName();
            String ic = COVID19VRS.loginPpl.getIDnumber();
            String date1 = COVID19VRS.loginPpl.getMyAppointment().getDate1();
            String time1 = COVID19VRS.loginPpl.getMyAppointment().getTime1();
            String date2 = COVID19VRS.loginPpl.getMyAppointment().getDate2();
            String time2 = COVID19VRS.loginPpl.getMyAppointment().getTime2();
            String Vaccine = COVID19VRS.loginPpl.getMyAppointment().getVaccine();
            String Center = COVID19VRS.loginPpl.getMyAppointment().getCenter().getName();
            
            Boolean d1= COVID19VRS.loginPpl.getMyAppointment().getDose1();
            String Dose1;
            if (d1){
                Dose1="Finish Vaccinated";
            }
            else{
                Dose1="Unknown";
            }
            Boolean d2= COVID19VRS.loginPpl.getMyAppointment().getDose1();
            String Dose2;
            if (d2){
                Dose2="Finish Vaccinated";
            }
            else{
                Dose2="Unknown";
            }
            JOptionPane.showMessageDialog(null, "COVID-19 Vaccination Status\n________________________________\n                    "+name+
                    "\n                "+ic+"\nDose1 : "+Dose1+"\nDate (DD/MM/YYYY) : "+date1+"\nTime : "+time1+"\nVaccine Type : "+Vaccine+
                    "\nCenter : "+Center+"\n\nDose2 : "+Dose2+"\nDate (DD/MM/YYYY) : "+date2+"\nTime : "+time2+"\nVaccine Type : "+
                    Vaccine+"\nCenter : "+Center+"\n");
                    }    
        }else if (e.getSource()==Search){
            boolean foundd = false;
            Appointment aptt = null;
            for(i=0; i<Dataio1.allAppointment.size(); i++){
                aptt = Dataio1.allAppointment.get(i);
                if(COVID19VRS.loginPpl.getIDnumber().equals(aptt.getPeople().getIDnumber())){
                    foundd = true;
                    break;
                }
            }
            if(!foundd){
                JOptionPane.showMessageDialog(null, "You Haven't Register For The Vaccination!");
            }else{
                Boolean d1= COVID19VRS.loginPpl.getMyAppointment().getDose1();
                String Dose1;
                if (d1){
                    Dose1="Finish Vaccinated";
                }
                else{
                    Dose1="Incompleted";
                }
                Boolean d2= COVID19VRS.loginPpl.getMyAppointment().getDose1();
                String Dose2;
                if (d2){
                    Dose2="Finish Vaccinated";
                }
                else{
                    Dose2="Incompleted";
                }
                try{
                    String searchdose = JOptionPane.showInputDialog("Enter Dose1 or Dose2 To Check Details ");
                    if (searchdose.equals("Dose1")||searchdose.equals("DOSE1")||searchdose.equals("DOSE 1")||searchdose.equals("Dose 1")){
                        JOptionPane.showMessageDialog(null,"Dose 1:"+Dose1+"\nDate: "+COVID19VRS.loginPpl.getMyAppointment().getDate1()+"\nTime : "+COVID19VRS.loginPpl.getMyAppointment().getTime1()+"\nVaccine: "+COVID19VRS.loginPpl.getMyAppointment().getVaccine()+"\nCenter: "+
                                COVID19VRS.loginPpl.getMyAppointment().getCenter().getName()); 
                    }else if (searchdose.equals("Dose2")||searchdose.equals("DOSE2")||searchdose.equals("DOSE 2")||searchdose.equals("Dose 2")){
                        JOptionPane.showMessageDialog(null,"Dose 2:"+Dose2+"\nDate: "+COVID19VRS.loginPpl.getMyAppointment().getDate2()+
                                "\nVaccine: "+COVID19VRS.loginPpl.getMyAppointment().getVaccine()+"\nCenter: "+COVID19VRS.loginPpl.getMyAppointment().getTime2()+
                                COVID19VRS.loginPpl.getMyAppointment().getCenter().getName());
                    }else{
                        JOptionPane.showMessageDialog(null,"Please enter the proper keyword(Dose1/Dose2)!");
                    }
                }catch(NullPointerException e1){
                    //Do nothing;
                }
            } 
        }
    }
    private Button View,Search,Back;
    private Label title;
    public Page4ppl(){
        setSize(400,300);
        setLocationRelativeTo(null);
        setLayout(null);
        setTitle("Covid-19 Vaccine Registration System");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        View = new Button("• View Vaccination Status");
        Search = new Button("• Search");
        Back = new Button("• Back");
        View.setBounds(40,130,300,30);
        Search.setBounds(40,160,300,30);
        Back.setBounds(40,190,300,30);
        View.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        Search.setFont(new Font(Font.DIALOG,Font.BOLD,12));      
        Back.setFont(new Font(Font.DIALOG,Font.BOLD,12));
        View.setBackground(new Color(220,220,220));
        Search.setBackground(new Color(220,220,220));
        Back.setForeground(Color.white);
        Back.setBackground(Color.black);
        title = new Label("\nView Vaccination status", Label.CENTER);
        title.setBounds(0, 30, 400, 60);
        title.setFont(new Font(Font.DIALOG,Font.BOLD,18));
        View.addActionListener(this);
        Search.addActionListener(this);
        Back.addActionListener(this);
        add(View);
        add(Search);
        add(Back);
        add(title);
//        setVisible(true);
    }
}
