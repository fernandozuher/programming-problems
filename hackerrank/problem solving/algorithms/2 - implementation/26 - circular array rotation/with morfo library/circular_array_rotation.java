// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

import java.util.List;

void main() {
    int n = Reader.read(Integer::parseInt);
    int nRotation = Reader.read(Integer::parseInt);
    int nQueries = Reader.read(Integer::parseInt);
    List<Integer> arr = Reader.read(n, Integer::parseInt);
    printQueries(arr, nRotation, nQueries);
}

// T: O(nQueries)
// S: O(1) extra space
void printQueries(List<Integer> arr, int nRotation, int nQueries) {
    int n = arr.size();
    int offset = n - nRotation % n;
    for (int i = 0; i < nQueries; i++) {
        int query = Reader.read(Integer::parseInt);
        int idx = (query + offset) % n;
        IO.println(arr.get(idx));
    }
}
