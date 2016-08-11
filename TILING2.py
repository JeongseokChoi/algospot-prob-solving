n_case = int(input())

cache = [-1 for i in range(101)]

def count_tiling_method(n):

    if n == 1: return 1
    if n == 2: return 2

    ret = cache[n]
    if ret != -1: return ret

    cache[n] =  count_tiling_method(n - 1) + count_tiling_method(n - 2)
    return cache[n]


for i_case in range(n_case):
    print(count_tiling_method(int(input())) % 1000000007)
