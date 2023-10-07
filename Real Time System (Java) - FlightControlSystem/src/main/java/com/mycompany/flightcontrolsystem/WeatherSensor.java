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
public class WeatherSensor implements Runnable{
    
    String myExchange = "WeatherExchange";
    ConnectionFactory cf = new ConnectionFactory();
    
    Random rand = new Random();
    String CurrentWeather;

    @Override
    public void run() {        
        // adjust the altitude   
        CurrentWeather = genCabin();
        sendCabin(CurrentWeather);    
    }

    public String genCabin(){
        String item;
        
        int no = rand.nextInt(4);
        
        switch (no) {
            case 0:
                item = "Sunny";
                break;
            case 1:
                item = "Cloudy";
                break;
            case 2:
                item = "Raining";
                break;
            default:
                item = "Thunder Storming";
                break;
        }
        return item;
    }
    
    public void sendCabin(String cabin){
        try(Connection con = cf.newConnection()){

            Channel chan = con.createChannel();
            chan.exchangeDeclare(myExchange, "direct"); //name, type
            chan.basicPublish(myExchange, "", false, null, cabin.getBytes());
        }
        catch (IOException | TimeoutException ex) {
        }
    }  
}
