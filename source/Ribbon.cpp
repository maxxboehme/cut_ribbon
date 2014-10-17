#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <utility>
#include <cstring>

#include "prints.h"

int max_pieces_recursion(int length, int a, int b, int c){
   if(length == 0){
      return 0;
   } else if(length < 0){
      return INT_MIN;
   } else {
      int max = 0;
      max = std::max(max, max_pieces_recursion(length - a, a, b, c)+1);
      max = std::max(max, max_pieces_recursion(length - b, a, b, c)+1);
      max = std::max(max, max_pieces_recursion(length - c, a, b, c)+1);
      if(!max)
         return -1;
      return max;
   }
}

int max_pieces(int length, int a, int b, int c){
   int groups[4001];
   memset(groups, -1, sizeof(groups));
   groups[0] = 0;
   for(int i = 0; i <= length; ++i){
      int groups_a = ((i -a)>=0) ? groups[i-a] : -1; 
      int groups_b = ((i -b)>=0) ? groups[i-b] : -1; 
      int groups_c = ((i -c)>=0) ? groups[i-c] : -1;

      groups[i] = groups_a != -1 ? std::max(groups[i], groups_a+1) : groups[i];
      groups[i] = groups_b != -1 ? std::max(groups[i], groups_b+1) : groups[i];
      groups[i] = groups_c != -1 ? std::max(groups[i], groups_c+1) : groups[i];
      //ArrayToStream(std::cout, groups, 6);
      //std::cout << std::endl;
   }
   return groups[length];
}

void quick_swap(int& a, int& b){
   a ^= b;
   b ^= a;
   a ^= b;
}

void cut_ribbon_solve(std::istream& in, std::ostream& out){
   int n, a, b, c;
   while(in >> n >> a >> b >> c){
      int result = max_pieces_recursion(n, a, b, c);
      out << result << std::endl;
   }
}
