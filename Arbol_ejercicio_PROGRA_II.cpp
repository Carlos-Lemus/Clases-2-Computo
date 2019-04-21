//Hecho por Carlos Alfonso Lemus Rodezno

/* Programa de arbol que utiliza el herencia, encapsulamiento, relaciones de clases como la de herencia, dependencia y agregacion
para crear objetos de la clase arbo*/

#include <iostream> //libreria estandar necesaria para todo programa en consola de c++
#include <windows.h> //libreria necesaria para utilizar sus funciones 
#include <string.h> //libreria que nos permite manejar y manipular cadenas de texto
#include <iomanip> //libreria necesaria para usar sus funciones sobre todo la de precision de decimales

using namespace std;

void ErrorDato(); //declaracion de funcion que evita el ingreso de datos erroneos
void Texto(int opcion); //Declaracion de funcion que imprime texto

void ErrorDato() //metodo para evitar el ingreso de datos incorrectos
{
		//en caso de un error al ingresar un dato se mostrara un mensaje
		if(cin.fail())	
		{
			cout << "\n\n\t\t\tHas ingresado un dato erroneo vuelve a ingresarlo\n\n";

			system("pause");
		}

		//ciclo para evitar el ingreso de datos en el programa
		while(cin.fail())
		{
			cin.clear(); //limpia el buffer

			cin.ignore(1000, '\n'); //ignora los primeros 1000 caracteres ingresados
		}
}

void Texto(int opcion) //metodo que imprime texto
{

	switch(opcion)
	{
		case 1:

			cout << "\n\n\n\t\t\t\t\t*******************************\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t|           ARBOLES           |\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t*******************************\n\n\n";

			cout << "\t\t\t\t\t1.Arbol Frutal" << endl;
			cout << "\t\t\t\t\t2.Arbol Ornamental" << endl;
			cout << "\t\t\t\t\t3.Arbol de Tamarindo" << endl;
			cout << "\t\t\t\t\t4.Salir" << endl;

			break; 

		case 2:

			cout << "\n\n\n\t\t\t\t\t*******************************\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t|         ARBOL FRUTAL        |\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t*******************************\n\n\n";

			break; 

		case 3:

			cout << "\n\n\n\t\t\t\t\t*******************************\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t|       ARBOL ORNAMENTAL      |\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t*******************************\n\n\n";

			break;

		case 4:

			cout << "\n\n\n\t\t\t\t\t*******************************\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t|      ARBOL DE TAMARINDO     |\n";
			cout << "\t\t\t\t\t|                             |\n";
			cout << "\t\t\t\t\t*******************************\n\n\n";

			break;
	}
}

class Tallo //clase tallo contiene los metodos que usara la clase arbol
{
	private:
		float longTallo;
	public:

		//cada atributo de la clase posee un metodo set para ingresar su valor y tambien un metodo get para retornar su valor 
	
		void setlongT(float longtallo)
		{
			this->longTallo = longtallo;
		}
		float getlongT()
		{
			return this->longTallo;	
		}	
};

class Hoja //clase hoja contiene los metodos que usara la clase arbol
{
	private:
		float longHoja;
		string forma;
	public:

		//cada atributo de la clase posee un metodo set para ingresar su valor y tambien un metodo get para retornar su valor

		void setlongH(float longH)
		{
			this->longHoja = longH;
		}
		float getlongH()
		{
			return this->longHoja;	
		}
			
		void setf(string form)
		{
			this->forma = form;
		}
		string getforma()
		{
			return this->forma;
		}
};

/* clase arbol que usa todos loes elementos de acceso publico de la clase tallo y de la
 clase hoja, utilizando lo que se conoce como relaciones de dependencia y  agregacion
 entre clases */ 
class Arbol
{
	private:
		string nombre;
		string NomCien;
		string familia;
		
				
	public:

		Hoja hoja; //agregacion
		Tallo *tallo; //depedencia
	
		Arbol()
		{
			tallo = new Tallo(); //depedencia
		}
		~Arbol()
		{
		 	delete tallo;
		}

		//cada atributo de la clase posee un metodo set para ingresar su valor y tambien un metodo get para retornar su valor 
		
