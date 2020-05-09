package org.elsys.glyubenov;

import java.util.*;

public class SportsCar extends Car{

    public SportsCar(Model model, int year, int price, EngineType engineType, Region region){
        this.model = model;
        this.year = year;
        this.price = price;
        this.engineType = engineType;
        this.region = region;
        this.registrationNumber = makeRegistrationNumber(region);
    }

}
