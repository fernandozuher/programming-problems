#!/bin/ruby

def extractEmailDomain(emailID)
    indexArroba = emailID.index('@')
    emailDomain = emailID[indexArroba..-1]
    emailDomain
end

def checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames)
    if emailDomain == "@gmail.com"
        firstNames.push(firstName)
    end
end

def sortNamesOfGmailEmails(firstNames)
    firstNames.sort
end

def printFirstGmailNames(firstNames)
    puts firstNames
end

N = gets.strip.to_i
firstNames = Array.new

N.times do
    first_multiple_input = gets.rstrip.split
    firstName = first_multiple_input[0]
    emailID = first_multiple_input[1]

    emailDomain = extractEmailDomain(emailID)
    checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames)
end

firstNames = sortNamesOfGmailEmails(firstNames)
printFirstGmailNames(firstNames)
