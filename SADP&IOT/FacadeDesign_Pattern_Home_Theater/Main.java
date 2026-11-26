package S15;

public class Main {

    public static void main(String[] args) {

        DVDPlayer dvd = new DVDPlayer();
        Projector projector = new Projector();
        Amplifier amplifier = new Amplifier();
        TheaterLights lights = new TheaterLights();

        HomeTheaterFacade homeTheater =
            new HomeTheaterFacade(
                dvd, projector, amplifier, lights);

        homeTheater.watchMovie();

        homeTheater.endMovie();
    }
}

