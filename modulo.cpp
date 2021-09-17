#include <iostream>

using namespace std;

bool seen[42] = { false };

int main()
{
  int n;
  int modulus = 42;

  for (int i = 0; i < 10; i++)
  {
    cin >> n;
    seen[n % modulus] = true;
  }
  n = 0;
  for (int i = 0; i < 42; i++)
  {
    (seen[i]) ? n++:0;
  }
  cout << n << endl;
  return(0);
}
