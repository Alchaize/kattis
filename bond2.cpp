#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

// Currently fails test 8/32
using namespace std;

int bondCount;

double CalculateHighestProduct(double **bonds, int bondIndex, int *takenMissions);
bool CheckIfTaken(int index, int *taken, int maxTakenMissions);

int main()
{
  string input;
  string hold;

  getline(cin, input);
  bondCount = stoi(input);

  // Store probabilities in a 2d-array
  double **probabilities = (double **)calloc(bondCount, sizeof(double *));
  int j = 0;
  stringstream ss;

  for (int i = 0; i < bondCount; i++)
  {
    probabilities[i] = (double *)calloc(bondCount, sizeof(double));

    // Input
    getline(cin, input);
    ss.clear();
    ss.str(input);

    // Convert input to integers
    while (getline(ss, hold, ' '))
    {
      probabilities[i][j] = (double)stod(hold) / 100;
      j++;
    }
    j = 0;
  }


  // Calculate highest product, brute force
  double product = 0;
  int *  takenMissions = (int *)calloc(bondCount, sizeof(int));

  product = CalculateHighestProduct(probabilities, 0, takenMissions) * 100;
  cout << product << endl;

  // Free allocated memory
  for (int i = 0; i < bondCount; i++)
  {
    free(probabilities[i]);
  }
  free(probabilities);
  free(takenMissions);

  return(0);
}

double CalculateHighestProduct(double **bonds, int bondIndex, int *takenMissions)
{
  double product = 0, max = 0;

  // If the last bond, get the remaining probability
  if (bondIndex == bondCount - 1)
  {
    for (int i = 0; i < bondCount; i++)
    {
      if (!CheckIfTaken(i, takenMissions, bondIndex))
      {
        return(bonds[bondIndex][i]);
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
        product = bonds[bondIndex][i] * CalculateHighestProduct(bonds, bondIndex + 1, takenMissions);
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
