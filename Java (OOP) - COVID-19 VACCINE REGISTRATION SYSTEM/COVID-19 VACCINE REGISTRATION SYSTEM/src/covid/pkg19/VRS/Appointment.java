package covid.pkg19.VRS;
public class Appointment {
    private int id;
    private String currentaddress;
    private String State;
    private String healthstatus;                    //q1
    private String agreestatement;                  //q2
    private String Date1,time1, Date2, time2;
    private Boolean Status,Dose1,Dose2;
    private String Vaccine;
    private Centre Center;
    private People people;
    public Appointment(int id, String currentaddress, String State, String healthstatus, 
            String agreestatement, String Date1, String time1, String Date2, String time2, 
            Boolean Status, Boolean Dose1, Boolean Dose2, String Vaccine, Centre Center, People people) {
        this.id = id;
        this.currentaddress = currentaddress;
        this.State = State;
        this.healthstatus = healthstatus;
        this.agreestatement = agreestatement;
        this.Date1 = Date1;
        this.time1 = time1;
        this.Date2 = Date2;
        this.time2 = time2;
        this.Status = Status;
        this.Dose1 = Dose1;
        this.Dose2 = Dose2;
        this.Vaccine = Vaccine;
        this.Center = Center;       //aggregation
        this.people = people;       //aggregation
    }
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getCurrentaddress() {
        return currentaddress;
    }

    public void setCurrentaddress(String currentaddress) {
        this.currentaddress = currentaddress;
    }

    public String getState() {
        return State;
    }

    public void setState(String State) {
        this.State = State;
    }

    public String getHealthstatus() {
        return healthstatus;
    }

    public void setHealthstatus(String healthstatus) {
        this.healthstatus = healthstatus;
    }

    public String getAgreestatement() {
        return agreestatement;
    }

    public void setAgreestatement(String agreestatement) {
        this.agreestatement = agreestatement;
    }

    public String getDate1() {
        return Date1;
    }

    public void setDate1(String Date1) {
        this.Date1 = Date1;
    }

    public String getTime1() {
        return time1;
    }

    public void setTime1(String time1) {
        this.time1 = time1;
    }

    public String getDate2() {
        return Date2;
    }

    public void setDate2(String Date2) {
        this.Date2 = Date2;
    }

    public String getTime2() {
        return time2;
    }

    public void setTime2(String time2) {
        this.time2 = time2;
    }

    public Boolean getStatus() {
        return Status;
    }

    public void setStatus(Boolean Status) {
        this.Status = Status;
    }

    public Boolean getDose1() {
        return Dose1;
    }

    public void setDose1(Boolean Dose1) {
        this.Dose1 = Dose1;
    }

    public Boolean getDose2() {
        return Dose2;
    }

    public void setDose2(Boolean Dose2) {
        this.Dose2 = Dose2;
    }

    public String getVaccine() {
        return Vaccine;
    }

    public void setVaccine(String Vaccine) {
        this.Vaccine = Vaccine;
    }

    public Centre getCenter() {
        return Center;
    }

    public void setCenter(Centre Center) {
        this.Center = Center;
    }

    public People getPeople() {
        return people;
    }

    public void setPeople(People people) {
        this.people = people;
    }
    
    


        
   
 
   
}
