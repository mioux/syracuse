#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <first number>" << endl;
    return EXIT_FAILURE;
  }

  unsigned long long nb = strtoul(argv[1], NULL, 10);

  if (nb == 0)
  {
    cout << 0 << endl;
    return EXIT_SUCCESS;
  }

  while (nb != 1)
  {
    cout << nb << endl;

    if ((nb & 1) == 0)
    {
      nb /= 2;
    }
    else
    {
      nb = nb * 3 + 1;
    }
  };

  cout << nb << endl;
  return EXIT_SUCCESS;
}
