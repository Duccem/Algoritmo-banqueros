/*
	JOSE VELIZ CI 26.778.376
*/

#include <iostream>

using namespace std;

const int MAXRECURSOS = 5; //Maximo de recursos posibles
const int MAXPROCESOS = 5; //Maximo de procesos posibles
int necesarios[MAXPROCESOS][MAXRECURSOS]; // Matriz de recursos necesarios por proceso
int asignados[MAXPROCESOS][MAXRECURSOS]; // Matriz de recursos asignados por proceso
int existentes[MAXPROCESOS]; // Vector de recursos existentes
int disponibles[MAXPROCESOS]; // Vector de recursos disponibles

// Funciones
void entrada();
void calcDisponibles();
bool chequear();
void esSeguro();

int main()
{
	esSeguro();
	system("pause");
	return 0;
}


// Funcion encargada de la entrada de datos
void entrada()
{
	cout << "Introduzca el vector de existentes---> \n";
	for(int i = 0; i < MAXRECURSOS; i++)
	{
		count << "Del recurso " << j << " existen:\n";
		cin >> existentes[i];
	}
	cout << "\nIntroduzca la matriz de asignados---> \n";
	for(int i = 0; i < MAXPROCESOS; i++)
	{
		count << "Proceso " << i << " tiene asignados del...\n";
		for(int j = 0; j < MAXRECURSOS; j++)
		{
			count << "Recurso " << j << ":\n";
			cin >> asignados[i][j];
		}
	}
	cout << "\nIntroduzca la matriz de necesarios---> \n";
	for(int i = 0; i < MAXPROCESOS; i++)
	{
		count << "Proceso " << i << " necesita del...\n";
		for(int j = 0; j < MAXRECURSOS; j++)
		{
			count << "Recurso " << j << ":\n";
			cin >> necesarios[i][j];
		}
	}
}

//Calculo de el vector de recursos disponibles
void calcDisponibles()
{
	for (int i = 0; i < MAXPROCESOS; i++) {
		for (int j = 0; j < MAXRECURSOS; j++) 
		{
			//Resto de los existentes cada uno de los asignados por recurso
			disponibles[j] = existentes[j] - asignados[i][j];
		}
	}
}

// Funcion que valida si se le pueden asignar los recursos a un proceso
bool chequear(int i)
{
	for (int j = 0; j < MAXRECURSOS; j++) {
		// si la cantidad de disponibles es menor a los necesarios retornamos falso
		if (disponibles[j] < necesarios[i][j]) {
			return false;
		}
	}
	// retornamos verdadero de no haber identificado un recurso con menos disponibles de los necesarios
	return true;
}

// Funcion principal que realiza la asignacion de recursos y valida el interbloqueo
void esSeguro()
{
	// Llamamos a la entrada de datos y el calculo del vector de recursos disponibles
	entrada();
	calcDisponibles();
	// Vector que funge como auxiliar para verificar si un proceso se le fue asignados sus recursos
	bool hecho[MAXPROCESOS]; 
	int j = 0; // Contador que ayuda a verificar la cantidad de precesos a los que se le asigno los recursos

	// Hasta que todos los recursos se asignen u ocurra un interbloqueo
	while(j<MAXPROCESOS)
	{
		bool asignado = false; // Bandera para identificar si el recurso se asigno
		for(int i = 0; i< MAXPROCESOS; i++)
		{
			if(!hecho[i] && chequear(i)) // si no se ha asignado o si es posible asignarse
			{
				for(int k = 0; k < MAXRECURSOS; k++) // Se realiza la asignacion
				{
					disponibles[k] = disponibles[k] - necesarios[i][k];
				}
				count << "Proceso " << i << " Asignado\n";
				hecho[i] = true;
				asig = hecho[i];
				j++;
			}
		}
		if(!asignado){ // Si no fue asignado rompemos el ciclo
			break;
		}
	}
	// Si la cantidad de procesos asignados es igual al maximo de procesos entonces
	// se indica el exito de lo contrario se indica que hubo un interbloqueo o deadlock
	if(j==MAXPROCESOS)
	{
		count << "Procesos asignados de forma segura\n";
	}
	else
	{
		count << "Deadlock\n";
	}
}