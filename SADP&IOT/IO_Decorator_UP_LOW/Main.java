package S1;

import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("=== I/O Decorator: Uppercase -> Lowercase ===");
        System.out.println("Type text and press Enter. Type 'exit' to quit.\n");

        while (true) {
            System.out.print("Enter text: ");
            if (!sc.hasNextLine()) break;
            String text = sc.nextLine();
            if (text.equalsIgnoreCase("exit")) break;

            try (InputStream in = new LowerCaseInputStream(
                    new BufferedInputStream(
                            new ByteArrayInputStream(text.getBytes())))) {
                StringBuilder sb = new StringBuilder();
                int c;
                while ((c = in.read()) >= 0) {
                    sb.append((char) c);
                }
                System.out.println("Output    : " + sb + "\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Bye!");
    }
}
