package S16;

public class HexaObserver implements Observer {

    public void update(String number) {
        int value = Integer.parseInt(number);

        System.out.println("Hexadecimal: "
                + Integer.toHexString(value).toUpperCase());
    }
}
