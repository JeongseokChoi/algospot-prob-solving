#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define max(a, b) (((a) > (b)) ? (a) : (b))


int seq[500];
int seq_sz;
int cache[500];


int find_lis(int from)
{
    if (cache[from] != 0)
        return cache[from];

    cache[from] = 1;
    for (int idx = from + 1; idx < seq_sz; idx++)
        if (seq[from] < seq[idx])
            cache[from] = max(cache[from], find_lis(idx) + 1);

    return cache[from];
}


int main(int argc, char *argv[])
{
    int n_case;
    scanf("%d", &n_case);

    for (int i_case = 0; i_case < n_case; i_case++)
    {
        seq_sz = 0;
        memset(seq, 0, sizeof(seq));
        memset(cache, 0, sizeof(cache));

        scanf("%d", &seq_sz);
        for (int i = 0; i < seq_sz; i++)
            scanf("%d", &seq[i]);

        printf("%d\n", find_lis(0));
    }

    return 0;
}
