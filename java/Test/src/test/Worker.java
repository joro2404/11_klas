package test;

import java.util.List;

public class Worker extends BaseUnit{
    protected double maxQuantityResource;
    protected double currQuantityResource;
    protected Resource resource;
    protected Position positionToLeave;

    public Worker(int x, int y, String name, int speed, int maxLifePoints, int currLifePoints, Position position, double maxQuantityResource, double currQuantityResource, Resource resource, Position positionToLeave) {
        super(x, y, name, speed, maxLifePoints, currLifePoints, position);
        this.maxQuantityResource = maxQuantityResource;
        this.currQuantityResource = currQuantityResource;
        this.resource = resource;
        this.positionToLeave = positionToLeave;
    }

    public int getAbsValue(){
        return Math.abs(x) + Math.abs(y);
    }

    @Override
    public void move(){
        int unitsToTravel = 0;
        if(currQuantityResource == maxQuantityResource || resource.getQuantity() == 0){
//            unitsToTravelX = Math.abs(resource.getPosition().getX() - positionToLeave.getX());
//            unitsToTravelY = Math.abs(resource.getPosition().getY() - positionToLeave.getY());
            if(speed > Math.abs(position.getX() - positionToLeave.getX())){
                position.setX(positionToLeave.getX());
                speed = speed - Math.abs(position.getX() - positionToLeave.getX());
                if(speed > Math.abs(position.getY() - positionToLeave.getY())){
                    position.setY(positionToLeave.getY());
                }

                else{
                    if(position.getY() - positionToLeave.getY() > 0) {
                        position.setY(position.getY() + speed);
                    }else{
                        position.setY(position.getY() - speed);
                    }
                }
            }

            else{
                if(position.getX() - positionToLeave.getX() > 0) {
                    position.setX(position.getX() + speed);
                }else{
                    position.setX(position.getX() - speed);
                }
            }
        }
    }
    public void nextTick(){
        if(currQuantityResource != maxQuantityResource ){
            move();
        }

        if(currQuantityResource == maxQuantityResource || resource.getQuantity() == 0){
            move();
            if(position.getX() == positionToLeave.getX() && position.getY() == positionToLeave.getY()){
                currQuantityResource = 0;
            }
        }
    }

    public void findNewResource(List<Resource> resources){
        if(resource.getQuantity() > 0){
        }else{
            int bestResource = 10000;
            for( Resource r : resources){
                if (resource.getAbsValue() - r.getAbsValue()< bestResource){
                    bestResource = resource.getAbsValue() - r.getAbsValue();
                    resource.setX(r.getX());
                    resource.setY(r.getY());
                }
            }
        }
    }

    public double getMaxQuantityResource() {
        return maxQuantityResource;
    }

    public void setMaxQuantityResource(double maxQuantityResource) {
        this.maxQuantityResource = maxQuantityResource;
    }

    public double getCurrQuantityResource() {
        return currQuantityResource;
    }

    public void setCurrQuantityResource(double currQuantityResource) {
        this.currQuantityResource = currQuantityResource;
    }

    public Resource getResource() {
        return resource;
    }

    public void setResource(Resource resource) {
        this.resource = resource;
    }

    public Position getPositionToLeave() {
        return positionToLeave;
    }

    public void setPositionToLeave(Position positionToLeave) {
        this.positionToLeave = positionToLeave;
    }
}
