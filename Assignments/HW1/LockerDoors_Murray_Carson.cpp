// Carson Murray Copyright 2022
// #include <Assignments/hw1.cc>
#include <iostream>
#include <cstddef>

int main (int argc, char*argv[]) {
  size_t total = 0;
  std::cout << "Please enter the number of lockers:" << std::endl;
  std::cin >> total;

  size_t passes = 0;
  std::cout << "Now enter the number of passes: " << std::endl;
  std::cin >> passes;

  size_t lockers[total];
  for (size_t i = 0; i < total; ++i) {
    lockers[i] = 0; // initializes all lockers to be closed (0 is closed, 1 is open)

  }
  if (passes > total) {
    do {
      if (lockers[0] == 0) {  // they must be all 0's so switch them all to 1's
        for (size_t i = 0; i < total; ++i) {
          lockers[i] = 1;
        } 
      } else {
        for (size_t i = 0; i < total; ++i) {  // they must be all 1's so switch them to 0's
          lockers[i] = 0; 
        }
      }
        passes = passes - total;  // subtract lockers already passed
    } while (passes > total); // at this point passes must be less than total lockers
      if (lockers[0] == 0) {  // they must be all 0's, switch remaining lockers to 1
        for (size_t i = 0; i < passes; ++i) {
          lockers[i] = 1;
          }
        } else {  // they must be all 1's, switch remaining lockers to 0
        for (size_t i = 0; i < passes; ++i) {
          lockers[i] = 0;
          }
        }   
  } else {  // the number of passes was already less than or equal to the total
    if (lockers[0] == 0) {  // they must be all 0's, switch remaining lockers to 1
      for (size_t i = 0; i < passes; ++i)
        lockers[i] = 1;
      } else {  // they must be all 1's, switch remaining lockers to 0
      for (size_t i = 0; i < passes; ++i)
        lockers[i] = 0;
      }
  }

  // At this point all lockers should be in their appropriate state
  // Now print info out for the user to see

  for (size_t i = 0; i < total; ++i) {
    if (lockers[i] == 0)
      std::cout << "Locker " << i+1 << " is Closed!" << std::endl;
    else
      std::cout << "Locker " << i+1 << " is Open!" << std::endl;  // must be 1
  }

  size_t counter = 0;

  for (size_t i = 0; i < total; ++i) {
    if (lockers[i] == 1)
      counter ++;
  }

  std::cout << "" << std::endl;

  if (counter > 1 )
    std::cout << "There are " << counter << " lockers open" << std::endl;
  else if (counter == 1)
    std::cout << "There is 1 locker open" << std::endl;
  else
    std::cout << "There are 0 lockers open" << std::endl;

}