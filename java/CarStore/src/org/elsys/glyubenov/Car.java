package org.elsys.glyubenov;
import java.util.*;

public abstract class Car implements Comparable<Car>{
    protected Model model;
    protected int year;
    protected int price;
    protected EngineType engineType;
    protected String registrationNumber;
    protected Region region;
//    static private int count = 1000;
    static private int SOFIA = 1000;
    static private int BURGAS = 1000;
    static private int VARNA = 1000;
    static private int PLOVDIV = 1000;
    static private int RUSE = 1000;
    static private int GABROVO = 1000;
    static private int VIDIN = 1000;
    static private int VRATSA = 1000;

    @Override
    public int compareTo(Car car){
        return model.compareTo(car.getModel());
    }

    /**
     * Returns the model of the car.
     */
    public Model getModel(){
        return this.model;
    }

    /**
     * Returns the year of manufacture of the car.
     */
    public int getYear(){
        return this.year;
    }

    /**
     * Returns the price of the car.
     */
    public int getPrice(){
        return this.price;
    }

    /**
     * Returns the engine type of the car.
     */
    public EngineType getEngineType(){
        return this.engineType;
    }

    /**
     * Returns the unique registration number of the car.
     */
    public String getRegistrationNumber(){
        return this.registrationNumber;
    }

    public String makeRegistrationNumber(Region region){
        String reg = "";
        reg += region.getPrefix();
        if (region == Region.SOFIA){
            reg += SOFIA;
            SOFIA += 1;
        }
        if (region == Region.VARNA){
            reg += VARNA;
            VARNA += 1;
        }
        if (region == Region.BURGAS){
            reg += BURGAS;
            BURGAS += 1;
        }
        if (region == Region.PLOVDIV){
            reg += PLOVDIV;
            PLOVDIV += 1;
        }
        if (region == Region.RUSE){
            reg += RUSE;
            RUSE += 1;
        }
        if (region == Region.GABROVO){
            reg += GABROVO;
            GABROVO += 1;
        }
        if (region == Region.VRATSA){
            reg += VRATSA;
            VRATSA += 1;
        }
        if (region == Region.VIDIN){
            reg += VIDIN;
            VIDIN += 1;
        }

        Random r1 = new Random();
        char c1 = (char)(r1.nextInt(26) + 'A');
        reg += c1;
        Random r2 = new Random();
        char c2 = (char)(r2.nextInt(26) + 'A');
        reg += c2;

        return reg;
    }
}
