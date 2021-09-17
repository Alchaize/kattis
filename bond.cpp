#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

// Currently fails test 8/32
#define MODE    1

using namespace std;

double CalculateHighestProduct(double **bonds, int bondIndex, int *takenMissions);
bool CheckIfTaken(int index, int *taken, int maxTakenMissions);

bool TestOne();
bool TestTwo();
bool TestThree();

int bondCount;

int main()
{
  string input;
  string hold;

  if (MODE == 0)
  {
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

      // Convert input to double
      while (getline(ss, hold, ' '))
      {
        probabilities[i][j] = (double)stoi(hold);
        j++;
      }
      j = 0;
    }


    // Calculate highest product, brute force
    double product = 0;
    int *  takenMissions = (int *)calloc(bondCount, sizeof(int));
    product = CalculateHighestProduct(probabilities, 0, takenMissions);

    // Print result
    cout << product << endl;

    // Free allocated memory
    for (int i = 0; i < bondCount; i++)
    {
      free(probabilities[i]);
    }
    free(probabilities);
    free(takenMissions);
  }
  else
  {
    cout << "Starting tests..." << endl;
    bondCount = 20;
    if (TestOne())
    {
      cout << "Passed first test\n\n" << endl;
    }
    bondCount = 3;
    if (TestTwo())
    {
      cout << "Passed second test\n\n" << endl;
    }
    if (TestThree())
    {
      cout << "Passed third test" << endl;
    }
    cout << "Tests finished." << endl;
  }


  return(0);
}

bool TestOne()
{
  int k = 19;
  double **bonds = (double **)calloc(20, sizeof(double *));
  int *    takenMissions = (int *)calloc(20, sizeof(int));

  cout << "Setting values for test 1" << endl;
  for (int i = 0; i < 20; i++)
  {
    bonds[i] = (double *)calloc(20, sizeof(double));
    for (int j = 0; j < 20; j++)
    {
      if (j == k)
      {
        bonds[i][j] = 1.0;
        k--;
      }
      else
      {
        bonds[i][j] = 0.0;
      }
      cout << bonds[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Starting calculating test 1" << endl;
  double result = CalculateHighestProduct(bonds, 0, takenMissions) * 100;

  printf("First result: %lf\n", result);

  for (int i = 0; i < 20; i++)
  {
    free(bonds[i]);
  }
  free(bonds);
  free(takenMissions);

  return(result == 100);
}

bool TestTwo()
{
  bondCount = 3;
  double **bonds = (double **)calloc(bondCount, sizeof(double *));
  int *    takenMissions = (int *)calloc(bondCount, sizeof(int));

  for (int i = 0; i < bondCount; i++)
  {
    bonds[i] = (double *)calloc(bondCount, sizeof(double));
  }
  bonds[0][0] = 0.25;
  bonds[0][1] = 0.6;
  bonds[0][2] = 1.0;
  bonds[1][0] = 0.13;
  bonds[1][1] = 0.0;
  bonds[1][2] = 0.50;
  bonds[2][0] = 0.12;
  bonds[2][1] = 0.70;
  bonds[2][2] = 0.90;

  cout << "Test two values" << endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << bonds[i][j] << " ";
    }
    cout << endl;
  }

  double result = CalculateHighestProduct(bonds, 0, takenMissions) * 100;

  for (int i = 0; i < 3; i++)
  {
    free(bonds[i]);
  }
  free(bonds);
  free(takenMissions);

  return(result == 9.1);
}

bool TestThree()
{
  return(true);
}

double CalculateHighestProduct(double **bonds, int bondIndex, int *takenMissions)
{
  double product = 0, max = 0;

  // If the last bond, get the remaining probability
  if (bondIndex + 1 == bondCount)
  {
    for (int i = 0; i < bondCount; i++)
    {
      if (!CheckIfTaken(i, takenMissions, bondIndex))
      {
        double ret = bonds[bondIndex][i];
        cout << "Finishing bond probability : " << ret << endl;
        return(ret);
      }
    }
  }

  // Recursively get the highest product
  for (int i = 0; i < bondCount; i++)
  {
    if (!CheckIfTaken(i, takenMissions, bondIndex))
    {
      takenMissions[bondIndex] = i;
      product = bonds[bondIndex][i] * CalculateHighestProduct(bonds, bondIndex + 1, takenMissions);
      if (product > max)
      {
        max = product;
      }
    }
  }
  cout << "Bond number: " << bondIndex + 1 << " probability: " << max << endl;
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
