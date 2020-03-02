#include <iostream>
using namespace std;

/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa košarkaš (košarkaš je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.

struct kosarkas
{
    char *ID;
    char *imePrezime;
    int *postignutiKosevi;
};
Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove. 
Omogućiti korisniku unos svih podataka za sve košarkaše, te napraviti funkciju koja će pronaći najuspješniji klub 
(klub u kojem je postignut najveći broj koševa). Također je potrebno pronači najuspješnijeg košarkaša u tom timu 
(ne mora biti najuspješniji u ligi) i najlošijeg košarkaša u kompletnoj ligi te izračunati razliku u broju postignutih koševa te dva košarkaša.
Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.
*/

struct kosarkas {

    char* ID;
    char* imePrezime;
    int* postignutiKosevi;

};

void unos (kosarkas&);
int klub (kosarkas**, int);
int* player (kosarkas**, int, int);
void dealoc (kosarkas&);

int main () {

    int vel;

    cout << "Unesite velicinu dvodimenzionalnog niza" << endl;
    cin >> vel;

    kosarkas** niz = new kosarkas * [vel];

    for (int i = 0; i < vel; i++)
        *(niz + i) = new kosarkas[vel];

    for (int i = 0; i < vel; i++)
        for (int j = 0; j < vel; j++)
            unos (*(*(niz + i) + j));

    int bestClub = klub (niz, vel);

    cout << "Klub sa najvise postignutih koseva je pod rednim brojem " << bestClub << "." << endl;

    cout<<"Adresa na kojoj se nalazi razlika izmedju najboljeg igraca u najboljem timu i najgoreg igraca u ligi je: "<<player (niz, vel, bestClub);

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++)
            dealoc (*(*(niz + i) + j));
        delete[] niz[i];
    }

        delete[]niz;
        niz = nullptr;

    return 0;
    system ("pause>0");
}

void unos (kosarkas& o) {

    char* lok = new char[20];
    int* vel = new int;

    cout << "Unesite ID kosarkasa" << endl;
    cin.ignore ();
    cin.getline (lok, 20);
    *vel = strlen (lok);
    o.ID = new char (*vel + 1);
    strcpy_s (o.ID, *vel + 1, lok);

    cout << "Unesite ime i prezime kosarkasa" << endl;
    cin.getline (lok, 20);
    *vel = strlen (lok);
    o.imePrezime = new char (*vel + 1);
    strcpy_s (o.imePrezime, *vel + 1, lok);

    cout << "Unesite broj postignutih koseva kosarkasa" << endl;
    o.postignutiKosevi = new int;
    cin >> *o.postignutiKosevi;

}

int klub (kosarkas** niz, int vel) {

    int suma = 0, max = INT_MIN, indeks = 0;

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++) 
            suma += *niz[j][i].postignutiKosevi;
        if (suma > max) {

            max = suma;
            indeks = i;
        }
    }
    return indeks;
}

int* player (kosarkas** niz, int vel, int cl) {

    int best = 0, razlika = 0, min = INT_MAX;

    for (int j = 0; j < vel; j++) 
         if (*niz[j][cl].postignutiKosevi > *niz[j+1][cl].postignutiKosevi)         
                best = *niz[j][cl].postignutiKosevi;
            

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++) 
            if (*niz[i][j].postignutiKosevi < min)
                min = *niz[i][j].postignutiKosevi;
    }
    razlika = best - min;

    return &razlika;
}

void dealoc (kosarkas& o) {

    delete[]o.ID;
    o.ID = nullptr;
    delete[]o.imePrezime;
    o.imePrezime = nullptr;
    delete[]o.postignutiKosevi;
    o.postignutiKosevi = nullptr;

}
