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
public class Engines implements Runnable {
     
    ConnectionFactory cf = new ConnectionFactory();
    String paralleExchange = "DirectExchange";
    
    @Override
    public void run() {
        adjustEngine();
        EngineMode();
    }
    
    public void adjustEngine(){
        try {
            Connection con = cf.newConnection();
            Channel ch = con.createChannel();
            ch.exchangeDeclare(paralleExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, paralleExchange, "speed");
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    int range = Integer.parseInt(message);
                    if(range == 0){
                        System.out.println("- Engines Actuator\t: Maintained Current RPM");
                    }
                    else if(range == 1){
                        System.out.println("- Engines Actuator\t: Accelerate Engine RPM");
                    }
                    else{
                        System.out.println("- Engines Actuator\t: Deccelerate Engine RPM");
                    }
                }, x->{});
                
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
    
    public void EngineMode(){
        try {
            Connection con = cf.newConnection(); 
            Channel ch = con.createChannel(); 
            ch.exchangeDeclare(paralleExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, paralleExchange, "engine");
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    int mode = Integer.parseInt(message);
                    if(mode == 3){
                        System.out.println("- Engines Actuator\t: Adjust engine to high thrust mode");
                    }
                    else if(mode == 2){
                        System.out.println("- Engines Actuator\t: Adjust engine to regular thrust mode");
                    }
                    else if(mode == 1){
                        System.out.println("- Engines Actuator\t: Adjust engine to low thrust mode");
                    }
                    else{
                        System.out.println("- Engines Actuator\t: Adjust engine to idling (constant low speed) mode");
                    }
                }, x->{});
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
}
