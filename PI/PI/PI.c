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
  int is_replicaion = FALSE;  // TRUE: (ex. 1212, 87878)

  // �� ���� ���ڷ� �����Ǿ��ִ��� Ȯ��
  for (int i = start_idx + 1; i < start_idx + len; i++)
    if (num[i] != num[start_idx])
      is_same_num = FALSE;
  if (is_same_num)
    return 1;

  // ������������ Ȯ��
  int diff = num[start_idx + 1] - num[start_idx];
  for (int i = start_idx + 1; i < start_idx + len; i++)
    if (num[i + 1] - num[i] != diff)
      is_arith_prog = FALSE;

  // ���������̸�, ������ 1 �Ǵ� -1���� Ȯ��
  if (is_arith_prog && (diff == 1 || diff == -1))
    is_inc_dec_one = TRUE;

  if (is_inc_dec_one)
    return 2;
  if (is_arith_prog)
    return 5;


}


int main(int argc, char *argv[])
{

  return 0;
}