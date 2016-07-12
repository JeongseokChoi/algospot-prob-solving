nCase = int(input())

for case in range(nCase):
    limit = int(input())
    usageList = input().split()
    total = 0
    for usage in usageList:
        total += int(usage)
    if total <= limit:
        print("YES")
    else:
        print("NO")
