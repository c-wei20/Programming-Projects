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
public class CommitteeInfo extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == peopleInfo){
            COVID19VRS.comtPeopleInfo.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == vaccineApp){
            COVID19VRS.comtVaccineApp.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == vaccineSup){
            COVID19VRS.comtVaccineSup.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == report){
            COVID19VRS.comtReport.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == viewAll){
            String[][] data = tableData(DataIO.allCommittee);
            tableM = new DefaultTableModel(data, columnNames);
            table.setModel(tableM);
            tableStyle(table);
            searchText.setText("");
        }else if(e.getSource() == search || e.getSource() == searchText){
            String[][] searchData;
            Committee searchC = null;
            String Search = searchText.getText();
            String def = "";
            if(Search.equals(def)){
                String[][] data = tableData(DataIO.allCommittee);
                tableM = new DefaultTableModel(data, columnNames);
                table.setModel(tableM);
                tableStyle(table);
            }else{
                boolean found = false;
                for(int i=0; i<DataIO.allCommittee.size(); i++){
                    searchC = DataIO.allCommittee.get(i);
                    if(Search.equals(searchC.getId())){
                        found = true;
                    }
                }
                if(!found){
                    JOptionPane.showMessageDialog(null, "No personnel of committee information found!");
                }else{
                    searchData = new String[1][9];
                    for(int j=0; j<DataIO.allCommittee.size(); j++){
                        searchC = DataIO.allCommittee.get(j);
                        if(Search.equals(searchC.getId())){
                            searchData[0][0] = searchC.getId();
                            searchData[0][1] = ""+searchC.getName();
                            searchData[0][2] = ""+searchC.getGender();
                            searchData[0][3] = ""+searchC.getPhone();
                            searchData[0][4] = ""+searchC.getPassword();
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
            COVID19VRS.registerComt.setVisible(true);
            setEnabled(false); 
        }else if(e.getSource()== edit){
            String EditC = JOptionPane.showInputDialog(null, "Enter personnel ID to edit: ");
            boolean found = false;
            try{
                for(int i=0; i<DataIO.allCommittee.size(); i++){
                    editC = DataIO.allCommittee.get(i);
                    if(EditC.equals(editC.getId())){
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
                    COVID19VRS.editComt.idText.setText(editC.getId());
                    COVID19VRS.editComt.nameText.setText(editC.getName());
                    if(editC.getGender().equals("Male")){
                        COVID19VRS.editComt.male.setSelected(true);
                    }else{
                        COVID19VRS.editComt.female.setSelected(true);
                    }
                    COVID19VRS.editComt.phoneText.setText(editC.getPhone());
                    COVID19VRS.editComt.pass1.setText(editC.getPassword());
                    COVID19VRS.editComt.pass2.setText(editC.getPassword());
                    setEnabled(false);
                    COVID19VRS.editComt.setVisible(true);
                }else{
                    JOptionPane.showMessageDialog(null,"Account not exists!");
                }
            }catch(NullPointerException e1){
            }
        }else if(e.getSource()== delete){
            try{
                String DeleteC = JOptionPane.showInputDialog(null, "Enter personnel Id to delete: ");
                int i=0;
                Committee deleteC = null;
                boolean found = false;
                for(i=0; i<DataIO.allCommittee.size(); i++){
                    Committee foundC = DataIO.allCommittee.get(i);
                    if(DeleteC.equals(foundC.getId())){
                        deleteC = foundC;
                        found = true;
                        break;
                    }
                }
                if(found){
                    int out = JOptionPane.showConfirmDialog(null, "Confirm to delete personnel?\n- ID: "+ deleteC.getId()
                            +"\n- Name: "+deleteC.getName(), "Message", JOptionPane.YES_NO_OPTION);
                    if(out == JOptionPane.YES_OPTION){
                        DataIO.allCommittee.remove(i);
                        DataIO.write();
                        if(searchText.getText().equals("")){
                            model = (DefaultTableModel) table.getModel();
                            model.removeRow(i);
                        }else if(searchText.getText().equals(DeleteC)){
                            String[][] data = tableData(DataIO.allCommittee);
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
    private Committee editC;
    private String[] columnNames;
    private Panel pc, pt, pw;
    private Button peopleInfo, vaccineApp, vaccineSup, report, comtInfo, viewAll, add, edit, delete, search, logout;
    private Label title, admin;
    private TextField searchText;
    private DefaultTableModel tableM, modelSearch;
    DefaultTableModel model;
    JTable table;
    public CommitteeInfo(){
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
//        admin = new Label("Admin: "+COVID19VRS.loginComt.getName()+" | "+COVID19VRS.loginComt.getId(), Label.RIGHT);
//        admin.setForeground(Color.white);
//        admin.setBounds(650,20,300, 20);
        pw = new Panel();
        pw.setBackground(new Color(220,220,220));
        pw.setLayout(null);
        pw.setSize(200, 720);
        peopleInfo = new Button("People Information");
        peopleInfo.setBounds(0, 0, 200, 40);
        peopleInfo.setBackground(new Color(220,220,220));
        vaccineApp = new Button("Vaccination Appoitment");
        vaccineApp.setBounds(0, 40, 200, 40);
        vaccineApp.setBackground(new Color(220,220,220));
        vaccineSup = new Button("Vaccine Supply");
        vaccineSup.setBounds(0, 80, 200, 40);
        vaccineSup.setBackground(new Color(220,220,220));
        report = new Button("Report");
        report.setBounds(0, 120, 200, 40);
        report.setBackground(new Color(220,220,220));
        comtInfo = new Button("Add New Committee");
        comtInfo.setBounds(0, 160, 200, 40);
        pt.add(title);
//        pt.add(admin);
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
        String[][] data = tableData(DataIO.allCommittee);
        columnNames = new String[]{"Personnel ID", "Name", "Gender", "Phone Number", "Password"};
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
    
    public String[][] tableData(ArrayList<Committee> allCommittee){
        int size = allCommittee.size();
        String[][] data = new String[size][9];
        for(int i=0; i<size; i++){
            Committee c = allCommittee.get(i);
            data[i][0] = c.getId();
            data[i][1] = ""+c.getName();
            data[i][2] = ""+c.getGender();
            data[i][3] = ""+c.getPhone();
            data[i][4] = ""+c.getPassword();
        }
        return data;
    }
    
    public void tableStyle(JTable table){
        table.setRowHeight(25);
        table.getTableHeader().setBackground(new Color(220,220,220));
        table.getTableHeader().setPreferredSize(new Dimension(100, 25));
        table.getTableHeader().setFont(new Font(Font.DIALOG,Font.BOLD,12));
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment( JLabel.CENTER );
        table.getColumnModel().getColumn(0).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(2).setCellRenderer( centerRenderer );
    }
}
