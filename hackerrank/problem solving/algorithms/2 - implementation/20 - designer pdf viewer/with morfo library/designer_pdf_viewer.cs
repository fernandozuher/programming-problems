// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

using Morfo.IO;

int[] lettersHeights = Reader.Read<int>(26);
string word = Reader.Read<string>();
Console.WriteLine(DesignerPdfViewer(lettersHeights, word));

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
int DesignerPdfViewer(int[] lettersHeights, string word)
{
    return word.Max(ch => lettersHeights[ch - 'a']) * word.Length;
}
