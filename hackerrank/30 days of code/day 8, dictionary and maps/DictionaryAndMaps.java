// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

import java.util.Scanner;
import java.util.HashMap;

public class DictionaryAndMaps {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        var phoneBook = new HashMap<String, String>();

        while (n-- > 0) {
            String[] entry = scanner.nextLine().split(" ");
            phoneBook.put(entry[0], entry[1]);
        }

        for (String name, phone; scanner.hasNextLine();) {
            name = scanner.nextLine();
            if ((phone = phoneBook.get(name)) != null)
                System.out.println(name + '=' + phone);
            else
                System.out.println("Not found");
        }
    }
}
