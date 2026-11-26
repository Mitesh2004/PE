package S8;

public class Main {

    public static void main(String[] args) {

        GumballMachine machine = new GumballMachine(2);

        System.out.println("Gumball Machine Started");

        machine.insertQuarter();
        machine.turnCrank();

        System.out.println();

        machine.insertQuarter();
        machine.turnCrank();

        System.out.println();

        machine.insertQuarter();

        System.out.println("\nRemaining Gumballs: " + machine.getCount());
    }
}

