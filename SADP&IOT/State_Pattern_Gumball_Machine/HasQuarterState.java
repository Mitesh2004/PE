package S8;

public class HasQuarterState implements State {

    GumballMachine machine;

    public HasQuarterState(GumballMachine machine) {
        this.machine = machine;
    }

    public void insertQuarter() {
        System.out.println("You can't insert another quarter.");
    }

    public void ejectQuarter() {
        System.out.println("Quarter returned.");
        machine.setState(machine.getNoQuarterState());
    }

    public void turnCrank() {
        System.out.println("You turned the crank...");
        machine.setState(machine.getSoldState());
    }

    public void dispense() {
        System.out.println("No gumball dispensed.");
    }
}

