#include <iostream>
#include <vector> /* Arrays do not provide dynamic storage. */
/* The below includes are suboptimal but required for some logic. */
/* #include <sstream>
   #include <iterator> */

#include <cmath> /* For Newton's Method. */

/* Base IO. */
#include "IOThingsForBaseConversions.hpp"

void displayMenu()
{
  std::cout << "A base conversion calculator.\n"
            << "(0) Quit.\n"
            << "(1) Base 10 to any base calculator.\n"
            << "(2) Any base to base 10 calculator.\n"
            << "(3) Factorial calculator.\n"
            << "(4) Sqrt calculator using Newton's Method.\n";
}

/* If the user ever times in a number bigger than a int...
 * It will not be pretty. */
unsigned long long calculateFactorial(unsigned long long number)
{
  unsigned long long initialNumber = 1;
  unsigned long long temp = number;
  for(initialNumber; initialNumber < number; initialNumber++)
  {
    temp *= initialNumber;
  }
  return temp;
}

long double calculateSqrt(int number)
{ long double tolerance = 1e-5;
  int iteration_limit = 10;
  int iteration_count = 0;
  long double xold = number / 2;
  long double delta = 2 * tolerance;
  long double xnew = 0.5 * (xold + number / xold);
  while (iteration_count < iteration_limit && delta > tolerance)
  { xnew = 0.5 * (xold + number / xold);
    delta = fabs(xnew - xold);
    xold = xnew;
    std::cout << (iteration_count + 1) << " " << xnew << std::endl;
    iteration_count += 1;
  }
  return xnew;
}

/* Global variable, global access.
 * TODO: Merge this into push function. */
std::vector<int> pushToStorage;

void push(long long remainder)
{
  pushToStorage.push_back(remainder);
  /* pushToStorage.size() to get the size. */
}

long long base10ToBaseX()
{ long long quotient = baseIO::getQuotient();
  int base = baseIO::getBase();
  long long remainder;
  do
  { /* Probably should implement my own mod function... */
    remainder = (quotient % base);
    quotient /= base;
    push(remainder);
  } while(quotient != 0);

  for (int element = pushToStorage.size() - 1; element >= 0; element--)
  {
    std::cout << pushToStorage[element];

  }
}

int main()
{
  displayMenu();
  std::cout << "Enter your choice: ";
  int choice;
  std::cin >> choice;
  switch (choice)
  { case 0:
      return 0;
      break;
    case 1:
      base10ToBaseX();
      break;
    case 2:
      std::cout << "Not implemented yet...";
      break;
    case 3:
      unsigned long long userInput;
      std::cout << std::endl << "Enter a whole number you want to have the factorial of: ";
      std::cin >> userInput;
      std::cout << std::endl << calculateFactorial(userInput) << std::endl;
      break;
    case 4:
      userInput = 0;
      std::cout << std::endl << "Enter a whole number to calculate it's sqrt using Newton's Method: ";
      std::cin >> userInput;
      std::cout << std::endl << "The sqrt is: " << calculateSqrt(static_cast<int>(userInput)) << std::endl;
      break;
    default:
      std::cout << "Unrecognized input. Quitting...";
      return 1;
  }
  return 0;
}
