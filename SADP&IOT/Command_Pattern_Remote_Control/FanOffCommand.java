package S6;

public class FanOffCommand implements Command {
    private final Fan fan;
    FanOffCommand(Fan fan) { this.fan = fan; }
    public void execute() { fan.off(); }
}
