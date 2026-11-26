package S16;

public class OctalObserver implements Observer {

    public void update(String number) {
        int value = Integer.parseInt(number);

        System.out.println("Octal: "
                + Integer.toOctalString(value));
    }
}
