// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

Console.ReadLine();
string steps = Console.ReadLine()!;
Console.WriteLine(CountingValleys(steps));

int CountingValleys(string steps)
{
    int valleys = 0;
    int currentAltitude = 0;

    foreach (char step in steps)
    {
        bool wasBelowSeaLevel = currentAltitude < 0;
        currentAltitude += step == 'D' ? -1 : 1;
        bool isInSeaLevelFromValley = wasBelowSeaLevel && currentAltitude == 0;
        if (isInSeaLevelFromValley)
            valleys++;
    }

    return valleys;
}
