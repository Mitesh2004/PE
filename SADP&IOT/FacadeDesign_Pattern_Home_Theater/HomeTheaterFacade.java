package S15;

public class HomeTheaterFacade {

    DVDPlayer dvd;
    Projector projector;
    Amplifier amplifier;
    TheaterLights lights;

    public HomeTheaterFacade(DVDPlayer dvd,
                             Projector projector,
                             Amplifier amplifier,
                             TheaterLights lights) {

        this.dvd = dvd;
        this.projector = projector;
        this.amplifier = amplifier;
        this.lights = lights;
    }

    public void watchMovie() {

        System.out.println("\nStarting Movie...");

        lights.dim(10);
        projector.on();
        projector.wideScreenMode();
        amplifier.on();
        amplifier.setVolume(10);
        dvd.on();
        dvd.play();
    }

    public void endMovie() {

        System.out.println("\nEnding Movie...");

        dvd.off();
        amplifier.off();
        projector.off();
        lights.on();
    }
}

