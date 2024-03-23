package covid.pkg19.VRS;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
public class CommitteeVaccineApp extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == peopleInfo){
            COVID19VRS.comtPeopleInfo.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == vaccineSup){
            COVID19VRS.comtVaccineSup.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == report){
            COVID19VRS.comtReport.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == comtInfo){
            String Password = "letmein";
            String password = JOptionPane.showInputDialog(null, "Enter Password: ");
            try{
                if(password.equals(Password)){
                    COVID19VRS.comtInfo.setVisible(true);
                    setVisible(false);
                }else{
                    JOptionPane.showMessageDialog(null, "Wrong Password!");
                }
            }catch(NullPointerException e1){
                //Do Nothing
            }
        }else if(e.getSource()== logout){
            int out = JOptionPane.showConfirmDialog(null, "Continue to logout?", "Message", JOptionPane.YES_NO_OPTION);
            if(out == JOptionPane.YES_OPTION){
                setVisible(false);
                COVID19VRS.login.setVisible(true);
            }
        }else if(e.getSource() == search || e.getSource()==searchText){
            String Search = searchText.getText();
            String def = "";
            if(Search.equals(def)){
                //Do Nothing;
            }else{
                String[][] searchData = new String[1][18];
                Appointment p = null;
                int size = Dataio1.allAppointment.size();
                boolean found = false;
                for(int i=0; i<size; i++){
                    p = Dataio1.allAppointment.get(i);
                    if(Search.equals(p.getPeople().getIDnumber())||Search.equals(String.valueOf(p.getId()))){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    JOptionPane.showMessageDialog(null, "No appointment record found!");
                    searchText.setText("");
                }else{
                    String Dos1 = "No", Dos2 = "No", Status = "Waiting";
                    if(p.getDose1()){
                        Dos1 = "Yes";
                    }
                    if(p.getDose2()){
                        Dos2 = "Yes";
                    }
                    if(p.getStatus()){
                        Status = "Approval";
                        unApproveApp.setFont(new Font(Font.DIALOG, Font.PLAIN, 12));
                        unApproveApp.setBackground(new Color(220,220,220));
                        approveApp.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
                        approveApp.setBackground(null);
                    }else{
                        unApproveApp.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
                        unApproveApp.setBackground(null);
                        approveApp.setFont(new Font(Font.DIALOG, Font.PLAIN, 12));
                        approveApp.setBackground(new Color(220,220,220));
                    }
                    searchData[0][0] = String.valueOf(p.getId());
                    searchData[0][1] = ""+p.getPeople().getIDnumber();
                    searchData[0][2] = ""+p.getPeople().getName();
                    searchData[0][3] = ""+p.getPeople().getAge();
                    searchData[0][4] = ""+p.getCurrentaddress();
                    searchData[0][5] = ""+p.getState();
                    searchData[0][6] = ""+p.getHealthstatus();
                    searchData[0][7] = ""+p.getAgreestatement();
                    searchData[0][8] = ""+p.getDate1();
                    searchData[0][9] = ""+p.getTime1();
                    searchData[0][10] = ""+p.getDate2();
                    searchData[0][11] = ""+p.getTime2();
                    searchData[0][12] = ""+Dos1;
                    searchData[0][13] = ""+Dos2;
                    searchData[0][14] = ""+p.getVaccine();
                    if(p.getCenter()==null){
                        searchData[0][15] = ""+"-";
                    }else{
                        searchData[0][15] = ""+p.getCenter().getName();
                    }
                    searchData[0][16] = ""+Status;
                    modelSearch = new DefaultTableModel(searchData, columnNames);
                    table.setModel(modelSearch);
                    tableStyle(table);
                }
            }
        }else if(e.getSource() == unApproveApp){
            unApproveApp.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
            unApproveApp.setBackground(null);
            approveApp.setFont(new Font(Font.DIALOG, Font.PLAIN, 12));
            approveApp.setBackground(new Color(220,220,220));
            searchText.setText("");
            tableApp = new ArrayList<Appointment>();
            for(int i=0; i<Dataio1.allAppointment.size(); i++){
                Appointment a = Dataio1.allAppointment.get(i);
                if(!a.getStatus()){
                    tableApp.add(a);
                }
            }
            String[][] data = tableData(tableApp);
            tableM = new DefaultTableModel(data, columnNames);
            table.setModel(tableM);
            tableStyle(table);
        }else if(e.getSource() == approveApp){
            unApproveApp.setFont(new Font(Font.DIALOG, Font.PLAIN, 12));
            unApproveApp.setBackground(new Color(220,220,220));
            approveApp.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
            approveApp.setBackground(null);
            searchText.setText("");
            tableApp = new ArrayList<Appointment>();
            for(int i=0; i<Dataio1.allAppointment.size(); i++){
                Appointment a = Dataio1.allAppointment.get(i);
                if(a.getStatus()){
                    tableApp.add(a);
                }
            }
            String[][] data = tableData(tableApp);
            tableM = new DefaultTableModel(data, columnNames);
            table.setModel(tableM);
            tableStyle(table);
        }else if(e.getSource() == addApp){
            addAppId = JOptionPane.showInputDialog(null, "Enter appointment ID to approval: ");
            int size = Dataio1.allAppointment.size();
            boolean found = false;
            Appointment foundApp = null;
            try{
                for(int i=0; i<size; i++){
                    foundApp = Dataio1.allAppointment.get(i);
                    if(addAppId.equals(String.valueOf(foundApp.getId()))){
                        found = true;
                        break;
                    }
                }
                if(found){
                    if(!foundApp.getStatus()){
                        COVID19VRS.addApp.appId.setText("Appointment ID:      "+foundApp.getId());
                        COVID19VRS.addApp.pplId.setText("IC/Passport No.:     "+foundApp.getPeople().getIDnumber());
                        COVID19VRS.addApp.name.setText("Name:                     "+foundApp.getPeople().getName());
                        COVID19VRS.addApp.addressText.setText(foundApp.getCurrentaddress());
                        COVID19VRS.addApp.stateText.setText(foundApp.getState());
                        if(!foundApp.getDate1().equals("-")){
                            COVID19VRS.addApp.day.setSelectedItem(foundApp.getDate1().substring(0, foundApp.getDate1().indexOf('/')));
                            COVID19VRS.addApp.month.setSelectedItem(foundApp.getDate1().substring(foundApp.getDate1().indexOf('/')+1, foundApp.getDate1().lastIndexOf('/')));
                            COVID19VRS.addApp.year.setSelectedItem(foundApp.getDate1().substring(foundApp.getDate1().lastIndexOf('/')+1));
                            COVID19VRS.addApp.timeBox.setSelectedItem(foundApp.getTime1());
                        }
                        for(int i=0; i<DataIO.allCentre.size(); i++){
                            if(foundApp.getState().equals(DataIO.allCentre.get(i).getState())){
                                COVID19VRS.addApp.centreBox.addItem(DataIO.allCentre.get(i).getName());
                            }
                        }
                        setEnabled(false);
                        COVID19VRS.addApp.setVisible(true);
                    }else{
                        JOptionPane.showMessageDialog(null, "Appointment has been aproved!");
                    }
                }else{
                    JOptionPane.showMessageDialog(null, "Appointment ID not exsit!");
                }
            }catch(NullPointerException e1){
                //Do nothing
            }
        }else if(e.getSource() == editApp){
            try{
                editAppId = JOptionPane.showInputDialog(null, "Enter appointment ID to edit: ");
                int size = Dataio1.allAppointment.size();
                boolean found = false, approve = false;
                Appointment foundApp = null;
                for(int i=0; i<size; i++){
                    foundApp = Dataio1.allAppointment.get(i);
                    if(editAppId.equals(String.valueOf(foundApp.getId()))){
                        found = true;
                        if(foundApp.getStatus()){
                            approve = true;
                        }
                        break;
                    }
                }
                if(found){
                    if(!approve){
                        JOptionPane.showMessageDialog(null, "Appointment has not been approve, cannot edit!");
                    }else{
                        COVID19VRS.editApp.idText.setText(String.valueOf(foundApp.getId()));
                        COVID19VRS.editApp.pplText.setText(foundApp.getPeople().getIDnumber());
                        COVID19VRS.editApp.centreBox.setSelectedItem(foundApp.getCenter().getName());
                        COVID19VRS.editApp.vcBox.setSelectedItem(foundApp.getVaccine());
                        if(foundApp.getDose1()){
                            COVID19VRS.editApp.dos1B.setSelectedIndex(1);
                        }
                        if(!foundApp.getDate1().equals("-")){
                            COVID19VRS.editApp.day1.setSelectedItem(foundApp.getDate1().substring(0, foundApp.getDate1().indexOf('/')));
                            COVID19VRS.editApp.month1.setSelectedItem(foundApp.getDate1().substring(foundApp.getDate1().indexOf('/')+1, foundApp.getDate1().lastIndexOf('/')));
                            COVID19VRS.editApp.year1.setSelectedItem(foundApp.getDate1().substring(foundApp.getDate1().lastIndexOf('/')+1));
                            COVID19VRS.editApp.time1B.setSelectedItem(foundApp.getTime1());
                        }
                        if(foundApp.getDose2()){
                            COVID19VRS.editApp.dos2B.setSelectedIndex(1);
                        }
                        if(!foundApp.getDate2().equals("-")){
                            COVID19VRS.editApp.day2.setSelectedItem(foundApp.getDate2().substring(0, foundApp.getDate2().indexOf('/')));
                            COVID19VRS.editApp.month2.setSelectedItem(foundApp.getDate2().substring(foundApp.getDate2().indexOf('/')+1, foundApp.getDate2().lastIndexOf('/')));
                            COVID19VRS.editApp.year2.setSelectedItem(foundApp.getDate2().substring(foundApp.getDate2().lastIndexOf('/')+1));
                            COVID19VRS.editApp.time2B.setSelectedItem(foundApp.getTime2());
                        }
                        if(foundApp.getStatus()){
                            COVID19VRS.editApp.statusB.setSelectedIndex(1);
                        }
                        setEnabled(false);
                        COVID19VRS.editApp.setVisible(true);
                    }
                }else{
                    JOptionPane.showMessageDialog(null, "Appointment ID not exsit!");
                }
            }catch(Exception e1){
                
            }
        }else if(e.getSource() == deleteApp){
            try{
                String DeleteApp = JOptionPane.showInputDialog(null, "Enter appointment ID to delete: ");
                int i=0;
                Appointment deleteApp = null;
                boolean found = false;
                for(i=0; i<Dataio1.allAppointment.size(); i++){
                    if(DeleteApp.equals(String.valueOf(Dataio1.allAppointment.get(i).getId()))){
                        deleteApp = Dataio1.allAppointment.get(i);
                        found = true;
                        break;
                    }
                }
                if(found){
                    int out = JOptionPane.showConfirmDialog(null, "Confirm to delete appointment?\n- Appointment ID: "+ deleteApp.getId()
                            +"\n- IC/Passport No.: "+deleteApp.getPeople().getIDnumber()+"\n- Name: "+deleteApp.getPeople().getName(), 
                            "Message", JOptionPane.YES_NO_OPTION);
                    if(out == JOptionPane.YES_OPTION){
                        Dataio1.allAppointment.remove(i);
                        Dataio1.write();
                        unApproveApp.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
                        unApproveApp.setBackground(null);
                        approveApp.setFont(new Font(Font.DIALOG, Font.PLAIN, 12));
                        approveApp.setBackground(new Color(220,220,220));
                        searchText.setText("");
                        tableApp = new ArrayList<Appointment>();
                        for(int j=0; j<Dataio1.allAppointment.size(); j++){
                            Appointment a = Dataio1.allAppointment.get(j);
                            if(!a.getStatus()){
                                tableApp.add(a);
                            }
                        }
                        String[][] data = tableData(tableApp);
                        tableM = new DefaultTableModel(data, columnNames);
                        table.setModel(tableM);
                        tableStyle(table);
                    }
                }else{
                    JOptionPane.showMessageDialog(null,"Account not exists!");
                }
            }catch(NullPointerException e1){
                //Do nothing
            }
        }
    }
    String addAppId, editAppId;
    ArrayList<Appointment> tableApp;
    String[] columnNames;
    int ctSize, arrayAppIndex, tableAppIndex;
    private Panel pc, pt, pw;
    private Button peopleInfo, vaccineApp, vaccineSup, report, comtInfo, addApp, editApp, deleteApp, search, logout;
    Button approveApp, unApproveApp;
    private Label title;
    TextField searchText;
    DefaultTableModel tableM, modelSearch;
    JTable table;
    public CommitteeVaccineApp(){
        setSize(1080, 720);
        setLocationRelativeTo(null);
        setTitle("Covid-19 Vaccine Regiatration System");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pc = new Panel();
        pc.setLayout(null);
        pt = new Panel();
        pt.setBackground(new Color(0,0,128));
        pt.setLayout(null);
        pt.setSize(1080, 50);
        title = new Label("Covid-19 Vaccine Regiatration System");
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setForeground(Color.white);
        title.setBounds(20,10,400, 30);
        pw = new Panel();
        pw.setBackground(new Color(220,220,220));
        pw.setLayout(null);
        pw.setSize(200, 720);
        peopleInfo = new Button("People Information");
        peopleInfo.setBounds(0, 0, 200, 40);
        peopleInfo.setBackground(new Color(220,220,220));
        vaccineApp = new Button("Vaccination Appoitment");
        vaccineApp.setBounds(0, 40, 200, 40);
        vaccineSup = new Button("Vaccine Supply");
        vaccineSup.setBounds(0, 80, 200, 40);
        vaccineSup.setBackground(new Color(220,220,220));
        report = new Button("Report");
        report.setBounds(0, 120, 200, 40);
        report.setBackground(new Color(220,220,220));
        comtInfo = new Button("Personnel of Committee Info");
        comtInfo.setBounds(0, 160, 200, 40);
        comtInfo.setBackground(new Color(220,220,220));
        logout = new Button("Logout");
        logout.setForeground(Color.white);
        logout.setBackground(new Color(0,0,128));
        logout.setBounds(970,15, 70, 25);
        pt.add(title);
        pt.add(logout);
        pw.add(peopleInfo);
        pw.add(vaccineApp);
        pw.add(vaccineSup);
        pw.add(report);
        pw.add(comtInfo);
        peopleInfo.addActionListener(this); 
        vaccineApp.addActionListener(this); 
        vaccineSup.addActionListener(this); 
        report.addActionListener(this); 
        comtInfo.addActionListener(this);
        logout.addActionListener(this);
//Table
        tableApp = new ArrayList<Appointment>();
        for(int i=0; i<Dataio1.allAppointment.size(); i++){
            Appointment a = Dataio1.allAppointment.get(i);
            if(!a.getStatus()){
                tableApp.add(a);
            }
        }
        String[][] data = tableData(tableApp);
        columnNames = new String[]{ "Appointment ID", "People IC/Passport No.", "Name", "Age", 
            "Current Address", "State", "Health Status", "Agreement", "Date1", "Time1", "Date2", "Time2",
            "Dos1","Dos2", "Vaccine", "Centre", "Status"};
        tableM = new DefaultTableModel(data, columnNames);
        table = new JTable(tableM);
        tableStyle(table);
        JScrollPane sp = new JScrollPane(table);
        sp.setBounds(20,50,820,520);
//Function
        unApproveApp = new Button("Unapproved Appointment");
        unApproveApp.setBounds(20,14, 180, 30);
        unApproveApp.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        approveApp = new Button("Approved Appointment");
        approveApp.setBounds(200,14, 180, 30);
        approveApp.setBackground(new Color(220,220,220));
        addApp = new Button("Add Approval");
        addApp.setBounds(560,590, 90, 25);
        addApp.setBackground(new Color(220,220,220));
        editApp = new Button("Edit");
        editApp.setBounds(655,590, 90, 25);
        editApp.setBackground(new Color(220,220,220));
        deleteApp = new Button("Delete");
        deleteApp.setBounds(750,590, 90, 25);
        deleteApp.setBackground(new Color(220,220,220));
        search = new Button("Search");
        search.setBounds(770,15, 70, 25);
        search.setBackground(new Color(220,220,220));
        searchText = new TextField();
        searchText.setBounds(565,15, 200, 25);
        approveApp.addActionListener(this);
        unApproveApp.addActionListener(this);
        addApp.addActionListener(this);
        editApp.addActionListener(this);
        deleteApp.addActionListener(this);
        search.addActionListener(this);
        searchText.addActionListener(this);
        pc.add(sp);
        pc.add(approveApp);
        pc.add(unApproveApp);
        pc.add(addApp);
        pc.add(editApp);
        pc.add(deleteApp);
        pc.add(search);
        pc.add(searchText);
        pt.add(logout);
        add(pc, BorderLayout.CENTER);
        add(pt, BorderLayout.NORTH);
        add(pw, BorderLayout.WEST);
        setResizable(false);
    }
    
    public void tableStyle(JTable table){
        table.setRowHeight(25);
        table.getTableHeader().setBackground(new Color(220,220,220));
        table.getTableHeader().setPreferredSize(new Dimension(100, 25));
        table.getTableHeader().setFont(new Font(Font.DIALOG,Font.BOLD,12));
        table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
        table.getColumn(columnNames[0]).setPreferredWidth(100);
        table.getColumn(columnNames[1]).setPreferredWidth(150);
        table.getColumn(columnNames[2]).setPreferredWidth(120);
        table.getColumn(columnNames[3]).setPreferredWidth(60);
        table.getColumn(columnNames[4]).setPreferredWidth(250);
        table.getColumn(columnNames[5]).setPreferredWidth(120);
        table.getColumn(columnNames[6]).setPreferredWidth(100);
        table.getColumn(columnNames[7]).setPreferredWidth(100);
        table.getColumn(columnNames[8]).setPreferredWidth(100);
        table.getColumn(columnNames[9]).setPreferredWidth(80);
        table.getColumn(columnNames[10]).setPreferredWidth(100);
        table.getColumn(columnNames[11]).setPreferredWidth(80);
        table.getColumn(columnNames[12]).setPreferredWidth(60);
        table.getColumn(columnNames[13]).setPreferredWidth(60);
        table.getColumn(columnNames[14]).setPreferredWidth(100);
        table.getColumn(columnNames[15]).setPreferredWidth(150);
        table.getColumn(columnNames[16]).setPreferredWidth(100);
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment( JLabel.CENTER );
        table.getColumnModel().getColumn(0).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(3).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(6).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(7).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(8).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(9).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(10).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(11).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(12).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(13).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(16).setCellRenderer( centerRenderer );
    }
    
    public String[][] tableData(ArrayList<Appointment> allAppointment){
        int size = allAppointment.size();
        String[][] data = new String[size][17];
        for(int i=0; i<size; i++){
            Appointment a = allAppointment.get(i);
            String Dos1 = "No", Dos2 = "No", Status = "Waiting";
            if(a.getDose1()){
                Dos1 = "Yes";
            }
            if(a.getDose2()){
                Dos2 = "Yes";
            }
            if(a.getStatus()){
                Status = "Approval";
            }
            data[i][0] = String.valueOf(a.getId());
            data[i][1] = ""+a.getPeople().getIDnumber();
            data[i][2] = ""+a.getPeople().getName();
            data[i][3] = ""+a.getPeople().getAge();
            data[i][4] = ""+a.getCurrentaddress();
            data[i][5] = ""+a.getState();
            data[i][6] = ""+a.getHealthstatus();
            data[i][7] = ""+a.getAgreestatement();
            data[i][8] = ""+a.getDate1();
            data[i][9] = ""+a.getTime1();
            data[i][10] = ""+a.getDate2();
            data[i][11] = ""+a.getTime2();
            data[i][12] = ""+Dos1;
            data[i][13] = ""+Dos2;
            data[i][14] = ""+a.getVaccine();
            if(a.getCenter()==null){
                data[i][15] = ""+"-";
            }else{
                data[i][15] = ""+a.getCenter().getName();
            }
            data[i][16] = ""+Status;
        }
        return data;
    }
}
