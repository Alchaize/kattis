#include <iostream>

using namespace std;

int main()
{
  int n = 0;

  scanf("%d", &n);

  int *nums = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &nums[i]);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    printf("%d\n", nums[i]);
  }

  free(nums);

  return(0);
}
