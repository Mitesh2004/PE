package S3;

import java.util.Observable;

/** Subject: uses built-in java.util.Observable. */
@SuppressWarnings("deprecation")
public class WeatherData extends Observable {
    private float temperature;
    private float humidity;
    private float pressure;

    public void measurementsChanged() {
        setChanged();          // mark state as changed
        notifyObservers();     // pull model: observers call getters
    }

    public void setMeasurements(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
        measurementsChanged();
    }

    public float getTemperature() { return temperature; }
    public float getHumidity()    { return humidity; }
    public float getPressure()    { return pressure; }
}
