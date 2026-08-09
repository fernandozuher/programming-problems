// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n = Reader.read(Integer::parseInt);
    for (int i = 0; i < n; i++) {
        int prisoners = Reader.read(Integer::parseInt);
        int sweets = Reader.read(Integer::parseInt);
        int startChair = Reader.read(Integer::parseInt);
        IO.println(saveThePrisoner(prisoners, sweets, startChair));
    }
}

// T: O(1)
// S: O(1) extra space
int saveThePrisoner(int prisoners, int sweets, int startChair) {
    return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
