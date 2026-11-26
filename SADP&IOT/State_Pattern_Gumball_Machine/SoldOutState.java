package S8;

public class SoldOutState implements State {

    GumballMachine machine;

    public SoldOutState(GumballMachine machine) {
        this.machine = machine;
    }

    public void insertQuarter() {
        System.out.println("Machine is sold out.");
    }

    public void ejectQuarter() {
        System.out.println("No quarter to eject.");
    }

    public void turnCrank() {
        System.out.println("Machine is sold out.");
    }

    public void dispense() {
        System.out.println("No gumball dispensed.");
    }
}

