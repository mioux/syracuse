#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <gmpxx.h>

void usage(char *command)
{
  std::cerr << "Usage: " << command << " <first number>" << std::endl;
}

int main(int argc, char *argv[])
{
  // Must provides exactly 1 argument
  if (argc != 2)
  {
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  // Argument is for help
  if (strcmp(argv[1], "--help") == 0 ||
      strcmp(argv[1], "-h") == 0 ||
      strcmp(argv[1], "-?") == 0 ||
      strcmp(argv[1], "/?") == 0)
  {
    usage(argv[0]);
    return EXIT_SUCCESS;
  }

  // Argument to very big int
  mpz_class nb(argv[1], 10);

  // If argument is invalid, it will be 0. If 0 or less is provided => Error
  if (nb < 1)
  {
    std::cerr << "Can only be used with integers > 1." << std::endl;
    return EXIT_FAILURE;
  }

  // Loop while I'm not on "4 2 1" loop (stops on 1)
  while (nb != 1)
  {
    // Shows current number
    std::cout << nb.get_str() << std::endl;

    // Applies the Syracuse algorithm
    if ((nb % 2) == 0)
    {
      nb /= 2;
    }
    else
    {
      nb = nb * 3 + 1;
    }
  };

  // Shows the final 1 before exit
  std::cout << nb.get_str() << std::endl;
  return EXIT_SUCCESS;
}
