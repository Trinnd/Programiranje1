#include <iostream>
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

    char* id;
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
        niz[i] = new uposlenik[vel];

    for (int i = 0; i < vel; i++)
        for (int j = 0; j < vel; j++)
            unos (*(*(niz + i) + j));

    return 0;
    system ("pause>0");
}

void unos (uposlenik& o) {

    char lok[20];
    int vel;

    cout << "Unesite ID zaposlenika" << endl;
    cin.ignore ();
    cin.getline (lok, 20);
    vel = strlen (lok);
    o.id = new char[vel + 1];
    strcpy_s (o.id, vel + 1, lok);

    cout << "Unesite ime i prezime zaposlenika" << endl;
    cin.getline (lok, 20);
    vel = strlen (lok);
    o.imePrezime = new char[vel + 1];
    strcpy_s (o.imePrezime, vel + 1, lok);

    cout << "Unesite iznos plate radnika" << endl;
    o.plata = new float;
    cin >> *o.plata;

}

void prosjek (uposlenik** niz, int vel) {

    float suma, prosjek;
    float min = INT_MIN, red = 0 , kol = 0;

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++) {

            suma += *(*(niz + i) + j)->plata;

        }

        prosjek = suma / vel;

        if (prosjek > min) {

            min = prosjek;
            red = i;

        }
    }

    cout << "Indeks reda sa najvecim prosjekom plate je [" << red << "] a iznos najveceg prosjeka plate je: " << min;

}
