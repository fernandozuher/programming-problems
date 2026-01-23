// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

int n = ReadNumber();
for (int i = 0; i < n; i++)
    Console.WriteLine(FindDigits(ReadNumber()));

int ReadNumber() => int.Parse(Console.ReadLine()!);

// k: quantity of digits of num = log num
// 0 < num < 10^9
// T: O(k) = O(9) = O(1)
// S: O(k) = O(9) = O(1) extra space
int FindDigits(int num) => num.ToString().ToCharArray().Select(c => c - '0').Count(d => d != 0 && num % d == 0);
