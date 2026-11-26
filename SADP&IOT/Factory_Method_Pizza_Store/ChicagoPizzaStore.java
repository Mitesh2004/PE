package S4;

public class ChicagoPizzaStore extends PizzaStore {
    @Override
    protected Pizza createPizza(String type) {
        switch (type) {
            case "cheese": return new ChicagoStyleCheesePizza();
            case "veggie": return new ChicagoStyleVeggiePizza();
            default: throw new IllegalArgumentException("Unknown pizza type: " + type);
        }
    }
}
