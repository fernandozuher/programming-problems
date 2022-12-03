import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Solution {

    static String extractEmailDomain(String emailID) {
        int indexArroba = emailID.indexOf('@');
        String emailDomain = emailID.substring(indexArroba);
        return emailDomain;
    }

    static void checkAndInsertNameIfEmailDomainGmail(String firstName, String emailDomain, List<String> firstNames) {
        if (emailDomain.equals("@gmail.com"))
            firstNames.add(firstName);
    }

    static void sortNamesOfGmailEmails(List<String> firstNames) {
        Collections.sort(firstNames);
    }
    
    static void printFirstGmailNames(List<String> firstNames) {
        for (String firstName : firstNames)
            System.out.println(firstName);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bufferedReader.readLine().trim());

        ArrayList<String> firstNames = new ArrayList<String>();

        IntStream.range(0, N).forEach(NItr -> {
            try {
                String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");
                String firstName = firstMultipleInput[0];
                String emailID = firstMultipleInput[1];

                String emailDomain = extractEmailDomain(emailID);
                checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        sortNamesOfGmailEmails(firstNames);
        printFirstGmailNames(firstNames);

        bufferedReader.close();
    }
}
