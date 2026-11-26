package S4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PizzaStore nyStore = new NYPizzaStore();
        PizzaStore chicagoStore = new ChicagoPizzaStore();

        System.out.println("=== Pizza Store (Factory Method) ===");
        while (true) {
            System.out.println("\nSelect store:  1) NY Style   2) Chicago Style   0) Exit");
            System.out.print("Choice: ");
            int store = readInt(sc);
            if (store == 0) break;
            if (store != 1 && store != 2) {
                System.out.println("Invalid store choice.");
                continue;
            }

            System.out.println("Select pizza:  1) Cheese   2) Veggie");
            System.out.print("Choice: ");
            int p = readInt(sc);
            String type;
            if (p == 1) type = "cheese";
            else if (p == 2) type = "veggie";
            else {
                System.out.println("Invalid pizza choice.");
                continue;
            }

            System.out.println();
            (store == 1 ? nyStore : chicagoStore).orderPizza(type);
        }
        System.out.println("Thank you, visit again!");
    }

    private static int readInt(Scanner sc) {
        if (!sc.hasNextLine()) return 0;
        try {
            return Integer.parseInt(sc.nextLine().trim());
        } catch (NumberFormatException e) {
            return -1;
        }
    }
}
