#include <iostream>

using namespace std;

/**
 * this function calculates the shipping cost
 * method tells which shipping type we use
 * cost is the price of the order
 * it returns the shipping cost or -1 if doing wrong
 */
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
      }else {
         result = 0;
      }
   }
      return result;
}

int main()
{ double cost;
  int method;

  cout << "Enter cost"; 
  cin >> cost;
  cout << "Enter method";
  cin >> method;

  double shipping;
  shipping = getShippingCost(method, cost);
} 
if (cost < 0 // method < 1 ?? method >3)
