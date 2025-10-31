// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true
// Java 25

import java.lang.IO;

void main() {
    IO.readln();
    String steps = IO.readln();
    IO.println(countingValleys(steps));
}

int countingValleys(String steps) {
    int valleys = 0;
    int currentAltitude = 0;

    for (char step : steps.toCharArray()) {
        boolean wasBelowSeaLevel = currentAltitude < 0;
        currentAltitude += step == 'D' ? -1 : 1;
        boolean isInSeaLevelFromValley = wasBelowSeaLevel && currentAltitude == 0;
        if (isInSeaLevelFromValley) valleys++;
    }

    return valleys;
}
