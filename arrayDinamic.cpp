// arrayDinamic.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

class DynamicArray
{
private:
	int size = 0;
	int capacity = 0;
	string* array;

public:
	DynamicArray() {};
	DynamicArray(int _c)
	{
		capacity = _c;
		array = new string[_c];

		for (int i = 0; i < capacity; i++)
		{
			array[i] = "";
		}
	}

	bool insert(string newElement, int position)
	{
		if (position >= capacity)
		{
			cout << "El indice esta fuera de capacity.";
			return false;
		}

		if (size == capacity)
		{
			cout << "El array esta lleno.";
			return false;
		}

		if (position >= size)
		{
			cout << "Se anade al final. Posicion " << size << endl;

			array[size] = newElement;
			size++;
		}
		else
		{
			for (int i = size - 1; i >= position; i--)
			{
				array[i + 1] = array[i];
			}
			array[position] = newElement;
			size++;
		}
		return true;
	}

	bool remove(int position)
	{
		if (position >= size || position < 0)
		{
			cout << "El indice esta fuera de capacity." << endl;
			return false;
		}

		else 
		{
			for (int i = position; i < size - 1; i++)
			{
				array[i] = array[i + 1];
			}
			size--;
			return true;
		}
	}

	void printInfo()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	DynamicArray myArray(10);

	myArray.insert("bli", 0);
	myArray.printInfo();
	myArray.insert("blo", 1);
	myArray.printInfo();
	myArray.insert("blu", 3);
	myArray.printInfo();
	myArray.remove(-10);
	myArray.printInfo();
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
