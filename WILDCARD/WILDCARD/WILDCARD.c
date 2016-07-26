#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INPUT_BUF_SZ 128
#define MAX_STR_LEN 100


char input_buf[INPUT_BUF_SZ];


void get_int(int *ptr)
{
    fgets(input_buf, INPUT_BUF_SZ, stdin);
    input_buf[strlen(input_buf) - 1] = '\0';
    *ptr = atoi(input_buf);
}

void get_string(char *ptr)
{
    fgets(input_buf, INPUT_BUF_SZ, stdin);
    input_buf[strlen(input_buf) - 1] = '\0';
    strcpy(ptr, input_buf);
}

int match(char *w, char *s, int w_idx, int s_idx, int (*cache)[MAX_STR_LEN + 1])
{
    int ret = cache[w_idx][s_idx];
    if (ret != -1)
        return ret;

    if (w_idx < strlen(w) && s_idx < strlen(s) &&
        ((w[w_idx] == '?') || (w[w_idx] == s[s_idx])))
    {
        cache[w_idx][s_idx] = match(w, s, w_idx + 1, s_idx + 1, cache);
        return cache[w_idx][s_idx];
    }

    if (w_idx == strlen(w))
        return (s_idx == strlen(s)) ? 1 : 0;

    if (w[w_idx] == '*')
    {
        if (match(w, s, w_idx + 1, s_idx, cache) ||
            (s_idx < strlen(s) && match(w, s, w_idx, s_idx + 1, cache)))
        {
            cache[w_idx][s_idx] = 1;
            return cache[w_idx][s_idx];
        }
    }

    return 0;
}

int is_matched(char *w, char *s)
{
    int cache[MAX_STR_LEN + 1][MAX_STR_LEN + 1];
    for (int i = 0; i < MAX_STR_LEN + 1; i++)
        for (int j = 0; j < MAX_STR_LEN + 1; j++)
            cache[i][j] = -1;

    return match(w, s, 0, 0, cache);
}


int main(int argc, char *argv[])
{
    char *w, *s[50];
    int n_case;

    get_int(&n_case);
    for (int i_case = 0; i_case < n_case; i_case++)
    {
        w = malloc(MAX_STR_LEN + 1);
        get_string(w);

        int n_str;
        get_int(&n_str);
        for (int i = 0; i < n_str; i++)
        {
            char tmp_str[MAX_STR_LEN + 1];
            get_string(tmp_str);
            int j;
            for (j = i; (j > 0) && (strcmp(s[j - 1], tmp_str) > 0); j--)
                s[j] = s[j - 1];
            s[j] = malloc(MAX_STR_LEN + 1);
            strcpy(s[j], tmp_str);
        }

        for (int i = 0; i < n_str; i++)
            if (is_matched(w, s[i]))
                printf("%s\n", s[i]);

        for (int i = 0; i < n_str; i++)
            free(s[i]);
        free(w);
    }

    return 0;
}
