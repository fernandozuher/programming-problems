#!/bin/python3

def extractEmailDomain(emailID):
    indexArroba = emailID.index('@')
    emailDomain = emailID[indexArroba:]
    return emailDomain

def checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames):
    if emailDomain == "@gmail.com":
        firstNames.append(firstName)

def sortNamesOfGmailEmails(firstNames):
    firstNames.sort()

def printFirstGmailNames(firstNames):
    for firstName in firstNames:
        print(firstName)

def main():
    N = int(input().strip())
    firstNames = []

    for N_itr in range(N):
        first_multiple_input = input().rstrip().split()
        firstName = first_multiple_input[0]
        emailID = first_multiple_input[1]

        emailDomain = extractEmailDomain(emailID)
        checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames)

    sortNamesOfGmailEmails(firstNames)
    printFirstGmailNames(firstNames)

if __name__ == '__main__':
    main()
