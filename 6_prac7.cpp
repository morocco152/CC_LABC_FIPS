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

    //Constructor copia con una referencia rvalue
    Holder(Holder&& other)     // <-- rvalue reference
    {
      m_data = other.m_data;   // (1)
      m_size = other.m_size;
      other.m_data = nullptr;  // (2)
      other.m_size = 0;
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
  Holder h1(10000); // constructor regular
  Holder h2 = h1;   // constructor copia
  Holder h3(h1);    // constructor copia (alternate syntax)

  return 0;
}