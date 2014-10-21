#include <iostream>
#include <algorithm>
#include <climits>
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
   ArrayToStream(std::cout, groups, length);
   std::cout << std::endl;

   int cuts[] = {a, b, c};
   std::sort(cuts, cuts+3);
   ArrayToStream(std::cout, cuts, 3);
   std::cout << std::endl;
   
   if(length % cuts[0] == 0)
      return length/cuts[0];

   for(int i = 0; i < 3; ++i){
      for(int j = 0; j <= length; ++j){
         int groups_i = ((j - cuts[i]) >= 0) ? groups[j - cuts[i]] : -1;
         groups[j] = groups_i != -1 ? std::max(groups[j], groups_i+1) : groups[j];
      }
      if(groups[length] != -1)
         break;
      ArrayToStream(std::cout, groups, length);
      std::cout << std::endl;
   }
   return groups[length];
}

int max_pieces3(int length, int a, int b, int c){
   int groups[4001];
   memset(groups, -1, sizeof(groups));
   groups[0] = 0;

   for(int i = 0; i <= length; ++i){
      int groups_a = ((i - a) >= 0) ? groups[i-a] : -1; 
      int groups_b = ((i - b) >= 0) ? groups[i-b] : -1; 
      int groups_c = ((i - c) >= 0) ? groups[i-c] : -1;

      groups[i] = groups_a != -1 ? std::max(groups[i], groups_a+1) : groups[i];
      groups[i] = groups_b != -1 ? std::max(groups[i], groups_b+1) : groups[i];
      groups[i] = groups_c != -1 ? std::max(groups[i], groups_c+1) : groups[i];
   }
   return groups[length];
}

int max_pieces2(int length, int a, int b, int c){
   int groups[4001];
   memset(groups, -1, sizeof(groups));
   groups[0] = 0;

   int cuts[] = {a, b, c};
   std::sort(cuts, cuts+3);

   if(length % cuts[0] == 0)
      return length/cuts[0];

   for(int i = 0; i <= length; ++i){
      for(int j = 0; j < 3; ++j){
         int groups_j = ((i - cuts[j]) >= 0) ? groups[i - cuts[j]] : -1;
         groups[i] = groups_j != -1 ? std::max(groups[i], groups_j+1) : groups[i];
      }
   }
   return groups[length];
}

int max_pieces(int length, int cuts[], int size){
   int groups[4001];
   memset(groups, -1, sizeof(groups));
   groups[0] = 0;

   for(int i = 0; i <= length; ++i){
      for(int j = 0; j < size; ++j){
         int groups_j = ((i - cuts[j]) >= 0) ? groups[i - cuts[j]] : -1;
         groups[i] = groups_j != -1 ? std::max(groups[i], groups_j+1) : groups[i];
      }
   }
   return groups[length];
}

void cut_ribbon_solve(std::istream& in, std::ostream& out){
   // turn off synchronization with C I/O
   //std::ios_base::sync_with_stdio(false);

   int n, a, b, c;
   while(in >> n >> a >> b >> c){
      int result = max_pieces(n, a, b, c);
      out << result << std::endl;
   }
}
