#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

#include "gtest/gtest.h"

#include "prints.h"
#include "Ribbon.h"


TEST(Ribbon, max_pieces_recursion){
   int result = max_pieces_recursion(5, 5, 3, 2);
   ASSERT_EQ(2, result);   
}

TEST(Ribbon, max_pieces_recursion_2){
   int result = max_pieces_recursion(7, 5, 5, 2);
   ASSERT_EQ(2, result);   
}

TEST(Ribbon, max_pieces_recursion_3){
   int result = max_pieces_recursion(5, 5, 5, 2);
   ASSERT_EQ(1, result);   
}

TEST(Ribbon, max_pieces){
   int result = max_pieces(5, 5, 3, 2);
   ASSERT_EQ(2, result);   
}

TEST(Ribbon, max_pieces_2){
   int result = max_pieces(7, 5, 5, 2);
   ASSERT_EQ(2, result);   
}

TEST(Ribbon, max_pieces_3){
   int result = max_pieces(5, 5, 5, 2);
   ASSERT_EQ(1, result);   
}

TEST(Ribbon, max_pieces_4){
   int result = max_pieces(4000, 5, 5, 2);
   ASSERT_EQ(2000, result);   
}

TEST(Ribbon, max_pieces_5){
   int result = max_pieces(5, 5, 1, 2);
   ASSERT_EQ(5, result);   
}

TEST(Ribbon, cut_ribbon_solve){
   std::stringstream r("5 5 3 2\n7 5 5 2");
   std::stringstream w;
   cut_ribbon_solve(r, w);
   //ASSERT_EQ(w.str(), "2\n2\n");   
}
