// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

int[] positionsAndVelocities = ReadNumbers();
Console.WriteLine(Kangaroo(positionsAndVelocities) ? "YES" : "NO");

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

bool Kangaroo(int[] positionsAndVelocities)
{
    int x1 = positionsAndVelocities[0];
    int v1 = positionsAndVelocities[1];
    int x2 = positionsAndVelocities[2];
    int v2 = positionsAndVelocities[3];

    if (v1 == v2)
        return x1 == x2;

    int distanceDiff = x2 - x1;
    int velocityDiff = v1 - v2;
    return distanceDiff * velocityDiff >= 0 && distanceDiff % velocityDiff == 0;
}
