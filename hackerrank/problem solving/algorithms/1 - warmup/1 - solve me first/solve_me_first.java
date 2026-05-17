// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true
// Java 25

void main() {
    int n1 = Integer.parseInt(IO.readln());
    int n2 = Integer.parseInt(IO.readln());
    IO.println(solveMeFirst(n1, n2));
}

// T: O(1)
// S: O(1) extra space
int solveMeFirst(int n1, int n2) {
    return n1 + n2;
}
