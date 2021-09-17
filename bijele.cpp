#include <iostream>

using namespace std;

int main()
{
  int  values[] = { 1, 1, 2, 2, 2, 8 };
  int  limit    = 12;
  int  r = 0;
  int  j = 0;
  char str[256];

  fgets(str, 256, stdin);

  for (int i = 0; i < limit; i += 2)
  {
    r = atoi(&str[i]);
    if (r == 10)
    {
      limit++;
      i++;
    }
    r = values[j] - r;
    std::cout << r << " ";
    j++;
  }

  return(0);
}
