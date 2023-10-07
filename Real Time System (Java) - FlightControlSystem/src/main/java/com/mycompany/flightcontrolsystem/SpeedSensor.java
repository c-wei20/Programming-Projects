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
 * @author Clarence Lee
 */
public class SpeedSensor implements Runnable{
    
    Airplane plane;

    public SpeedSensor(Airplane plane) {
        this.plane = plane;
    }
    
    String myExchange = "SpeedExchange";
    ConnectionFactory cf = new ConnectionFactory();
    
    Random rand = new Random();
    int CurrentSpeed = 900;
    @Override
    public void run() {        
        int newAlt = getSpeed();
        sendSpeed(newAlt);    
    }

    public int getSpeed(){
        if(plane.getPreLand() == false){
            int change = rand.nextInt(50);        
            if (rand.nextBoolean()){            
                change*= -1;        
            }        
            CurrentSpeed+=change;
        }
        else if(plane.getLandingMode() == false){
            int change = rand.nextInt(50)+150;
            CurrentSpeed-=change;
            if(CurrentSpeed <= 280){
                CurrentSpeed = 280;
            }
        }
        else{
            CurrentSpeed-=20;
            if(CurrentSpeed <= 40){
                CurrentSpeed = 40;
            }
        }
        
        return CurrentSpeed;
    }
    
    public void sendSpeed(int alt){
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
