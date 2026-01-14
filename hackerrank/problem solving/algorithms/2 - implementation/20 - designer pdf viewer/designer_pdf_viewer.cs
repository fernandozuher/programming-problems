// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

int[] lettersHeights = ReadNumbers();
String word = Console.ReadLine()!;
Console.WriteLine(DesignerPdfViewer(lettersHeights, word));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

// n_w: length of string word, no more than 10 letters
// T = O(10) = O(1)
// S = O(1) extra space
int DesignerPdfViewer(int[] lettersHeights, string word)
{
    return word.Max(ch => lettersHeights[ch - 'a']) * word.Length;
}
