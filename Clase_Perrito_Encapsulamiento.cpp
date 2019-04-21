//Hecho por Carlos Alfonso Lemus Rodezno

//Programa que se basa en una clase perrito en la cual se pone en practica el encapsulamiento

#include <iostream> //libreria estandar necesaria para usar sus elemntos y funciones esenciales para todo programa en c++
#include <string.h> //libreria para el manejo de cadenas de caracteres
#include <windows.h> //libreria necesaria para usar sus elementos y funciones
#include <locale.h> //libreria que permite usar caracteres del idioma español

using namespace std; //espacio de nombre a usar el standar o std que permite abreviar el codigo

class Perrito
{
	//atributos
	private:
		string nombre;
		string raza;
		string tamanio;
		float peso;
		float altura;
	//metodos
	public:
		Perrito();//constructor
		~Perrito();//destructor
		void comer();
		void ladrar();
		void setNombre(string nom);
		string getNombre();
		void setRaza(string r);
		string getRaza();
		void setTamanio(string t);
		string getTamanio();
		void setPeso(float x);
		float getPeso();
		void setAltura(float a);
		float getAltura();
		void ErrorDato(); //metodo para evitar un error de dato
};

Perrito::Perrito() //constructor
{

}

Perrito::~Perrito() //destructor
{

}

void Perrito::comer()
{
	cout << "\n\n\t\t\t\tEl perrito come Croquetas" << endl;;
}
void Perrito::ladrar()
{
	cout << "\n\n\t\t\t\tEl perrito ladra Gua, Gua, Gua" << endl;
}

void Perrito::setNombre(string nom) //metodo set para ingresar el nombre
{
	nombre = nom;
}

string Perrito::getNombre() //metodo que retorna el atributo nombre de la clase perrtio
{
	return nombre;
}

void Perrito::setRaza(string r) //metodo set para ingresar la raza
{
	raza = r;
}

string Perrito::getRaza() //metodo que retorna el atributo raza de la clase perrtio
{
	return raza;
}

void Perrito::setTamanio(string t) //metodo set para ingresar el tamanio
{
	tamanio = t;
}

string Perrito::getTamanio() //metodo que retorna el atributo tmanaio de la clase perrtio
{
	return tamanio;
}

void Perrito::setPeso(float x) //metodo set para ingresar el peso
{
	peso = x;
}

float Perrito::getPeso() //metodo que retorna el atributo peso de la clase perrtio
{
	return peso;
}

void Perrito::setAltura(float a) //metodo set para ingresar la altura
{
	altura = a;
}

float Perrito::getAltura() //metodo que retorna el atributo altura de la clase perrtio

{
	return altura;
}

void Perrito::ErrorDato() //funcion que impide el ingreso de datos incorrestos
{
	if(cin.fail())
	{
		cout << "\n\n\t\t\tHas ingresado un dato errorneo vuelve a ingresarlos" << endl;
	}

	while(cin.fail()) //funcion que se realizara si hay un error de entrada
	{
		cin.clear(); //funcion que limpia el buffer

		cin.ignore(1000, '\n'); //funcion que ignora los primeros 1000 caracteres
	}

}


int main(){
	
	//Declaracion de varaibles
	string nombre;
	string raza;
	string tamanio;
	float peso;
	float altura;

	Perrito *perro = new Perrito(); //se reserva espacion en la memoria y se segmenta

	system("color 4F"); //funcion que le da color al fondo y letra de la pantalla

	setlocale(LC_CTYPE, "Spanish"); //funcion que permite el uso de caracteres del lenguaje español tal como la Ñ entre otros


	do { //ciclo para evitar el ingreso de datos errroneos

		system("cls");	//funcion que limpia el texto de la consola

		cout << "\n\n\n\t\t\t\tMenu\n" << endl;

		
		cout << "\t\t\t\tIngresa el nombre del perrito: ";
		fflush(stdin); //funcion que limpia el buffer
		cin >> nombre;
		perro->ErrorDato(); //metodo para evitar el ingreso de datos errroneos

		cout << "\t\t\t\tIngresa la raza del perrito: ";
		fflush(stdin); //funcion que limpia el buffer
		cin >> raza;
		perro->ErrorDato(); //metodo para evitar el ingreso de datos errroneos

		cout << "\t\t\t\tIngresa el tamaño del perrito: ";
		fflush(stdin); //funcion que limpia el buffer
		cin >> tamanio;
		perro->ErrorDato(); //metodo para evitar el ingreso de datos errroneos
		
		cout << "\t\t\t\tIngresa el peso del perrito: ";
		fflush(stdin); //funcion que limpia el buffer
		cin >> peso;
		perro->ErrorDato(); //metodo para evitar el ingreso de datos errroneos

		cout << "\t\t\t\tIngresa la altura del perrito: ";
		fflush(stdin); //funcion que limpia el buffer
		cin >> altura;
		perro->ErrorDato(); //metodo para evitar el ingreso de datos errroneos

		system("pause");

	} while(peso == cin.fail() || altura == cin.fail());

	//Ingreso de los datos atravez de los metodos set de cada atributo
	perro->setNombre(nombre);
	perro->setRaza(raza);
	perro->setTamanio(tamanio);
	perro->setPeso(peso);
	perro->setAltura(altura);

	system("cls");	//funcion que limpia el texto de la consola

	//se imprimen los atributos del objeto con los metodos get de cada atributo
	cout << "\n\n\n\t\t\t\tDatos del perrito \t\t\n\n";
	
	cout << "\t\t\t\tNombre: "<< perro->getNombre() << "\n\n";
	cout << "\t\t\t\tRaza: "<< perro->getRaza() << "\n\n";
	cout << "\t\t\t\tTamaño: "<< perro->getTamanio() << "\n\n";
	cout << "\t\t\t\tPeso: "<< perro->getPeso() << "\n\n";
	cout << "\t\t\t\tAltura: "<< perro->getAltura() << "\n\n";
	
	perro->comer();
	perro->ladrar();

	system("pause");
	return 0;	
}


