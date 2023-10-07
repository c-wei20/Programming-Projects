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
public class AddCentre extends JFrame implements ActionListener{
    public void actionPerformed(ActionEvent e){
        if(e.getSource()==submit){
            String def = "";
            String Name = nameText.getText();
            String State = (String)stateBox.getSelectedItem();
            if(Name.equals(def) || State.equals(def)){
                JOptionPane.showMessageDialog(null, "Incomplete information!");
            }else{
                int size = COVID19VRS.comtVaccineSup.ctSize;
                boolean found =false;
                for(int i=0; i<size; i++){
                    if(Name.equals(DataIO.allCentre.get(i).getName()) && State.equals(DataIO.allCentre.get(i).getState())){
                        found = true;
                        break;
                    }
                }
                if(found){
                    JOptionPane.showMessageDialog(null, "Centre record exsit!");
                    setVisible(false);
                    COVID19VRS.comtVaccineSup.setEnabled(true);
                }else{
                    int out = JOptionPane.showConfirmDialog(null, "Confirm the Following Information:\n\nCentre Name: "
                            +Name+"\nState: "+State+"\n", "Message", JOptionPane.YES_NO_OPTION);
                    if(out == JOptionPane.YES_OPTION){
                        Centre c = new Centre(Name, State);
                        DataIO.allCentre.add(c);
                        DataIO.write();
                        setVisible(false);
                        COVID19VRS.comtVaccineSup.setEnabled(true);
                        nameText.setText(def);
                        stateBox.setSelectedIndex(0);
                        COVID19VRS.comtVaccineSup.centre.addItem(Name);
                    }
                }
            }
        }else if(e.getSource()==clear){
            nameText.setText("");
            stateBox.setSelectedIndex(0);
        }else if(e.getSource()==cancel){
            setVisible(false);
            COVID19VRS.comtVaccineSup.setEnabled(true);
            nameText.setText("");
            stateBox.setSelectedIndex(0);
        }
    }
    private Panel panel;
    private Button submit, clear, cancel;
    private Label title, name, state;
    private TextField nameText;
    private JComboBox stateBox;
    private String[] states = {"Johor", "Kedah", "Kelatan", "Kuala Lumpur", "Malacca", "Negeri Sembilan",
        "Pahang", "Penang", "Perak", "Perlis", "Sabah", "Sarawak", "Selangor", "Terengganu"};
    public AddCentre(){
        setSize(500, 330);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setTitle("Covid-19 Vaccine Regiatration System");
        panel = new Panel();
        panel.setLayout(null);
        title = new Label("Add Vaccination Centre", Label.CENTER);
        title.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        title.setBounds(0, 20, 500, 30);
        name = new Label("Centre Name");
        name.setBounds(95, 90, 100, 20);
        nameText = new TextField();
        nameText.setBounds(200, 90, 200, 23);
        state = new Label("State");
        state.setBounds(95, 120, 100, 20);
        stateBox = new JComboBox(states);
        stateBox.setBounds(200, 120, 200, 23);
        submit = new Button("Submit");
        submit.setBounds(200, 230, 70, 25);
        clear = new Button("Clear");
        clear.setBounds(275, 230, 70, 25);
        cancel = new Button("Cancel");
        cancel.setBounds(350, 230, 70, 25);
        panel.add(title);
        panel.add(name);
        panel.add(state);
        panel.add(stateBox);
        panel.add(nameText);
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
