#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE  1
#define FALSE 0
#define INF   1122223333


char num[10001];
int cache[10000];


int classify(int start_idx, int len)
{
  int is_same_num = TRUE;  // TRUE: composed of one digit (ex. 1111,5555)
  int is_arith_prog = TRUE;  // TRUE: arithmetical progression (ex. 13579, 6789)
  int is_inc_dec_one = FALSE;  // TRUE: (+/-) 1 (ex. 1234, 6543)
  int is_repeated = TRUE;  // TRUE: (ex. 1212, 87878)

  // 다 같은 숫자로 구성되어있는지 확인
  for (int i = start_idx + 1; i < start_idx + len; i++)
  {
    if (num[i] != num[start_idx])
    {
      is_same_num = FALSE;
      break;
    }
  }
  if (is_same_num)
    return 1;

  // 등차수열인지 확인
  int diff = num[start_idx + 1] - num[start_idx];
  for (int i = start_idx + 1; i < start_idx + len - 1; i++)
  {
    if (num[i + 1] - num[i] != diff)
    {
      is_arith_prog = FALSE;
      break;
    }
  }

  // 등차수열이면, 공차가 1 또는 -1인지 확인
  if (is_arith_prog && (diff == 1 || diff == -1))
    is_inc_dec_one = TRUE;

  if (is_inc_dec_one)
    return 2;
  if (is_arith_prog)
    return 5;

  for (int i = start_idx; i < start_idx + len; i++)
  {
    if (num[i] != num[start_idx + ((i - start_idx) % 2)])
    {
      is_repeated = FALSE;
      break;
    }
  }
  if (is_repeated)
    return 4;

  return 10;
}


int get_solution()
{
  memset(cache, 0, sizeof(cache));
  cache[2] = classify(0, 3);
  cache[3] = classify(0, 4);
  cache[4] = classify(0, 5);
  int num_len = strlen(num);
  for (int i = 5; i < num_len; i++)
  {
    
  }
}


int main(int argc, char *argv[])
{
  char buf[1024];
  int n_case;

  fgets(buf, 1024, stdin);
  n_case = atoi(buf);
  for (int i_case = 0; i_case < n_case; i_case++)
  {
    fgets(buf, 1024, stdin);
    buf[strlen(buf) - 1] = '\0';
    strcpy(num, buf);

    
  }

  return 0;
}