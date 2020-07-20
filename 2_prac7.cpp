#include <iostream>
using namespace std;

//creamos la clase A
class A {
  public:
    int a;
    A& operator= (A&& other) { // sobrecargamos el operador, par que tome una referncia de valor
        this->a = other.a; // llamamos al dato con thid->; y le asignamos el otro valor 
        other.a = 0; // actualizamos al dato "a" de other con 0
        return *this;
    }
};

int main() //- función principal
{

   //lvalue y rvalue 
   int x = 3 + 4; // x -> lvalue, trasciende. y 3+4 -> un rvalue, valor temporal 
   cout << x << endl; // 

   string   s1  = "Hello "; //s1-lvalue y "hello"-rvalue
   string   s2  = "world"; //s2-lvalue y "world"-rvalue

   cout<<s1<<endl; // impresion y extracción  de dirección de memoria
   cout<<&s1<<endl;

   cout<<s2<<endl;
   cout<<&s2<<endl;

   cout<<endl;

   string&& s_rref = s1 + s2; //se declara la referncia a al rvalue y se guarda s_rref(referencia a obj temporal rvalue)  
   s_rref += ", my friend";   // podemos agregarle o cambiarlo!

   cout<<&s_rref<<endl;
   cout << s_rref << '\n';    // imprime  "Hello world, my friend"

   //semántica de movimiento

   A a; // creamos un objeto "a"
   a.a = 1;
   A b; // creamos objeto "b"
   b = std::move(a); //llamamos al operador
   std::cout << a.a << std::endl; //0
   std::cout << b.a << std::endl; //1
    

   return 0;
}