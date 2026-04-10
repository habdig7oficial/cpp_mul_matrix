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


template <typename Number>
Number *markov_step(uint target, Number *chain, int len, uint step, uint step_b,  bool *success){
  if(step == target){
    *success = true;
    return chain;
  }
  else if(step > target || step  == 0){
    *success = false;
    return chain;
  }

  cout << step << " " << step + step_b << endl;

  Number *res = markov_step(target, chain, len, 2 * step, step, success);
  
  if(*success)
    return res;
  else
    return  markov_step(target, chain, len, step + step_b, step_b / 2, success);;
}


int main(){
  
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

   /* 

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
   */

   int sizex_a = sizeof(a[0]) / sizeof(double);
   int sizex_b = sizeof(b[0]) / sizeof(double);

   int sizey_a = sizeof(a) / sizeof(a[0]);
   int sizey_b = sizeof(b) / sizeof(b[0]);

   double *res = mul_matrix<double>((double *) a, sizex_a, sizey_a, (double *) a, sizex_a, sizey_a);

   for(int i = 0; i < sizey_a; i++){
     for(int j = 0; j < sizex_a; j++){
       cout << *((res + i * sizex_a) + j) << " ";
     }
     cout << endl;
   }

   bool s;
   markov_step<double>(15, (double *) a, sizey_b, 2, 1, &s);
  
} 


/*

 1 - 2
 2 - 4
 3 - 8
 

15 = 2 ** 3 + 2 ** 4 + 2 ** 2 + 2 ** 1
 
 */
