// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        List<int> lettersHeights = _readIntArray();
        String word = Console.ReadLine();
        var obj = new DesignerPdfViewer(lettersHeights, word);
        Console.WriteLine(obj.Area);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    class DesignerPdfViewer
    {
        private List<int> _lettersHeights;
        private string _word;
        private int _area;

        public DesignerPdfViewer(List<int> lettersHeights, string word)
        {
            _lettersHeights = lettersHeights;
            _word = word;
            _area = 0;
            _calculateArea();
        }

            private void _calculateArea()
            {
                int maxHeight = 0;

                foreach (char letter in _word)
                {
                    int letterIndex = letter - 'a';
                    int letterHeight = _lettersHeights[letterIndex];
                    maxHeight = Math.Max(maxHeight, letterHeight);
                }

                _area = maxHeight * _word.Length;
            }

        public int Area
        {
            get { return _area; }
        }
    }
