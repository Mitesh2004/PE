package S17;

public class FactoryProducer {

    public static AbstractFactory getFactory() {
        return new ShapeColorFactory();
    }
}

