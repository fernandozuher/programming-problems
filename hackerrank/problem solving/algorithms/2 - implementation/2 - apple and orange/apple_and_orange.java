// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// Java 16

import java.util.*;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            var input = readInput(scan);

            House house = input.house();
            FruitTree appleTree = input.appleTree();
            FruitTree orangeTree = input.orangeTree();

            System.out.println(countFruitsOnHouse(appleTree, house));
            System.out.println(countFruitsOnHouse(orangeTree, house));
        }
    }

    private static Input readInput(Scanner scan) {
        var house = new House(scan.nextInt(), scan.nextInt());
        var appleTreeLocation = scan.nextInt();
        var orangeTreeLocation = scan.nextInt();

        var appleCount = scan.nextInt();
        var orangeCount = scan.nextInt();
        scan.nextLine(); // Discard new line

        var appleTree = new FruitTree(appleTreeLocation, readNumbers(scan));
        var orangeTree = new FruitTree(orangeTreeLocation, readNumbers(scan));

        return new Input(house, appleTree, orangeTree);
    }

    private static int[] readNumbers(Scanner scan) {
        return Arrays.stream(scan.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    private static int countFruitsOnHouse(FruitTree fruitTree, House house) {
        return (int) Arrays.stream(fruitTree.fruitDistances())
                .map(distance -> fruitTree.treeLocation() + distance)
                .filter(house::contains)
                .count();
    }
}

record House(int start, int end) {
    public boolean contains(int position) {
        return start <= position && position <= end;
    }
}

record FruitTree(int treeLocation, int[] fruitDistances) {
}

record Input(House house, FruitTree appleTree, FruitTree orangeTree) {
}
