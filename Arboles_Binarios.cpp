//Hecho por Carlos Alfonso Lemus Rodezno

//clase de programacion II arboles binarios

#include <iostream> //libreria estandar necesaria para utilizar sus elementos
#include <windows.h> //libreria necesaria para utilizar sus funciones
#include <stdio.h> //libreria necesaria para utilizar sus funciones

using namespace std; //nombre de espacio a usar el estandar 

struct nodo //estructura que utilizaremos como nodo para nuestro arbol binario
{
	int nro;
	struct nodo *izq, *der; /*variables del tipo de la estructura nodo que seran usadas como el 							apuntador derecho y el apuntador izquierdo de todos los nodos del 								arbol*/ 
};
//typedef pone un alias a un tipo de dato
typedef struct nodo *ABB;

//declaracion de funciones
void menu(); //declaracion de funcion que sera el menu del programa
void verarbol(ABB , int ); //declaracion de funcion que permite ver los datos del arbol
void insertar(ABB &, int ); //declaracion de funcion que permite ingresar los datos en el arbol
void preorden(ABB ); //declaracion de funcion que imprime los datos del arbol en preorden
void postorden(ABB ); //declaracion de funcion que imprime los datos del arbol en postorden
void inorden(ABB ); //declaracion de funcion que permite imprimir los datos del arbol en inorden
int contarhojas(ABB ); //declaracion defuncion que imprime el numeros de hojas del arbol
void eliminar(ABB &, int ); //declaracion de funcion que elimina datos del arbol
ABB unirABB(ABB, ABB); //declaracion de funcion que une
void ErrorDato(); //declaracion de funcion para evitar errores de entradas


int main()
{
	
	menu(); //funcion que contiene el menu de este programa

	system("pause");
	
	return 0;
}

