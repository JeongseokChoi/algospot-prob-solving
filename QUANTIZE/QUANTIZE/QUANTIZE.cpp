#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


#define INF 999999999


int arr[100];
int table[100][100];  // table[i][j] : 구간[i, j]에서 최소오차제곱합
int memo[100][11];  // memo[i][j] : i부터 j개의 구간으로 나누었을 때 최소오차제곱합
int n, s;


int func(int from, int sep)
{
  if (from >= n) return 0;
  if (sep <= 0) return INF;

  int& ret = memo[from][sep];
  if (ret == INF)
    for (int i = from; i < n; i++)
      ret = min(ret, table[from][i] + func(i + 1, sep - 1));
  return ret;
}


int main(int argc, char* argv[])
{
  int n_case;
  scanf("%d", &n_case);

  for (int i_case = 0; i_case < n_case; i_case++)
  {
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);
    sort(arr, arr + n);

    // preprocessing
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        float mean = 0;
        for (int x = i; x <= j; x++)
          mean += (float)arr[x];
        mean /= (j - i + 1);
        mean = (int)(mean + 0.5f);

        int sum_of_diff_sq = 0;
        for (int x = i; x <= j; x++)
          sum_of_diff_sq += (arr[x] - mean) * (arr[x] - mean);

        table[i][j] = sum_of_diff_sq;
      }
    }

    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 11; j++)
        memo[i][j] = INF;

    cout << func(0, s) << endl;
  }

  return 0;
}
