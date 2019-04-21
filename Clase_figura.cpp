
//Hecho por Carlos Alfonso Lemus Rodezno 

/* Programa para calcular el area y perimetro de las figuras geometricas de: rectangulo y triangulo y cuadrado
utilizando el encapsulamiento, herencia y composicion */

#include<iostream> //libreria estandar necesaria para todo programa en c++
#include <math.h> /* libreria que nos permite utilizar sus funciones y elementos orientados a operaciones
					matematicas */
#include <windows.h> //libreria necesaria para usar sus funciones
#include <conio.h> //libreria necesaria para usar sus funciones
#include <iomanip> //libreria necesaria para usar sus funciones sobre todo la de precision de decimales
					
using namespace std; //espacion de nombre a usar el std, nos permite abrebiar el codigo

//clase figura contiene metodos que heredaran las clases derivadas de estas
class Figura
{	
	private:

		float base;
		float altura;
	
	public:
		//Pueden haber varios constructores gracias al polimorfismo
		Figura()
		{ //inicializa todas las variables en 0
			this->base = 0;
			this->altura = 0;
		}
		
		Figura(float b, float h){ //inicializa las variables en un valor espeficico
			this->base = b;
			this->altura = h;
		}
		
		//No se puede tener dos constructores que reciban la misma cantidad de argumentos y el mismo tipo de dato (de los argumentos que pide)
		~Figura(){
			
		}
		
		//se necesita crear un set y get para cada propiedad/atributo, ademas de las funciones area y perimetro
		void setBase(float b)
		{
			this->base = b;
		}
		float getBase()
		{
			return this->base;
		}
		
		void setAltura(float h)
		{
			this->altura = h;
		}
		float getAltura(){
			return this->altura;
		}

		void ErrorDato() //metodo para evitar el ingreso de datos incorrectos
		{
			//en caso de un error al ingresar un dato se mostrara un mensaje
			if(cin.fail())
			{
				cout << "\n\n\t\tHas ingresado un dato erroneo vuelve a ingresarlo\n\n";

				system("pause");
			}

			//ciclo para evitar el ingreso de datos en el programa
			while(cin.fail())
			{
				cin.clear(); //limpia el buffer

				cin.ignore(1000, '\n'); //ignora los primeros 1000 caracteres ingresados
			}
		}

		//virtual significa que luego se puede sobreescribir/redefinir sobre la funcion.
		
		//se iguala a 0 para definir la funcion
		virtual float area() = 0; 
		virtual float perimetro() = 0;
			
};

class Color //color que se le da a la de la figura
{
	public:

		void ColorT() //metodo que imprime texto en la consola
		{
			cout << "\n\n\n\t\t\t\t\t===============================\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t|       ELIJE UN COLOR        |\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t===============================\n\n\n";
			
			cout << "\t\t\t\t\t\t1.Rojo" << endl;
			cout << "\t\t\t\t\t\t2.Azul" << endl;
			cout << "\t\t\t\t\t\t3.Verde" << endl;
		}

		void colorear(int OpcColor) 
		{		
				switch(OpcColor)
				{
					case 1:
						//funcion que le da color y fondo a una linea de texto
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);	
						
						break;
					
					case 2:
						//funcion que le da color y fondo a una linea de texto
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE);	
						
						break;

					case 3:
						//funcion que le da color y fondo a una linea de texto
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | BACKGROUND_GREEN);	

						break;

					
				}		
		}
};

//clase rectangulo que hereda de las clases figura y color
class Rectangulo: public Figura, public Color
{
	public:
		//metodo virtual area que le pertenece a la clase figura pero que la clase rectangulo redefine debido al polimorfismo
		float area() 
		{
			return getAltura()*getBase();
		}
		
		//metodo virtual perimetro que le pertenece a la clase figura pero que la clase rectangulo redefine debido al polimorfismo
		float perimetro()
		{
			return ((2*getAltura())+(2*getBase()));
		}
		
		void imprimirR(){ //imprimira el rectangulo
			cout << endl;
			for(int i = 0; i < getAltura(); i++)
			{
				cout << "\t\t\t\t\t\t";
				
				for(int j = 0; j < getBase(); j++)
				{
						if(i == 0 or j == 0 or j == getAltura()+1 or i == getAltura()-1)
						{
							cout << " * ";	
						}
						else
						{
							cout << "   ";
						}
							
				}
				cout << endl;
			}
			cout << endl;
		}

		void TextoR() //metodo que imprime texto
		{
			cout << "\n\n\t\t\t\t\t****************************\n";
			cout << "\t\t\t\t\t+                          +\n";
			cout << "\t\t\t\t\t+       RECTANGULO         +\n";
			cout << "\t\t\t\t\t+                          +\n";
			cout << "\t\t\t\t\t****************************\n\n";	
		}
		
};

//clase cuadrado que hereda de las clases figura y color
class Cuadro : public Figura, public Color
{
	public:
		//metodo virtual area que le pertenece a la clase figura pero que la clase cuadrado redefine debido al polimorfismo
		float area()
		{
			return getAltura()*getBase();
		}
		//metodo virtual perimetro que le pertenece a la clase figura pero que la clase cuadrado redefine debido al polimorfismo
		float perimetro()
		{
			return ((2*getAltura())+(2*getBase()));
		}
		
