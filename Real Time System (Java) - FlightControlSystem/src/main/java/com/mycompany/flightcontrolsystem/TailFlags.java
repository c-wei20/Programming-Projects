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
public class TailFlags implements Runnable{

    ConnectionFactory cf = new ConnectionFactory();
    String paralleExchange = "DirectExchange";
    
    @Override
    public void run() {
        adjustFlap();
    }
    
    public void adjustFlap(){
        try {
            Connection con = cf.newConnection(); 
            Channel ch = con.createChannel(); 
            ch.exchangeDeclare(paralleExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, paralleExchange, "gps");
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    int angle = Integer.parseInt(message);
                    int tailAngle = 90;
                    tailAngle += angle;
                    System.out.println("- Tail Flags Actuator\t: Adjsut "
                            + angle + " degree to angle: " + tailAngle);
                }, x->{});  
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
}
