package test;

public class Resource extends Position{
    protected Position position;
    protected double quantity;

    public Resource(int x, int y, Position position, double quantity) {
        super(x, y);
        this.position = position;
        this.quantity = quantity;
    }
    public int getAbsValue(){
        return Math.abs(x) + Math.abs(y);
    }

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    public double getQuantity() {
        return quantity;
    }

    public void setQuantity(double quantity) {
        this.quantity = quantity;
    }
}
