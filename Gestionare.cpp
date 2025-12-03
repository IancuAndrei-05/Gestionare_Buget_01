#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Tranzactie {
public:
	string descriere=""; 
	double suma=0.0;
	string tip=""; 

};

class BugetManager {public :
	std::vector<Tranzactie> tranzactii;
	void AdaugaTranzactie(string descriere, double suma, string  tip)
	{
		Tranzactie t1; 
		t1.descriere = descriere;
		t1.suma = suma;
		t1.tip = tip;
		tranzactii.push_back(t1);

	}

	void AfiseazaRaport()
	{
		double TotalVenituri = 0.0;
		double TotalCheltuieli = 0.0;
		for (int i = 0; i < tranzactii.size(); i++)
		{  
			Tranzactie tranzactieCurenta = tranzactii[i];
			if (tranzactieCurenta.tip == "Venit") {
				TotalVenituri += tranzactieCurenta.suma;
			}
			else if (tranzactieCurenta.tip == "Cheltuiala")
			{
				TotalCheltuieli += tranzactieCurenta.suma;
			}


				
		}
		cout << "\n--- RAPORT BUGET ---" << endl;
		cout << "Total Venituri: " << TotalVenituri << endl;
		cout << "Total Cheltuieli" << TotalCheltuieli << endl;
		cout << "Balanta Curenta:" << (TotalVenituri - TotalCheltuieli) << endl;	
	}
};


int main()
{
	BugetManager manager;
	string descriere;
	double suma;
	string tip;
	char continua = 'D';
	do {
		cout << "--- Adauga Tranzactie ---" << endl;
		cout << "Introdu Tipul ( Venit/Cheltuiala) : ";
		cin >> tip;
		cout << "Introdu Suma";
		while (!(cin >> suma)) {
			cout << "Suma invalida . Introdu numar: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introdu descrierea";
		getline(cin, descriere);
		manager.AdaugaTranzactie(descriere, suma, tip);
		cout << "Tranzactie adaugata cu succes" << endl;
		cout << "\nDoresti sa adaugi inca o tranzactie ? (D/N):";
		cin >> continua;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (continua == 'D' || continua == 'd');
	manager.AfiseazaRaport();
	return 0;
}