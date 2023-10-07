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
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
public class CommitteeVaccineSup extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == peopleInfo){
            COVID19VRS.comtPeopleInfo.setVisible(true);
            setVisible(false);
        }else if(e.getSource() == vaccineApp){
            COVID19VRS.comtVaccineApp.setVisible(true);
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
        }else if(e.getSource() == viewC){
            ctSize = DataIO.allCentre.size();
            cName = (String)centre.getSelectedItem();
            int j;
            for(j = 0; j < ctSize; j++){
                if(cName.equals(DataIO.allCentre.get(j).getName())){
                    break;
                }
            }
            centreData = DataIO.allCentre.get(j);
            currentCtN.setText("Centre Name: "+centreData.getName());
            currentCtS.setText("State: "+centreData.getState());
            String[][] data = tableData(centreData);
            tableM = new DefaultTableModel(data, columnNames);
            table.setModel(tableM);
            tableStyle(table);
        }else if(e.getSource() == addC){
            COVID19VRS.addCentre.setVisible(true);
            setEnabled(false);
        }else if(e.getSource() == deleteC){
            ctSize = DataIO.allCentre.size();
            ctName = new String[ctSize];
            for(int i=0; i<ctSize; i++){
                String name = DataIO.allCentre.get(i).getName();
                ctName[i] = name;
            }
            try{
                String select = (String)JOptionPane.showInputDialog(null,"Select the centre to delete", 
                        "Message", JOptionPane.PLAIN_MESSAGE,null,ctName, ctName[0]);
                int j;
                for(j = 0; j < ctSize; j++){
                    if(select.equals(DataIO.allCentre.get(j).getName())){
                        break;
                    }
                }
                int out = JOptionPane.showConfirmDialog(null, "Confirm to delete centre with the vaccine record?\n- Centre Name: "+ DataIO.allCentre.get(j).getName()
                            +"\n- State: "+DataIO.allCentre.get(j).getState(), "Message", JOptionPane.YES_NO_OPTION);
                    if(out == JOptionPane.YES_OPTION){
                        int v;
                        for(v=0; v<DataIO.allVaccine.size(); v++){
                            if(select.equals(DataIO.allVaccine.get(v).getCentre().getName())){
                                DataIO.allVaccine.remove(v);
                                v--;
                            }
                        }
                        DataIO.allCentre.remove(j);
                        DataIO.write();
                        centre.removeItem(select);
                        cName = (String)centre.getSelectedItem();
                        int n;
                        for(n = 0; n < ctSize; n++){
                            if(cName.equals(DataIO.allCentre.get(n).getName())){
                                break;
                            }
                        }
                        centreData = DataIO.allCentre.get(n);
                        currentCtN.setText("Centre Name: "+centreData.getName());
                        currentCtS.setText("State: "+centreData.getState());
                        String[][] data = tableData(centreData);
                        tableM = new DefaultTableModel(data, columnNames);
                        table.setModel(tableM);
                        tableStyle(table);
                    }
            }catch(NullPointerException e1){
            }
        }else if(e.getSource() == addV){
            COVID19VRS.addVaccine.centre.setText("Centre Name:         "+centreData.getName());
            COVID19VRS.addVaccine.setVisible(true);
            setEnabled(false);
        }else if(e.getSource() == editV){
            int vSize = centreData.getCentreVaccine().size();
            if (vSize == 0){
                JOptionPane.showMessageDialog(null, "There is no vaccine record in "+centreData.getName());
            }else{
                String[] vaccineList = new String[vSize];
                for(int i=0; i<vSize; i++){
                    vaccineList[i] = centreData.getCentreVaccine().get(i).getName();
                }
                try{
                    String select = (String)JOptionPane.showInputDialog(null,"Select the vaccine in "+centreData.getName()+" to edit\nVaccine:", 
                            "Message", JOptionPane.PLAIN_MESSAGE,null,vaccineList, vaccineList[0]);
                    Vaccine v = null;
                    for(int i = 0; i<vSize; i++){
                        v = centreData.getCentreVaccine().get(i);
                        if(select.equals(v.getName())){
                            tableVcIndex = i;
                            break;
                        }
                    }
                    for(int i = 0; i < DataIO.allVaccine.size(); i++){
                        if(select.equals(DataIO.allVaccine.get(i).getName())&&centreData.getName().equals(DataIO.allVaccine.get(i).getCentre().getName())){
                            arrayVcIndex = i;
                            break;
                        }
                    }
                    COVID19VRS.editVaccine.centre.setText("Centre Name:         "+centreData.getName());
                    COVID19VRS.editVaccine.codeText.setText(v.getCode());
                    COVID19VRS.editVaccine.nameText.setText(v.getName());
                    COVID19VRS.editVaccine.countryText.setText(v.getCountry());
                    COVID19VRS.editVaccine.dosText.setText(String.valueOf(v.getDosage()));
                    COVID19VRS.editVaccine.qtyText.setText(String.valueOf(v.getQuantity()));
                    COVID19VRS.editVaccine.setVisible(true);
                    setEnabled(false);
                }catch(NullPointerException e1){
                }
            }
        }else if(e.getSource() == deleteV){
            int vSize = centreData.getCentreVaccine().size();
            if (vSize == 0){
                JOptionPane.showMessageDialog(null, "There is no vaccine record in "+centreData.getName());
            }
            else{
                String[] vaccineList = new String[vSize];
                for(int i=0; i<vSize; i++){
                    vaccineList[i] = centreData.getCentreVaccine().get(i).getName();
                }
                try{
                    String select = (String)JOptionPane.showInputDialog(null,"Select the vaccine in "+centreData.getName()+" to delete\nVaccine:", 
                            "Message", JOptionPane.PLAIN_MESSAGE,null,vaccineList, vaccineList[0]);
                    int i;
                    for(i = 0; i < DataIO.allVaccine.size(); i++){
                        if(select.equals(DataIO.allVaccine.get(i).getName())&&centreData.getName().equals(DataIO.allVaccine.get(i).getCentre().getName())){
                            break;
                        }
                    }
                    int j;
                    for(j = 0; j < vSize; j++){
                        if(select.equals(centreData.getCentreVaccine().get(j).getName())){
                            break;
                        }
                    }
                    int out = JOptionPane.showConfirmDialog(null, "Confirm to delete the vaccine record?\n- Centre Name: "+ centreData.getName()
                            +"\n- Vaccine Code: "+centreData.getCentreVaccine().get(j).getCode()
                            +"\n- Vaccine Name: "+centreData.getCentreVaccine().get(j).getName(), "Message", JOptionPane.YES_NO_OPTION);
                    if(out == JOptionPane.YES_OPTION){
                        DataIO.allVaccine.remove(i);
                        DataIO.write();
                        model = (DefaultTableModel) table.getModel();
                        model.removeRow(j);
                        centreData.getCentreVaccine().remove(j);
                    }
                }catch(NullPointerException e1){
                }  
            }
        }else if(e.getSource()== search || e.getSource() == searchText){
            ctSize = DataIO.allCentre.size();
            String searchC = searchText.getText();
            if(searchC.equals("")){
                //Do nothing
            }else{
                int j;
                boolean found = false;
                for(j = 0; j < ctSize; j++){
                    if(searchC.equals(DataIO.allCentre.get(j).getName())){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    JOptionPane.showMessageDialog(null, "No centre information found!");
                }else{
                    centreData = DataIO.allCentre.get(j);
                    currentCtN.setText("Centre Name: "+centreData.getName());
                    currentCtS.setText("State: "+centreData.getState());
                    String[][] data = tableData(centreData);
                    tableM = new DefaultTableModel(data, columnNames);
                    table.setModel(tableM);
                    tableStyle(table);
                    centre.setSelectedItem(DataIO.allCentre.get(j).getName());
                }
            }
        }else if(e.getSource()== logout){
            int out = JOptionPane.showConfirmDialog(null, "Continue to logout?", "Message", JOptionPane.YES_NO_OPTION);
            if(out == JOptionPane.YES_OPTION){
                setVisible(false);
                COVID19VRS.login.setVisible(true);
            }
        }
    }
    Centre centreData = null;
    private String[] columnNames;
    int ctSize, arrayVcIndex, tableVcIndex;
    private String cName;
    private String[] ctName;
    private Panel pc, pt, pw, centreInfo;
    private Button peopleInfo, vaccineApp, vaccineSup, report, comtInfo, addV, editV, deleteV, viewC, addC, deleteC, search, logout;
    private Label title, selectCentre, currentCtN, currentCtS;
    private TextField searchText;
    JComboBox centre;
    private DefaultTableModel tableM, modelSearch;
    DefaultTableModel model;
    JTable table;
    public CommitteeVaccineSup(){
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
        vaccineApp.setBackground(new Color(220,220,220));
        vaccineSup = new Button("Vaccine Supply");
        vaccineSup.setBounds(0, 80, 200, 40);
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
        selectCentre = new Label("Select Centre");
        selectCentre.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        selectCentre.setBounds(20,17, 80, 22);
        ctSize = DataIO.allCentre.size();
        ctName = new String[ctSize];
        for(int i=0; i<ctSize; i++){
            String name = DataIO.allCentre.get(i).getName();
            ctName[i] = name;
        }
        centre = new JComboBox(ctName);
        centre.setBounds(110,14, 160, 25);
        cName = (String)centre.getSelectedItem();
        int j;
        for(j = 0; j < ctSize; j++){
            if(cName.equals(DataIO.allCentre.get(j).getName())){
                break;
            }
        }
        centreData = DataIO.allCentre.get(j);
        centreInfo = new Panel();
        centreInfo.setLayout(null);
        centreInfo.setBackground(new Color(220,220,220));
        centreInfo.setBounds(20,50,820,30);
        currentCtN = new Label("Centre Name: "+centreData.getName());
        currentCtN.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        currentCtS = new Label("State: "+centreData.getState());
        currentCtS.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        currentCtN.setBounds(15, 0, 300, 30);
        currentCtS.setBounds(330, 0, 300, 30);
        centreInfo.add(currentCtN);
        centreInfo.add(currentCtS);
        pt.add(title);
        pt.add(logout);
        pw.add(peopleInfo);
        pw.add(vaccineApp);
        pw.add(vaccineSup);
        pw.add(report);
        pw.add(comtInfo);
        pc.add(centre);
        pc.add(selectCentre);
        pc.add(centreInfo);
        peopleInfo.addActionListener(this); 
        vaccineApp.addActionListener(this); 
        vaccineSup.addActionListener(this); 
        report.addActionListener(this); 
        comtInfo.addActionListener(this);
        logout.addActionListener(this);
//Table
        String[][] data = tableData(centreData);
        columnNames = new String[]{"Vaccine code", "Vaccine", "Country", "Dosage", "Quantity"};
        tableM = new DefaultTableModel(data, columnNames);
        table = new JTable(tableM);
        tableStyle(table);
        JScrollPane sp = new JScrollPane(table);
        sp.setBounds(20,85,820,465);
//Function 
        viewC = new Button("View");
        viewC.setBounds(270,14, 80, 25);
        viewC.setBackground(new Color(220,220,220));
        addC = new Button("Add Centre");
        addC.setBounds(365,14, 80, 25);
        addC.setBackground(new Color(220,220,220));
        deleteC = new Button("Delete Centre");
        deleteC.setBounds(450,14, 80, 25);
        deleteC.setBackground(new Color(220,220,220));
        addV = new Button("Add Vaccine");
        addV.setBounds(560,590, 90, 25);
        addV.setBackground(new Color(220,220,220));
        editV = new Button("Edit Vaccine");
        editV.setBounds(655,590, 90, 25);
        editV.setBackground(new Color(220,220,220));
        deleteV = new Button("Delete Vaccine");
        deleteV.setBounds(750,590, 90, 25);
        deleteV.setBackground(new Color(220,220,220));
        search = new Button("Search");
        search.setBounds(770,15, 70, 25);
        search.setBackground(new Color(220,220,220));
        searchText = new TextField();
        searchText.setBounds(565,15, 200, 25);
        viewC.addActionListener(this);
        addC.addActionListener(this);
        deleteC.addActionListener(this);
        addV.addActionListener(this);
        editV.addActionListener(this);
        deleteV.addActionListener(this);
        search.addActionListener(this);
        searchText.addActionListener(this);
        pc.add(sp);
        pc.add(viewC);
        pc.add(addC);
        pc.add(deleteC);
        pc.add(addV);
        pc.add(editV);
        pc.add(deleteV);
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
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment( JLabel.CENTER );
        table.getColumnModel().getColumn(0).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(2).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(3).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(4).setCellRenderer( centerRenderer );
    }
    
    public String[][] tableData(Centre centreData){
        int size = centreData.getCentreVaccine().size();
        String[][] data = new String[size][5];
        for(int i=0; i<size; i++){
            Vaccine v = centreData.getCentreVaccine().get(i);
            data[i][0] = v.getCode();
            data[i][1] = ""+v.getName();
            data[i][2] = ""+v.getCountry();
            data[i][3] = ""+v.getDosage();
            data[i][4] = ""+v.getQuantity();
        }
        return data;
    }
}
