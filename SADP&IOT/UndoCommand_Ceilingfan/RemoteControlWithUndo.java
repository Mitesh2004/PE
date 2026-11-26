package S7;

public class RemoteControlWithUndo {
    private static final int SLOTS = 7;
    private final Command[] commands = new Command[SLOTS];
    private Command undoCommand = new NoCommand();

    RemoteControlWithUndo() {
        for (int i = 0; i < SLOTS; i++) commands[i] = new NoCommand();
    }

    void setCommand(int slot, Command c) { commands[slot] = c; }

    void buttonWasPushed(int slot) {
        commands[slot].execute();
        undoCommand = commands[slot];
    }

    void undoButtonWasPushed() {
        System.out.print("[UNDO] ");
        undoCommand.undo();
    }
}
