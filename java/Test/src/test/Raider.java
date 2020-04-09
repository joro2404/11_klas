package test;

import java.util.List;

public class Raider extends Worker {
    protected int power;
    protected int range;


    public Raider(int x, int y, String name, int speed, int maxLifePoints, int currLifePoints, Position position, double maxQuantityResource, double currQuantityResource, Resource resource, Position positionToLeave, int power, int range) {
        super(x, y, name, speed, maxLifePoints, currLifePoints, position, maxQuantityResource, currQuantityResource, resource, positionToLeave);
        this.power = power;
        this.range = range;
    }

    public void findNewVictim(List<Worker> workers){
        for(Worker w : workers){
            if(range <= w.getAbsValue()){
                w.setCurrLifePoints(w.getCurrLifePoints() - power);
            }
            if(w.getCurrLifePoints() <= 0){
                currQuantityResource += w.getCurrQuantityResource();
            }
        }
    }
}