		void imprimirC()
		{ //imprimira el cuadrado
			cout << endl;
			for(int i = 0; i < getAltura(); i++)
			{
				cout << "\t\t\t\t\t\t";

				for(int j = 0; j < getBase(); j++)
				{
						if(i == 0 or j == 0 or j == getAltura()-1 or i == getAltura()-1)
						{

							cout << "* ";	
							
						}
						else{
							cout << "  ";
						}
							
				}
				cout << endl;
			}
			cout << endl;
		}

		void TextoC() //metodo que imprime texto
		{
			cout << "\n\n\t\t\t\t\t****************************\n";
			cout << "\t\t\t\t\t+                          +\n";
			cout << "\t\t\t\t\t+         CUADRADO         +\n";
			cout << "\t\t\t\t\t+                          +\n";
			cout << "\t\t\t\t\t****************************\n\n";	
		}
		
};

//clase triangulo que hereda de las clases figura y color
class Triangulo : public Figura, public Color
{
	private:
		float lado1;
		float lado2;
	public:
		//metodo get y set para todos los lados 1 y 2
		void setLado1(float l)
		{
			this->lado1 = l;
		}
		float getLado1()
		{
			return this->lado1;
		}
		
		void setLado2(float l)
		{
			this->lado2 = l;
		}
		float getLado2()
		{
			return this->lado2;
		}
		
		//metodo virtual area que le pertenece a la clase figura pero que la clase triangulo redefine debido al polimorfismo
		float area()
		{
			float semi = (getBase() + getLado1() + getLado2())/2;
			float area = sqrt(semi*(semi-lado1)*(semi-lado2)*(semi-getBase()));
			return area;
		}
		
		//metodo virtual triangulo que le pertenece a la clase figura pero que la clase triangulo redefine debido al polimorfismo
		float perimetro()
		{
			return (getLado1()+getBase()+getLado2());
		}
		
		void imprimirT()
		{ //imprimira el triangulo
			cout << endl;
			
			for(int i = 0; i < getBase(); i++)
			{
				cout << "\t\t\t\t\t\t";

				for(int j = 0; j < getBase() - i; j++)
				{
					cout << " ";
									
				}

				for(int j = 0; j < 2*i-1 ; j++)
				{
					cout << "*";	
				}

				cout << endl;
			}

			cout << endl;
		}
		
		void TextoT() //metodo que imprime texto
		{
			cout << "\n\n\t\t\t\t\t****************************\n";
			cout << "\t\t\t\t\t+                          +\n";
			cout << "\t\t\t\t\t+         Triangulo        +\n";
			cout << "\t\t\t\t\t+                          +\n";
			cout << "\t\t\t\t\t****************************\n\n";	
		}
		
};


//clase principal utilizada para instanciar todos los objetos a ocupar en el programa
class Principal 
{
	private:
		int opcion;
		int OpcCol; //variable que solo sera utilizada para seleccionar el color de la figura
		float base;
		float lado1;
		float lado2;
		//se instancia
		Rectangulo *r = new Rectangulo();
		Cuadro *c = new Cuadro();
		Triangulo *t = new Triangulo();

	public:

