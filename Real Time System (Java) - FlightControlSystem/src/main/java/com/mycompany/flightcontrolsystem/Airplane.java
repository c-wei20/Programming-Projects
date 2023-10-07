/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.flightcontrolsystem;

/**
 *
 * @author Clarence Lee
 */
public class Airplane {

    boolean pre_landing;
    boolean landing;

    public Airplane(boolean pre_landing, boolean landing) {
        this.pre_landing = pre_landing;
        this.landing = landing;
    }

    public void setPreLand(boolean pre_landing) {
        this.pre_landing = pre_landing;
    }

    public boolean getPreLand() {
        return pre_landing;
    }

    public void setLandingMode(boolean landing) {
        this.landing = landing;
    }

    public boolean getLandingMode() {
        return landing;
    }
}
