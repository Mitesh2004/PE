package S14;

public class Main {

    public static void main(String[] args) {

        RemoteControl remote = new RemoteControl();

        Light light = new Light();
        GarageDoor garage = new GarageDoor();
        Stereo stereo = new Stereo();

        remote.setCommand(new LightOnCommand(light));
        remote.buttonPressed();

        remote.setCommand(new LightOffCommand(light));
        remote.buttonPressed();

        remote.setCommand(new GarageDoorUpCommand(garage));
        remote.buttonPressed();

        remote.setCommand(new StereoOnWithCDCommand(stereo));
        remote.buttonPressed();
    }
}

