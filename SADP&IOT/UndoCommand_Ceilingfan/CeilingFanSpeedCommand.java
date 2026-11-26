package S7;

/** One class handles LOW, MEDIUM, HIGH and OFF. */
public class CeilingFanSpeedCommand implements Command {
    private final CeilingFan fan;
    private final int speed;
    private int prevSpeed;
    CeilingFanSpeedCommand(CeilingFan fan, int speed) { this.fan = fan; this.speed = speed; }
    public void execute() { prevSpeed = fan.getSpeed(); fan.setSpeed(speed); }
    public void undo()    { fan.setSpeed(prevSpeed); }
}
