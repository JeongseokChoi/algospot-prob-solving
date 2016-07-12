import urllib.parse

nCase = int(input())
for case in range(nCase):
    s = input()
    print(urllib.parse.unquote(s))
