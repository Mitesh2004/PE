package S4;

public class NYPizzaStore extends PizzaStore {
    @Override
    protected Pizza createPizza(String type) {
        switch (type) {
            case "cheese": return new NYStyleCheesePizza();
            case "veggie": return new NYStyleVeggiePizza();
            default: throw new IllegalArgumentException("Unknown pizza type: " + type);
        }
    }
}
