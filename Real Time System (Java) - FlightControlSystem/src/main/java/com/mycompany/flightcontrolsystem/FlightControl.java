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
import java.util.ArrayList;
import java.util.concurrent.TimeoutException;

/**
 *
 * @author Acer
 */
public class FlightControl implements Runnable {
    
    Airplane plane;

    public FlightControl(Airplane plane) {
        this.plane = plane;
    }

    ConnectionFactory cf = new ConnectionFactory();
    String AltExchange = "AltExchange";
    String DirectionExchange = "DirectionExchange";
    String SpeedExchange = "SpeedExchange";
    String DistExchange = "DistExchange";
    String CabinExchange = "CabinExchange";
    String WeatherExchange = "WeatherExchange";
    
    int cruisingAlt = 10000;    //meter
    int cruisingDir = 75;   //degree
    int cruisingSpeed = 900;    //km/h
    public int cruisingDistance = 502;  //miles

    public int getCruisingAlt() {
        return cruisingAlt;
    }
    public int getCruisingDir() {
        return cruisingDir;
    }
    public int getCruisingSpeed() {
        return cruisingSpeed;
    }
    public int getCruisingDistance() {
        return cruisingDistance;
    }

    @Override
    public void run() {
        retriveAlt();
        retriveDirection();
        retriveSpeed();
        retriveDist();
        retriveCabin();
        retriveWeather();
    }
    
    public int altLogic(int alt){
        int flapAngle;
        int adjustAlt = cruisingAlt - alt;
        // wing flap adjsutment logic
        if(adjustAlt > 0){
            if(adjustAlt < 100){
                flapAngle = 10;
            }
            else if (adjustAlt < 200){
                flapAngle = 25;
            }
            else {
                flapAngle = 35;
            }
        }
        else {
            if(adjustAlt < -100){
                flapAngle = -10;
            }
            else if (adjustAlt < -200){
                flapAngle = -25;
            }
            else {
                flapAngle = -35;
            }
        }
        
        return flapAngle;
    }
    
    public int DirectionLogic(int Dir){
        int tailAngle;
        int adjustDir = cruisingDir - Dir;
        if(adjustDir > 0){
            if(adjustDir < 10){
                tailAngle = -5;
            }
            else if (adjustDir < 20){
                tailAngle = -15;
            }
            else {
                tailAngle = -20;
            }
        }
        else {
            if(adjustDir < -10){
                tailAngle = 5;
            }
            else if (adjustDir < -20){
                tailAngle = 15;
            }
            else {
                tailAngle = 20;
            }
        }
        
        return tailAngle;
    }
    
    public int SpeedLogic(int Speed){
        int engineAdjust;
        int adjustSpeed = cruisingSpeed - Speed;
        if(adjustSpeed >= -5 && adjustSpeed <= 10){
            engineAdjust = 0;
        }
        else if(adjustSpeed > 10){
            engineAdjust = 1;
        }
        else {
            engineAdjust = -1;
        }
        
        return engineAdjust;
    }
    
    public void retriveAlt(){
        try {
            Connection con = cf.newConnection();
            Channel ch = con.createChannel();
            ch.exchangeDeclare(AltExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, AltExchange, ""); 
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    System.out.println("[Flight Control System]\t: Current Altitude: " + message + " meter");
                    int alt = Integer.parseInt(message);
                    int flapAngle = altLogic(alt);
                    if(alt - cruisingAlt > 0){
                        System.out.println("[Flight Control System]\t: Altitude is high");
                    }
                    else{
                        System.out.println("[Flight Control System]\t: Altitude is low");
                    }
                    sendMsg(new AdjustData("alt", flapAngle));
                }, x->{});
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
    
    public void retriveDirection(){
        try {
            Connection con = cf.newConnection(); 
            Channel ch = con.createChannel(); 
            ch.exchangeDeclare(DirectionExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, DirectionExchange, ""); 
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    System.out.println("[Flight Control System]\t: Current Direction = " + message + " degree");
                    int dir = Integer.parseInt(message);
                    int tailAngle = DirectionLogic(dir);
                    if(dir - cruisingDir > 0){
                        System.out.println("[Flight Control System]\t: Offset flight path direction to the left.");
                    }
                    else{
                        System.out.println("[Flight Control System]\t: Offset flight path direction to the right.");
                    }
                    sendMsg(new AdjustData("gps", tailAngle));
                }, x->{}); 
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
    
    public void retriveSpeed(){
        try {
            Connection con = cf.newConnection();
            Channel ch = con.createChannel();
            ch.exchangeDeclare(SpeedExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, SpeedExchange, ""); 
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    int speed = Integer.parseInt(message);
                    int engineAdjust = SpeedLogic(speed);
                    if(engineAdjust == 0){
                        System.out.println("[Flight Control System]\t: Current Speed = " + message + " km/h, within the regular range");
                    }
                    else if(engineAdjust == 1){
                        System.out.println("[Flight Control System]\t: Current Speed = " + message + " km/h, need to speed up");
                    }
                    else{
                        System.out.println("[Flight Control System]\t: Current Speed = " + message + " km/h, need to slow down");
                    }
                    sendMsg(new AdjustData("speed", engineAdjust));
                }, x->{}); 
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
    
