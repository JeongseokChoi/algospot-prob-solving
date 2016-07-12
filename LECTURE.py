nCase = int(input())

for case in range(nCase):
    s = input()
    sLen = len(s)
    ssList = []
    ans = ''

    for i in range(int(sLen / 2)):
        ssList.append(s[i * 2: i * 2 + 2])
    ssList.sort()
    for ss in ssList:
        ans += ss
    print(ans)
