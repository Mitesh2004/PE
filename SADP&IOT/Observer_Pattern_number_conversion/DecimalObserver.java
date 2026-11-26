package S16;

public class DecimalObserver implements Observer {

    public void update(String number) {
        int value = Integer.parseInt(number);

        System.out.println("Decimal: " + value);
    }
}
