/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.flightcontrolsystem;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import java.io.IOException;
import java.util.Random;
import java.util.concurrent.TimeoutException;

/**
 *
 * @author Acer
 */
public class AltitudeSensor implements Runnable {
    
    static Airplane plane;

    public AltitudeSensor(Airplane plane) {
        this.plane = plane;
    }

    String myExchange = "AltExchange";
    ConnectionFactory cf = new ConnectionFactory();
    
    Random rand = new Random();
    int CurrentAlt = 10000;
    @Override
    public void run() {        
        // generate and sent new altitude   
        int newAlt = getAlt();
        sendAlt(newAlt);    
    }

    public int getAlt(){
        //not pre landing altitube
        if(plane.getPreLand() == false){
            int change = rand.nextInt(100);        
            if (rand.nextBoolean()){            
                change*= -1;        
            }        
            CurrentAlt+=change;

            return CurrentAlt;
        }
        //pre landind altitude
        else if(plane.getLandingMode() == false){
            int change = rand.nextInt(100)+1500;
            CurrentAlt-=change;
            if(CurrentAlt <= 3000){
                CurrentAlt = 3000;
            }
        }
        //landing altitude
        else{
            CurrentAlt-=420;
            if(CurrentAlt <= 0){
                CurrentAlt = 0;
            }
        }
        
        return CurrentAlt;
    }
    
    public void sendAlt(int alt){
        
        try(Connection con = cf.newConnection()){
            
            String msg = String.valueOf(alt);
            Channel chan = con.createChannel();
            chan.exchangeDeclare(myExchange, "direct"); //name, type
            chan.basicPublish(myExchange, "", false, null, msg.getBytes());
            
        }
        catch (IOException | TimeoutException ex) {
        }
    }
    
}
