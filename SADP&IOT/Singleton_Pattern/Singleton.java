package S2;

/** Thread-safe Singleton using double-checked locking. */
public class Singleton {
    private static volatile Singleton uniqueInstance;

    private Singleton() {
        System.out.println("Singleton instance created by " + Thread.currentThread().getName());
    }

    public static Singleton getInstance() {
        if (uniqueInstance == null) {                  // 1st check (no lock)
            synchronized (Singleton.class) {
                if (uniqueInstance == null) {          // 2nd check (locked)
                    uniqueInstance = new Singleton();
                }
            }
        }
        return uniqueInstance;
    }
}
