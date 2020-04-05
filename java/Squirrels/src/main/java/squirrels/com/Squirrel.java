package main.java.squirrels.com;

public class Squirrel implements IWinter{
    private String name;
    private String type;
    private int age;
    private int goForFood;
    private Burrow burrow;

    public Squirrel(String name, String type, int age) {
        this.name = name;
        this.type = type;
        this.age = age;
        this.goForFood = 0;
    }

    void addFood(Food food){
        burrow.addFood(food);
        if(goForFood >= 4)throw new IncorrectGoingOutForFood("The squirrel already went out its max times for this winter!");
        goForFood += 1;
    }

    @Override
    public void passWinter() {
        for(Food food : burrow.getFoods()){
            food.passWinter();
            goForFood = 0;
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getGoForFood() {
        return goForFood;
    }

    public Burrow getBurrow() {
        return burrow;
    }

    public void setBurrow(Burrow burrow) {
        this.burrow = burrow;
    }
}
