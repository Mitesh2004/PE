package S6;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        RemoteControl remote = new RemoteControl();

        Light livingRoomLight = new Light("Living Room");
        Fan livingRoomFan = new Fan("Living Room");
        Light bedroomLight = new Light("Bedroom");
        Fan bedroomFan = new Fan("Bedroom");
        Light parkingLight = new Light("Parking");

        remote.setCommand(0, new LightOnCommand(livingRoomLight), new LightOffCommand(livingRoomLight));
        remote.setCommand(1, new FanOnCommand(livingRoomFan), new FanOffCommand(livingRoomFan));
        remote.setCommand(2, new LightOnCommand(bedroomLight), new LightOffCommand(bedroomLight));
        remote.setCommand(3, new FanOnCommand(bedroomFan), new FanOffCommand(bedroomFan));
        remote.setCommand(4, new LightOnCommand(parkingLight), new LightOffCommand(parkingLight));

        System.out.println(remote);
        System.out.println("Slot 0 = Living Room light");
        System.out.println("Slot 1 = Living Room fan");
        System.out.println("Slot 2 = Bedroom light");
        System.out.println("Slot 3 = Bedroom fan");
        System.out.println("Slot 4 = Parking light");
        System.out.println("Slot 5, 6 = empty");

        while (true) {
            System.out.print("\nEnter slot (0-6) or -1 to exit: ");
            int slot = readInt(sc);
            if (slot == -1) break;
            if (slot < 0 || slot > 6) {
                System.out.println("Invalid slot.");
                continue;
            }
            System.out.print("Press button: 1) ON   2) OFF : ");
            int btn = readInt(sc);
            if (btn == 1) remote.onButtonWasPushed(slot);
            else if (btn == 2) remote.offButtonWasPushed(slot);
            else System.out.println("Invalid button.");
        }
        System.out.println("Remote turned off.");
    }

    private static int readInt(Scanner sc) {
        if (!sc.hasNextLine()) return -1;
        try {
            return Integer.parseInt(sc.nextLine().trim());
        } catch (NumberFormatException e) {
            return -99;
        }
    }
}
