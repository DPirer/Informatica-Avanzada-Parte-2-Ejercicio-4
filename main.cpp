// EJERCICIO 4

// AUTOR: PEDRO ESTÉVEZ

/* Implementar un ´Dicionario´.
•El diccionario debe contener palabras en castellano y una lista de posibles significados de cada palabra
•Notas:
-Implementar una clase diccionario, con métodos de inserción y búsqueda
-Para palabras y significados use la clase string*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Creamos el contenedor que contendrá el diccionario. Tiene que ser una variable global
map<string,string> entradas;

// CLASES
class Diccionario{
    private:
        string palabra;
        string significado;
    public:
        // Constructores
        Diccionario(string, string);
        Diccionario(string);
        // Métodos
        void insercion(Diccionario);
        void busqueda(Diccionario);
};


// CONSTRUCTOR 1 (PARA INSERCIÓN DE PALABRAS)
Diccionario::Diccionario(string _palabra, string _significado){
    this -> palabra = _palabra;
    this -> significado = _significado;
}

// CONSTRUCTOR 2 (PARA BÚSQUEDA DE PALABRAS)
Diccionario::Diccionario(string _palabra){
    palabra = _palabra;
}


// DEFINIMOS LAS FUCNIONES
void Diccionario::insercion(Diccionario entrada){
    // Cojo mi objeto con la palabra y el significado y los introduzco dentro del contenedor
    entradas.insert(make_pair(entrada.palabra, entrada.significado));

    cout<<"\nPalabra agregada correctamente al diccionario."<<endl<<endl;
    system("pause");
    system("cls");
}

void Diccionario::busqueda(Diccionario entrada){
    // Creamos un iterador y buscamos la palabra introducida por el usuario
    std::map<string,string>::iterator it;
    it = entradas.find(entrada.palabra);

    if (it != entradas.end()){ // Si el puntero no está al final del contenedor, se ha encontrado la palabra
        cout<<"\nPalabra encontrada en el diccionario."<<endl;
        cout<<endl<<"Significado: "<<it -> second<<endl<<endl;
    } else {
        cout<<"\nPalabra no encontrada en el diccionario"<<endl<<endl;
    }
    system("pause");
    system("cls");
}

// MAIN
int main() {

    while(true){
        int respuesta;
        string _palabra, _significado;

        cout<<"\t.:DICCIONARIO:."<<endl;
        cout<<"1. Agregar palabra al diccionario"<<endl;
        cout<<"2. Buscar palabra en el diccionario"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>respuesta;

        switch (respuesta) { // Por algún motivo, si no pongo las llaves, el switch da error
            case 1:
            {
                system("cls");
                fflush(stdin);
                cout<<"\nIntroduzca la palabra: ";
                getline(cin, _palabra);
                cout<<"Introduzca su significado: ";
                getline(cin, _significado);

                // Creamos un objeto que sea una entrada del diccionario
                Diccionario entrada(_palabra, _significado);

                // Y lo mando a la función inserción
                entrada.insercion(entrada);

                break;
            }
            case 2:
            {
                system("cls");
                fflush(stdin);
                cout<<"\nIntroduzca la palabra: ";
                getline(cin, _palabra);

                // Creamos el objeto que usa el segundo constructor
                Diccionario entrada(_palabra);

                // Y llamamos a la función de búsqueda
                entrada.busqueda(entrada);
                break;
            }
        case 3:
            {
                exit(1);
            }
        default:
            cout<<"\nIntroduce una opcion valida"<<endl<<endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}

