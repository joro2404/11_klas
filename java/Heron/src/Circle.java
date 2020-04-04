public class Circle {

    private Point x;
    private Integer r;


    public Circle(Point x, Integer r){
        this.x = x;
        this.r = r;
    }

    public Point getX() {
        return x;
    }

    public void setX(Point x) {
        this.x = x;
    }

    public Integer getR() {
        return r;
    }

    public void setR(Integer r) {
        this.r = r;
    }

    public Integer get_Perimeter(){
        return 1;
    }
}
