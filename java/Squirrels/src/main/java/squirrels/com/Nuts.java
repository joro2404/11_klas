package main.java.squirrels.com;

public class Nuts extends Food implements IWinter{

    Nuts(double quality, double quantity){
        super(quality, quantity);
    }

    @Override
    public void passWinter() {
        winters_passed += 1;
    }
}
