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
public class LandingGear implements Runnable{
    
    ConnectionFactory cf = new ConnectionFactory();
    String paralleExchange = "DirectExchange";
    
    int status = 0;     //0 - close, 1 - open
    
    @Override
    public void run() {
        openGear(); 
    }
    
    public void openGear(){
        try {
            Connection con = cf.newConnection(); 
            Channel ch = con.createChannel(); 
            ch.exchangeDeclare(paralleExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, paralleExchange, "gear"); 
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    int landingMode = Integer.parseInt(message);
                    if(landingMode == 1){
                        System.out.println("- Landing Gear Actuator\t: Open the landing gear");  
                    }
                    else if(landingMode == -1){
                        System.out.println("Plane arrived at the simulation airport");
                        System.out.println("Simulation end");
                        System.exit(0); 
                    }
                }, x->{});                 
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
}
