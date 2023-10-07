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

/**A
 *
 * @author Clarence Lee
 */
public class CabinSensor implements Runnable{
    
    String myExchange = "CabinExchange";
    ConnectionFactory cf = new ConnectionFactory();
    
    Random rand = new Random();
    
    @Override
    public void run() { 
        int newCabin = getCabin();
        sendCabin(newCabin);       
    }

    public int getCabin(){
        
        int CurrentCabin = rand.nextInt(25) + 75;
        
        return CurrentCabin;
    }
    
    public void sendCabin(int cabin){
        try(Connection con = cf.newConnection()){
            
            String msg = String.valueOf(cabin);
            Channel chan = con.createChannel();
            chan.exchangeDeclare(myExchange, "direct"); //name, type
            chan.basicPublish(myExchange, "", false, null, msg.getBytes());
            
        }
        catch (IOException | TimeoutException ex) {
        }
    }
}


