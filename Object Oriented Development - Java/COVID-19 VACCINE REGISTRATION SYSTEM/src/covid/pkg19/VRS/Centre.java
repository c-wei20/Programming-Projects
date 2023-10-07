package covid.pkg19.VRS;
import java.util.ArrayList;
public class Centre {
    private String name, state;
    private ArrayList<Vaccine> centreVaccine = new ArrayList<Vaccine>();
    public Centre(String name, String state) {
        this.name = name;
        this.state = state;
    } 
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getState() {
        return state;
    }
    public void setState(String state) {
        this.state = state;
    }
    public ArrayList<Vaccine> getCentreVaccine() {      //assosiation
        return centreVaccine;
    }
    public void setCentreVaccine(ArrayList<Vaccine> centreVaccine) {
        this.centreVaccine = centreVaccine;
    }
}
