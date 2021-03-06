#include <iostream>
using namespace std;

/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata. Osigurati da bude isti broj kolona i redova. 
Potrebno je napraviti funkciju koja će provjeriti da li su figure na bijelim poljima simetrično raspoređene po visini u odnosu
na glavnu dijagonalu (da li je visina figure na poziciji 0,1 jednaka visini figure na poziciji 1,0 itd. za sva bijela polja).
Funkcija treba da vrati pokazivač na memorijsku lokaciju u kojoj je upisan zbir visina figura ako je tabela simetrično raspoređena,
a broj -1 ako nije simetrično raspoređena.

struct figura
{
    int ID;
    char *nazivFigure;
    float *visinaFigure;
};
*/

struct figura {

    int id;
    char* nazivFigure;
    float* visinaFigure;

};

void unos (figura&);
float* sim (figura**, int);
void dealoc (figura&);

int main () {

    int vel;

    cout << "Unesite velicinu dvodimenzionalnog dinamickog niza" << endl;
    cin >> vel;

    figura** niz = new figura*[vel];

    for (int i = 0; i < vel; i++)
        *(niz + i) = new figura[vel];

    for (int i = 0; i < vel; i++)
        for (int j = 0; j < vel; j++)
            unos (*(*(niz + i) + j));

    float* zbir = sim (niz, vel);

    if (*zbir != -1)
        cout << "Zbir visina figura na bijelim poljima simetricno rasporedjene matrice po visini je: " << *zbir << endl;
    else
        cout << "Matrica nije simetricno rasporedjena po visini" << endl;

    for (int i = 0; i < vel; i++) {
        for (int j = 0; j < vel; j++)
            dealoc (*(*(niz + i) + j));
        delete[]niz[i];
    }
    delete[] niz;
    niz = nullptr;

    return 0;
    system ("pause>0");
}

void dealoc (figura& o) {

    delete[]o.nazivFigure;
    o.nazivFigure = nullptr;
    delete o.visinaFigure;
    o.visinaFigure = nullptr;

}

void unos (figura& o) {

    char* lok = new char[10];
    int vel;

    cout << "Unesite ID figure" << endl;
    cin >> o.id;

    cout << "Unesite naziv figure" << endl;
    cin.ignore ();
    cin.getline (lok, 10);
    vel = strlen (lok);
    o.nazivFigure = new char[vel + 1];
    strcpy_s (o.nazivFigure, vel + 1, lok);

    cout << "Unesite visinu figure" << endl;
    o.visinaFigure = new float;
    cin >> *o.visinaFigure;

}

float* sim (figura** o, int vel) {

    float* zbir = new float(0);

    for(int i =0;i<vel;i++)
        for (int j = 0; j < vel; j++) {

            if ((i + j) % 2 != 0) {

                if (*o[i][j].visinaFigure == *o[j][i].visinaFigure)
                    *zbir += *o[i][j].visinaFigure;
                else {

                    delete zbir;
                    return new float(-1);

                }
            }

        }
    return zbir;
}
