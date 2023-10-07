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
public class LossCabin implements Runnable{

    Random rand = new Random();
    
    String myExchange = "CabinExchange";
    ConnectionFactory cf = new ConnectionFactory();
    
    @Override
    public void run(){
        try{
            Thread.sleep(rand.nextInt(10000) + 50000);
            sendCabin(20);
        }
        catch(InterruptedException e) {  
        }
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
