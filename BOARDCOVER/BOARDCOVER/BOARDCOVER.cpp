#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;


typedef vector< vector<char> > Board_t;


int tileType[4][3][2] =
{
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};


bool isAbleToCover(Board_t& board, int row, int col, int type);
int cover(Board_t& board);


int main(int argc, char* argv[])
{
    Board_t board;
    int nTestCase = 0;
    int nRow = 0, nCol = 0;

    cin >> nTestCase;
    for (int testCase = 0; testCase < nTestCase; testCase++)
    {
        cin >> nRow >> nCol;
        board.clear();
        board.assign(nRow, vector<char>(nCol, '#'));
        for (int i = 0; i < nRow; i++)
            for (int j = 0; j < nCol; j++)
                cin >> board[i][j];

        cout << cover(board) << endl;;
    }

    return 0;
}


bool isAbleToCover(Board_t& board, int row, int col, int type)
{
    for (int i = 0; i < 3; i++)
    {
        int chkRow = row + tileType[type][i][0];
        int chkCol = col + tileType[type][i][1];
        if (chkRow < 0 || chkRow >= board.size() ||
            chkCol < 0 || chkCol >= board[0].size())
        {
            return false;
        }
        if (board[chkRow][chkCol] == '#')
        {
            return false;
        }
    }
    return true;
}

int cover(Board_t& board)
{
    // find top-left empty position
    int rowTopLeft = -1;
    int colTopLeft = -1;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                rowTopLeft = i;
                colTopLeft = j;
                break;
            }
        }
        if (rowTopLeft >= 0 && colTopLeft >= 0)
            break;
    }
    if (rowTopLeft == -1 && colTopLeft == -1)
        return 1;

    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        if (isAbleToCover(board, rowTopLeft, colTopLeft, i))
        {
            // cover the board with '#'
            for (int j = 0; j < 3; j++)
            {
                int tmpRow = rowTopLeft + tileType[i][j][0];
                int tmpCol = colTopLeft + tileType[i][j][1];
                board[tmpRow][tmpCol] = '#';
            }
            ret += cover(board);
            for (int j = 0; j < 3; j++)
            {
                int tmpRow = rowTopLeft + tileType[i][j][0];
                int tmpCol = colTopLeft + tileType[i][j][1];
                board[tmpRow][tmpCol] = '.';
            }
        }
    }
    return ret;
}
