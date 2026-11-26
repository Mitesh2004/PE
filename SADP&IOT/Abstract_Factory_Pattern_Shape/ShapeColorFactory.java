package S17;

public class ShapeColorFactory implements AbstractFactory {

    public Shape getShape(String type) {

        if (type.equalsIgnoreCase("CIRCLE"))
            return new Circle();

        else if (type.equalsIgnoreCase("RECTANGLE"))
            return new Rectangle();

        else if (type.equalsIgnoreCase("SQUARE"))
            return new Square();

        return null;
    }

    public Color getColor(String type) {

        if (type.equalsIgnoreCase("RED"))
            return new Red();

        else if (type.equalsIgnoreCase("GREEN"))
            return new Green();

        else if (type.equalsIgnoreCase("BLUE"))
            return new Blue();

        return null;
    }
}

