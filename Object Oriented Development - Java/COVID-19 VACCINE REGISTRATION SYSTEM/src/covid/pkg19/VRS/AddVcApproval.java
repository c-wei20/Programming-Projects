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
public class AddVcApproval extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == centreBox){
            if(centreBox.getSelectedIndex()!=0){
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
        }else if(e.getSource() == add){
            String Date = (String)day.getSelectedItem() 
                    + "/" + (String)month.getSelectedItem()
                    + "/" + (String)year.getSelectedItem();
            String Time = (String)timeBox.getSelectedItem();
            String SCentre = (String)centreBox.getSelectedItem();
            Centre Centre = null;
            for(int i=0; i<DataIO.allCentre.size(); i++){
                if(SCentre.equals(DataIO.allCentre.get(i).getName())){
                    Centre = DataIO.allCentre.get(i);
                }
            }
            String Vaccine = (String)vcBox.getSelectedItem();
            if(centreBox.getSelectedIndex()==0 || vcBox.getSelectedIndex()==0){
                JOptionPane.showMessageDialog(null, "Please select a centre and a vaccine!");
            }else{
                int out = JOptionPane.showConfirmDialog(null, "Confirm to approve the appointment?\n- Appointment ID: "+ COVID19VRS.comtVaccineApp.addAppId
                        +"\n- Date: "+Date+"\n- Time: "+Time+"\n- Centre: "+Centre.getName()+"\n- Vaccine: "+Vaccine, 
                        "Message", JOptionPane.YES_NO_OPTION);
                if(out == JOptionPane.YES_OPTION){
                    int i;
                    for(i=0;i<Dataio1.allAppointment.size(); i++){
                        if(COVID19VRS.comtVaccineApp.addAppId.equals(String.valueOf(Dataio1.allAppointment.get(i).getId()))){
                            break;
                        }
                    }
                    Dataio1.allAppointment.get(i).setDate1(Date);
                    Dataio1.allAppointment.get(i).setTime1(Time);
                    Dataio1.allAppointment.get(i).setCenter(Centre);
                    Dataio1.allAppointment.get(i).setVaccine(Vaccine);
                    Dataio1.allAppointment.get(i).setStatus(true);
                    Dataio1.write();
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
            }
            for(int i=centreBox.getItemCount(); i>1; i--){
                centreBox.removeItemAt(i-1);
            }
            for(int i=vcBox.getItemCount(); i>1; i--){
                vcBox.removeItemAt(i-1);
            }
        }else if(e.getSource() == cancel){
            day.setSelectedIndex(0);
            month.setSelectedIndex(0);
            year.setSelectedIndex(0);
            timeBox.setSelectedIndex(0);
            for(int i=centreBox.getItemCount(); i>1; i--){
                centreBox.removeItemAt(i-1);
            }
            for(int i=vcBox.getItemCount(); i>1; i--){
                vcBox.removeItemAt(i-1);
            }
            setVisible(false);
            COVID19VRS.comtVaccineApp.setEnabled(true);
        }
    } 
    private Label title, date, address, state, time, centre, vaccine;
    Label appId, pplId, name;
    TextField addressText, stateText;
    JComboBox day, month, year, timeBox, centreBox, vcBox;
    private String[] days, months, years, times;
    private String[] centreName = new String[]{"Select Centre"}, vcName = new String[]{"Select Vaccine"};
    private Button add, cancel;
    public AddVcApproval(){
        setSize(500, 450);
        setLocationRelativeTo(null);
        setLayout(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setTitle("Covid-19 Vaccine Regiatration System");
        title = new Label("Add Approval", Label.CENTER);
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setBounds(0, 20, 500, 30);
        appId = new Label("Appointment ID:  ");
        appId.setBounds(100, 80, 300, 25);
        pplId = new Label("IC/Passport No.: ");
        pplId.setBounds(100, 110, 300, 25);
        name = new Label("Name:            ");
        name.setBounds(100, 140, 300, 25);
        address = new Label("Current Address");
        address.setBounds(100, 170, 100, 25);
        addressText = new TextField();
        addressText.setBounds(200, 170, 200, 25);
        addressText.setEditable(false);
        state = new Label("State");
        state.setBounds(100, 200, 100, 25);
        stateText = new TextField();
        stateText.setBounds(200, 200, 200, 25);
        stateText.setEditable(false);
        date = new Label("Date");
        date.setBounds(100, 230, 100, 25);
        days = new String[]{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", 
            "22", "23", "24", "25", "26", "27", "28", "29", "30", "31" };
        day = new JComboBox(days);
        day.setBounds(200, 230, 60, 25);
        months = new String[]{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July",
            "Aug", "Sep", "Oct", "Nov", "Dec"};
        month = new JComboBox(months);
        month.setBounds(260, 230, 60, 25);
        years = new String[]{"2021", "2022"};
        year = new JComboBox(years);
        year.setBounds(320, 230, 80, 25);
        time = new Label("Time");
        time.setBounds(100, 260, 100, 25);
        times = new String[]{"8:00", "8:30", "9:00", "9:30", "10:00", "10:30", "11:00", "11:30",
            "12:00", "12:30", "13:00", "13:30", "14:00", "14:30", "15:00", "15:30", "16:00",
            "16:30", "17:00", "17:30", "18:00"};
        timeBox = new JComboBox(times);
        timeBox.setBounds(200, 260, 200, 25);
        centre = new Label("Centre");
        centre.setBounds(100, 290, 100, 25);
        centreBox = new JComboBox(centreName);
        centreBox.setBounds(200, 290, 200, 25);
        vaccine = new Label("Vaccine");
        vaccine.setBounds(100, 320, 100, 25);
        vcBox = new JComboBox(vcName);
        vcBox.setBounds(200, 320, 200, 25);
        add = new Button("Add");
        add.setBounds(235, 360, 80, 25);
        cancel = new Button("Cancel");
        cancel.setBounds(320, 360, 80, 25);
        add(title);
        add(appId);
        add(pplId);
        add(name);
        add(address);
        add(addressText);
        add(state);
        add(stateText);
        add(date);
        add(day);
        add(month);
        add(year);
        add(time);
        add(timeBox);
        add(centre);
        add(centreBox);
        add(vaccine);
        add(vcBox);
        add(add);
        add(cancel);
        add.addActionListener(this);
        cancel.addActionListener(this);
        centreBox.addActionListener(this);
        setResizable(false);
    }
}
