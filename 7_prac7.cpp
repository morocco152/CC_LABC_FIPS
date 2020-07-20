#include <iostream>
using namespace std;

class Holder //nueva clase holder
{
  public:

    Holder(int size)         // Constructor  paso por valor size 
    {
      m_data = new int[size];  // damos memoria dinamica para poder demostrarlos moviemitnos 
      m_size = size;   //guardamos el valor en las variables mienbro
    }

    Holder(const Holder& other) //lvalue argument
    {
      m_data = new int[other.m_size];  // (1)
      std::copy(other.m_data, other.m_data + other.m_size, m_data);  // (2)
      m_size = other.m_size;
    }

    /* Investigar, describir e implementar un ejemplo usando el 
     *   operador de asignación move (move assigment constructor)
     */
    //Sobrecargando el operador = con una referencia rvalue

    Holder& operator=(Holder&& other){     // <-- rvalue reference  
      
      if (this == &other) return *this;

      delete[] m_data;         // (1)

      m_data = other.m_data;   // (2)
      m_size = other.m_size;

      other.m_data = nullptr;  // (3)
      other.m_size = 0;

      return *this;
    }

    ~Holder()                // Destructor
    {
      delete[] m_data;   //eliminarmos los los valores luego de usarlos, es necesario esto para no acumular basura 
    }

  private:

    int*   m_data; //datos mienbro
    size_t m_size;
};

int main(){  //fx principal
  Holder h = createHolder(1000); // constructor copia
  h = createHolder(500);         // operador de asginación

  return 0;
}