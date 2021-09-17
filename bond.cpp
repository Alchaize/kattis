#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int CalculateHighestProduct(int **bonds, int bondIndex, int bondCount, int *takenMissions);
bool CheckIfTaken(int index, int *taken, int maxTakenMissions);

int main()
{
  string input;
  string hold;

  getline(cin, input);

  int numberOfBonds = stoi(input);

  // Store probabilities in a 2d-array
  int **probabilities = (int **)calloc(numberOfBonds, sizeof(int *));
  int   j = 0;
  stringstream ss;

  for (int i = 0; i < numberOfBonds; i++)
  {
    probabilities[i] = (int *)calloc(numberOfBonds, sizeof(int));

    // Input
    getline(cin, input);
    ss.clear();
    ss.str(input);

    // Convert input to integers
    while (getline(ss, hold, ' '))
    {
      probabilities[i][j] = stoi(hold);
      j++;
    }
    j = 0;
  }


  // Calculate highest product, brute force
  double product = 0;
  int *  takenMissions = (int *)calloc(numberOfBonds, sizeof(int));

  product = CalculateHighestProduct(probabilities, 0, numberOfBonds, takenMissions);

  // Convert to percentage
  product = product / pow(100, numberOfBonds - 1);
  cout << product << endl;

  // Free allocated memory
  for (int i = 0; i < numberOfBonds; i++)
  {
    free(probabilities[i]);
  }
  free(probabilities);
  free(takenMissions);

  return(0);
}

int CalculateHighestProduct(int **bonds, int bondIndex, int bondCount, int *takenMissions)
{
  int product = 0, max = 0;

  // If the last bond, get the remaining probability
  if (bondIndex == bondCount - 1)
  {
    for (int i = 0; i < bondCount; i++)
    {
      if (!CheckIfTaken(i, takenMissions, bondIndex))
      {
        int ret = bonds[bondIndex][i];
        return(ret);
      }
    }
  }

  // Recursively get the highest product
  for (int i = 0; i < bondCount; i++)
  {
    if (!CheckIfTaken(i, takenMissions, bondIndex))
    {
      if (bonds[bondIndex][i] != 0)
      {
        takenMissions[bondIndex] = i;
        product = bonds[bondIndex][i] * CalculateHighestProduct(bonds, bondIndex + 1, bondCount, takenMissions);
        if (product > max)
        {
          max = product;
        }
      }
    }
  }
  return(max);
}

// Check if a mission is already taken
bool CheckIfTaken(int index, int *taken, int maxTakenMissions)
{
  for (int i = 0; i < maxTakenMissions; i++)
  {
    if (taken[i] == index)
    {
      return(true);
    }
  }
  return(false);
}
