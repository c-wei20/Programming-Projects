package covid.pkg19.VRS;
import java.util.ArrayList;
public class Committee {
    private String id, name, gender, phone, password;
    private ArrayList<Appointment> appointments = new ArrayList<Appointment>();
    public Committee(String id, String name, String gender, String phone, String password) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        this.phone = phone;
        this.password = password;
    }
    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getGender() {
        return gender;
    }
    public void setGender(String gender) {
        this.gender = gender;
    }
    public String getPhone() {
        return phone;
    }
    public void setPhone(String phone) {
        this.phone = phone;
    }
    public String getPassword() {
        return password;
    }
    public void setPassword(String password) {
        this.password = password;
    }
    public ArrayList<Appointment> getAppointments() {
        return appointments;
    }
    public void setAppointments(ArrayList<Appointment> appointments) {      //assosiation
        this.appointments = appointments;
    }
}
