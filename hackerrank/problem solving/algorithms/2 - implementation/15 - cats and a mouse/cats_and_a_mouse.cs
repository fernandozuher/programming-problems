// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<string> nearestCatsOrNot = new List<string>(new string[n]);

        for (int i = 0; i < n; ++i)
        {
            List<int> positions = _readIntArray();
            var obj = new CatsAndAMouse(positions);
            nearestCatsOrNot[i] = obj.NearestCatOrNot;
        }

        nearestCatsOrNot.ForEach(x => Console.WriteLine(x));
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class CatsAndAMouse
    {
        private int _catAPosition;
        private int _catBPosition;
        private int _mousePosition;
        private string _nearestCatOrNot;

        public CatsAndAMouse(List<int> catsAndMousePositions)
        {
            _catAPosition = catsAndMousePositions.First();
            _catBPosition = catsAndMousePositions[1];
            _mousePosition = catsAndMousePositions.Last();
            _nearestCatOrNot = "";
            _findNearestCatOrNot();
        }

            private void _findNearestCatOrNot()
            {
                int catAPositionFromMouse = Math.Abs(_catAPosition - _mousePosition);
                int catBPositionFromMouse = Math.Abs(_catBPosition - _mousePosition);

                if (catAPositionFromMouse < catBPositionFromMouse)
                    _nearestCatOrNot = "Cat A";
                else if (catAPositionFromMouse > catBPositionFromMouse)
                    _nearestCatOrNot = "Cat B";
                else
                    _nearestCatOrNot = "Mouse C";
            }

        public string NearestCatOrNot
        {
            get { return _nearestCatOrNot; }
        }
    }
