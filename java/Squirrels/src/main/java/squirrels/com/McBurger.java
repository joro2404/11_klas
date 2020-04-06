package main.java.squirrels.com;

public class McBurger extends Food implements IWinter{


    McBurger(double quality, double quantity){
        super(quality, quantity);
        this.winters_passed = 0;
    }


    @Override
    public void passWinter() {
        if(winters_passed == 0) {
            quality = quality * 0.5;
            quantity = quantity * 0.8;
            winters_passed += 1;
        }
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
