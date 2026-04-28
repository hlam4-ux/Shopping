//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
using namespace std;



double getShippingCost(int method, double cost){
   double result = -1;
   
   //Drone Delivery
   if (method == 1) {
      if (cost < 100) {
         result = -1;
      } else if (cost < 500) {
         result = 50;
      } else {
         result = cost * 0.1;
      }
   }

   //2-Day Delivery
   if (method == 2) {
      if (cost <= 300) {
         result = 10 + cost * 0.02;
      } else {
         result = 0;
      }
   }

   //Standard Delivery
   if (method == 3) {
      if (cost < 35) {
         result = 5;
      } else if (cost < 100) {
         result = 8;
         
      }
   }
      return result;
}



///----------------------------------------------------------------------------------
/// Tests
/// Uncomment tests to work on them. Make sure any test that does not compile or
/// causes a crash gets commented back out. Any test that runs should be left
/// on (uncommented), even if the test fails.
///----------------------------------------------------------------------------------

TEST_CASE( "getShippingCost Drone" ) {
   cout << "1: getShippingCost Drone" << endl;
   CHECK( getShippingCost(1, 100) == doctest::Approx(50) );
   CHECK( getShippingCost(1, 400) == doctest::Approx(50) );
   CHECK( getShippingCost(1, 615) == doctest::Approx(61.5) );
}

TEST_CASE( "getShippingCost 2-Day" ) {
   cout << "2: getShippingCost 2-Day" << endl;
   CHECK( getShippingCost(2, 120) == doctest::Approx(12.4) );
   CHECK( getShippingCost(2, 300) == doctest::Approx(16) );
   CHECK( getShippingCost(2, 350) == doctest::Approx(0) );
}

TEST_CASE( "getShippingCost Standard" ) {
   cout << "3: getShippingCost Standard" << endl;
   CHECK( getShippingCost(3, 10) == doctest::Approx(5) );
   CHECK( getShippingCost(3, 50) == doctest::Approx(8) );
   CHECK( getShippingCost(3, 200) == doctest::Approx(0) );
}

TEST_CASE( "getShippingCost Invalid" ) {
   cout << "4: getShippingCost Invalid" << endl;
   CHECK( getShippingCost(1, 50) == doctest::Approx(-1) );   // Drone under $100
   CHECK( getShippingCost(4, 150) == doctest::Approx(-1) );  // Invalid method
   CHECK( getShippingCost(0, 600) == doctest::Approx(-1) );  // Invalid method
}
