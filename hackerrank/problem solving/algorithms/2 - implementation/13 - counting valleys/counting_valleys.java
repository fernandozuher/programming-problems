// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    String steps = IO.readln();
    IO.println(countingValleys(steps));
}

// n: length of steps
// T: O(n)
// S: O(1) extra space
int countingValleys(String steps) {
    int valleys = 0;
    int currentAltitude = 0;

    for (int i = 0; i < steps.length(); i++) {
        char step = steps.charAt(i);
        boolean wasBelowSeaLevel = currentAltitude < 0;
        currentAltitude += step == 'D' ? -1 : 1;
        boolean isInSeaLevelFromValley = wasBelowSeaLevel && currentAltitude == 0;
        if (isInSeaLevelFromValley) valleys++;
    }

    return valleys;
}
