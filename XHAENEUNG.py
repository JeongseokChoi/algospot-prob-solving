dic = {
    'zero': 0, 'one': 1, 'two': 2, 'three': 3, 'four': 4,
    'five': 5, 'six': 6, 'seven': 7, 'eight': 8, 'nine': 9, 'ten': 10,
    0: 'zero', 1: 'one', 2: 'two', 3: 'three', 4: 'four',
    5: 'five', 6: 'six', 7: 'seven', 8: 'eight', 9: 'nine', 10: 'ten'
}

nCase = int(input())
for case in range(nCase):
    inputExpr = input().split()

    # get right answer
    ans = eval(str(dic[inputExpr[0]]) + inputExpr[1] + str(dic[inputExpr[2]]))
    if ans < 0 or ans > 10:
        print("No")
        continue

    # sort characters
    rightAns = list(dic[ans])
    stuAns = list(inputExpr[4])
    rightAns.sort()
    stuAns.sort()

    # compare
    if rightAns == stuAns:
        print("Yes")
    else:
        print("No")
