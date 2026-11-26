package S6;

public class RemoteControl {
    private static final int SLOTS = 7;
    private final Command[] onCommands = new Command[SLOTS];
    private final Command[] offCommands = new Command[SLOTS];

    RemoteControl() {
        Command none = new NoCommand();
        for (int i = 0; i < SLOTS; i++) {
            onCommands[i] = none;
            offCommands[i] = none;
        }
    }

    void setCommand(int slot, Command on, Command off) {
        onCommands[slot] = on;
        offCommands[slot] = off;
    }

    void onButtonWasPushed(int slot)  { onCommands[slot].execute(); }
    void offButtonWasPushed(int slot) { offCommands[slot].execute(); }

    public String toString() {
        StringBuilder sb = new StringBuilder("\n------ Remote Control ------\n");
        for (int i = 0; i < SLOTS; i++) {
            sb.append("[slot ").append(i).append("] ")
              .append(onCommands[i].getClass().getSimpleName()).append("    ")
              .append(offCommands[i].getClass().getSimpleName()).append("\n");
        }
        return sb.toString();
    }
}
