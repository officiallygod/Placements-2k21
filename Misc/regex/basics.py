import re

# HTTP/1.1 www.bmsit.ac.in 600 OK
# HTTP/1.1 www.google.com 300 OK

fp = open('./regex/abx.txt', 'r')

patt = re.compile(r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b')

for texttt in fp:
    ans = patt.search(texttt.rstrip("\n"))

    if ans:
        print("Found: " + ans.group())
    else:
        print("Not Found")
