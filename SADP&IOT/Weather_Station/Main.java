package S3;

public class Main {
    public static void main(String[] args) {
        WeatherData weatherData = new WeatherData();
        new CurrentConditionsDisplay(weatherData);
        new StatisticsDisplay(weatherData);

        weatherData.setMeasurements(27, 65, 1013.1f);
        weatherData.setMeasurements(30, 70, 1012.5f);
        weatherData.setMeasurements(24, 90, 1010.0f);
    }
}
