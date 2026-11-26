package S6;

public class Light {
    private final String location;
    Light(String location) { this.location = location; }
    void on()  { System.out.println(location + " light is ON"); }
    void off() { System.out.println(location + " light is OFF"); }
}
