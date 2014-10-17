
#ifndef __RIBBON__
#define __RIBBON__

#include <iostream>

void cut_ribbon_solve(std::istream& in, std::ostream& out);


int max_pieces_recursion(int length, int a, int b, int c);
int max_pieces(int length, int a, int b, int c);
void quick_swap(int& a, int& b);
#endif
