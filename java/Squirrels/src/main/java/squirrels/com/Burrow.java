package main.java.squirrels.com;

import java.util.ArrayList;

public class Burrow {

    private ArrayList<Food> foods;

    public double getTotalFoodScore(){
        double result = 0;
        for(Food i : foods){
            result += i.getFoodScore();
        }
        return result;
    }

    public Burrow(ArrayList<Food> foods) {
        this.foods = foods;
    }

    public ArrayList<Food> getFoods() {
        return foods;
    }

    public void setFoods(ArrayList<Food> foods) {
        this.foods = foods;
    }

    public void addFood(Food food){
        this.foods.add(food);
    }
}
