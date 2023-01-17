// Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

using System;


class Solution
{
    public static void Main()
    {
        List<int> inputLine1 = ReadLineAsListInt();
        String inputLine2 = ReadLineAsString();

        Result result = new Result(inputLine1, inputLine2);
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }

        private static string ReadLineAsString()
        {
            string inputLine = Console.ReadLine();
            return inputLine;
        }
}

    class Result
    {
        private List<int> _lettersHeights;
        private string _word;
        private int _area;

        public Result(List<int> lettersHeights, string word)
        {
            _lettersHeights = lettersHeights;
            _word = word;
            _area = 0;

            _DesignerPdfViewer();
            PrintResult();
        }

            private void _DesignerPdfViewer()
            {
                int maxHeight = 0;

                foreach (char letter in _word)
                {
                    int letterIndex = letter - 'a';
                    int letterHeight = _lettersHeights[letterIndex];

                    if (maxHeight < letterHeight)
                        maxHeight = letterHeight;
                }

                _area = maxHeight * _word.Length;
            }

            public void PrintResult()
            {
                Console.WriteLine(_area);
            }
    }
