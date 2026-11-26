package S5;

import java.util.*;

public class Main {

    public static void main(String[] args) {

        Vector<String> v = new Vector<String>();

        v.add("Apple");
        v.add("Banana");
        v.add("Mango");
        v.add("Orange");

        Enumeration<String> e = v.elements();

        Iterator<Object> iterator = new EnumerationIterator(e);

        System.out.println("Elements using Iterator:");

        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}

