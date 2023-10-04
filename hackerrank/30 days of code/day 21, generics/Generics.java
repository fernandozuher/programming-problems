// https://www.hackerrank.com/challenges/30-generics/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Generics {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine(); // new line character
        List<Integer> intList = (Arrays.asList(new Integer[n])).stream().map(x -> x = scan.nextInt()).collect(toList());;

        n = scan.nextInt();
        scan.nextLine(); // new line character
        List<String> stringList = (Arrays.asList(new String[n])).stream().map(x -> x = scan.nextLine()).collect(toList());;

        var intPrinter = new Printer<Integer>();
        var stringPrinter = new Printer<String>();
        intPrinter.printList(intList);
        stringPrinter.printList(stringList);
    }
}

    class Printer <T> {
        public void printList(final List<T> l) {
            l.forEach(System.out::println);
        }
    }
