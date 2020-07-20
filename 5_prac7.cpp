#include <iostream>
#include <utility>
#include <vector>
#include <string>
 
int main()
{
    std::string str = "Hola"; // declaramos un string con "hola"
    std::vector<std::string> v; //usamos el vector son contenedores de secuencias que representan matrices que pueden cambiar de tamaño
 
    v.push_back(str); //Agrega un nuevo elemento al final del vector , después de su último elemento actual. El contenido de val se copia (o mueve) al nuevo elemento.
    std::cout << "Antes de la copia \"" << str << "\"\n";

    v.push_back(std::move(str));//se activa el push y se mueve el str
    std::cout << "Antes del moviemiento \"" << str << "\"\n";
 
    std::cout << "Contenido del vector \"" << v[0] // imprimimos los contenidos del vector para demostarr el movimiento
                                         << "\", \"" << v[1] << "\"\n";
}