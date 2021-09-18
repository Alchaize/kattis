#include <iostream>
#include <cstring>

#define MAX    14

using namespace std;

int Walk(int s);
int Step(int x, int y, int s);

int savedSteps[MAX + MAX + 1][MAX + MAX + 1][MAX];

int main()
{
  int testCount;
  int testCases[MAX];

  memset(savedSteps, -1, sizeof(savedSteps));

  // Get number of test cases
  cin >> testCount;

  // Get test case
  for (int i = 0; i < testCount; i++)
  {
    cin >> testCases[i];
  }

  // Run test cases
  for (int i = 0; i < testCount; i++)
  {
    cout << Walk(testCases[i]) << endl;
  }

  return(0);
}

int Walk(int s)
{
  return(Step(0, 0, (s <= MAX) ? s:MAX));
}

int Step(int x, int y, int s)
{
  // Check if we can take more steps
  if (s == 0)
  {
    return((x == 0) && (y == 0));
  }

  // Check if current configuration has already been calculated
  if (savedSteps[x + MAX][y + MAX][s] != -1)
  {
    return(savedSteps[x + MAX][y + MAX][s]);
  }

  // Sum the different possible paths from current configuration
  int validWalks = 0;

  validWalks += Step(x, y + 1, s - 1);
  validWalks += Step(x + 1, y + 1, s - 1);
  validWalks += Step(x + 1, y, s - 1);
  validWalks += Step(x, y - 1, s - 1);
  validWalks += Step(x - 1, y - 1, s - 1);
  validWalks += Step(x - 1, y, s - 1);

  savedSteps[x + MAX][y + MAX][s] = validWalks;

  return(validWalks);
}
