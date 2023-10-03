// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

import java.util.Scanner;
import java.util.LinkedList;

public class LinkedListExercise {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        LinkedList list = new LinkedList();

        for (; scan.hasNext(); list.add(scan.nextInt()));
        for (var element : list)
            System.out.print(element + " ");
    }
}
