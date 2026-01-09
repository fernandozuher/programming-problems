// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

int n = ReadNumbers()[0];
for (int i = 0; i < n; i++)
    Console.WriteLine(FindNearestCatOrNot(ReadPositions()));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

(int, int, int) ReadPositions()
{
    var nums = Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
    return (nums[0], nums[1], nums[2]);
}

// T: O(1)
// S: O(1) extra space
string FindNearestCatOrNot((int, int, int) positions)
{
    var (catA, catB, mouse) = positions;
    int catAFromMouse = Math.Abs(catA - mouse);
    int catBFromMouse = Math.Abs(catB - mouse);

    if (catAFromMouse < catBFromMouse)
        return "Cat A";
    if (catAFromMouse > catBFromMouse)
        return "Cat B";
    return "Mouse C";
}
