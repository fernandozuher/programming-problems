// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int pageQuantity = int.Parse(Console.ReadLine());
        int page = int.Parse(Console.ReadLine());
        var obj = new DrawingBook(pageQuantity, page);
        Console.WriteLine(obj.MinimumTurnOfPages);
    }
}

    public class DrawingBook
    {
        private int _pageQuantity;
        private int _page;
        private int _turnOfPagesFromFront;
        private int _turnOfPagesFromBack;
        private int _minimumTurnOfPages;

        public DrawingBook(int pageQuantity, int page)
        {
            _pageQuantity = pageQuantity;
            _page = page;
            _turnOfPagesFromFront = 0;
            _turnOfPagesFromBack = 0;
            _minimumTurnOfPages = 0;
            _pageCount();
        }

            private void _pageCount()
            {
                _turnOfPagesFromFront = _calculateTurnOfPages(_page);
                int maximumTurns = _calculateTurnOfPages(_pageQuantity);
                _turnOfPagesFromBack = maximumTurns - _turnOfPagesFromFront;
                _minimumTurnOfPages = Math.Min(_turnOfPagesFromFront, _turnOfPagesFromBack);
            }

                private int _calculateTurnOfPages(int page)
                {
                    return (page & 1) == 1 ? _pageIsOdd(page) : _pageIsEven(page);
                }

                    private int _pageIsOdd(int page)
                    {
                        return (page - 1) / 2;
                    }

                    private int _pageIsEven(int page)
                    {
                        return page / 2;
                    }

        public int MinimumTurnOfPages
        {
            get { return _minimumTurnOfPages; }
        }
    }
