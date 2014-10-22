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

TEST(Ribbon, max_pieces2){
   int cuts[] = {5, 3, 2};
   int result = max_pieces(5, cuts, 3);
   ASSERT_EQ(2, result);   
}

TEST(Ribbon, max_pieces2_2){
   int cuts[] = {5, 5, 2};
   int result = max_pieces(7, cuts, 3);
   ASSERT_EQ(2, result);   
}

TEST(Ribbon, max_pieces2_3){
   int cuts[] = {5, 5, 2};
   int result = max_pieces(5, cuts, 3);
   ASSERT_EQ(1, result);   
}

TEST(Ribbon, max_pieces2_4){
   int cuts[] = {5, 5, 2};
   int result = max_pieces(4000, cuts, 3);
   ASSERT_EQ(2000, result);   
}

TEST(Ribbon, max_pieces2_5){
   int cuts[] = {5, 1, 2};
   int result = max_pieces(5, cuts, 3);
   ASSERT_EQ(5, result);   
}

TEST(Ribbon, cut_ribbon_solve){
   std::stringstream r("5 5 3 2\n7 5 5 2");
   std::stringstream w;
   cut_ribbon_solve(r, w);
   ASSERT_EQ("2\n2\n", w.str());   
}

TEST(Ribbon, cut_ribbon_solve_2){
   std::stringstream r("16 10 8 3");
   std::stringstream w;
   cut_ribbon_solve(r, w);
   ASSERT_EQ("3\n", w.str());   
}


TEST(Ribbon, cut_ribbon_solve_3){
   std::stringstream r("3328 44 92 148\n3336 651 18 268");
   std::stringstream w;
   cut_ribbon_solve(r, w);
   ASSERT_EQ("70\n115\n", w.str());   
}

TEST(Ribbon, cut_ribbon_solve_4){
   std::stringstream r("490 4 49 50\n100 3 17 22");
   std::stringstream w;
   cut_ribbon_solve(r, w);
   ASSERT_EQ("111\n27\n", w.str());   
}
