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
(radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika). Omogućiti korisniku unos svih podataka za sve radnike, 
te napraviti funkciju koja će naći najveći prosjek plate po odjelima firme te ispisati koji je to redni broj odjela
(indeks reda sa najvećim prosjekom) i koji je najveći prosjek plate.
*/

struct uposlenik {

    char* ID;
    char* imePrezime;
    float* plata;

};

void unos (uposlenik&);
void prosjek (uposlenik**, int);

int main () {

    int vel;

    cout << "Unesite velicinu niza" << endl;
    cin >> vel;

    uposlenik** niz = new uposlenik * [vel];

    for (int i = 0; i < vel; i++)
        *(niz + i) = new uposlenik[vel];

    for (int i = 0; i < vel; i++)
        for (int j = 0; j < vel; j++)
            unos (*(*(niz + i) + j));

    prosjek (niz, vel);

    return 0;
    system ("pause>0");
}

void unos (uposlenik& o) {

    char* lok = new char[20];
    int* vel = new int;

    cout << "Unesite ID uposlenika" << endl;
    cin.ignore ();
    cin.getline (lok, 20);
    *vel = strlen (lok);
    o.ID = new char[*vel + 1];
    strcpy_s (o.ID, *vel + 1, lok);

    cout << "Unesite ime i prezime uposlenika" << endl;
    cin.getline (lok, 20);
    *vel = strlen (lok);
    o.imePrezime = new char[*vel + 1];
    strcpy_s (o.imePrezime, *vel + 1, lok);

    cout << "Unesite iznos plate uposlenika" << endl;
    o.plata = new float;
    cin >> *o.plata;

    delete[]lok;
    lok = nullptr;
    delete vel;
    vel = nullptr;
}

void prosjek (uposlenik** niz, int vel) {

    float* prosjek = new float[vel] {};
    int max = 0;

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++)
            *(prosjek + i) += *(*(niz + i) + j)->plata;
        *(prosjek + i) /= vel;
    }

    for (int i = 1; i < vel; i++)
        if (*(prosjek + i) > * (prosjek + max))
            max = i;

    cout << "Odjel sa najvecim prosjekom plate je pod indexom: [" << max << "] a najveci prosjek plate iznosi: " << *(prosjek + max) << endl;

}