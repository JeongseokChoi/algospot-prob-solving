nCase = int(input())

for case in range(nCase):
    xList = []
    yList = []
    ansX = 0
    ansY = 0

    for i in range(3):
        x, y = input().split()
        xList.append(int(x))
        yList.append(int(y))

    # 세 좌표값을 모두 XOR 연산하면, 다른 하나, 즉 한 개 존재하는 값이 된다.
    # 참고: x ^ x = 0, x ^ 0 = x, 0 ^ x = x
    for x in xList:
        ansX ^= x
    for y in yList:
        ansY ^= y

    print("{0} {1}".format(ansX, ansY))
