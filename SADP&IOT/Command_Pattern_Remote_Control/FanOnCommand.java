package S6;

public class FanOnCommand implements Command {
    private final Fan fan;
    FanOnCommand(Fan fan) { this.fan = fan; }
    public void execute() { fan.on(); }
}
