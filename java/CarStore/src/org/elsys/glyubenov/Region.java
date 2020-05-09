package org.elsys.glyubenov;

public enum Region {

    SOFIA("СВ"),
    BURGAS("А"),
    VARNA("В"),
    PLOVDIV("РВ"),
    RUSE("Р"),
    GABROVO("ЕВ"),
    VIDIN("ВН"),
    VRATSA("ВР");

    private String region;

    Region(String region){
        this.region = region;
    }

    public String getPrefix(){
        return this.region;
    }
}
