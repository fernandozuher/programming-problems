// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

int n = ReadNumbers()[0];
for (int i = 0; i < n; i++)
    Console.WriteLine(FindNearestCatOrNot(ReadNumbers()));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// T: O(1)
// S: O(1) extra space
string FindNearestCatOrNot(int[] positions)
{
    var (catA, catB, mouse) = (positions[0], positions[1], positions[2]);
    int catAFromMouse = Math.Abs(catA - mouse);
    int catBFromMouse = Math.Abs(catB - mouse);

    if (catAFromMouse < catBFromMouse)
        return "Cat A";
    if (catAFromMouse > catBFromMouse)
        return "Cat B";
    return "Mouse C";
}
