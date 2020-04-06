package main.java.squirrels.com;

import java.util.ArrayList;

public class Burrow implements IWinter{

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

    @Override
    public void passWinter() {
        for(Food food : foods){
            food.passWinter();
        }
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
