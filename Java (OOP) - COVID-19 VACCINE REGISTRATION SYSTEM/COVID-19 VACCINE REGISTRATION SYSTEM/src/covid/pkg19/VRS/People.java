package covid.pkg19.VRS;
public class People{
    private String name, IDnumber, birthDate, gender, address, state, phoneNumber, email, password;
    private int age;
    private boolean nationality;
    private Appointment myAppointment;
    
    public People(String IDnumber, boolean nationality, String name, String birthDate, int age, String gender, 
            String address, String state, String phoneNumber, String email, String password) {
        this.name = name;
        this.IDnumber = IDnumber;
        this.birthDate = birthDate;
        this.gender = gender;
        this.address = address;
        this.state = state;
        this.phoneNumber = phoneNumber;
        this.email = email;
        this.password = password;
        this.age = age;
        this.nationality = nationality;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getAddress() {
        return address;
    }
    public void setAddress(String address) {
        this.address = address;
    }
    public String getPhoneNumber() {
        return phoneNumber;
    }
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public String getBirthDate() {
        return birthDate;
    }
    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }
    public String getPassword() {
        return password;
    }
    public void setPassword(String password) {
        this.password = password;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public String getGender() {
        return gender;
    }
    public void setGender(String gender) {
        this.gender = gender;
    }
    public String getState() {
        return state;
    }
    public void setState(String state) {
        this.state = state;
    }
    public String getIDnumber() {
        return IDnumber;
    }
    public void setIDnumber(String IDnumber) {
        this.IDnumber = IDnumber;
    } 
    public boolean isNationality() {
        return nationality;
    }
    public void setNationality(boolean nationality) {
        this.nationality = nationality;
    }
    public Appointment getMyAppointment() {     //assosiation
        return myAppointment;
    }
    public void setMyAppointment(Appointment myAppointment) {
        this.myAppointment = myAppointment;
    }
}
