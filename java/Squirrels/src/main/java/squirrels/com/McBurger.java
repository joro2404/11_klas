package main.java.squirrels.com;

public class McBurger extends Food implements IWinter{


    McBurger(double quality, double quantity){
        super(quality, quantity);
    }

    @Override
    public void passWinter() {
        if(winters_passed == 0) {
            quality = quality * 0.5;
            quantity = quantity * 0.8;
            winters_passed += 1;
        }
    }
}
