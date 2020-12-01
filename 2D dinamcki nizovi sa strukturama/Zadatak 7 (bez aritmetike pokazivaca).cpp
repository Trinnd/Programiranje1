#include <iostream>
using namespace std;

/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.

struct vozilo
{
    char *markaVozila;
    char *nazivVozila;
    char *tipVozila; // omogućiti unos samo 'A', 'B','C'
    float *potrosnja_goriva_po_km;
};
Redovi matrice predstavljaju firme, kolone automobile. Izračunati u kojoj je firmi najveća potrošnja goriva po km.
Naći i ispisati prosjek potrošnje goriva po km u vozilima tipa C u cijeloj matrici. U zadataku koristiti artimetiku pokazivaca.
*/

struct vozilo {

    char* markaVozila;
    char* nazivVozila;
    char* tipVozila; // omogućiti unos samo 'A', 'B','C'
    float* potrosnja_goriva_po_km;

};

void unos (vozilo&);
int maxPotrosnja (vozilo**, int);
float prosjekC (vozilo**, int);

int main () {

    int vel;
    cout << "Unesite velicinu niza" << endl;

    cin >> vel;

    vozilo** niz = new vozilo * [vel];

    for (int i = 0; i < vel; i++)
        *(niz + i) = new vozilo[vel];

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++)
            unos (*(*(niz + i) + j));
    }

    cout << "Najveca potrosnja goriva po kilometru je u firmi sa indeksom reda u nizu: [" << maxPotrosnja (niz, vel) << "], sto je " << maxPotrosnja (niz, vel) + 1 << ". u redu"<<endl;
    cout << "Prosjek potrosnje goriva u vozilima tipa C je" << prosjekC (niz, vel);

    return 0;
    system ("pause>0");
}

int maxPotrosnja (vozilo** niz, int vel) {

    int indeks = 0, int min=INT_MIN;
    float suma = 0, float prosjek = 0;

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++) 
            suma += *niz[i][j].potrosnja_goriva_po_km;

        prosjek = suma / vel;
        if (prosjek > min)
            indeks = i;

    }

    return indeks;
}

float prosjekC (vozilo** niz, int vel) {

    float suma = 0, prosjek = 0;

    for (int i = 0; i < vel; i++) 
        for (int j = 0; j < vel; j++) 
            if (*niz[i][j].tipVozila == 'C')
                suma += *niz[i][j].potrosnja_goriva_po_km;       
    
    prosjek = suma / vel;
    return prosjek;
}

void unos (vozilo& o) {

    char lok[20];
    int vel = 0;

    cout << "Unesita marku vozila" << endl;
    cin.ignore ();
    cin.getline (lok, 20);
    vel = strlen (lok);
    o.markaVozila = new char[vel];
    strcpy_s (o.markaVozila, vel + 1, lok);

    cout << "Unesite naziv vozila" << endl;
    cin.getline (lok, 20);
    vel = strlen (lok);
    o.nazivVozila = new char[vel];
    strcpy_s (o.nazivVozila, vel + 1, lok);

    o.tipVozila = new char;
    do {

        cout << "Unesite tip vozila" << endl;
        cin >> o.tipVozila;

    } while (*o.tipVozila != 'A' && *o.tipVozila != 'B' && *o.tipVozila != 'C');

    cout << "Unesite potrosnju goriva" << endl;
    o.potrosnja_goriva_po_km = new float;
    cin >> *o.potrosnja_goriva_po_km;

}
