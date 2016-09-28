#include <iostream>

namespace baseIO {
  inline int getBase(void)
  { int base;
    std::cout << "Enter the base to convert to: ";
    std::cin >> base;
    return base;
  }
  /* DM 2.11 gave us a number that required the use of long long... */
  inline long long getQuotient(void)
  { long long quotient;
    std::cout << "Enter the base 10 number: ";
    std::cin >> quotient;
    return quotient;
  }
}
