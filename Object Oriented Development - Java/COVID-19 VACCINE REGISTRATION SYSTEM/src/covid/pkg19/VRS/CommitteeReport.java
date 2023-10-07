package covid.pkg19.VRS;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Label;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
public class CommitteeReport extends JFrame implements ActionListener{
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
        }else if(e.getSource()== logout){
            int out = JOptionPane.showConfirmDialog(null, "Continue to logout?", "Message", JOptionPane.YES_NO_OPTION);
            if(out == JOptionPane.YES_OPTION){
                setVisible(false);
                COVID19VRS.login.setVisible(true);
            }
        }else if(e.getSource() == generate){
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("uuuu/MM/dd");
            LocalDate Date = LocalDate.now();
            dtf = DateTimeFormatter.ofPattern("HH:mm:ss");
            LocalTime Time = LocalTime.now();
            if(reportBox.getSelectedIndex()==0){
                reportName.setText("People Gender Report");
                date.setText("Date: "+Date);
                time.setText("Time: "+Time);
                int total=0, male=0, female=0;
                for(int i=0; i<DataIO.allPeople.size(); i++){
                    if(DataIO.allPeople.get(i).getGender().equals("Male")){
                        male++;
                    }else{
                        female++;
                    }
                    total++;
                }
                data[0][0] = "Male";
                data[0][1] = String.valueOf(male);
                data[0][2] = String.valueOf(((float)male/(float)total)*100);
                data[1][0] = "Female";
                data[1][1] = String.valueOf(female);
                data[1][2] = String.valueOf(((float)female/(float)total)*100);
                data[2][0] = "Total number of people";
                data[2][1] = String.valueOf(total);
                data[2][2] = "100";
                tableM = new DefaultTableModel(data, columnNames);
                table.setModel(tableM);
                DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
                centerRenderer.setHorizontalAlignment( JLabel.CENTER );
                table.getColumnModel().getColumn(1).setCellRenderer( centerRenderer );
                table.getColumnModel().getColumn(2).setCellRenderer( centerRenderer );
            }else if(reportBox.getSelectedIndex()==1){
                reportName.setText("People Nationality Report");
                date.setText("Date: "+Date);
                time.setText("Time: "+Time);
                int total=0, cit=0, nCit=0;
                for(int i=0; i<DataIO.allPeople.size(); i++){
                    if(DataIO.allPeople.get(i).isNationality()){
                        cit++;
                    }else{
                        nCit++;
                    }
                    total++;
                }
                data[0][0] = "Citizen";
                data[0][1] = String.valueOf(cit);
                data[0][2] = String.valueOf(((float)cit/(float)total)*100);
                data[1][0] = "Non Citizen";
                data[1][1] = String.valueOf(nCit);
                data[1][2] = String.valueOf(((float)nCit/(float)total)*100);
                data[2][0] = "Total number of people";
                data[2][1] = String.valueOf(total);
                data[2][2] = "100";
                tableM = new DefaultTableModel(data, columnNames);
                table.setModel(tableM);
                DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
                centerRenderer.setHorizontalAlignment( JLabel.CENTER );
                table.getColumnModel().getColumn(1).setCellRenderer( centerRenderer );
                table.getColumnModel().getColumn(2).setCellRenderer( centerRenderer );
            }else{
                reportName.setText("People Vaccination Report");
                date.setText("Date: "+Date);
                time.setText("Time: "+Time);
                int total=0, dos1=0, dos2=0;
                for(int i=0; i<Dataio1.allAppointment.size(); i++){
                    if(Dataio1.allAppointment.get(i).getDose1()){
                        dos1++;
                    }
                    if(Dataio1.allAppointment.get(i).getDose2()){
                        dos2++;
                    }
                    total++;
                }
                data[0][0] = "Complete Dose 1";
                data[0][1] = String.valueOf(dos1);
                data[0][2] = String.valueOf(((float)dos1/(float)total)*100);
                data[1][0] = "Complete Dose 2";
                data[1][1] = String.valueOf(dos2);
                data[1][2] = String.valueOf(((float)dos2/(float)total)*100);
                data[2][0] = "Total vaccination registration";
                data[2][1] = String.valueOf(total);
                data[2][2] = "100";
                tableM = new DefaultTableModel(data, columnNames);
                table.setModel(tableM);
                DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
                centerRenderer.setHorizontalAlignment( JLabel.CENTER );
                table.getColumnModel().getColumn(1).setCellRenderer( centerRenderer );
                table.getColumnModel().getColumn(2).setCellRenderer( centerRenderer );
            }
        }
    }
    private Panel pc, pt, pw, rp;
    private Button peopleInfo, vaccineApp, vaccineSup, report, comtInfo, logout, generate;
    private JComboBox reportBox;
    private String[] reportType;
    private Label title, select, reportName, date, time;
    private String[][] data;
    private String[] columnNames;
    private DefaultTableModel tableM;
    private JTable table;
    public CommitteeReport(){
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
        vaccineSup.setBackground(new Color(220,220,220));
        report = new Button("Report");
        report.setBounds(0, 120, 200, 40);
        comtInfo = new Button("Personnel of Committee Info");
        comtInfo.setBounds(0, 160, 200, 40);
        comtInfo.setBackground(new Color(220,220,220));
        logout = new Button("Logout");
        logout.setForeground(Color.white);
        logout.setBackground(new Color(0,0,128));
        logout.setBounds(970,15, 70, 25);
        select = new Label("Select Report");
        select.setBounds(20, 10, 90, 25);
        select.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        reportType = new String[]{"People Gender Report", "People Nationality Report", "People Vaccination Report"};
        reportBox = new JComboBox(reportType);
        reportBox.setBounds(110, 10, 200, 25);
        generate = new Button("Generate");
        generate.setBounds(310, 10, 80, 25);
        generate.setBackground(new Color(220,220,220));
        rp = new Panel();
        rp.setLayout(null);
        rp.setBounds(20,50,820, 520);
        rp.setBackground(Color.white);
        reportName = new Label("Report", Label.CENTER);
        reportName.setBounds(0, 20, 820, 25);
        reportName.setFont(new Font(Font.DIALOG, Font.BOLD, 14));
        date = new Label("Date: ", Label.CENTER);
        date.setBounds(0, 50, 820, 25);
        date.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        time = new Label("Time: ", Label.CENTER);
        time.setBounds(0, 80, 820, 25);
        time.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        pt.add(title);
        pt.add(logout);
        pw.add(peopleInfo);
        pw.add(vaccineApp);
        pw.add(vaccineSup);
        pw.add(report);
        pw.add(comtInfo);
        pc.add(select);
        pc.add(reportBox);
        pc.add(generate);
        pc.add(rp);
        rp.add(reportName);
        rp.add(date);
        rp.add(time);
    //Table
        data = new String[3][3];
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("uuuu/MM/dd");
        LocalDate Date = LocalDate.now();
        dtf = DateTimeFormatter.ofPattern("HH:mm:ss");
        LocalTime Time = LocalTime.now();
        reportName.setText("People Gender Report");
        date.setText("Date: "+Date);
        time.setText("Time: "+Time);
        int total=0, male=0, female=0;
        for(int i=0; i<DataIO.allPeople.size(); i++){
            if(DataIO.allPeople.get(i).getGender().equals("Male")){
                male++;
            }else{
                female++;
            }
            total++;
        }
        data[0][0] = "Male";
        data[0][1] = String.valueOf(male);
        data[0][2] = String.valueOf(((float)male/(float)total)*100);
        data[1][0] = "Female";
        data[1][1] = String.valueOf(female);
        data[1][2] = String.valueOf(((float)female/(float)total)*100);
        data[2][0] = "Total number of people";
        data[2][1] = String.valueOf(male);
        data[2][2] = "100";
        columnNames = new String[]{" ", "Amonut", "Percentage(%)"};
        tableM = new DefaultTableModel(data, columnNames);
        table = new JTable(tableM);
        table.setRowHeight(30);
        table.getTableHeader().setBackground(new Color(220,220,220));
        table.getTableHeader().setPreferredSize(new Dimension(100, 30));
        table.getTableHeader().setFont(new Font(Font.DIALOG,Font.BOLD,12));
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment( JLabel.CENTER );
        table.getColumnModel().getColumn(1).setCellRenderer( centerRenderer );
        table.getColumnModel().getColumn(2).setCellRenderer( centerRenderer );
        JScrollPane sp = new JScrollPane(table);
        sp.setBounds(110, 120, 600, 123);
        rp.add(sp);
        
        peopleInfo.addActionListener(this); 
        vaccineApp.addActionListener(this); 
        vaccineSup.addActionListener(this); 
        report.addActionListener(this); 
        comtInfo.addActionListener(this);
        logout.addActionListener(this);
        generate.addActionListener(this);
        add(pc, BorderLayout.CENTER);
        add(pt, BorderLayout.NORTH);
        add(pw, BorderLayout.WEST);
        setResizable(false);
    }  
}