		Principal()
		{
			do { //ciclo que permite la ejecucion del programa mientras no se elija la opcion de salir 

				system("color 5E"); //funcion que le da color al texto y fondo de la consola

				do { // utilizado para evitar el ingreso de datos erroneos

					system("cls"); //funcion que limpia la pantalla de la consola de los texto

					cout << "\n\n\n\t\t\t\t\t===============================\n";
					cout << "\t\t\t\t\t|                             |\n";
					cout << "\t\t\t\t\t|     Figuras Geometricas     |\n";
					cout << "\t\t\t\t\t|                             |\n";
					cout << "\t\t\t\t\t===============================\n\n\n";

					cout << "\t\t\t\t1.Rectangulo" << endl;
					cout << "\t\t\t\t2.Cuadrado" << endl;
					cout << "\t\t\t\t3.Triangulo" << endl;
					cout << "\t\t\t\t4.Salir" << endl;

					cout << "\n\t\t\t\tEscoja una opcion: ";
					cin >> opcion;
					r->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneos

				} while (opcion < 1 or opcion > 4 or opcion == cin.fail());
				
				switch(opcion)
				{
					case 1:

						do { //ciclo que evita el ingreso de un dato erroneo
							
							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							r->TextoR(); //metodo que imprime texto

							cout << "\n\n\t\t\tIngresa la Base: ";
							cin >> base;
							r->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneo

						} while(base == cin.fail());
						
						r->setBase(base);

						do { //ciclo que evita el ingreso de un dato erroneo

							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							r->TextoR(); //metodo que imprime texto

							cout << "\n\n\t\t\tIngresa la ALtura: ";
							cin >> lado1;
							r->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneo1

						} while (lado1 == cin.fail());
						
						r->setAltura(lado1);
						
						do { // utilizado para evitar el ingreso de datos erroneos

							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							r->ColorT(); //metodo que imprime texto y proviene de la clase color

							cout << "\n\t\t\t\tEscoja una opcion: ";
							cin >> OpcCol;
							r->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneos

						} while (OpcCol < 1 or  OpcCol > 3 or  OpcCol == cin.fail());

						system("cls"); //funcion que limpia la pantalla de la consola de los texto

						r->TextoR(); //metodo que imprime texto

						//se imprime el resultado	
						cout << "\n\n\t\t\t\tBase: " << fixed << setprecision(2) << r->getBase();
						cout  << "\t\t\tAltura: " << fixed << setprecision(2) << r->getAltura() << endl;
						cout << "\n\n\t\t\t\tArea: " << fixed << setprecision(2)  << r->area();
						cout << "\t\t\tPerimetro: " << fixed << setprecision(2) << r->perimetro() << endl; 

						r->colorear(OpcCol);//Proviene desde colorear y le da color a la figura
						
						r->imprimirR(); //se imprime la figura del rectangulo
						
						getch();

						break;
					
					case 2:

						do { //ciclo que evita el ingreso de un dato erroneo

							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							c->TextoC(); //metodo que imprime texto

							cout << "\n\n\t\t\tIngresa la Base: ";
							cin >> base;
							c->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneo

						} while(base == cin.fail());
						
						c->setBase(base);

						do { //ciclo que evita el ingreso de un dato erroneo

							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							c->TextoC(); //metodo que imprime texto

							cout << "\n\n\t\t\tIngresa la ALtura: ";
							cin >> lado1;
							c->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneo

						} while (lado1 == cin.fail());
						
						c->setAltura(lado1);

						do { // utilizado para evitar el ingreso de datos erroneos

							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							c->ColorT(); //metodo que imprime texto y proviene de la clase color

							cout << "\n\t\t\t\tEscoja una opcion: ";
							cin >>  OpcCol;
							c->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneos

						} while (OpcCol < 1 or  OpcCol > 3 or  OpcCol == cin.fail());

						system("cls"); //funcion que limpia la pantalla de la consola de los texto

						c->TextoC(); //metodo que imprime texto

						//se imprime el resultado	
						cout << "\n\n\t\t\t\tBase: " << fixed << setprecision(2) << c->getBase();
						cout  << "\t\t\tAltura: " << fixed << setprecision(2) << c->getAltura() << endl;
						cout << "\n\n\t\t\t\tArea: " << fixed << setprecision(2)  << c->area();
						cout << "\t\t\tPerimetro: " << fixed << setprecision(2) << c->perimetro() << endl; 

						c->colorear(OpcCol);//Proviene desde colorear y le da color a la figura
						
						c->imprimirC(); //se imprime la figura del rectangulo

						getch();

						break;
					
					case 3:
					
						do { //ciclo que evita el ingreso de un dato erroneo

							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							t->TextoT(); //metodo que imprime texto

							cout << "\n\n\t\t\tIngresa la Base: ";
							cin >> base;
							t->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneo

						} while(base == cin.fail());
						
						t->setBase(base);

						do { //ciclo que evita el ingreso de un dato erroneo

							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							t->TextoT(); //metodo que imprime texto

							cout << "\n\n\t\t\tIngresa el lado 1: ";
							cin >> lado1;
							t->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneo

						} while (lado1 == cin.fail());
						
						t->setLado1(lado1);

						do { //ciclo que evita el ingreso de un dato erroneo

							system("cls"); //funcion que limpia la pantalla de la consola de los texto

							t->TextoT(); //metodo que imprime texto

							cout << "\n\n\t\t\tIngresa el lado 2: ";
							cin >> lado2;
							t->ErrorDato(); //metodo utilizado para evitar el ingreso de datos erroneo

						} while (lado2 == cin.fail());
						
						t->setLado2(lado2);

						system("cls"); //funcion que limpia la pantalla de la consola de los texto

						t->TextoT(); //metodo que imprime texto
						
						cout << "\n\n\t\t\t\tBase: " << fixed << setprecision(2) << t->getBase();
						cout  << "\t\tLado 1: " << fixed << setprecision(2) << t->getLado1();
						cout  << "\t\tLado 2: " << fixed << setprecision(2) << t->getLado2() << endl;
						cout << "\n\n\t\t\t\tArea: " << fixed << setprecision(2)  << t->area();
						cout << "\t\t\tPerimetro: " << fixed << setprecision(2) << t->perimetro() << endl; 

						t->imprimirT(); //se imprime la figura del triangulo

						getch();

						break;
					
					case 4:

						system("cls"); //funcion que limpia la pantalla de la consola de los texto

						cout << "\n\n\t\t\t\tEsta saliendo del programa\n\n";

						break;

				}
		
			} while(opcion == 1 or opcion == 2 or opcion == 3);

		} 
};

int main()
{
	Principal *pro = new Principal(); //Es una relacion de dependencia
	
	cout << "\n\n\t\t\t\tPresione cualquier tecla para continuar...";
	cin.get();
	return 0;
}
