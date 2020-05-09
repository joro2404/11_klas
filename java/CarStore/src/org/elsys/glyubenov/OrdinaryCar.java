package org.elsys.glyubenov;

public class OrdinaryCar extends Car{

    public OrdinaryCar(Model model, int year, int price, EngineType engineType, Region region){
        this.model = model;
        this.year = year;
        this.price = price;
        this.engineType = engineType;
        this.region = region;
        this.registrationNumber = makeRegistrationNumber(region);
    }




}
