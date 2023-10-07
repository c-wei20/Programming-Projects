package covid.pkg19.VRS;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
public class Dataio1 {
    public static ArrayList<Appointment> allAppointment = new ArrayList<Appointment>();
    public static void read(){
        try{
            Scanner s = new Scanner(new File("Appointment.txt"));
            while(s.hasNext()){
                int id = Integer.parseInt(s.nextLine());
                String currentadd = s.nextLine();
                String State = s.nextLine();
                String healthstatus = s.nextLine();
                String Qhealth =s.nextLine();
                String date1= s.nextLine();
                String time1= s.nextLine();
                String date2= s.nextLine();
                String time2 =s.nextLine();
                boolean Status = Boolean.parseBoolean(s.nextLine());
                boolean dose1 = Boolean.parseBoolean(s.nextLine());
                boolean dose2 = Boolean.parseBoolean(s.nextLine());
                String Vaccine = s.nextLine();
                Centre Center = DataIO.checkCt(s.nextLine());
                if(Center==(null)){
                    Center = new Centre("-", "-");
                }
                People x = DataIO.checkPpl(s.nextLine());
                s.nextLine();
                Appointment p = new Appointment(id, currentadd, State, healthstatus, Qhealth, date1, time1, date2, time2, Status, dose1, dose2, Vaccine, Center, x);
                allAppointment.add(p);
                x.setMyAppointment(p);
                for(int i=0; i<DataIO.allCommittee.size(); i++){
                    Committee c = DataIO.allCommittee.get(i);
                    c.getAppointments().add(p);
                }
            }
        }catch(Exception e){
            System.out.println("Error in read file");
            
        } 
        
    }
    public static void write(){
        try{
            PrintWriter a = new PrintWriter("Appointment.txt");
            for(int i=0;i<allAppointment.size();i++){
                a.println(allAppointment.get(i).getId());
                a.println(allAppointment.get(i).getCurrentaddress());
                a.println(allAppointment.get(i).getState());
                a.println(allAppointment.get(i).getHealthstatus());
                a.println(allAppointment.get(i).getAgreestatement());
                a.println(allAppointment.get(i).getDate1());
                a.println(allAppointment.get(i).getTime1());
                a.println(allAppointment.get(i).getDate2());
                a.println(allAppointment.get(i).getTime2());
                a.println(allAppointment.get(i).getStatus());
                a.println(allAppointment.get(i).getDose1());
                a.println(allAppointment.get(i).getDose2());
                a.println(allAppointment.get(i).getVaccine());
                a.println(allAppointment.get(i).getCenter().getName());
                a.println(allAppointment.get(i).getPeople().getIDnumber());
                a.println();
            }
            a.close();
        }catch(Exception e){
            System.out.println("Error in write");
        }
    }
}
