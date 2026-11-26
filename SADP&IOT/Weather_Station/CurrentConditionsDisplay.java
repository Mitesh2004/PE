package S3;

import java.util.Observable;
import java.util.Observer;

@SuppressWarnings("deprecation")
public class CurrentConditionsDisplay implements Observer, DisplayElement {
    private float temperature, humidity, pressure;

    public CurrentConditionsDisplay(Observable observable) {
        observable.addObserver(this);
    }

    @Override
    public void update(Observable o, Object arg) {
        if (o instanceof WeatherData) {
            WeatherData w = (WeatherData) o;
            this.temperature = w.getTemperature();
            this.humidity = w.getHumidity();
            this.pressure = w.getPressure();
            display();
        }
    }

    @Override
    public void display() {
        System.out.println("Current conditions: " + temperature + "C, "
                + humidity + "% humidity, " + pressure + " hPa");
    }
}
