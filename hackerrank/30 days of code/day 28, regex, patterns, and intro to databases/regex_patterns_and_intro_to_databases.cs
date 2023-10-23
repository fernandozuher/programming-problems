using System;

class Solution
{
    static string extractEmailDomain(string emailID)
    {
        int indexArroba = emailID.IndexOf('@');
        string emailDomain = emailID.Substring(indexArroba);
        return emailDomain;
    }

    static void checkAndInsertNameIfEmailDomainGmail(string firstName, string emailDomain, List<string> firstNames)
    {
        if (String.Compare(emailDomain, "@gmail.com") == 0)
            firstNames.Add(firstName);
    }

    static void sortNamesOfGmailEmails(List<string> firstNames)
    {
        firstNames.Sort();    
    }
    
    static void printFirstGmailNames(List<string> firstNames)
    {
        foreach (string firstName in firstNames)
            Console.WriteLine(firstName);
    }

    public static void Main(string[] args)
    {
        int N = Convert.ToInt32(Console.ReadLine().Trim());
        List<string> firstNames = new List<string>();

        for (int NItr = 0; NItr < N; NItr++)
        {
            string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');
            string firstName = firstMultipleInput[0];
            string emailID = firstMultipleInput[1];

            string emailDomain = extractEmailDomain(emailID);
            checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames);
        }

        sortNamesOfGmailEmails(firstNames);
        printFirstGmailNames(firstNames);
    }
}
