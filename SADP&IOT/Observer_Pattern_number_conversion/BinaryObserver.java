package S16;

public class BinaryObserver implements Observer {

    public void update(String number) {
        int value = Integer.parseInt(number);

        System.out.println("Binary: "
                + Integer.toBinaryString(value));
    }
}
