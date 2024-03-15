#include <iostream>
using namespace std;

int main()
{
	int n1(1);
	int n2(1);

	cout << "Entrez un nombre: ";
	cin >> n1;
	cout << "Entrez un autre nombre: ";
	cin >> n2;
	cout << "Résultat de l'addition de " << n1 << " + " << n2 << ": " << n1 + n2;
	cout << ++n1;
	return (0);
}