#include <iostream>
#include "Ribbon.h"

int main(int argc, char** argv){
   // turn off synchronization with C I/O
   std::ios_base::sync_with_stdio(false);
   cut_ribbon_solve(std::cin, std::cout);
   return 0;
}
