#include <iostream>
using namespace std;

/*
Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata.

struct figura
{
    int ID
    char *nazivFigure;
    float *visinaFigure;
}
Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale.
Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.

i paran == j paran na crnim poljima  
i neparan == j neparan na crnim poljima

if(i+j>n-1)

*/

struct figura {

    int id;
    char* nazivFigure;
    float* visinaFigure;

};

void dealoc (figura&);
void unos (figura&);
float* prosjek (figura**, int);

int main () {

    int vel;

    cout << "Unesite velicinu dvodimenzionalnog dinamickog niza" << endl;
    cin >> vel;

    figura** niz = new figura * [vel];

    for (int i = 0; i < vel; i++)
        *(niz+i) = new figura[vel];

    for (int i = 0; i < vel; i++)
        for (int j = 0; j < vel; j++)
            unos (*(*(niz + i) + j));

    for (int i = 0; i < vel; i++) {

        for (int j = 0; j < vel; j++)
            dealoc (niz[i][j]);

        delete[]niz[i];

    }

    delete[] niz;
    niz = nullptr;

    cout << "Prosjecna visina figura na crnim poljima ispod sporedne dijagonale je: " << *prosjek (niz, vel)<<" i ta vrijednos se nalazi na "<< prosjek (niz, vel)<<" lokaciji";

    return 0;
    system ("pause>0");
}

void dealoc (figura& o) {

    delete o.nazivFigure;
    o.nazivFigure = nullptr;
    delete o.visinaFigure;
    o.visinaFigure = nullptr;

}

void unos (figura& o) {

    char* temp = new char[20];
    int vel;

    cout << "Unesite id figure" << endl;
    cin >> o.id;

    cin.ignore ();
    cout << "Unesite naziv figure" << endl;
    cin.getline (temp, 20);
    vel = strlen (temp);
    o.nazivFigure = new char[vel + 1];
    strcpy_s (o.nazivFigure, vel + 1, temp);

    cout << "Unesite visinu figure" << endl;
    o.visinaFigure = new float;
    cin >> *o.visinaFigure;

}

float* prosjek (figura** o, int vel) {

    float* prosjek = new float{ 0 };

    float suma = 0;
    int brojac = 0;

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++) {

            if (i + j > vel - 1)
                if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {

                    suma += *o[i][j].visinaFigure;
                    brojac++;
                }
        }
    }

    *prosjek = suma / brojac;

    return prosjek;

}
