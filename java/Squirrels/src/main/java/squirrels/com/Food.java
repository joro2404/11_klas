package main.java.squirrels.com;

public class Food implements IWinter{
    protected double quality;
    protected double quantity;
    protected int winters_passed;

    Food(double quality, double quantity){
        this.quality = quality;
        this.quantity = quantity;
    }

    public void passWinter(){

    }

    public double getFoodScore(){
        return quality * quantity;
    }

    public double getQuality() {
        return quality;
    }

    public void setQuality(double quality) {
        this.quality = quality;
    }

    public double getQuantity() {
        return quantity;
    }

    public void setQuantity(double quantity) {
        this.quantity = quantity;
    }

    public int getWinters_passed() {
        return winters_passed;
    }

    public void setWinters_passed(int winters_passed) {
        this.winters_passed = winters_passed;
    }
}