#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define max(a, b) (((a) > (b)) ? (a) : (b))


int seq[500];
int seq_sz;
int cache[500];


int find_lis()
{
    for (int i = seq_sz - 1; i >= 0; i--)
    {
        cache[i] = 1;
        for (int j = i + 1; j < seq_sz; j++)
            if (seq[j] > seq[i])
                cache[i] = max(cache[i], cache[j] + 1);
    }

    int ans = 0;
    for (int i = 0; i < seq_sz; i++)
        if (ans < cache[i])
            ans = cache[i];
    return ans;
}


int main(int argc, char *argv[])
{
    int n_case;
    scanf("%d", &n_case);

    for (int i_case = 0; i_case < n_case; i_case++)
    {
        // initialize
        seq_sz = 0;
        memset(seq, 0, sizeof(seq));
        memset(cache, 0, sizeof(cache));

        // get input
        scanf("%d", &seq_sz);
        for (int i = 0; i < seq_sz; i++)
            scanf("%d", &seq[i]);

        // find & print answer
        printf("%d\n", find_lis());
    }

    return 0;
}
