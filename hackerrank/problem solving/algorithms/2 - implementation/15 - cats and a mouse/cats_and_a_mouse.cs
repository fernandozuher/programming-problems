// Source: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        List<int> inputLine = ReadLineAsListInt();
        int n = inputLine.First();

        List<List<int>> inputLines = ReadCatsAndMousePositionsLines(n);

        Result result = new Result(inputLines);
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }

        private static List<List<int>> ReadCatsAndMousePositionsLines(int n)
        {
            List<List<int>> catsAndMousePositionsLines = new List<List<int>>();

            for (int i = 0; i < n; i++)
                catsAndMousePositionsLines.Add(ReadLineAsListInt());

            return catsAndMousePositionsLines;
        }
}

    class Result
    {
        private List<List<int>> _catsAndMousePositionsLines;
        private List<string> _result;

        public Result(List<List<int>> catsAndMousePositionsLines)
        {
            _catsAndMousePositionsLines = catsAndMousePositionsLines;
            _result = new List<string>();

            _CatAndMouse();
            printResult();
        }

            private void _CatAndMouse()
            {
                foreach (List<int> catsAndMousePositions in _catsAndMousePositionsLines)
                    _FindNearestCatOrNot(catsAndMousePositions);
            }

                private void _FindNearestCatOrNot(List<int> catsAndMousePositions)
                {
                    int catAPosition = catsAndMousePositions[0];
                    int catBPosition = catsAndMousePositions[1];
                    int mousePosition = catsAndMousePositions[2];

                    int catAPositionDifference = Math.Abs(catAPosition - mousePosition);
                    int catBPositionDifference = Math.Abs(catBPosition - mousePosition);

                    _setStringResult(catAPositionDifference, catBPositionDifference);
                }

                    private void _setStringResult(int catAPositionDifference, int catBPositionDifference)
                    {
                        if (catAPositionDifference < catBPositionDifference)
                            _result.Add("Cat A");
                        else if (catAPositionDifference > catBPositionDifference)
                            _result.Add("Cat B");
                        else
                            _result.Add("Mouse C");
                    }

            public void printResult()
            {
                foreach (string result in _result)
                    Console.WriteLine(result);
            }
    }
