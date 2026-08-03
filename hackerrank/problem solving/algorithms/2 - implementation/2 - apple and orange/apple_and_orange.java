// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// Java 25

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
    var arr = readNums();
    var house = new House(arr[0], arr[1]);

    arr = readNums();
    var appleTreeLocation = arr[0];
    var orangeTreeLocation = arr[1];

    readNums(); // Discard array sizes

    var appleTree = new FruitTree(appleTreeLocation, readNums());
    var orangeTree = new FruitTree(orangeTreeLocation, readNums());

    return new Input(house, appleTree, orangeTree);
}

int[] readNums() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of fruitTree.fruitDistances
// T: O(n)
// S: O(1) extra space
int countFruitsOnHouse(FruitTree fruitTree, House house) {
    return (int) Arrays.stream(fruitTree.fruitDistances())
            .filter(distance -> house.contains(fruitTree.treeLocation() + distance))
            .count();
}
