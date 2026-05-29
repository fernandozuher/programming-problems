// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

Console.ReadLine();
var arr = Console.ReadLine()!.Split().Select(int.Parse).Reverse().ToArray();
foreach (int x in arr)
    Console.Write("{0} ", x);