		void setTallo(float lt)
		{
			tallo->setlongT(lt);
		}

		void setHoja(float l, string f)
		{
			hoja.setlongH(l);
			hoja.setf(f);
		}
		
		void setnom(string nom)
		{
			this->nombre = nom;
		}
		string getnom()
		{
			return this->nombre;
		}
		
		void setnomcien(string NC)
		{
			this->NomCien = NC;
		}
		string getnomcien()
		{
			return this->NomCien;
		}
		
		void setfamilia(string fam)
		{
			this->familia = fam;
		}	
		string getfamilia()
		{
			return this->familia;
		}
		
};

class Arbolfrutal : public Arbol
{
	private:
		int PromFrutas;

	public:
		//cada atributo de la clase posee un metodo set para ingresar su valor y tambien un metodo get para retornar su valor 
		void setPfruta(int PF)
		{
			this->PromFrutas = PF;
		}
		int getPfruta()
		{
			return this->PromFrutas;
		}
	
};

//clase Tamarindo que hereda de la clase Arborfrutal
class Tamarindo : public Arbolfrutal
{
private:
		string region;
		
	public:
		//cada atributo de la clase posee un metodo set para ingresar su valor y tambien un metodo get para retornar su valor 
		void setRegion(string r)
		{
			this->region = r;
		}
		string getRegion()
		{
			return this->region;
		}	
};

//clase Arbolornamental que hereda de la clase arbol
class Arbolornamental : public Arbol
{
	//cada atributo de la clase posee un metodo set para ingresar su valor y tambien un metodo get para retornar su valor 
	private:
		string especie;
	public:
			
			void setEspecie(string e)
			{
				this->especie = e;
			}	
			string getEspecie()
			{
				return this->especie;
			}
};

/* clase que se encarga de instanciar, esta clase sera la encargada de fabricar los objetos
y contendra todo el programa */
class Factory 
{
	private:
		int opcion;

		float longTallo;
		float longHoja;
		string forma;
		string nombre;
		string NomCien;
		string familia;
		int PromFrutas;
		string especie;
		string region;

		Arbolfrutal *af;
		Arbolornamental *ao;
		Tamarindo *at;

	public:

