#include "iostream"
#include "stdlib.h"

#define DIMENSIONS  3

using namespace std;

template <typename Number>

Number *mul_matrix(Number *matrix1, int lenx1, int leny1, Number *matrix2, int lenx2, int leny2){
  if(lenx1 != leny2)
    throw runtime_error("Invalid multiplication");
  
  Number *matrix_res = (Number *) malloc(leny1 * lenx2 * sizeof(Number));
  
  for(int i = 0; i < lenx2; i++){
    for(int j =  0; j < leny1; j++){
      for(int k = 0; k < leny2; k++){
	cout << "[" << i << "] [" << j << "] "<< *((matrix1 + i * leny2) + k)  << " + " << *((matrix2 + k * leny1) + j) << "\t";
	//*((matrix_res + k * leny2) + i) = *((matrix1 + i * leny1)); 
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
  };

  */

    double a[][DIMENSIONS] = {
      {2, 3, 1},
      {-1, 0, 2},
      // {0.1, 0.8, 0.1}
    };

  
    double b[][2] = {
      {1, -2},
      {0, 5},
      {4, 1.0}
     };
  

   int sizex_a = sizeof(a[0]) / sizeof(double);
   int sizex_b = sizeof(b[0]) / sizeof(double);

   int sizey_a = sizeof(a) / sizeof(a[0]);
   int sizey_b = sizeof(b) / sizeof(b[0]);

   double *res = mul_matrix<double>((double *) a, sizex_a, sizey_a, (double *) b, sizex_b, sizey_b);

   for(int i = 0; i < sizey_a; i++){
     for(int j = 0; j < sizex_b; j++){
       cout << *((res + i * sizex_b) + j) << " ";
     }
     cout << endl;
   }
  
} 
