// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

import java.util.LinkedList;
import java.util.Scanner;

public class MoreLinkedLists {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        var dataList = new LinkedList<String>();

        for (int n = scan.nextInt(); n-- > 0; dataList.add(scan.next()));

        removeDuplicates(dataList);
        display(dataList);
    }

        public static void display(LinkedList<String> l) {
            for (var el : l)
                System.out.print(el + " ");
        }

        public static void removeDuplicates(LinkedList<String> l) {
            for (int i = 0; i < l.size() - 1;)
                if (l.get(i).equals(l.get(i + 1)))
                    l.remove(i + 1);
                else
                    ++i;
        }
}
