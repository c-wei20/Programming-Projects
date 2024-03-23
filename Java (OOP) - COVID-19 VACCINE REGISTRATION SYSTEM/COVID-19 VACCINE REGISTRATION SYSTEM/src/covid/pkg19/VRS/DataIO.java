package covid.pkg19.VRS;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
public class DataIO {
    public static ArrayList<People> allPeople = new ArrayList<People>();
    public static ArrayList<Committee> allCommittee = new ArrayList<Committee>();
    public static ArrayList<Centre> allCentre = new ArrayList<Centre>();
    public static ArrayList<Vaccine> allVaccine = new ArrayList<Vaccine>();
    public static void read(){
        try{
            Scanner s = new Scanner(new File("people.txt"));
            while(s.hasNext()){
                String IDno = s.nextLine();
                boolean Nationality = Boolean.parseBoolean(s.nextLine());
                String Name = s.nextLine();
                String DOB = s.nextLine();
                int age = Integer.parseInt(s.nextLine());
                String Gender = s.nextLine();
                String Address = s.nextLine();
                String State = s.nextLine();
                String Phone = s.nextLine();
                String Email = s.nextLine();
                String Password = s.nextLine();
                s.nextLine();
                People c = new People(IDno, Nationality, Name, DOB, age, Gender, Address, State, Phone, Email, Password);
                allPeople.add(c); 
            }
            
            Scanner s1 = new Scanner(new File("committee.txt"));
            while(s1.hasNext()){
                String ID = s1.nextLine();
                String Name = s1.nextLine();
                String Gender = s1.nextLine();
                String Phone = s1.nextLine();
                String Password = s1.nextLine();
                s1.nextLine();
                Committee comt = new Committee(ID, Name, Gender, Phone, Password);
                allCommittee.add(comt);
            } 
            
            Scanner s2 = new Scanner(new File("centre.txt"));
            while(s2.hasNext()){
                String Name = s2.nextLine();
                String State = s2.nextLine();
                s2.nextLine();
                Centre ct = new Centre(Name, State);
                allCentre.add(ct);
            } 
            
            Scanner s3 = new Scanner(new File("vaccine.txt"));
            while(s3.hasNext()){
                String code = s3.nextLine();
                String Name = s3.nextLine();
                String Country = s3.nextLine();
                int dos = Integer.parseInt(s3.nextLine());
                int qtt = Integer.parseInt(s3.nextLine());
                Centre ct = checkCt(s3.nextLine());
                s3.nextLine();
                Vaccine vc = new Vaccine(code, Name,Country, dos, qtt, ct);
                allVaccine.add(vc);
                ct.getCentreVaccine().add(vc);
            } 
        }catch(Exception e){
            System.out.println("Error in read!");
        }
    }
    public static void write(){
        try{
            PrintWriter people = new PrintWriter("people.txt");
            for(int i=0; i<allPeople.size(); i++){
                people.println(allPeople.get(i).getIDnumber());
                people.println(allPeople.get(i).isNationality());
                people.println(allPeople.get(i).getName());
                people.println(allPeople.get(i).getBirthDate());
                people.println(allPeople.get(i).getAge());
                people.println(allPeople.get(i).getGender());
                people.println(allPeople.get(i).getAddress());
                people.println(allPeople.get(i).getState());
                people.println(allPeople.get(i).getPhoneNumber());
                people.println(allPeople.get(i).getEmail());
                people.println(allPeople.get(i).getPassword());
                people.println();
            }
            people.close();
            
            PrintWriter committee = new PrintWriter("committee.txt");
            for(int i=0; i<allCommittee.size(); i++){
                committee.println(allCommittee.get(i).getId());
                committee.println(allCommittee.get(i).getName());
                committee.println(allCommittee.get(i).getGender());
                committee.println(allCommittee.get(i).getPhone());
                committee.println(allCommittee.get(i).getPassword());
                committee.println();
            }
            committee.close();
            
            PrintWriter centre = new PrintWriter("centre.txt");
            for(int i=0; i<allCentre.size(); i++){
                centre.println(allCentre.get(i).getName());
                centre.println(allCentre.get(i).getState());
                centre.println();
            }
            centre.close();
            
            PrintWriter vaccine = new PrintWriter("vaccine.txt");
            for(int i=0; i<allVaccine.size(); i++){
                vaccine.println(allVaccine.get(i).getCode());
                vaccine.println(allVaccine.get(i).getName());
                vaccine.println(allVaccine.get(i).getCountry());
                vaccine.println(allVaccine.get(i).getDosage());
                vaccine.println(allVaccine.get(i).getQuantity());
                vaccine.println(allVaccine.get(i).getCentre().getName());
                vaccine.println();
            }
            vaccine.close();
        }catch(Exception e){
            System.out.println("Error in write!");
        }
    }
    public static People checkPpl(String ID){
        for(int i=0; i<allPeople.size(); i++){
            if(ID.equals(allPeople.get(i).getIDnumber())){
                return allPeople.get(i);
            }
        }
        return null;
    }
    public static Committee checkComt(String ID){
        for(int i=0; i<allCommittee.size(); i++){
            if(ID.equals(allCommittee.get(i).getId())){
                return allCommittee.get(i);
            }
        }
        return null;
    }
    public static Centre checkCt(String Name){
        for(int i=0; i<allCentre.size(); i++){
            if(Name.equals(allCentre.get(i).getName())){
                return allCentre.get(i);
            }
        }
        return null;
    }
}
