package S10;

public class Main {

    public static void main(String[] args) {

        Duck duck = new Duck() {
            public void display() {
                System.out.println("I am a Donald Duck.");
            }
        };

        duck.setFlyBehavior(new FlyWithWings());
        duck.setQuackBehavior(new Quack());

        duck.display();
        duck.performFly();
        duck.performQuack();
        duck.swim();

        System.out.println("\nChanging Duck Behavior:");

        duck.setFlyBehavior(new FlyNoWay());
        duck.setQuackBehavior(new Squeak());

        duck.performFly();
        duck.performQuack();
    }
}

