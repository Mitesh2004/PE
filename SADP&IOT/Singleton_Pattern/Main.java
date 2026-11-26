package S2;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Thread[] threads = new Thread[5];
        for (int i = 0; i < threads.length; i++) {
            threads[i] = new Thread(() -> {
                Singleton s = Singleton.getInstance();
                System.out.println(Thread.currentThread().getName()
                        + " got instance hash: " + System.identityHashCode(s));
            }, "Thread-" + (i + 1));
        }
        for (Thread t : threads) t.start();
        for (Thread t : threads) t.join();
    }
}
