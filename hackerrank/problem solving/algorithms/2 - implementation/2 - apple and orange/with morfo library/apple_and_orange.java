// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

record House(int start, int end) {
    public boolean contains(int position) {
        return start <= position && position <= end;
    }
}

record FruitTree(int treeLocation, int[] fruitDistances) {
}

record Input(House house, FruitTree appleTree, FruitTree orangeTree) {
}

void main() {
    var input = readInput();
    House house = input.house();
    FruitTree appleTree = input.appleTree();
    FruitTree orangeTree = input.orangeTree();

    IO.println(countFruitsOnHouse(appleTree, house));
    IO.println(countFruitsOnHouse(orangeTree, house));
}

Input readInput() {
    int houseStart = Reader.read(Integer::parseInt);
    int houseEnd = Reader.read(Integer::parseInt);
    var house = new House(houseStart, houseEnd);

    int appleTreeLocation = Reader.read(Integer::parseInt);
    int orangeTreeLocation = Reader.read(Integer::parseInt);

    int nApples = Reader.read(Integer::parseInt);
    int nOranges = Reader.read(Integer::parseInt);

    var appleTree = new FruitTree(appleTreeLocation, readNums(nApples));
    var orangeTree = new FruitTree(orangeTreeLocation, readNums(nOranges));

    return new Input(house, appleTree, orangeTree);
}

int[] readNums(int n) {
    return Reader.read(n, Integer::parseInt).stream().mapToInt(Integer::intValue).toArray();
}

// n: length of fruitTree.fruitDistances
// T: O(n)
// S: O(1) extra space
int countFruitsOnHouse(FruitTree fruitTree, House house) {
    return (int) Arrays.stream(fruitTree.fruitDistances())
            .filter(distance -> house.contains(fruitTree.treeLocation() + distance))
            .count();
}
