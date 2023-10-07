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
public class DirectionSensor implements Runnable{
    
    String myExchange = "DirectionExchange";
    ConnectionFactory cf = new ConnectionFactory();
    
    Random rand = new Random();
    int CurrentDirection = 75;
    @Override
    public void run() {          
        int newDir = getDirection();
        sendDirection(newDir);    
    }

    public int getDirection(){
        CurrentDirection = 75;
        int change = rand.nextInt(10);        
        if (rand.nextBoolean()){            
            change*= -1;        
        }        
        CurrentDirection+=change;
        
        return CurrentDirection;
    }
    
    public void sendDirection(int alt){
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
