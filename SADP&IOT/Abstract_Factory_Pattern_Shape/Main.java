package S17;

public class Main {

    public static void main(String[] args) {

        AbstractFactory factory = FactoryProducer.getFactory();

        Shape s1 = factory.getShape("CIRCLE");
        s1.draw();

        Color c1 = factory.getColor("RED");
        c1.fill();

        Shape s2 = factory.getShape("RECTANGLE");
        s2.draw();

        Color c2 = factory.getColor("GREEN");
        c2.fill();

        Shape s3 = factory.getShape("SQUARE");
        s3.draw();

        Color c3 = factory.getColor("BLUE");
        c3.fill();
    }
}

