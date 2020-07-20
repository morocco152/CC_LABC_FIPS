#include <iostream>
using namespace std;

void fun (const int & lref) // los argumentos de lvalue seleccionarán esta
{ 
  cout << "referencia de valor l para const "<<endl; 
}
void fun (int && rref) // los argumentos de rvalue seleccionarán esta función
{ 
  cout << "r-value reference n"<<endl; 
}
int main () 
{ 
   int x {5}; 
   fun (x); // El argumento lvalue llama a la versión l-value de la función 
   fun (5); // el argumento rvalue llama a la versión de valor r de la función 
   return 0; 
} 