    public int[] distanceLogic(int distance){
        int engineMode = 0;
        int landingMode = 0;
        int[] result = new int[2];
        if(distance > 10 && distance <= 50){
            System.out.println("[Flight Control System]\t: Airplane is near to "
                    + "the distination, prepare to pre-landing mode");
            plane.setPreLand(true);
            cruisingAlt = 3000;
            cruisingSpeed = 280;
            engineMode = 2;
            landingMode = 0;
        }
        else if(distance > 0 && distance <= 10){
            System.out.println("[Flight Control System]\t: Airplane is near to "
                    + "the distination airport, prepare to landing mode");
            plane.setLandingMode(true);
            cruisingAlt = 20;
            cruisingSpeed = 60;
            engineMode = 1;
            landingMode = 1;
        }        
        else if(distance == 0){
            System.out.println("[Flight Control System]\t: Plane landed at airport");
            engineMode = -1;
            landingMode = -1;
        }
        
        result[0] = engineMode;
        result[1] = landingMode;
        
        return result;
    }
    
    public void retriveDist(){
        try {
            Connection con = cf.newConnection(); 
            Channel ch = con.createChannel(); 
            ch.exchangeDeclare(DistExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, DistExchange, "");
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    int distance = Integer.parseInt(message);
                    int remainDist = cruisingDistance - distance;
                    System.out.println("[Flight Control System]\t: Current Traveled Distance = " + 
                            distance + " miles. Total Distance Remain = "+ remainDist + " miles");
                    if(remainDist <= 50){
                        int[] adjust = distanceLogic(remainDist);
                        sendMsg(new AdjustData("engine", adjust[0]));
                        sendMsg(new AdjustData("gear", adjust[1]));
                    } 
                }, x->{});
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
    
    public int CabinLogic(int cabin) {
        int dropMasks;
        
        if(cabin >= 75 && cabin <= 101){
            System.out.println("[Flight Control System]\t: Current Cabin "
                    + "Pressure in regular range.");
            dropMasks = 0;
        }        
        else if(cabin < 75){
            System.out.println("[Flight Control System]\t: !!!Attention!!! "
                    + "Loses Cobin Pressure!!!Loses Cobin Pressure!!!"
                    + "Loses Cobin Pressure!!!");
            dropMasks = 1;
        }
        else{
            dropMasks = 0;
        }
        
        return dropMasks;
    }
    
    public void retriveCabin(){
        try {
            Connection con = cf.newConnection();
            Channel ch = con.createChannel();
            ch.exchangeDeclare(CabinExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, CabinExchange, "");
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    System.out.println("[Flight Control System]\t: Current Cabin"
                            + " Pressure = " + message + " kPa");
                    int cabin = Integer.parseInt(message);
                    int dropMask = CabinLogic(cabin);
                    sendMsg(new AdjustData("Cabin", dropMask));
                }, x->{});
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
    
    public int[] WeatherLogic(String weather){
        int[] adjust = new int[2];
        
        if(weather.equals("Sunny") || weather.equals("Clody")){
            adjust[0] = 3;  //engine
            adjust[1] = 0;  //wing flags
        }
        else if(weather.equals("Raining")){
            adjust[0] = 2;
            adjust[1] = -15;
        }
        else{
            adjust[0] = 1;
            adjust[1] = -25;
        }
        
        return adjust;
    }
    
    public void retriveWeather(){
        try {
            Connection con = cf.newConnection(); 
            Channel ch = con.createChannel(); 
            ch.exchangeDeclare(WeatherExchange, "direct");
            String qName = ch.queueDeclare().getQueue();
            ch.queueBind(qName, WeatherExchange, ""); 
            try {
                ch.basicConsume(qName, true, (x, msg)->{
                    String message = new String(msg.getBody(),"UTF-8");
                    System.out.println("[Flight Control System]\t: Current Weather: " + message);
                    int[] adjust = WeatherLogic(message);
                    if(plane.getPreLand() == false){
                        sendMsg(new AdjustData("engine", adjust[0]));
                    }
                    sendMsg(new AdjustData("alt", adjust[1]));
                }, x->{});
            } catch (IOException ex) {
            }
        } catch (IOException | TimeoutException ex) {
        }
    }
    
    public static void sendMsg(AdjustData i){
        
        //send the i value to a direct exchange
        String actExchange = "DirectExchange";
        ConnectionFactory cf = new ConnectionFactory();
        try(Connection con = cf.newConnection()){
            Channel chan = con.createChannel();
            chan.exchangeDeclare(actExchange,"direct"); //name, type
            chan.basicPublish(actExchange, i.key, null, String.valueOf(i.adjustReading).getBytes());
        }
        catch (IOException | TimeoutException ex) {
        }
    }
    
}
