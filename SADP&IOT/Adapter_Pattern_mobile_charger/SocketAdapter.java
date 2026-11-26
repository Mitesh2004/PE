
package S13;

public class SocketAdapter extends Socket {

    public Volt get3Volt() {
        Volt v = getVolt();
        return new Volt(v.getVolts() / 40);
    }

    public Volt get12Volt() {
        Volt v = getVolt();
        return new Volt(v.getVolts() / 10);
    }

    public Volt get120Volt() {
        return getVolt();
    }
}

