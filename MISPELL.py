nCase = int(input())

count = 0
for case in range(nCase):
    count += 1
    inputList = input().split()
    index, word = int(inputList[0]), inputList[1]

    print(str(count) + " " + word[0:index - 1] + word[index:])
