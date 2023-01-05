// Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

using System;


class Solution
{
    public static void Main()
    {
        List<int> pageQuantity = ReadLineAsListInt();
        List<int> page = ReadLineAsListInt();
        
        Result result = new Result(pageQuantity.First(), page.First());
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return numbers;
        }
}

    class Result
    {
        private int _pageQuantity;
        private int _page;
        private int _turnOfPagesFromFront;
        private int _turnOfPagesFromBack;
        private int _minimumTurnOfPages;

        public Result(int pageQuantity, int page)
        {
            _pageQuantity = pageQuantity;
            _page = page;
            _turnOfPagesFromFront = 0;
            _turnOfPagesFromBack = 0;
            _minimumTurnOfPages = 0;

            _DrawingBook();
            PrintResult();
        }

            private void _DrawingBook()
            {
                _turnOfPagesFromFront = _CalculateTurnOfPages(_page);
        
                int maximumTurns = _CalculateTurnOfPages(_pageQuantity);

                _turnOfPagesFromBack = maximumTurns - _turnOfPagesFromFront;

                _minimumTurnOfPages = Math.Min(_turnOfPagesFromFront, _turnOfPagesFromBack);
            }

                int _CalculateTurnOfPages(int page)
                {
                    return (page & 1) == 1 ? _PageIsOdd(page) : _PageIsEven(page);
                }

                    int _PageIsOdd(int page)
                    {
                        return (page - 1) / 2;
                    }

                    int _PageIsEven(int page)
                    {
                        return page / 2;
                    }

            public void PrintResult()
            {
                Console.WriteLine(_minimumTurnOfPages);
            }
    }
