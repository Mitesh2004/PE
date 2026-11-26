package S12;

public class Main {

    public static void main(String[] args) {

        Car basicCar = new BasicCar();

        System.out.println("Basic Car:");
        basicCar.assemble();

        System.out.println("\nSports Car:");
        Car sportsCar = new SportsCar(new BasicCar());
        sportsCar.assemble();

        System.out.println("\nLuxury Sports Car:");
        Car luxuryCar = new LuxuryCar(
                new SportsCar(new BasicCar()));

        luxuryCar.assemble();
    }
}

