package test;

import javax.sql.ConnectionPoolDataSource;

public abstract class BaseUnit extends Position{
    protected String name;
    protected int speed;
    protected int maxLifePoints;
    protected int currLifePoints;
    protected Position position;

    public BaseUnit(int x, int y, String name, int speed, int maxLifePoints, int currLifePoints, Position position) {
        super(x, y);
        this.name = name;
        this.speed = speed;
        this.maxLifePoints = maxLifePoints;
        this.currLifePoints = currLifePoints;
        this.position = position;
    }

    public abstract void move();
    public abstract void nextTick();


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public int getMaxLifePoints() {
        return maxLifePoints;
    }

    public void setMaxLifePoints(int maxLifePoints) {
        this.maxLifePoints = maxLifePoints;
    }

    public int getCurrLifePoints() {
        return currLifePoints;
    }

    public void setCurrLifePoints(int currLifePoints) {
        this.currLifePoints = currLifePoints;
    }

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }
}