void menu() //funcion que sera el menu del programa
{
	int opcion; //varible que almacena la opcion que el usuario elija
    char seguir; //varaible que almacena la opcion de siguer o no haciendo cierta accion
	int valor;//variable que captura el valor del nodo a eliminar
	ABB arbol = NULL; //se inicializa el arbol en null
	int x;//dato que se inserta en el nodo
	int n;//numero de nodos

	system("color 2F"); //funcion que le da color al fondo y texto de la consola

    do { //ciclo que permite la ejecucion del programa mientras el usario no haigo elejido la opcion de salir

        do { //ciclo que evita entradas de datos erroneos

            system("cls"); //funcion que borra texto de la pantalla

			cout << "\n\n\n\n\t\t\t\t\t\t\t__________________" << endl;
            cout << "\t\t\t\t\t\t\t\tMenu" << endl;
            cout << "\t\t\t\t\t\t\t***============***\n\n";
            cout << "\t\t\t\t\t\t\t1.Agregar" << endl;
            cout << "\t\t\t\t\t\t\t2.Mostrar" << endl;
            cout << "\t\t\t\t\t\t\t3.Eliminar" << endl;
            cout << "\t\t\t\t\t\t\t4.Datos del arbol" << endl;
            cout << "\t\t\t\t\t\t\t5.Salir" << endl;

            fflush(stdin); //funcion que limpia el buffer
            cout << "\n\n\t\t\t\t\t\t\tIngrese una opcion: ";
            cin >> opcion;
            ErrorDato(); //funcion para evitar errores de entradas


        } while (opcion < 1 || opcion > 6 || opcion == cin.fail());

		switch(opcion)
		{
			case 1:
				
				do { //ciclo que evita errores de ingresos de datos

					system("cls"); //funcion que borra texto de la pantalla

					cout << "\n\n\n\n\t\t\t\t\t\t\t'''''''''''''''''''''''" << endl;
					cout << "\t\t\t\t\t\t\tIngresa datos en el Arbol!" << endl;
					cout << "\t\t\t\t\t\t\t====----------------====\n\n";

					fflush(stdin); //funcion que limpia el buffer
					cout<<"\n\n\t\t\t\t\t\t\tIngrese el numero de nodos del arbol: ";
					cin>>n;
					ErrorDato(); //funcion para evitar errores de entradas

				} while(n == cin.fail());
				
				for(int i=0; i<n; i++) { //ciclo for para ingresar los nodos ingresados

					do { //ciclo que evita errores de ingresos de datos

						system("cls"); //funcion que borra texto de la pantalla

						cout << "\n\n\n\n\t\t\t\t\t\t\t'''''''''''''''''''''''" << endl;
						cout << "\t\t\t\t\t\t\tIngresa datos en el Arbol!" << endl;
						cout << "\t\t\t\t\t\t\t====----------------====\n\n";
						
						fflush(stdin); //funcion que limpia el buffer
						cout << "\n\n\t\t\t\t\t\t\tIngrese el valor del nodo: ";
						cin >> x;
						ErrorDato(); //funcion para evitar errores de entradas

					} while(x == cin.fail());

					insertar(arbol, x); //funcion que ingresa el dato al arbol
				
				}

				system("pause");
				
				break;

				case 2:
					
					if(arbol == NULL) //si arbol es null entonces no se mostrara nada puesto que el arbol no posee elemntos
					{
						system("cls"); //funcion que borra texto de la pantalla

						cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tNo hay registros\n\n" << endl;
					}

					else {
					
						system("cls"); //funcion que borra texto de la pantalla

						cout << "\n\n\n\n\t\t\t\t\t\t\t'''''''''''''''''''''''''" << endl;
						cout << "\t\t\t\t\t\t\tLista de datos en el Arbol" << endl;
						cout << "\t\t\t\t\t\t\t====-------------------====\n\n\n\n";
						
						verarbol(arbol, n); //funcion que muestra los datos del arbol

					}

					system("pause");

					break;


				case 3:
					if(arbol == NULL) //si arbol es null entonces no se elimara nada puesto que el arbol no posee elementos
					{
						system("cls"); //funcion que borra texto de la pantalla

						cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tNo hay registros\n\n" << endl;
					}

					else {
						do { //ciclo que evita errores de datos y permite elimnar mas de un elemnto del arbol

							system("cls"); //funcion que borra texto de la pantalla
							
							do { //ciclo que evita errores de ingresos de datos

								system("cls"); //funcion que borra texto de la pantalla

								cout << "\n\n\n\n\t\t\t\t\t\t\t''''''''''''''''''''''''" << endl;
								cout << "\t\t\t\t\t\t\tElimina datos en el Arbol!" << endl;
								cout << "\t\t\t\t\t\t\t====------------------====\n\n";

								fflush(stdin); //funcion que limpia el buffer
								cout << "\n\n\t\t\t\t\t\tIngrese el valor del nodo que desea eliminar: ";
								cin >> valor;
								ErrorDato(); //funcion para evitar errores de entradas

							} while(valor == cin.fail());							
							
							eliminar(arbol,valor); //funcion que elimina un dato del arbol

							fflush(stdin); //funcion que limpia el buffer
							cout << "\n\n\t\t\t\t\t\tDesea eliminar otro examen (y/n): ";
							cin >> seguir;
							ErrorDato(); //funcion para evitar errores de entradas
								
						} while(arbol != NULL && ((seguir == 'y' || seguir == 'Y') || (seguir != 'y' && seguir != 'Y' && seguir != 'n' && seguir != 'N')));
					
					}
					
					system("pause");

					break;
		
					case 4:
						if(arbol == NULL) //si arbol es null entonces no se mostrara nada puesto que el arbol no posee elemntos
						{
							system("cls"); //funcion que borra texto de la pantalla

							cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tNo hay registros\n\n" << endl;
						}

						else {
						
							system("cls"); //funcion que borra texto de la pantalla

							cout << "\n\n\n\n\t\t\t\t\t\t\t'''''''''''''''''''''''" << endl;
							cout << "\t\t\t\t\t\t\t    Datos del Arbol" << endl;
							cout << "\t\t\t\t\t\t\t====----------------====\n\n";
							
							cout << "\n\n\t\t\tMostrando el arbol en pre-orden: " ;
							preorden(arbol);

							cout << "\n\n\t\t\tMostrando el arbol en post-orden: " ;
							postorden(arbol);

							cout<<"\n\n\t\t\tMostrando el arbol en in-orden: ";
							inorden(arbol);

							cout<<"\n\n\t\t\tCantidad de hojas del arbol: ";
							cout << contarhojas(arbol) << endl << endl;

						}
						
						system("pause");
						
						break;

					case 5:

						system("cls"); //funcion que borra texto de la pantalla

						cout << "\n\n\n\n\t\t\t\t\t\tGracias por usar el programa\n\n\n" << endl;

						system("pause");

						break;

		} 

	} while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4);
	
}

