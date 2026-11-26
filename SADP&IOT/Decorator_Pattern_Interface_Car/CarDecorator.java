package S12;

public class CarDecorator implements Car {

    protected Car car;

    public CarDecorator(Car car) {
        this.car = car;
    }

    public void assemble() {
        car.assemble();
    }
}

