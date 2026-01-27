// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true
// Java 25

void main() {
    int n = readNumbers()[0];
    for (int i = 0; i < n; i++) {
        var range = readNumbers();
        IO.println(squares(range[0], range[1]));
    }
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// T: O(1)
// S: O(1) extra space
int squares(int startNum, int endNum) {
    int maxSquare = (int) Math.floor(Math.sqrt(endNum));
    int minSquare = (int) Math.ceil(Math.sqrt(startNum));
    return maxSquare - minSquare + 1;
}
