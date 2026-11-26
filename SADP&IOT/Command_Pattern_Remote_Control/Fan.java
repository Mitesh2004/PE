package S6;

public class Fan {
    private final String location;
    Fan(String location) { this.location = location; }
    void on()  { System.out.println(location + " fan is ON"); }
    void off() { System.out.println(location + " fan is OFF"); }
}
