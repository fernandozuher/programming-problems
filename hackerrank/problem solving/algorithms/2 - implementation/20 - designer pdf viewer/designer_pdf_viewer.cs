// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

int[] lettersHeights = ReadNumbers();
String word = Console.ReadLine()!;
Console.WriteLine(DesignerPdfViewer(lettersHeights, word));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int DesignerPdfViewer(int[] lettersHeights, string word)
{
    return word.Max(letter => lettersHeights[letter - 'a']) * word.Length;
}
