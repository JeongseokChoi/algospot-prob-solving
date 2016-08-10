#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int arr[100];
int table[100][100];  // table[i][j] : 구간[i, j]에서 최소오차제곱합


int main(int argc, char* argv[])
{
  int n_case;
  scanf("%d", &n_case);

  for (int i_case = 0; i_case < n_case; i_case++)
  {
    int n, s;
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);
    sort(arr, arr + n);

    // preprocessing
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        int mean = 0;
        for (int x = i; x <= j; x++)
          mean += arr[x];
        mean /= (j - i + 1);

        int sum_of_diff_sq = 0;
        for (int x = i; x <= j; x++)
          sum_of_diff_sq += (arr[x] - mean) * (arr[x] - mean);

        table[i][j] = sum_of_diff_sq;
      }
    }

    
  }

  return 0;
}
