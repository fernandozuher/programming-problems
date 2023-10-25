# https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

def main():

    n = int(input())
    names = find_names_with_gmail_domains_emails_from_stdin(n)
    sort_in_place_and_print_names(names)


def find_names_with_gmail_domains_emails_from_stdin(n):

    names = []
    for _ in range(n):
        name, email_id = input().split()
        if '@gmail.com' in email_id:
            names.append(name)
    return names


def sort_in_place_and_print_names(names):

    names.sort()
    for name in names:
        print(name)


if __name__ == '__main__':
    main()
