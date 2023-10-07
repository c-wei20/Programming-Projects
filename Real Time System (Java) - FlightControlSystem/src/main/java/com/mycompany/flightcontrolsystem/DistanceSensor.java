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
public class DistanceSensor implements Runnable{
    
    Airplane plane;

    public DistanceSensor(Airplane plane) {
        this.plane = plane;
    }
    
    String myExchange = "DistExchange";
    ConnectionFactory cf = new ConnectionFactory();
    
    int CurrentDistance = 0;
    @Override
    public void run() {        
        int newDis = getDistance();
        sendDistance(newDis);    
    }

    public int getDistance(){
        
        int change;
        
        if(plane.getLandingMode()){
            change = 1; 
        }
        else{
            change = 5;
        }
        CurrentDistance+=change;
        if(CurrentDistance >= 502){
            CurrentDistance = 502;
        }
        
        return CurrentDistance;
    }
    
    public void sendDistance(int dist){
        try(Connection con = cf.newConnection()){
            
            String msg = String.valueOf(dist);
            Channel chan = con.createChannel();
            chan.exchangeDeclare(myExchange, "direct"); //name, type
            chan.basicPublish(myExchange, "", false, null, msg.getBytes());
            
        }
        catch (IOException | TimeoutException ex) {
        }
    }
}
