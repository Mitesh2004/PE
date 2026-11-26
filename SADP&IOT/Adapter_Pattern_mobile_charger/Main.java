package S13;

public class Main {

    public static void main(String[] args) {

        SocketAdapter adapter = new SocketAdapter();

        System.out.println("Mobile Charger Adapter");

        System.out.println("3 Volts: "
                + adapter.get3Volt().getVolts() + "V");

        System.out.println("12 Volts: "
                + adapter.get12Volt().getVolts() + "V");

        System.out.println("Default Voltage: "
                + adapter.get120Volt().getVolts() + "V");
    }
}