void insertar(ABB &arbol, int x) //funcion que permite ingresar los datos en el arbol
{ 
	if(arbol==NULL) //la condicion evalua si el nodo del arbol posee un elemento 
	{
		ABB nuevonodo = new(struct nodo); //reserva espacio en la memoria y segmenta la memoria
		nuevonodo->nro = x; //ingresa el dato al nodo
		nuevonodo->izq = NULL; //establece como null el apuntador izquiedo del nodo
		nuevonodo->der = NULL; //establece como null el apuntador derecho del nodo
		arbol = nuevonodo; //luego arbol almacena la direccion del nodo ingresado
	}
	else if(x < arbol->nro) //evalua si el dato ingresado es menor al nodo  anteriormente ingresado
	{
		//si lo es envia el apuntador irzquierdo del nodo evaluado atraves de la misma funcion insertar utilizando recursividad
		insertar(arbol->izq,x);
	}
	else if(x>arbol->nro) //evalua si el dato ingresado es mayor al nodo  anteriormente ingresado
	{
		//si lo es envia el apuntador derecho del nodo evaluado atraves de la misma funcion insertar utilizando recursividad
		insertar(arbol->der,x);
	}
}

void verarbol(ABB arbol, int n) //funcion que permite ver los datos del arbol
{
	if(arbol == NULL) //si nodo es null la funcion se terminara 
	{ 
		return;
	}

	verarbol(arbol->der,n+1); //envia el apuntador derecho del nodo evaluado a la misma funcion por medio de la recursividad
	
	for(int i=0; i<n; i++ ) //ciclo imprime espacio entre los datos de los nodos
	{
		cout << "       "; 
	}
	
	cout << arbol->nro << endl; //imprime el valor del nodo evaluado en la funcion

	verarbol(arbol->izq, n+1); //envia el apuntador izquierdo del nodo evaluado a la misma funcion por medio de la recursividad
}

void preorden(ABB arbol) //funcion que imprime los datos del arbol en preorden
{
	if(arbol!=NULL) //si arbor si arbol es diferente de null es decir si posee elementos
	{
		cout << arbol->nro << " "; //imprime el valor del nodo evaludao en la funcion
		preorden(arbol->izq); //envia el apuntador izquierdo del nodo evaluado a la misma funcion por medio de la recursividad
		preorden(arbol->der); //envia el apuntador derecho del nodo evaluado a la misma funcion por medio de la recursividad
	}
}

void postorden(ABB arbol) //funcion que imprime los datos del arbol en postorden
{
	if(arbol!=NULL) //si arbor si arbol es diferente de null es decir si posee elementos
	{
		preorden(arbol->izq); //envia el apuntador izquierdo del nodo evaluado a la misma funcion por medio de la recursividad
		preorden(arbol->der); //envia el apuntador derecho del nodo evaluado a la misma funcion por medio de la recursividad
		cout << arbol->nro << " "; //imprime el valor del nodo evaludao en la funcion
	}
}


