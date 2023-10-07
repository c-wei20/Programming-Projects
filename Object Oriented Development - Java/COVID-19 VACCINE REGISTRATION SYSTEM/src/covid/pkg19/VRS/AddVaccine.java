package covid.pkg19.VRS;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Font;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
public class AddVaccine extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource()==submit){
            String def = "";
            String Code = codeText.getText();
            String Name = nameText.getText();
            String Country = countryText.getText();
            String ctVCode, ctVName;
            int Dos = 0, Qty = 0;
            boolean check = false, found = false;
            try{
                Dos = Integer.parseInt(dosText.getText());
                Qty = Integer.parseInt(qtyText.getText());
            }catch(Exception e1){
                check = true;
            }
            for(int i = 0; i<COVID19VRS.comtVaccineSup.centreData.getCentreVaccine().size(); i++){
                ctVCode = COVID19VRS.comtVaccineSup.centreData.getCentreVaccine().get(i).getCode();
                ctVName = COVID19VRS.comtVaccineSup.centreData.getCentreVaccine().get(i).getName();
                if(Code.equals(ctVCode) && Name.equals(ctVName)){
                    found = true;
                    break;
                }
            }
            if(Code.equals(def)||Name.equals(def)||Country.equals(def)){
                JOptionPane.showMessageDialog(null, "Incomplete information!");
            }else if(check){
                JOptionPane.showMessageDialog(null, "Input Error!\nDosage and quantity must be a value!");
            }else if(found){
                JOptionPane.showMessageDialog(null, "Vaccine record exsit in the vaccination centre!");
                setVisible(false);
                COVID19VRS.comtVaccineSup.setEnabled(true);
            }else{
                int out = JOptionPane.showConfirmDialog(null, "Confirm the Following Information:\n\nCentre Name: "
                        +COVID19VRS.comtVaccineSup.centreData.getName()+"\nVaccine: "+Name+"\nDosage: "+Dos+"\nQuantity: "+Qty, "Message", JOptionPane.YES_NO_OPTION);
                if(out == JOptionPane.YES_OPTION){
                    Vaccine v = new Vaccine(Code, Name, Country, Dos, Qty, COVID19VRS.comtVaccineSup.centreData);
                    DataIO.allVaccine.add(v);
                    COVID19VRS.comtVaccineSup.centreData.getCentreVaccine().add(v);
                    DataIO.write();
                    COVID19VRS.comtVaccineSup.model = (DefaultTableModel) COVID19VRS.comtVaccineSup.table.getModel();
                    COVID19VRS.comtVaccineSup.model.addRow(new Object[]{v.getCode(),v.getName(),v.getCountry(),v.getDosage(),v.getQuantity()});
                    setVisible(false);
                    COVID19VRS.comtVaccineSup.setEnabled(true);
                    codeText.setText("");
                    nameText.setText("");
                    countryText.setText("");
                    dosText.setText("");
                    qtyText.setText("");
                }
            }
        }else if(e.getSource()==clear){
            codeText.setText("");
            nameText.setText("");
            countryText.setText("");
            dosText.setText("");
            qtyText.setText("");
        }else if(e.getSource()==cancel){
            setVisible(false);
            COVID19VRS.comtVaccineSup.setEnabled(true);
            codeText.setText("");
            nameText.setText("");
            countryText.setText("");
            dosText.setText("");
            qtyText.setText("");
        }
    }
    private Panel panel;
    private Button submit, clear, cancel;
    private Label title, code, name, country, dos, qty;
    Label centre;
    private TextField codeText, nameText, countryText, dosText, qtyText;
    public AddVaccine(){
        setSize(500, 330);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setTitle("Covid-19 Vaccine Regiatration System");
        panel = new Panel();
        panel.setLayout(null);
        title = new Label("Add Vaccine", Label.CENTER);
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setBounds(0, 20, 500, 30);
        centre = new Label("Centre Name:         "+COVID19VRS.comtVaccineSup.centreData.getName());
        centre.setFont(new Font(Font.DIALOG, Font.BOLD, 12));
        centre.setBounds(95, 60, 300, 20);
        code = new Label("Vaccine Code");
        code.setBounds(95, 90, 100, 20);
        codeText = new TextField();
        codeText.setBounds(200, 90, 200, 23);
        name = new Label("Vaccine Name");
        name.setBounds(95, 120, 100, 20);
        nameText = new TextField();
        nameText.setBounds(200, 120, 200, 23);
        country = new Label("Country");
        country.setBounds(95, 150, 100, 20);
        countryText = new TextField();
        countryText.setBounds(200, 150, 200, 23);
        dos = new Label("Dosage");
        dos.setBounds(95, 180, 100, 20);
        dosText = new TextField();
        dosText.setBounds(200, 180, 200, 23);
        qty = new Label("Quantity");
        qty.setBounds(95, 210, 100, 20);
        qtyText = new TextField();
        qtyText.setBounds(200, 210, 200, 23);
        submit = new Button("Submit");
        submit.setBounds(200, 250, 70, 25);
        clear = new Button("Clear");
        clear.setBounds(275, 250, 70, 25);
        cancel = new Button("Cancel");
        cancel.setBounds(350, 250, 70, 25);
        panel.add(title);
        panel.add(centre);
        panel.add(code);
        panel.add(codeText);
        panel.add(name);
        panel.add(nameText);
        panel.add(country);
        panel.add(countryText);
        panel.add(dos);
        panel.add(dosText);
        panel.add(qty);
        panel.add(qtyText);
        panel.add(submit);
        panel.add(clear);
        panel.add(cancel);
        submit.addActionListener(this);
        clear.addActionListener(this);
        cancel.addActionListener(this);
        add(panel, BorderLayout.CENTER);
        setResizable(false);
    }
}
