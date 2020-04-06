package main.java.squirrels.com;

public class Cake extends Food implements IWinter{
    private int winters_passed;

    Cake(double quality, double quantity){
        super(quality, quantity);
        this.winters_passed = 0;
    }

    @Override
    public void passWinter() {
        winters_passed += 1;
        quality = quality * (0.1 + 1.99 / Math.pow(2,(winters_passed / 0.85)));
        quantity = quantity * 0.7;
    }

    @Override
    public int getWinters_passed() {
        return winters_passed;
    }

    @Override
    public void setWinters_passed(int winters_passed) {
        this.winters_passed = winters_passed;
    }
}
