// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

int n = ReadNumbers()[0];
for (int i = 0; i < n; i++)
    Console.WriteLine(FindNearestCatOrNot(ReadNumbers()));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

string FindNearestCatOrNot(int[] positions)
{
    int catA = positions[0];
    int catB = positions[1];
    int mouse = positions[2];
    int catAFromMouse = Math.Abs(catA - mouse);
    int catBFromMouse = Math.Abs(catB - mouse);

    if (catAFromMouse < catBFromMouse)
        return "Cat A";
    if (catAFromMouse > catBFromMouse)
        return "Cat B";
    return "Mouse C";
}
