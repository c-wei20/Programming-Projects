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
import java.util.concurrent.TimeoutException;

/**
 *
 * @author Clarence Lee
 */
public class OxygenMasks implements Runnable{
    
    ConnectionFactory cf = new ConnectionFactory();
    String paralleExchange = "DirectExchange";
    
    @Override
    public void run() {
        dropMasks();
    }
    
    public void dropMasks(){
        try {
            Connection con = cf.newConnection();
            Channel ch = con.createChannel(); 
            ch.exchangeDeclare(paralleExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, paralleExchange, "Cabin");
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    int dropMask = Integer.parseInt(message);
                    if(dropMask == 1){
                        System.out.println("- OxygenMasks Actuator\t: Oxygen Masks Drop. "
                                + "Attention! Low Cabin Pressure. Please put on the mask.");
                    }
                }, x->{}); 
                
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
}
