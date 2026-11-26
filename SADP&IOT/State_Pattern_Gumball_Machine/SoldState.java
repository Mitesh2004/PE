package S8;

public class SoldState implements State {

    GumballMachine machine;

    public SoldState(GumballMachine machine) {
        this.machine = machine;
    }

    public void insertQuarter() {
        System.out.println("Please wait, we're already giving you a gumball.");
    }

    public void ejectQuarter() {
        System.out.println("Sorry, you already turned the crank.");
    }

    public void turnCrank() {
        System.out.println("Turning twice doesn't get you another gumball!");
    }

    public void dispense() {
        machine.releaseBall();

        if (machine.getCount() > 0) {
            machine.setState(machine.getNoQuarterState());
        } else {
            System.out.println("Oops, out of gumballs!");
            machine.setState(machine.getSoldOutState());
        }
    }
}

