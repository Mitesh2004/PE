package S12;

public class LuxuryCar extends CarDecorator {

    public LuxuryCar(Car car) {
        super(car);
    }

    public void assemble() {
        super.assemble();
        System.out.println("Adding Luxury Car Features.");
    }
}

