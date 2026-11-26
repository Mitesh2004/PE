package S16;

import java.util.*;

public class NumberConverter implements Subject {

    private String decimal;
    private List<Observer> observers;

    public NumberConverter() {
        observers = new ArrayList<>();
    }

    public void attach(Observer observer) {
        observers.add(observer);
    }

    public void detach(Observer observer) {
        observers.remove(observer);
    }

    public void setNumber(String number, int base) {

        int value = Integer.parseInt(number, base);

        decimal = String.valueOf(value);

        notifyObservers();
    }

    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(decimal);
        }
    }
}

