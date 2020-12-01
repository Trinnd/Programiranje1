#include <iostream>
using namespace std;

/*
Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata.

Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale. 
Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.
*/
struct figura {

    int ID;
    char* nazivFigure;
    float* visinaFigure;
};

void unos (figura&);
void dealoc (figura&);
float* height (figura**,int);

int main () {

    int vel;

    cout << "Unesite velicinu dvodimenzionalnog niza" << endl;
    cin >> vel;

    figura** niz = new figura * [vel];

    for (int i = 0; i < vel; i++)
        *(niz + i) = new figura[vel];

    for (int i = 0; i < vel; i++)
        for (int j = 0; j < vel; j++)
            unos (*(*(niz + i) + j));

    cout << "Prosjek visine figura na crnim poljima ispid spredne dijagonale se nalazi na " << height (niz, vel)<<" adresi i iznosi: "<< *height (niz, vel);

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++)
            dealoc (*(*(niz + i) + j));
        delete[]niz[i];
    }

    delete[]niz;
    niz = nullptr;

    return 0;
    system ("pause>0");
}

void unos (figura& o) {

    char lok[20];
    int vel = 0;

    cout << "Unesite ID figure" << endl;
    cin >> o.ID;

    cout << "Unesite naziv figura" << endl;
    cin.ignore ();
    cin.getline (lok, 20);
    vel = strlen (lok);
    o.nazivFigure = new char[vel + 1];
    strcpy_s (o.nazivFigure, vel+1, lok);

    cout << "Unesite visinu figure" << endl;
    o.visinaFigure = new float;
    cin >> *o.visinaFigure;
}

void dealoc (figura& o) {

    delete[]o.nazivFigure;
    o.nazivFigure = nullptr;
    delete[]o.visinaFigure;
    o.visinaFigure = nullptr;

}

float* height (figura** o, int vel) {

    float suma = 0, prosjek = 0, brojac = 0;

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++) {

            if (i + j > vel - 1 && i + j % 2 == 0) {

                suma += *o[i][j].visinaFigure;
                brojac++;
            }
        }
    }
    prosjek = suma / brojac;

    return &prosjek;
}
