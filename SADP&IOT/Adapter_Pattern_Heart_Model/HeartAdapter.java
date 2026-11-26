package S11;

public class HeartAdapter implements BeatModelInterface {

    HeartModelInterface heart;

    public HeartAdapter(HeartModelInterface heart) {
        this.heart = heart;
    }

    public void initialize() {
        System.out.println("Heart Adapter Initialized.");
    }

    public void on() {
        heart.start();
    }

    public void off() {
        heart.stop();
    }

    public int getBPM() {
        return heart.getHeartRate();
    }

    public void setBPM(int bpm) {
        System.out.println("Heart rate cannot be changed manually.");
    }
}

