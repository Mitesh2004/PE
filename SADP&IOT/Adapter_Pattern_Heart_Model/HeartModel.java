package S11;

public class HeartModel implements HeartModelInterface {

    private int heartRate = 72;

    public int getHeartRate() {
        return heartRate;
    }

    public void start() {
        System.out.println("Heart Model Started.");
    }

    public void stop() {
        System.out.println("Heart Model Stopped.");
    }
}

