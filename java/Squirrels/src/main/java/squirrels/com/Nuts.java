package main.java.squirrels.com;

public class Nuts extends Food implements IWinter{

    Nuts(double quality, double quantity){
        super(quality, quantity);
    }

    @Override
    public void passWinter() {
        winters_passed += 1;
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
