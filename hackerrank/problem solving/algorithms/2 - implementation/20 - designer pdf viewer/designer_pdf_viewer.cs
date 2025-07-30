// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        List<int> lettersHeights = ReadNumbers();
        String word = Console.ReadLine()!;
        Console.WriteLine(DesignerPdfViewer(lettersHeights, word));
    }

    private static List<int> ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToList();
    }

    private static int DesignerPdfViewer(List<int> lettersHeights, string word)
    {
        return word.Max(letter => lettersHeights[letter - 'a']) * word.Length;
    }
}
