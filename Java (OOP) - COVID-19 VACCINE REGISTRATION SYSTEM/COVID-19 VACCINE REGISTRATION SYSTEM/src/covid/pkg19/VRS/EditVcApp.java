package covid.pkg19.VRS;
import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
public class EditVcApp extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource()==centreBox){
            if(!centreBox.getSelectedItem().equals("-")){
                for(int i=vcBox.getItemCount(); i>1; i--){
                    vcBox.removeItemAt(i-1);
                }
                String selectC = (String)centreBox.getSelectedItem();
                int i;
                for(i=0; i<DataIO.allCentre.size(); i++){
                    if(selectC.equals(DataIO.allCentre.get(i).getName())){
                        break;
                    }
                }
                for(int j=0; j<DataIO.allCentre.get(i).getCentreVaccine().size(); j++){
                    vcBox.addItem(DataIO.allCentre.get(i).getCentreVaccine().get(j).getName());
                }
            }else{
                for(int i=vcBox.getItemCount(); i>1; i--){
                    vcBox.removeItemAt(i-1);
                }
            }
        }else if(e.getSource()==save){
            boolean Dos1 = false, Dos2 = false, Status = false;
            if(dos1B.getSelectedIndex()==1){
                Dos1 = true;
            }
            if(dos2B.getSelectedIndex()==1){
                Dos2 = true;
            }
            if(statusB.getSelectedIndex()==1){
                Status = true;
            }
            String Date1 = (String)day1.getSelectedItem() 
                    + "/" + (String)month1.getSelectedItem()
                    + "/" + (String)year1.getSelectedItem();
            if(day1.getSelectedIndex()==0 || month1.getSelectedIndex()==0 || year1.getSelectedIndex()==0){
                Date1 = "-";
            }
            String Time1 = (String)time1B.getSelectedItem();
            if(time1B.getSelectedIndex()==0){
                Time1 = "-";
            }
            String Date2 = (String)day2.getSelectedItem() 
                    + "/" + (String)month2.getSelectedItem()
                    + "/" + (String)year2.getSelectedItem();
            if(day2.getSelectedIndex()==0 || month2.getSelectedIndex()==0 || year2.getSelectedIndex()==0){
                Date2 = "-";
            }
            String Time2 = (String)time2B.getSelectedItem();
            if(time2B.getSelectedIndex()==0){
                Time2 = "-";
            }
            String SCentre = (String)centreBox.getSelectedItem();
            Centre Centre = null;
            if(centreBox.getSelectedIndex() > 1){
                for(int i=0; i<DataIO.allCentre.size(); i++){
                    if(SCentre.equals(DataIO.allCentre.get(i).getName())){
                        Centre = DataIO.allCentre.get(i);
                    }
                }
            }else{
                Centre = new Centre("-","-");
            }
            String Vaccine;
            if(vcBox.getSelectedIndex() == 1){
                Vaccine = "-";
            }else{
                Vaccine = (String)vcBox.getSelectedItem();
            }
            int out = JOptionPane.showConfirmDialog(null, "Confirm to save change?", 
                    "Message", JOptionPane.YES_NO_OPTION);
            if(out == JOptionPane.YES_OPTION){
                int i;
                for(i=0;i<Dataio1.allAppointment.size(); i++){
                    if(COVID19VRS.comtVaccineApp.editAppId.equals(String.valueOf(Dataio1.allAppointment.get(i).getId()))){
                        break;
                    }
                }
                if(Dos1 == true && Dos2==false){
                    VaccineUsed(Dataio1.allAppointment.get(i).getCenter().getName(), Dataio1.allAppointment.get(i).getVaccine());
                }
                if(Dos2){
                    VaccineUsed(Dataio1.allAppointment.get(i).getCenter().getName(), Dataio1.allAppointment.get(i).getVaccine());
                }
                Dataio1.allAppointment.get(i).setDate1(Date1);
                Dataio1.allAppointment.get(i).setTime1(Time1);
                Dataio1.allAppointment.get(i).setDate2(Date2);
                Dataio1.allAppointment.get(i).setTime2(Time2);
                Dataio1.allAppointment.get(i).setCenter(Centre);
                Dataio1.allAppointment.get(i).setVaccine(Vaccine);
                Dataio1.allAppointment.get(i).setDose1(Dos1);
                Dataio1.allAppointment.get(i).setDose2(Dos2);
                Dataio1.allAppointment.get(i).setStatus(Status);
                Dataio1.write();
                //Change table to all Approval App
                COVID19VRS.comtVaccineApp.unApproveApp.setFont(new Font(Font.DIALOG, Font.PLAIN, 12));
                COVID19VRS.comtVaccineApp.unApproveApp.setBackground(new Color(220,220,220));
                COVID19VRS.comtVaccineApp.approveApp.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
                COVID19VRS.comtVaccineApp.approveApp.setBackground(null);
                COVID19VRS.comtVaccineApp.searchText.setText("");
                COVID19VRS.comtVaccineApp.tableApp = new ArrayList<Appointment>();
                for(int j=0; j<Dataio1.allAppointment.size(); j++){
                    Appointment a = Dataio1.allAppointment.get(j);
                    if(a.getStatus()){
                        COVID19VRS.comtVaccineApp.tableApp.add(a);
                    }
                }
                String[][] data = COVID19VRS.comtVaccineApp.tableData(COVID19VRS.comtVaccineApp.tableApp);
                COVID19VRS.comtVaccineApp.tableM = new DefaultTableModel(data, COVID19VRS.comtVaccineApp.columnNames);
                COVID19VRS.comtVaccineApp.table.setModel(COVID19VRS.comtVaccineApp.tableM);
                COVID19VRS.comtVaccineApp.tableStyle(COVID19VRS.comtVaccineApp.table);
                setVisible(false);
                COVID19VRS.comtVaccineApp.setEnabled(true);
            }
        }else if(e.getSource()==cancel){
            setVisible(false);
            COVID19VRS.comtVaccineApp.setEnabled(true);
        }
    }
    
    public void VaccineUsed(String centre, String vaccine){
        for(int i=0; i<DataIO.allVaccine.size(); i++){
            if(centre.equals(DataIO.allVaccine.get(i).getCentre().getName()) && vaccine.equals(DataIO.allVaccine.get(i).getName())){
                DataIO.allVaccine.get(i).setQuantity(DataIO.allVaccine.get(i).getQuantity() - 1);
                DataIO.write();
                break;
            }
        }
    }
    
    private Label title, id, pplId, centre, vaccine, dos1, date1, time1, dos2, date2, time2, status;
    TextField idText, pplText;
    JComboBox centreBox, vcBox, dos1B, day1, month1, year1, time1B, dos2B, day2, month2, year2, time2B, statusB;
    private Button save, cancel;
    private String[] days, months, years, times, centreS, vaccineS, dosS, statusS;
    public EditVcApp(){
        setSize(650, 420);
        setLocationRelativeTo(null);
        setLayout(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setTitle("Covid-19 Vaccine Regiatration System");
        title = new Label("Edit Appointment", Label.CENTER);
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setBounds(0, 20, 650, 30);
        id = new Label("Appointment ID");
        id.setBounds(50,80,100,25);
        idText = new TextField();
        idText.setEnabled(false);
        idText.setBounds(150,80,150,25);
        pplId = new Label("IC/Passport No."); 
        pplId.setBounds(50,110,100,25);
        pplText = new TextField();
        pplText.setBounds(150,110,150,25);
        pplText.setEnabled(false);
        centre = new Label("Centre");
        centre.setBounds(50,140,100,25);
        centreS = new String[]{"Select Centre", "-"};
        centreBox = new JComboBox(centreS);
        for(int i=0; i<DataIO.allCentre.size(); i++){
           centreBox.addItem(DataIO.allCentre.get(i).getName());
        }
        centreBox.setBounds(150,140,150,25);
        vaccine = new Label("Vaccine");
        vaccine.setBounds(50,170,100,25);
        vaccineS = new String[]{"Select Vaccine", "-"};
        vcBox = new JComboBox(vaccineS);
        vcBox.setBounds(150,170,150,25);
        dos1 = new Label("Dos 1");
        dos1.setBounds(350,80,100,25);
        dosS = new String[]{"Incomplete", "Completed"};
        dos1B = new JComboBox(dosS);
        dos1B.setBounds(450,80,150,25);
        date1 = new Label("Date 1");
        date1.setBounds(350,110,100,25);
        days = new String[]{"-", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", 
            "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
        months = new String[]{"-", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "July",
            "Aug", "Sep", "Oct", "Nov", "Dec"};
        years = new String[]{"-", "2021", "2022"};
        day1 = new JComboBox(days);
        month1 = new JComboBox(months);
        year1 = new JComboBox(years);
        day1.setBounds(450,110,40,25);
        month1.setBounds(490,110,50,25);
        year1.setBounds(540,110,60,25);
        time1 = new Label("Time 1");
        time1.setBounds(350,140,100,25);
        times = new String[]{"-", "8:00", "8:30", "9:00", "9:30", "10:00", "10:30", "11:00", "11:30",
            "12:00", "12:30", "13:00", "13:30", "14:00", "14:30", "15:00", "15:30", "16:00",
            "16:30", "17:00", "17:30", "18:00"};
        time1B = new JComboBox(times);
        time1B.setBounds(450, 140, 150, 25);
        dos2 = new Label("Dos 2");
        dos2.setBounds(350,170,100,25);
        dos2B = new JComboBox(dosS);
        dos2B.setBounds(450,170,150,25);
        date2 = new Label("Date 2");
        date2.setBounds(350,200,100,25);
        day2 = new JComboBox(days);
        month2 = new JComboBox(months);
        year2 = new JComboBox(years);
        day2.setBounds(450,200,40,25);
        month2.setBounds(490,200,50,25);
        year2.setBounds(540,200,60,25);
        time2 = new Label("Time 2");
        time2.setBounds(350,230,100,25);
        time2B = new JComboBox(times);
        time2B.setBounds(450, 230, 150, 25);
        statusS = new String[]{"Waiting", "Approved"};
        status = new Label("Status");
        status.setBounds(350,260,100,25);
        statusB = new JComboBox(statusS);
        statusB.setBounds(450,260,150,25);
        save = new Button("Save");
        save.setBounds(435,330,80,25);
        cancel = new Button("Cancel");
        cancel.setBounds(520,330,80,25);
        add(title);
        add(id);
        add(idText);
        add(pplId);
        add(pplText);
        add(centre);
        add(centreBox);
        add(vaccine);
        add(vcBox);
        add(dos1);
        add(dos1B);
        add(date1);
        add(day1);
        add(month1);
        add(year1);
        add(time1);
        add(time1B);
        add(dos2);
        add(dos2B);
        add(date2);
        add(day2);
        add(month2);
        add(year2);
        add(time2);
        add(time2B);
        add(status);
        add(statusB);
        add(save);
        add(cancel);
        centreBox.addActionListener(this);
        save.addActionListener(this);
        cancel.addActionListener(this);
        setResizable(false);
    }
}
