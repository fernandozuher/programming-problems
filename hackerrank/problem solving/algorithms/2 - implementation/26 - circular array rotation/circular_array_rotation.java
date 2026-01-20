// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true
// Java 25

void main() {
    int[] line = readNumbers();
    int nRotation = line[1];
    int nQueries = line[2];
    int[] arr = readNumbers();
    printQueries(arr, nRotation, nQueries);
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// T: O(nQueries)
// S: O(1) extra space
void printQueries(int[] arr, int nRotation, int nQueries) {
    int n = arr.length;
    int offset = n - nRotation % n;
    for (int i = 0; i < nQueries; i++) {
        int query = Integer.parseInt(IO.readln());
        int idx = (query + offset) % n;
        IO.println(arr[idx]);
    }
}
