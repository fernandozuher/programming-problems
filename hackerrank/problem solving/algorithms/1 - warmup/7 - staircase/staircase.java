// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

void main() {
    int n = Integer.parseInt(IO.readln());
    staircase(n);
}

// T: O(n^2)
// S: O(n) extra space
void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        var spaces = " ".repeat(n - i);
        var hashes = "#".repeat(i);
        IO.println(spaces + hashes);
    }
}
