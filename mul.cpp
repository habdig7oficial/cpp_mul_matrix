#include "iostream"
#include "stdlib.h"

#define DIMENSIONS  5

using namespace std;

template <typename Number>

Number *mul_matrix(Number *matrix1, int lenx1, int leny1, Number *matrix2, int lenx2, int leny2){
  if(lenx1 != leny2)
    throw runtime_error("Invalid multiplication");
  
  Number *matrix_res = (Number *) malloc(leny1 * lenx2 * sizeof(Number));
  
  for(int i = 0; i < lenx2; i++){
    for(int k = 0; k < leny2; k++){
      for(int j =  0; j < leny1; j++){
	cout << "[" << i << "] [" << j << "] "<< *((matrix1 + i * leny2) + k)  << " + " << *((matrix2 + k * leny1) + j) << "\t";
	*((matrix_res + i * leny1) + j) += *((matrix1 + i * leny2) + k) * *((matrix2 + k * leny1) + j);
      }
      cout << endl;
    } 
    cout << endl;
  }

  return matrix_res;
}

int main(){
  /*
  double a[][DIMENSIONS] = {
    {0.1, 0.2, 0.7},
    {0.9, 0.1, 0},
    {0.1, 0.8, 0.1}
  };

  
   double b[][2] = {
     {2.0, 1.0},
     {1.0, 2.0},
     {0.1, 1.0}
--  };

  */

   int house [][DIMENSIONS] = {
     {5, 20, 16, 7, 17},
     {7, 18, 12, 9, 21},
     {6, 25, 8, 5, 23}
   };

   int constructed [][1] = {
     {5},
     {7},
     {12}
   };

   int sizex_house = sizeof(house[0]) / sizeof(int);
   int sizex_constructed = 1;

   int sizey_house = sizeof(house) / sizeof(house[0]);
   int sizey_constructed = sizeof(constructed) / sizeof(constructed[0]);

   int *res = mul_matrix<int>((int *) house, sizex_house, sizey_house, (int *) constructed, sizex_constructed, sizey_constructed);

   for(int i = 0; i < sizey_house; i++){
     for(int j = 0; j <  sizex_house ; j++){
       cout << *((res + i * sizex_house) + j) << " ";
     }
     cout << endl;
   }
  
} 
