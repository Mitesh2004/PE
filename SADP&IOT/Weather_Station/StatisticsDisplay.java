package S3;

import java.util.Observable;
import java.util.Observer;

@SuppressWarnings("deprecation")
public class StatisticsDisplay implements Observer, DisplayElement {
    private float max = Float.MIN_VALUE, min = Float.MAX_VALUE, sum = 0;
    private int count = 0;

    public StatisticsDisplay(Observable observable) {
        observable.addObserver(this);
    }

    @Override
    public void update(Observable o, Object arg) {
        if (o instanceof WeatherData) {
            float t = ((WeatherData) o).getTemperature();
            sum += t;
            count++;
            if (t > max) max = t;
            if (t < min) min = t;
            display();
        }
    }

    @Override
    public void display() {
        System.out.println("Avg/Max/Min temperature = " + (sum / count) + "/" + max + "/" + min);
    }
}
