import java.util.*;

class Solution {
    public static void removeDuplicates(LinkedList<String> dataList) {
        for (int i = 0; i < dataList.size() - 1; )
            if (dataList.get(i).equals(dataList.get(i + 1)))
                dataList.remove(i + 1);
            else
                i++;
    }

    public static void display(LinkedList<String> dataList) {
        for (var data : dataList)
            System.out.print(data + " ");
    }
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        var dataList = new LinkedList<String>();

        for (int n = sc.nextInt(); n-- > 0; dataList.add(sc.next()));

        removeDuplicates(dataList);
        display(dataList);
    }
}
