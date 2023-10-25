# https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

def main
    n = gets.to_i
    names = find_names_with_gmail_domains_emails_from_stdin(n)
    names.sort!
    puts names
end

    def find_names_with_gmail_domains_emails_from_stdin(n)
        names = Array.new

        n.times do
            name, email_id = gets.split
            if email_id.include? '@gmail.com'
                names.push(name)
            end
        end

        names
    end

main
