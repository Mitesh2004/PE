package S16;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        NumberConverter converter = new NumberConverter();

        converter.attach(new DecimalObserver());
        converter.attach(new BinaryObserver());
        converter.attach(new OctalObserver());
        converter.attach(new HexaObserver());

        while (true) {

            System.out.println("\nNUMBER CONVERSION");
            System.out.println("1. Decimal");
            System.out.println("2. Binary");
            System.out.println("3. Octal");
            System.out.println("4. Hexadecimal");
            System.out.println("5. Exit");

            System.out.print("Select Number System: ");
            int choice = sc.nextInt();

            if (choice == 5) {
                System.out.println("Program Ended.");
                break;
            }

            int base;

            switch (choice) {

                case 1:
                    base = 10;
                    break;

                case 2:
                    base = 2;
                    break;

                case 3:
                    base = 8;
                    break;

                case 4:
                    base = 16;
                    break;

                default:
                    System.out.println("Invalid Choice!");
                    continue;
            }

            System.out.print("Enter Number: ");
            String number = sc.next();

            try {

                System.out.println("\nConverted Values:");

                converter.setNumber(number, base);

            } catch (NumberFormatException e) {

                System.out.println("Invalid Number for selected base!");

            }
        }

        sc.close();
    }
}

