# https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

def main
  n = gets.to_i
  names = collect_gmail_users(n)
  names.sort!
  puts names
end

def collect_gmail_users(n)
  n.times.map do
    name, email = gets.split
    name if email.end_with?('@gmail.com')
  end.compact
end

main