		void crearArbol()
		{

			do { //ciclo que permite la ejecucion del programa mientras no se elija la opcion de salir 

				system("color 2F"); //funcion que le da color al texto y fondo de la consola

				do { // utilizado para evitar el ingreso de datos erroneos

					system("cls"); //funcion que limpia la pantalla de la consola de los 
					
						Texto(1); //funcion que imprime texto

						cout << "\n\t\t\t\t\tEscoja una opcion: ";
						fflush(stdin); //funcion que limpia el buffer
						cin >> opcion;
						ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneos

						} while (opcion < 1 or opcion > 4 or opcion == cin.fail());
						

						switch(opcion)
						{
							case 1:

								af = new Arbolfrutal(); //Reserva espacio en la memoria para el objeto de tipo arbolfrutal

								do { //ciclo que evita el ingreso de un dato erroneo
									
									system("cls"); //funcion que limpia la pantalla de la consola de los texto

									Texto(2); //funcion que imprime texto

									cout << "\n\n\t\t\tIngresa la longitud del tallo: ";
									fflush(stdin); //funcion que limpia el buffer
									cin >> longTallo;
									ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneo

								} while(longTallo == cin.fail());

								do { //ciclo que evita el ingreso de un dato erroneo
									
									system("cls"); //funcion que limpia la pantalla de la consola de los texto

									Texto(2); //funcion que imprime texto

									cout << "\n\n\t\t\tIngresa la longitud de la hoja: ";
									fflush(stdin); //funcion que limpia el buffer
									cin >> longHoja;
									ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneo

								} while(longHoja == cin.fail());

								/* No se realiza un ciclo do-while para evitar el ingreso de dato erroneos a las variables string
								debido a que las variables de tipo string aceptan todos los caracteres*/

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(2); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa la forma: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> forma;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(2); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa el nombre del arbol: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> nombre;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(2); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa el nombre cientifico: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> NomCien;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(2); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa la familia a la que pertence el arbol: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> familia;

								do { //ciclo que evita el ingreso de un dato erroneo
									
									system("cls"); //funcion que limpia la pantalla de la consola de los texto

									Texto(2); //funcion que imprime texto

									cout << "\n\n\t\t\tIngresa el promedio de arboles frutales: ";
									fflush(stdin); //funcion que limpia el buffer
									cin >> PromFrutas;
									ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneo

								} while(PromFrutas == cin.fail());		

								//Se ingresan los datos al objeto atraves de los metodos set del objeto
								af->setTallo(longTallo);
								af->setHoja(longHoja, forma);
								af->setnom(nombre);
								af->setnomcien(NomCien);
								af->setfamilia(familia);
								af->setPfruta(PromFrutas);

								//se imprimen los resultados por medio de los metodos get del objeto
								
								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(2); //funcion que imprime texto

								cout << "\n\n\t\t\t\tLongitud del tallo: " << fixed << setprecision(2) << af->tallo->getlongT() << endl;
								cout  << "\t\t\t\tLongitud de la hoja: " << fixed << setprecision(2) << af->hoja.getlongH() << endl;
								cout << "\t\t\t\tForma de la hoja: "<< af->hoja.getforma()  << endl;
								cout << "\t\t\t\tNombre: "<< af->getnom() << endl; 
								cout << "\t\t\t\tNombre Cientifico: " << af->getnomcien() << endl; 
								cout << "\t\t\t\tFamilia: " << af->getfamilia()<< endl;
								cout << "\t\t\t\tPromedio de arboles frutales: " << af->getPfruta()<< "\n\n";

								delete af; //Se libera espacio de la memoria
								system("pause");

								break;
							
							case 2:

								//Reserva espacio en la memoria para el objeto de tipo arborornamental
								ao = new Arbolornamental(); 
								
								do { //ciclo que evita el ingreso de un dato erroneo
									
									system("cls"); //funcion que limpia la pantalla de la consola de los texto

									Texto(3); //funcion que imprime texto

									cout << "\n\n\t\t\tIngresa la longitud del tallo: ";
									fflush(stdin); //funcion que limpia el buffer
									cin >> longTallo;
									ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneo

								} while(longTallo == cin.fail());

								do { //ciclo que evita el ingreso de un dato erroneo
									
									system("cls"); //funcion que limpia la pantalla de la consola de los texto

									Texto(3); //funcion que imprime texto

									cout << "\n\n\t\t\tIngresa la longitud de la hoja: ";
									fflush(stdin); //funcion que limpia el buffer
									cin >> longHoja;
									ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneo

								} while(longHoja == cin.fail());

								/* No se realiza un ciclo do-while para evitar el ingreso de dato erroneos a las variables string
								debido a que las variables de tipo string aceptan todos los caracteres*/

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(3); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa la forma: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> forma;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(3); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa el nombre del arbol: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> nombre;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(3); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa el nombre cientifico: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> NomCien;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(3); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa la familia a la que pertence el arbol: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> familia;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(3); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa la especie del arbol ornamental: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> especie;	

								//Se ingresan los datos al objeto atraves de los metodos set del objeto
								ao->setTallo(longTallo);
								ao->setHoja(longHoja, forma);
								ao->setnom(nombre);
								ao->setnomcien(NomCien);
								ao->setfamilia(familia);
								ao->setEspecie(especie);						

								//se imprimen los resultados por medio de los metodos get del objeto
								
								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(3); //funcion que imprime texto

								cout << "\n\n\t\t\t\tLongitud del tallo: " << fixed << setprecision(2) << ao->tallo->getlongT() << endl;
								cout  << "\t\t\t\tLongitud de la hoja: " << fixed << setprecision(2) << ao->hoja.getlongH() << endl;
								cout << "\t\t\t\tForma de la hoja: "<< ao->hoja.getforma() << endl;
								cout << "\t\t\t\tNombre: "<< ao->getnom() << endl; 
								cout << "\t\t\t\tNombre Cientifico: " << ao->getnomcien() << endl; 
								cout << "\t\t\t\tFamilia: " << ao->getfamilia()<< endl;
								cout << "\t\t\t\tEspecie del arbol ornamental: " << ao->getEspecie() << endl; 

								delete ao; //Se libera espacio de la memoria

								system("pause");
								break;
							
							case 3:

								at = new Tamarindo(); //Reserva espacio en la memoria para el objeto de tipo tamarindo

								do { //ciclo que evita el ingreso de un dato erroneo
									
									system("cls"); //funcion que limpia la pantalla de la consola de los texto

									Texto(4); //funcion que imprime texto

									cout << "\n\n\t\t\tIngresa la longitud del tallo: ";
									fflush(stdin); //funcion que limpia el buffer
									cin >> longTallo;
									ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneo

								} while(longTallo == cin.fail());

								do { //ciclo que evita el ingreso de un dato erroneo
									
									system("cls"); //funcion que limpia la pantalla de la consola de los texto

									Texto(4); //funcion que imprime texto

									cout << "\n\n\t\t\tIngresa la longitud de la hoja: ";
									fflush(stdin); //funcion que limpia el buffer
									cin >> longHoja;
									ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneo

								} while(longHoja == cin.fail());

								/* No se realiza un ciclo do-while para evitar el ingreso de dato erroneos a las variables string
								debido a que las variables de tipo string aceptan todos los caracteres*/

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(4); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa la forma: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> forma;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(4); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa el nombre del arbol: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> nombre;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(4); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa el nombre cientifico: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> NomCien;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(4); //funcion que imprime texto

								cout << "\n\n\t\t\tIngresa la familia a la que pertence el arbol: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> familia;

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(4); //funcion que imprime texto

								cout << "\n\n\t\t\tRegion de donde proviene el arbol de tamarindo: ";
								fflush(stdin); //funcion que limpia el buffer
								cin >> region;

								do { //ciclo que evita el ingreso de un dato erroneo
									
									system("cls"); //funcion que limpia la pantalla de la consola de los texto

									Texto(4); //funcion que imprime texto

									cout << "\n\n\t\t\tIngresa el promedio de arboles tamarindo: ";
									fflush(stdin); //funcion que limpia el buffer
									cin >> PromFrutas;
									ErrorDato(); //funcion utilizado para evitar el ingreso de datos erroneo

								} while(PromFrutas == cin.fail());		

								//Se ingresan los datos al objeto atraves de los metodos set del objeto
								at->setTallo(longTallo);
								at->setHoja(longHoja, forma);
								at->setnom(nombre);
								at->setnomcien(NomCien);
								at->setfamilia(familia);
								at->setRegion(region);
								at->setPfruta(PromFrutas);

								//se imprimen los resultados por medio de los metodos get del objeto
								
								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								Texto(4); //funcion que imprime texto

								cout << "\n\n\t\t\t\tLongitud del tallo: " << fixed << setprecision(2) << at->tallo->getlongT() << endl;
								cout  << "\t\t\t\tLongitud de la hoja: " << fixed << setprecision(2) << at->hoja.getlongH() << endl;
								cout << "\t\t\t\tForma de la hoja: "<< at->hoja.getforma() << endl;
								cout << "\t\t\t\tNombre: "<< at->getnom() << endl; 
								cout << "\t\t\t\tNombre Cientifico: " << at->getnomcien() << endl; 
								cout << "\t\t\t\tFamilia: " << at->getfamilia()<< endl;
								cout << "\t\t\t\tRegion: " << at->getRegion() << endl;
								cout << "\t\t\t\tPromedio de arboles de tamarindo: " << at->getPfruta()<< "\n\n";

								delete at; //se libera memoria

								system("pause");
								break;

							case 4:

								system("cls"); //funcion que limpia la pantalla de la consola de los texto

								cout << "\n\n\t\t\t\tGracias por usar el programa\n\n";
										
								break;

						}
		
			} while(opcion == 1 or opcion == 2 or opcion == 3);
		}
};

int main()
{
	Factory *fac = new Factory(); //Reserva espacio en la memoria
	
	fac->crearArbol(); //Metodo que contiene todo el programa
	
	delete fac; //se libera espacio en la memoria

	system("pause");
	return 0;
}
