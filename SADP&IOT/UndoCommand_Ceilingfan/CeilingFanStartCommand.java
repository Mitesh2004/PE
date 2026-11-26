package S7;

public class CeilingFanStartCommand implements Command {
    private final CeilingFan fan;
    private int prevSpeed;
    CeilingFanStartCommand(CeilingFan fan) { this.fan = fan; }
    public void execute() { prevSpeed = fan.getSpeed(); fan.start(); }
    public void undo()    { fan.setSpeed(prevSpeed); }
}
