package test;

import java.util.ArrayList;
import java.util.List;

public class Simulation {
    private List<Resource> resources = new ArrayList<>();
    private List<Worker> workers = new ArrayList<>();
    private double resourceCounter = 0;


    public void run(){
        for(Worker w : workers){
            w.nextTick();
            List<Resource> CurrResources = new ArrayList<>();
            for(Resource r : resources){
                if(r.getQuantity() > 0)CurrResources.add(r);
            }
            w.findNewResource(CurrResources);
        }
    }
}
