// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int n = Reader.read(Integer::parseInt);
    int[] utopianTree = generateHeightsUtopianTree();
    for (int i = 0; i < n; i++) {
        int cycles = Reader.read(Integer::parseInt);
        IO.println(utopianTree[cycles]);
    }
}

// k: length of output = 61
// T: O(k) = O(61) = O(1)
// S: O(61) = O(1) extra space
int[] generateHeightsUtopianTree() {
    final int maxCycles = 60;
    int[] heights = new int[maxCycles + 1];

    for (int cycle = 0, n = maxCycles + 1, height = 0; cycle < n; cycle++) {
        height += isCycleHappeningDuringSpring(cycle) ? height : 1;
        heights[cycle] = height;
    }

    return heights;
}

boolean isCycleHappeningDuringSpring(int cycle) {
    return (cycle & 1) == 1;
}
