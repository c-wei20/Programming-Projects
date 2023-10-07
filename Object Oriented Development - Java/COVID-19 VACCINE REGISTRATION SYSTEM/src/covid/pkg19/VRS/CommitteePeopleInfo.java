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
public class CommitteePeopleInfo extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == vaccineApp){
            COVID19VRS.comtVaccineApp.approveApp.setFont(new Font(Font.DIALOG, Font.PLAIN, 12));
            COVID19VRS.comtVaccineApp.approveApp.setBackground(new Color(220,220,220));
            COVID19VRS.comtVaccineApp.unApproveApp.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
            COVID19VRS.comtVaccineApp.unApproveApp.setBackground(null);
            COVID19VRS.comtVaccineApp.searchText.setText("");
            COVID19VRS.comtVaccineApp.tableApp = new ArrayList<Appointment>();
            for(int j=0; j<Dataio1.allAppointment.size(); j++){
                Appointment a = Dataio1.allAppointment.get(j);
                if(!a.getStatus()){
                    COVID19VRS.comtVaccineApp.tableApp.add(a);
                }
            }
            String[][] data = COVID19VRS.comtVaccineApp.tableData(COVID19VRS.comtVaccineApp.tableApp);
            COVID19VRS.comtVaccineApp.tableM = new DefaultTableModel(data, COVID19VRS.comtVaccineApp.columnNames);
            COVID19VRS.comtVaccineApp.table.setModel(COVID19VRS.comtVaccineApp.tableM);
            COVID19VRS.comtVaccineApp.tableStyle(COVID19VRS.comtVaccineApp.table);
            COVID19VRS.comtVaccineApp.setVisible(true);
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
                
            }
        }else if(e.getSource() == viewAll){
            String[][] data = tableData(DataIO.allPeople);
            tableM = new DefaultTableModel(data, columnNames);
            table.setModel(tableM);
            tableStyle(table);
            searchText.setText("");
        }else if(e.getSource() == search || e.getSource() == searchText){
            String[][] searchData;
            People searchC = null;
            String Search = searchText.getText();
            String def = "";
            if(Search.equals(def)){
                String[][] data = tableData(DataIO.allPeople);
                tableM = new DefaultTableModel(data, columnNames);
                table.setModel(tableM);
                tableStyle(table);
            }else{
                boolean found = false;
                for(int i=0; i<DataIO.allPeople.size(); i++){
                    searchC = DataIO.allPeople.get(i);
                    if(Search.equals(searchC.getIDnumber())){
                        found = true;
                    }
                }
                if(!found){
                    JOptionPane.showMessageDialog(null, "No people information found!");
                }else{
                    searchData = new String[1][10];
                    for(int j=0; j<DataIO.allPeople.size(); j++){
                        searchC = DataIO.allPeople.get(j);
                        if(Search.equals(searchC.getIDnumber())){
                            searchData[0][0] = searchC.getIDnumber();
                            searchData[0][1] = ""+searchC.getName();
                            String n = "Non Citizen";
                            if(searchC.isNationality()){
                                n = "Citizen";
                            }
                            searchData[0][2] = ""+n;
                            searchData[0][3] = ""+searchC.getBirthDate();
                            searchData[0][4] = ""+searchC.getAge();
                            searchData[0][5] = ""+searchC.getGender();
                            searchData[0][6] = ""+searchC.getAddress();
                            searchData[0][7] = ""+searchC.getState();
                            searchData[0][8] = ""+searchC.getPhoneNumber();
                            searchData[0][9] = ""+searchC.getEmail();;
                        }
                    }
                    modelSearch = new DefaultTableModel(searchData, columnNames);
                    table.setModel(modelSearch);
                    tableStyle(table);
                }
            }
        }else if(e.getSource() == add){
            if(searchText.getText().equals("")){
                flag = true;
            }
            COVID19VRS.addPeople.setVisible(true);
            setEnabled(false); 
        }else if(e.getSource()== edit){
            String EditC = JOptionPane.showInputDialog(null, "Enter people IC/Passport No. to edit: ");
            boolean found = false;
            try{
                for(int i=0; i<DataIO.allPeople.size(); i++){
                    editC = DataIO.allPeople.get(i);
                    if(EditC.equals(editC.getIDnumber())){
                        arrayCount = i;
                        found = true;
                        break;
                    }
                }
                if(EditC.equals(searchText.getText())){
                    tableCount = 0;
                }else if(searchText.getText().equals("")){
                    tableCount = arrayCount;
                }else{
                    flag = true;
                }
                if(found){
                    COVID19VRS.editPeople.IDNumText.setText(editC.getIDnumber());
                    COVID19VRS.editPeople.nameText.setText(editC.getName());
                    if(editC.isNationality()){
                        COVID19VRS.editPeople.cit.setSelected(true);
                    }else{
                        COVID19VRS.editPeople.nCit.setSelected(true);
                    }
                    COVID19VRS.editPeople.day.setSelectedItem(editC.getBirthDate().substring(0, editC.getBirthDate().indexOf('/')));
                    COVID19VRS.editPeople.month.setSelectedItem(editC.getBirthDate().substring(editC.getBirthDate().indexOf('/')+1, 
                            editC.getBirthDate().lastIndexOf('/')));
                    COVID19VRS.editPeople.year.setSelectedItem(editC.getBirthDate().substring(editC.getBirthDate().lastIndexOf('/')+1, 
                            editC.getBirthDate().length()));
                    if(editC.getGender().equals("Male")){
                        COVID19VRS.editPeople.male.setSelected(true);
                    }else{
                        COVID19VRS.editPeople.female.setSelected(true);
                    }
                    COVID19VRS.editPeople.addressText.setText(editC.getAddress());
                    COVID19VRS.editPeople.stateBox.setSelectedItem(editC.getState());
                    COVID19VRS.editPeople.phoneText.setText(editC.getPhoneNumber());
                    COVID19VRS.editPeople.emailText.setText(editC.getEmail());
                    COVID19VRS.editPeople.pass1.setText(editC.getPassword());
                    COVID19VRS.editPeople.pass2.setText(editC.getPassword());
                    setEnabled(false);
                    COVID19VRS.editPeople.setVisible(true);
                }else{
                    JOptionPane.showMessageDialog(null,"Account not exists!");
                }
            }catch(NullPointerException e1){
            }
        }else if(e.getSource()== delete){
            try{
                String DeleteC = JOptionPane.showInputDialog(null, "Enter people IC/Passport No. to delete: ");
                int i=0;
                People deleteC = null;
                boolean found = false;
                for(i=0; i<DataIO.allPeople.size(); i++){
                    People foundC = DataIO.allPeople.get(i);
                    if(DeleteC.equals(foundC.getIDnumber())){
                        deleteC = foundC;
                        found = true;
                        break;
                    }
                }
                if(found){
                    int out = JOptionPane.showConfirmDialog(null, "Confirm to delete people?\n- IC/Passport No.: "+ deleteC.getIDnumber()
                            +"\n- Name: "+deleteC.getName(), "Message", JOptionPane.YES_NO_OPTION);
                    if(out == JOptionPane.YES_OPTION){
                        for(int j=0; j<Dataio1.allAppointment.size(); j++){
                            if(DeleteC.equals(Dataio1.allAppointment.get(j).getPeople().getIDnumber())){
                                Dataio1.allAppointment.remove(j);
                                Dataio1.write();
                            }
                        }
                        DataIO.allPeople.remove(i);
                        DataIO.write();
                        if(searchText.getText().equals("")){
                            model = (DefaultTableModel) table.getModel();
                            model.removeRow(i);
                        }else if(searchText.getText().equals(DeleteC)){
                            String[][] data = tableData(DataIO.allPeople);
                            tableM = new DefaultTableModel(data, columnNames);
                            table.setModel(tableM);
                            tableStyle(table);
                            searchText.setText("");
                        }
                    }
                }else{
                    JOptionPane.showMessageDialog(null,"Account not exists!");
                }
            }catch(NullPointerException e1){
                //Do nothing
            }
        }else if(e.getSource()== logout){
            int out = JOptionPane.showConfirmDialog(null, "Continue to logout?", "Message", JOptionPane.YES_NO_OPTION);
            if(out == JOptionPane.YES_OPTION){
                setVisible(false);
                COVID19VRS.login.setVisible(true);
            }
        }
            
    }
    boolean flag = false;
    int arrayCount, tableCount;
    private People editC;
    private String[] columnNames;
    private Panel pc, pt, pw;
    private Button peopleInfo, vaccineApp, vaccineSup, report, comtInfo, viewAll, add, edit, delete, search, logout;
    private Label title, admin;
    private TextField searchText;
    private DefaultTableModel tableM, modelSearch;
    DefaultTableModel model;
    JTable table;
    public CommitteePeopleInfo(){
        setSize(1080, 720);
        setLocationRelativeTo(null);
        setTitle("Covid-19 Vaccine Registration System");
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
        vaccineApp = new Button("Vaccination Appoitment");
        vaccineApp.setBounds(0, 40, 200, 40);
        vaccineApp.setBackground(new Color(220,220,220));
        vaccineSup = new Button("Vaccine Supply");
        vaccineSup.setBounds(0, 80, 200, 40);
        vaccineSup.setBackground(new Color(220,220,220));
        report = new Button("Report");
        report.setBounds(0, 120, 200, 40);
        report.setBackground(new Color(220,220,220));
        comtInfo = new Button("Personnel of Committee Info");
        comtInfo.setBounds(0, 160, 200, 40);
        comtInfo.setBackground(new Color(220,220,220));
        pt.add(title);
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
//Table
        String[][] data = tableData(DataIO.allPeople);
        columnNames = new String[]{"IC/Passport No.", "Name", "Nationality", "Date of Birth", 
            "Age", "Gender", "Address", "State", "Phone Number", "Email Address"};
        tableM = new DefaultTableModel(data, columnNames);
        table = new JTable(tableM);
        tableStyle(table);
        JScrollPane sp = new JScrollPane(table);
        sp.setBounds(20,50,820,520);        
//Function
        viewAll = new Button("View All");
        viewAll.setBounds(20,15, 70, 25);
        viewAll.setBackground(new Color(220,220,220));
        add = new Button("Add");
        add.setBounds(620,590, 70, 25);
        add.setBackground(new Color(220,220,220));
        edit = new Button("Edit");
        edit.setBounds(695,590, 70, 25);
        edit.setBackground(new Color(220,220,220));
        delete = new Button("Delete");
        delete.setBounds(770,590, 70, 25);
        delete.setBackground(new Color(220,220,220));
        search = new Button("Search");
        search.setBounds(770,15, 70, 25);
        search.setBackground(new Color(220,220,220));
        logout = new Button("Logout");
        logout.setForeground(Color.white);
        logout.setBackground(new Color(0,0,128));
        logout.setBounds(970,15, 70, 25);
        searchText = new TextField();
        searchText.setBounds(565,15, 200, 25);
        viewAll.addActionListener(this);
        add.addActionListener(this);
        edit.addActionListener(this);
        delete.addActionListener(this);
        searchText.addActionListener(this);
        search.addActionListener(this);
        logout.addActionListener(this);
        pc.add(sp);
        pc.add(viewAll);
        pc.add(add);
        pc.add(edit);
        pc.add(delete);
        pc.add(search);
        pc.add(searchText);
        pt.add(logout);
        add(pc, BorderLayout.CENTER);
        add(pt, BorderLayout.NORTH);
        add(pw, BorderLayout.WEST);
        setResizable(false);
    }
    
    public String[][] tableData(ArrayList<People> allCitizen){
        int size = allCitizen.size();
        String[][] data = new String[size][10];
        for(int i=0; i<size; i++){
            People c = allCitizen.get(i);
            data[i][0] = c.getIDnumber();
            data[i][1] = ""+c.getName();
            String n = "Non Citizen";
            if(c.isNationality()){
                n = "Citizen";
            }
            data[i][2] = ""+n;
            data[i][3] = ""+c.getBirthDate();
            data[i][4] = ""+c.getAge();
            data[i][5] = ""+c.getGender();
            data[i][6] = ""+c.getAddress();
            data[i][7] = ""+c.getState();
            data[i][8] = ""+c.getPhoneNumber();
            data[i][9] = ""+c.getEmail();
        }
        return data;
    }
    
    public void tableStyle(JTable table){
        table.setRowHeight(25);
        table.getTableHeader().setBackground(new Color(220,220,220));
        table.getTableHeader().setPreferredSize(new Dimension(100, 25));
        table.getTableHeader().setFont(new Font(Font.DIALOG,Font.BOLD,12));
        table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
        table.getColumn(columnNames[0]).setPreferredWidth(120);
        table.getColumn(columnNames[1]).setPreferredWidth(120);
        table.getColumn(columnNames[2]).setPreferredWidth(120);
        table.getColumn(columnNames[3]).setPreferredWidth(110);
        table.getColumn(columnNames[4]).setPreferredWidth(60);
        table.getColumn(columnNames[5]).setPreferredWidth(80);
        table.getColumn(columnNames[6]).setPreferredWidth(350);
        table.getColumn(columnNames[7]).setPreferredWidth(100);
        table.getColumn(columnNames[8]).setPreferredWidth(120);
        table.getColumn(columnNames[9]).setPreferredWidth(150);
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment( JLabel.CENTER );
        table.getColumnModel().getColumn(2).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(3).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(4).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(5).setCellRenderer( centerRenderer );
    }      
}
