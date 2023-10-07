/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.flightcontrolsystem;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ScheduledFuture;
import java.util.concurrent.TimeUnit;
import org.openjdk.jmh.annotations.Benchmark;

/**
 *
 * @author Clarence Lee
 */
public class FlightManegementSimulator {

    static ScheduledExecutorService timer;
    static ScheduledFuture<?> Altitude;
    static ScheduledFuture<?> Direction;
    static ScheduledFuture<?> Speed;
    static ScheduledFuture<?> Distance;
    static ScheduledFuture<?> Cabin;
    static ScheduledFuture<?> Weather;
    
    public static void main(String[] args) {
        Airplane plane = new Airplane(false, false);
        
        //Flight Control system
        FlightControl FC = new FlightControl(plane);
        //Simulation Starting Context
        System.out.println("\nA airplane currently cruising with the following parameters:");
        System.out.println("Crusing altitude: "+ FC.getCruisingAlt()+" meter");
        System.out.println("Crusing direction from the point of departure: "+ FC.getCruisingDir()+" degree");
        System.out.println("Destination total travel distance: "+ FC.getCruisingDistance()+" miles");
        System.out.println("Crusing speed: "+ FC.getCruisingSpeed() +" km/h");
        System.out.println();
        
        //Sensor system thread
        timer = Executors.newScheduledThreadPool(6);
        Altitude = timer.scheduleAtFixedRate(new AltitudeSensor(plane), 1, 1, TimeUnit.SECONDS);
        Direction = timer.scheduleAtFixedRate(new DirectionSensor(), 1, 1, TimeUnit.SECONDS);
        Speed = timer.scheduleAtFixedRate(new SpeedSensor(plane), 1, 1, TimeUnit.SECONDS);
        Distance = timer.scheduleAtFixedRate(new DistanceSensor(plane), 1, 1, TimeUnit.SECONDS);
        Cabin = timer.scheduleAtFixedRate(new CabinSensor(), 1, 1, TimeUnit.SECONDS);
        Weather = timer.scheduleAtFixedRate(new WeatherSensor(), 2, 5, TimeUnit.SECONDS);
        
        //Flight Control System thread
        new Thread(FC).start();
        
        //Actuators Thread
        new Thread(new WingFlags()).start();
        new Thread(new TailFlags()).start();
        new Thread(new Engines()).start();
        new Thread(new OxygenMasks()).start();
        new Thread(new LandingGear()).start();
        
        //Unexpected event - loss cabin
        new Thread(new LossCabin()).start();
    }
    
}
