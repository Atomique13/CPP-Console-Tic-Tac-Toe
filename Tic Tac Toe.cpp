#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

char a[10] = { '0','1','2','3','4','5','6','7','8','9' };
void gui()
{
	system("cls");
	cout << " X si 0\n\n";
	cout << " Jucatorul 1 (X) -- Jucatorul 2 (0)\n\n";
	cout << " " << "   |   |   \n";
	cout << "  " << a[1] << " | " << a[2] << " | " << a[3] << "  \n";
	cout << " " << "___|___|___\n";
	cout << " " << "   |   |   \n";
	cout << "  " << a[4] << " | " << a[5] << " | " << a[6] << "  \n";
	cout << " " << "___|___|___\n";
	cout << " " << "   |   |   \n";
	cout << "  " << a[7] << " | " << a[8] << " | " << a[9] << "  \n";
	cout << " " << "   |   |   \n";
}
int verificare()
{
	if (a[1] == a[2] && a[2] == a[3])
		return 1;
	else if (a[4] == a[5] && a[5] == a[6])
		return 1;
	else if (a[7] == a[8] && a[8] == a[9])
		return 1;
	else if (a[1] == a[4] && a[4] == a[7])
		return 1;
	else if (a[2] == a[5] && a[5] == a[8])
		return 1;
	else if (a[3] == a[6] && a[6] == a[9])
		return 1;
	else if (a[1] == a[5] && a[5] == a[9])
		return 1;
	else if (a[3] == a[5] && a[5] == a[7])
		return 1;
	else if (a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && a[5] != '5' && a[6] != '6' && a[7] != '7' && a[8] != '8' && a[9] != '9')
		return -1;
	return 0;
}
int main()
{
	unsigned pos, jucator = 2;
	int k = 0;
	do
	{
		gui();
		if (jucator == 1)
			jucator = 2;
		else
			jucator = 1;
		cout << "Jucator " << jucator << ", introduceti pozitia: \n\n";
		cin >> pos;
		while ((pos < 1 || pos>9) || (a[pos] == 'x' || a[pos] == '0') || (cin.fail()))
		{
			gui();
			cin.clear();
			cin.ignore();
			cout << "Pozitia nu exista sau este ocupata, reintroduceti din nou: \n\n";
			cin >> pos;
		}
		if (jucator == 1)
			a[pos] = 'x';
		else
			a[pos] = '0';
		k = verificare();
	} while (k == 0);
	gui();
	if (k == 1)
		cout << "==>\aJucatorul " << jucator << " a castigat!\n";
	else
		cout << "==>\aJocul s-a terminat la egalitate\n";
	cout << "\n\n";
	_getch();
	return 0;
}