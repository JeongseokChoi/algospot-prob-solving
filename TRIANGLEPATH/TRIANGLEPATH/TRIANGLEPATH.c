#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int arr[100][100];
    int n_case, n_line;

    scanf("%d", &n_case);
    for (int i_case = 0; i_case < n_case; i_case++)
    {
        memset(arr, 0, sizeof(arr));

        scanf("%d", &n_line);
        for (int i_line = 0; i_line < n_line; i_line++)
            for (int i = 0; i <= i_line; i++)
                scanf("%d", &arr[i_line][i]);

        for (int i = 1; i < n_line; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j != 0)
                    arr[i][j] += (arr[i - 1][j - 1] > arr[i - 1][j]) ? arr[i - 1][j - 1] : arr[i - 1][j];
                else
                    arr[i][j] += arr[i - 1][j];
            }
        }

        int max = -1;
        for (int i = 0; i < n_line; i++)
            if (max < arr[n_line - 1][i])
                max = arr[n_line - 1][i];
        printf("%d\n", max);
    }

    return 0;
}
