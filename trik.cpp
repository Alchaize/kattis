#include <iostream>
#include <cstdlib>

using namespace std;

void MoveCups(char move, bool *cups);

int main()
{
  bool cups[] = { true, false, false };
  char str[256];

  fgets(str, 256, stdin);

  int i = 0;

  while (str[i] != '\n')
  {
    MoveCups(str[i], cups);
    i++;
  }

  for (int i = 0; i < 3; i++)
  {
    if (cups[i])
    {
      cout << i + 1;
    }
  }
  return(0);
}

void MoveCups(char move, bool *cups)
{
  bool temp;

  switch (move)
  {
  case 'A':
    temp    = cups[1];
    cups[1] = cups[0];
    cups[0] = temp;
    break;

  case 'B':
    temp    = cups[2];
    cups[2] = cups[1];
    cups[1] = temp;
    break;

  case 'C':
    temp    = cups[2];
    cups[2] = cups[0];
    cups[0] = temp;
    break;

  default:
    break;
  }
}
