#include<iostream>
using namespace std;

/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa uposlenik (uposlenik je struktura čija su obilježja data). 
Omogućiti korisniku da unese dimenzije niza.

struct uposlenik
{
    char *ID;
    char *imePrezime;
    float *plata;
}
Redovi dvodimenzionalnog niza predstavljaju različite odjele firme u kojima rade različiti radnici 
(radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika). 
Omogućiti korisniku unos svih podataka za sve radnike, te napraviti funkciju koja će naći najveći prosjek plate po odjelima
firme te ispisati koji je to redni broj odjela (indeks reda sa najvećim prosjekom) i koji je najveći prosjek plate.
*/

struct uposlenik {

    char* ID;
    char* imePrezime;
    float* plata;

};

void unos (uposlenik&);
void plata (uposlenik**, int);
void dealoc (uposlenik&);

int main () {

    int vel;

    cout << "Upisite velicinu 2d dinamickog niza" << endl;
    cin >> vel;

    uposlenik** niz = new uposlenik * [vel];

    for (int i = 0; i < vel; i++)
        *(niz + i) = new uposlenik[vel];

    for (int i = 0; i < vel; i++)
        for (int j = 0; j < vel; j++)
            unos (*(*(niz + i) + j));

    plata (niz, vel);

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++)
            dealoc (*(*(niz + i) + j));
        delete[]*(niz+i);
    }

    delete[]niz;
    niz = nullptr;

    return 0;
    system ("pause>0");
}

void unos (uposlenik& o) {

    char lok[20];
    int vel;

    cout << "Upisite ID uposlenika" << endl;
    cin.ignore ();
    cin.getline (lok, 20);
    vel = strlen (lok);
    o.ID = new char[vel + 1];
    strcpy_s (o.ID, vel + 1, lok);

    cout << "Upisite ime i prezime uposlenika" << endl;
    cin.getline (lok, 20);
    vel = strlen (lok);
    o.imePrezime = new char[vel + 1];
    strcpy_s (o.imePrezime, vel + 1, lok);

    cout << "Upisite iznos plate" << endl;
    o.plata = new float;
    cin >> *o.plata;
}

void plata (uposlenik** niz, int vel) {

    float suma = 0, prosjek = 0, min = INT_MIN;
    int indeks = 0;

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++)
            suma += *(*(niz + i) + j)->plata;
        prosjek = suma / vel;
        if (prosjek > min) {
            min = prosjek;
            indeks = i;
        }
        suma = 0;
    }
    cout << "Odjel sa najvecim prosjekom plate je pod rednim brojem: " << indeks + 1 << ". Prosjek plate iznosi: " << prosjek << endl;
}

void dealoc (uposlenik& o) {

    delete[]o.ID;
    o.ID = nullptr;
    delete[]o.imePrezime;
    o.imePrezime = nullptr;
    delete[]o.plata;
    o.plata = nullptr;

}
