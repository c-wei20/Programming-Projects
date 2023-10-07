package covid.pkg19.VRS;
public class Vaccine {
    private String code, name, country;
    private int dosage, quantity;
    private Centre centre;
    public Vaccine(String code, String name, String country, int dosage, int quantity, Centre centre) {
        this.code = code;
        this.name = name;
        this.country = country;
        this.dosage = dosage;
        this.quantity = quantity;
        this.centre = centre;   //aggregation
    }
    public String getCode() {
        return code;
    }
    public void setCode(String code) {
        this.code = code;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getCountry() {
        return country;
    }
    public void setCountry(String country) {
        this.country = country;
    }
    public int getDosage() {
        return dosage;
    }
    public void setDosage(int dosage) {
        this.dosage = dosage;
    }
    public int getQuantity() {
        return quantity;
    }
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
    public Centre getCentre() {
        return centre;
    }
    public void setCentre(Centre centre) {
        this.centre = centre;
    }
}
