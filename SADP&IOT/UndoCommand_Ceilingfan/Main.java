package S7;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        RemoteControlWithUndo remote = new RemoteControlWithUndo();
        CeilingFan fan = new CeilingFan("Living Room");

        remote.setCommand(0, new CeilingFanStartCommand(fan));
        remote.setCommand(1, new CeilingFanSpeedCommand(fan, CeilingFan.LOW));
        remote.setCommand(2, new CeilingFanSpeedCommand(fan, CeilingFan.MEDIUM));
        remote.setCommand(3, new CeilingFanSpeedCommand(fan, CeilingFan.HIGH));
        remote.setCommand(4, new CeilingFanSpeedCommand(fan, CeilingFan.OFF));

        System.out.println("=== Ceiling Fan Remote (with Undo) ===");
        while (true) {
            System.out.println("\n1) Start  2) Low  3) Medium  4) High  5) Off  6) Undo  7) Exit");
            System.out.print("Choice: ");
            int ch = readInt(sc);
            if (ch == 7) break;
            if (ch >= 1 && ch <= 5) remote.buttonWasPushed(ch - 1);
            else if (ch == 6) remote.undoButtonWasPushed();
            else System.out.println("Invalid choice.");
        }
        System.out.println("Remote turned off.");
    }

    private static int readInt(Scanner sc) {
        if (!sc.hasNextLine()) return 7;
        try {
            return Integer.parseInt(sc.nextLine().trim());
        } catch (NumberFormatException e) {
            return -1;
        }
    }
}
