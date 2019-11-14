#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
//Variables Globales
int total = 0;
struct nodo {
  int indice;
  char producto[80];
  int pc;
  int pv;
  int exi;
  int nvlr;
  nodo * siguiente;
  nodo * anterior;
};
nodo * ptr = NULL;
nodo * inicio = NULL;
nodo * fin = NULL;
nodo * nuevo = NULL;

void Administrador();
void Ventas();
void Escritura();
void Lectura();
int main() {
  //menu

  int opcion = 0;

  {
    cout << "menu\n";
    cout << "1 Administrador\n";
    cout << "2 ventas\n";
    cout << "3 Salir\n";
    cin >> opcion;
    switch (opcion) {
    case 1:
      Administrador();
      break;
    case 2:
      Ventas();
      break;
    case 3:
      cout << "cerrando sistema";
      break;
    default:
      cout << "opcion invalida";
    }
  }
  while (opcion != 3);

  return 0;
}

void Administrador() {
  {
    int password;
    password = 1234;

    string username;
    username = "admin";
    string userinput;

    do {
      cout << "Enter username:";
      cin >> userinput;

      if (userinput == username); {
        cout << "\n";
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
  do {
    cout << "Estas en el modulo Administrador\n";
    cout << "1 Alta de producto\n";
    cout << "2  Mostar Producto" << '\n';
    cout << "3  Ventas" << '\n';
    cin >> opcion;
    switch (opcion) {
    case 1:
      Escritura();
      break;
    case 2:
      Lectura();
      break;
    case 3:
      Ventas();
      break;
    default:
      cout << "opcion invalida";
    }
  } while (opcion != 8);
}


void Escritura() {
  fstream ArchivoInventario("inventario.bin", ios:: in | ios::binary);
int indice;
    char NombreProducto[80];
    int PrecioDeCompra;
    int PrecioDeVenta;
    int ExistenciaFisicas;
    int NivelDeReorden;
    if (!ArchivoInventario)
    cout<<"Error en la apertura del archivo";
else{
        do{
            cout<<"Escriba el indice del poducto(0 para salir debe empezar en # 5 en adelante)  ";
            cin>>indice;
            if(indice!=0){
                cout<<"Escriba el nombre del prodcuto que quiere dar de alta : ";
                cin>>NombreProducto;
                fflush(stdin);//vac�a el bufer de lectura
                cout<<"Escriba el precio de compra: ";
                cin>>PrecioDeCompra;
                cout<<"Escriba el precio de venta: ";
                cin>>PrecioDeVenta;
                cout<<"Escriba las existencias fisicas del producto: ";
                cin>>ExistenciaFisicas;
                cout<<"Escriba el nivel de reorder del producto: ";
                cin>>NivelDeReorden;     //escritura en el archiv
        reinterpret_cast < char * > ( & indice), sizeof(indice);
      ArchivoInventario.write(NombreProducto, 80);
      ArchivoInventario.write(
        reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
      ArchivoInventario.write(
        reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
      ArchivoInventario.write(
        reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
      ArchivoInventario.write(
        reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
            }
        }while(indice!=0);
    }
    ArchivoInventario.close();

}
void Ventas() {

}
void Lectura() { // Lectura del archivo binario previamente creado
    ifstream ArchivoInventario("inventario1.bin", ios:: in | ios::binary);
    //Variables locales
    int total = 0;
    int indice;
    char NombreProducto[80];
    int PrecioDeCompra;
    int PrecioDeVenta;
    int ExistenciaFisicas;
    int NivelDeReorden;
    if (!ArchivoInventario)
      cout << "Error en la apertura del archivo";
    else {
     cout << left << setw(8) << "Indice" << setw(20) << "Nombre del Producto" << setw(10) << "Precio de Compra" << setw(10) << "Precio de venta" << setw(10) << "Existencias" << setw(10) << "Nivel de Reorden" << endl;
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & indice), sizeof(indice));
      ArchivoInventario.read(NombreProducto, 80);
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
      //Primera lectura del programa y creacion de los datos a listas
      nuevo = new(nodo);
      strcpy(nuevo -> producto, NombreProducto); //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      inicio=nuevo;
      fin=nuevo;
     
      //Segunda lectura del archivo binario
      while (ArchivoInventario.eof() == false){
      cout << left << setw(8) << "Indice" << setw(20) << "Nombre del Producto" << setw(10) << "Precio de Compra" << setw(10) << "Precio de venta" << setw(10) << "Existencias" << setw(10) << "Numero de Reorden" << endl;
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & indice), sizeof(indice));
      ArchivoInventario.read(NombreProducto, 80);
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
      ArchivoInventario.read(
        reinterpret_cast <char *> ( & PrecioDeVenta), sizeof(PrecioDeVenta));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
nuevo = new(nodo);
      strcpy(nuevo -> producto, NombreProducto); //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      fin -> siguiente = nuevo;
      fin = nuevo;
    
      }
      //Borrado del ultimo nodo porque no tiene informacion y no tiene informacion. 
      ptr = inicio;
      while(ptr->siguiente !=fin)
        ptr=ptr->siguiente;
      delete(fin);
      fin=ptr;
      fin->siguiente=NULL;
       // Aqui se desplega la lista con los valores previamente agregados. 
      cout << left << setw(8) << "Indice" << setw(20) << "Nombre del Producto" << setw(10) << "Precio de Compra" << setw(10) << "Precio de venta" << setw(10) << "Existencias" << setw(10) << "Numero de Reorden" << endl;
      ptr =inicio;
      while(ptr!=NULL){
        cout<<ptr->producto<<setw(8)<< ptr->pc<<setw(8)<< ptr->pv<<setw(8)<<endl;
        ptr=ptr->siguiente;
      
      }
ArchivoInventario.close();
    }
  }
