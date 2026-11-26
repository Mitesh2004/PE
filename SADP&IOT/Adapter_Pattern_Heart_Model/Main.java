package S11;

public class Main {

    public static void main(String[] args) {

        HeartModel heart = new HeartModel();

        BeatModelInterface beat =
                new HeartAdapter(heart);

        beat.initialize();

        beat.on();

        System.out.println("Heart Rate: "
                + beat.getBPM() + " BPM");

        beat.setBPM(100);

        beat.off();
    }
}

