from sys import stdin

phoneBook = {}
n = int(input())

for i in range(n):
    name, phone = input().split()
    phoneBook[name] = phone

for query in stdin:
    query = query.rstrip()
    if value := phoneBook.get(query):
        print(f"{query}={value}")
    else:
        print("Not found")
