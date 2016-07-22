#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#define VALUE 0
#define POSSIBILITY 1


int board[2][100][100];
int board_size;


void make_possibiliy_board(int i, int j)
{
    /*
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
            printf("%d ", board[POSSIBILITY][i][j]);
        printf("\n");
    }
    printf("\n");
    */

    int idx_i, idx_j;

    // 아래
    idx_i = i + board[VALUE][i][j];
    idx_j = j;
    if (idx_i >= 0 && idx_i < board_size &&
        idx_j >= 0 && idx_j < board_size &&
        board[POSSIBILITY][idx_i][idx_j] == 0)
    {
        board[POSSIBILITY][idx_i][idx_j] += 1;
        make_possibiliy_board(idx_i, idx_j);
    }

    // 오른쪽
    idx_i = i;
    idx_j = j + board[VALUE][i][j];
    if (idx_i >= 0 && idx_i < board_size &&
        idx_j >= 0 && idx_j < board_size &&
        board[POSSIBILITY][idx_i][idx_j] == 0)
    {
        board[POSSIBILITY][idx_i][idx_j] += 1;
        make_possibiliy_board(idx_i, idx_j);
    }
}


int main(int argc, char *argv[])
{
    int n_case;
    scanf("%d", &n_case);
    
    for (int i_case = 0; i_case < n_case; i_case++)
    {
        memset(board, 0, sizeof(board));

        scanf("%d", &board_size);
        for (int i = 0; i < board_size; i++)
            for (int j = 0; j < board_size; j++)
                scanf("%d", &board[VALUE][i][j]);

        board[POSSIBILITY][0][0] = 1;
        make_possibiliy_board(0, 0);

        if (board[POSSIBILITY][board_size - 1][board_size - 1] == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
