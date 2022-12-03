import java.util.Scanner;
import java.util.LinkedList;

public class Solution {
    public static void main(String[] args) {
        
        var scanner = new Scanner(System.in);
        var n = scanner.nextInt();
        var list = new LinkedList();

        for (; scanner.hasNext(); list.add(scanner.nextInt()));
        for (var element : list)
            System.out.print(element + " ");
    }
}
