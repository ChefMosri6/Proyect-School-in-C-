#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
using namespace std;
//Variables Globales
int total =0;
string NombreProducto[100]={"Leche","Pan","Agua","Huevos","Refresco"};
int PrecioDeCompra[100]={10,10,10,10,10};
int PrecioDeVenta[100]={10,20,10,15,11};
int ExistenciaFisicas[100]={23,20,12,20,10};
int NumeroDeReorden[100]={5,2,8,5,3};
int StatusDelProducto[100]={1,1,1,1,1};

struct productos{


    string NombreProducto;
    int PrecioDeCompra;
    int PrecioDeVenta;
    int ExistenciaFisicas;
    int NumeroDeReorden;
    int StatusDelProducto;
    } ;

    productos info[100]; // declaracion del arreglo de estructuras

void Altas();
void Mostrar();
void Administrador();
void Ventas();
int main() {
    //menu

    int opcion = 0;

    {
        cout<< "menu\n";
        cout<< "1 Administrador\n";
        cout<< "2 ventas\n";
        cout<< "3 Salir\n";
        cin>> opcion;
        switch (opcion)
        {
            case 1: Administrador();
                break;
            case 2: Ventas();
                break;
            case 3: cout<< "cerrando sistema";
                break;
            default : cout << "opcion invalida";
        }
    }while(opcion != 3);

    return 0;
    }

void Administrador(){
{
      int password;
      password = 1234;

      string username;
      username = "admin";
      string userinput;

      do
      {
          cout << "Enter username:";
          cin >> userinput;

          if (userinput == username);
          {
              cout <<"\n";
              cout << "Enter password:";
              cin >> password;

          }
      }
      while (userinput == username);

      if (password == 1234)
          cout << "Accesso concedido ...";
      if (password != 1234)
          cout << "Acceso Incorrecto.....Invalid Username/Password:";

  }
// Menu de opciones a escojer
  int opcion = 0; //variable local
  do
  {
      cout<< "Estas en el modulo Administrador\n";
      cout<< "1 Alta\n";
      cout << "2  Mostar" << '\n';
      cout << "3  Ventas" << '\n';
      cin >> opcion;
      switch (opcion)
      {
          case 1: Altas();
              break;
          case 2: Mostrar();
              break;
          case 3: Ventas();
              break;
         default : cout << "opcion invalida";
      }
  }while(opcion != 8);
}
 

    

void Altas(){
      int i;
    i=total;
    int valor_temp;

    while (true) {
        cout << "Ingrese Indice del producto: ";
        cin>>valor_temp;
        if (valor_temp == 0)
            break;
        cout << "Nombre del producto: ";
        cin >> info[i].NombreProducto;
        cout << "Precio de compra: ";
        cin >> info[i].PrecioDeCompra;
        cout << "Precio de venta: ";
        cin >> info[i].PrecioDeVenta;
        cout << "Existencias Fisicas: ";
        cin >> info[i].ExistenciaFisicas;
        cout << "Numero de Reorden: ";
        cin >> info[i].NumeroDeReorden;
          cout <<"Status del Producto(Si es 1 esta activo 0 esta desactivado)";
        cin >> info[i].StatusDelProducto;
        i++;
    }
    total = i;

}
void Mostrar(){
    int i;
  for(i=0;i<total;i++)
      cout<<"Nombre del producto: "<<info[i].NombreProducto<<'\n'<<"Precio de compra: "<<info[i].PrecioDeCompra<<'\n'<<"Precio de venta: "<<info[i].PrecioDeVenta<<'\n'<<"Existencias Fisicas: "<<info[i].ExistenciaFisicas<<'\n'<<"Numero de reorden: "<<info[i].NumeroDeReorden<<'\n'<<"Status del producto: "<<info[i].StatusDelProducto<<'\n';

}
void Ventas(){

}
    

