package S7;

public class CeilingFan {
    static final int OFF = 0, LOW = 1, MEDIUM = 2, HIGH = 3;
    private final String location;
    private int speed = OFF;
    private int lastSpeed = LOW;      // speed used by START

    CeilingFan(String location) { this.location = location; }

    int getSpeed() { return speed; }

    void setSpeed(int s) {
        speed = s;
        if (s != OFF) lastSpeed = s;
        switch (s) {
            case LOW:    System.out.println(location + " ceiling fan is on LOW");    break;
            case MEDIUM: System.out.println(location + " ceiling fan is on MEDIUM"); break;
            case HIGH:   System.out.println(location + " ceiling fan is on HIGH");   break;
            default:     System.out.println(location + " ceiling fan is OFF");
        }
    }

    /** Power on at the last used speed (LOW the first time). */
    void start() {
        if (speed != OFF) {
            System.out.println(location + " ceiling fan is already running");
        } else {
            System.out.print("Starting... ");
            setSpeed(lastSpeed);
        }
    }
}