void inorden(ABB arbol) //funcion que imprime los datos del arbol en inorden
{
	if(arbol!=NULL) //si arbor si arbol es diferente de null es decir si posee elementos
	{
		preorden(arbol->izq); //envia el apuntador izquierdo del nodo evaluado a la misma funcion por medio de la recursividad
		cout << arbol->nro << " "; //imprime el valor del nodo evaludao en la funcion
		preorden(arbol->der); //envia el apuntador derecho del nodo evaluado a la misma funcion por medio de la recursividad
	}
}

int contarhojas(ABB arbol) //funcion que imprime el numeros de hojas del arbol
{
	if(arbol==NULL) //si nodo es null la funcion se terminara 
	{
		return 0;
	}
	//si el apuntador derecho y izquierdo del nodo evaluado la funcion devolvera 1
	else if((arbol->der == NULL) && (arbol->izq == NULL)) 
	{
		return 1;
	}
	
	else  //si ninguna de las condiciones anteriores se cumple entonces se ejecutara este bloque
	{
		/*La funcion enviara enviara a la fucnion contarhoas el apuntador izquierdo y derecho del nodo evaluado y los sumara hasta que los 
		apuntadores de estos sean null luego devolvera el valor obtennido  */
		return contarhojas(arbol->izq) + contarhojas(arbol->der);
	}
}

ABB unirABB(ABB izq, ABB der) //funcion que une el apuntador izquierdo y derecho de un nodo
{
	if(izq==NULL) //si el apuntador izquierdo es null entonces devolvera el apuntador derecho
	{
		return der;
	}
	if(der==NULL) //si el apuntador derecho es null entonces devolvera el apuntador izquierdo
	{
		return izq;
	}
	/*la variable centro de tipo ABB alamacera la funcion unirABBque enviara el apuntador izquierdo y derecho del nodo evaluado nuevamente 
	a la funcion unirABB para evaluarlas por medio de la recursividad */
	ABB centro = unirABB(izq->der, der->izq);
	//el apuntador derecho del nodo izquierdo almacenara la direccion de la variale centro
	izq->der = centro;
	//el apuntador izquierdo del nodo derecho almacenara la direccion de la variale centro
	der->izq = izq;
	
	return der; //la funcion devolvera el nodo derecho
}

void eliminar(ABB &arbol, int x) //funcion que elimina un nodo del arbol
{
	
	if(arbol==NULL) //si nodo es null la funcion se terminara 
	{
		return;
	}
	else if(x < arbol->nro) //si el valor ingresado es mayor al valor del nodo entonces se enviara a 						la funcion eliminar el apuntador izquierdo del nodo evaluado
	{
		eliminar(arbol->izq, x);
	}
	else if(x > arbol->nro) //si el valor ingresado es mayor al valor del nodo entonces se enviara a 						la funcion eliminar el apuntador derecho del nodo evaluado
	{
		eliminar(arbol->der, x);
	}
	else //si ninguna de las condiciones anteriores se cumple entonces se ejecutara este bloque
	{
		//la variable a p de tipo ABB almacenara la direccion del nodo ingresado
		ABB p = arbol;
		
		/*el nodo evaluado almacenara la funcion unirABB que envia el apuntador izquierdo y derecho del nodo evaluado para ser evaluados en la funcion 
		unirABB para eliminar todos los nods hijos del nodo evaluado */
		arbol = unirABB(arbol->izq, arbol->der);
		
		delete p; //luego se liberara la memoria eliminando el nodo evaluado
	}
}

void ErrorDato() //funcion para evitar errores de entradas
{

    //condicion que verifica si hubo un ingreso de dato erroneo
    if(cin.fail())
    {
        cout << "\n\n\t\t\t\t\tSe ha introducido un dato erroneo vuelva a ingrearlo\n\n" << endl;

        system("pause");
    }

    while(cin.fail()) //ciclo que evita el error de entradas
    {
        cin.clear(); //limpia el buffer

        cin.ignore(1000, '\n'); //ignora los primeros 1000 elements ingresados

    }
}

