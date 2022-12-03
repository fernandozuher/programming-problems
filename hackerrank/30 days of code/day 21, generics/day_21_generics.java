import java.util.*;

class Printer <T> {
    void printArray(T[] array) {
        for (var val : array)
            System.out.println(val);
    }
}

public class Generics {
    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        Integer[] intArray = new Integer[n];
        for (int i = 0; i < n; intArray[i++] = scanner.nextInt());

        n = scanner.nextInt();
        String[] stringArray = new String[n];
        for (int i = 0; i < n; stringArray[i++] = scanner.next());
        
        var intPrinter = new Printer<Integer>();
        var stringPrinter = new Printer<String>();
        intPrinter.printArray(intArray);
        stringPrinter.printArray(stringArray);
        
        if(Printer.class.getDeclaredMethods().length > 1){
            System.out.println("The Printer class should only have 1 method named printArray.");
        }
    } 
}
