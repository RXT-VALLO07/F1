#include <iostream>
#include <string>
#include <algorithm>  // Per std::sort

using namespace std;

// Costanti
const int MAX_PILOTI = 20;

// Struttura Pilota
struct Pilota {
    string nome;
    string scuderia;
    int punti;
};

// Array per i piloti
Pilota piloti[MAX_PILOTI];
int numPiloti = 0;

// Tabella punteggi per i primi 10
int punti_f1[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

// Funzione per ordinare la classifica in base ai punti (sort)
bool confrontaPiloti(const Pilota &a, const Pilota &b) {
    return a.punti > b.punti;
}

int main() {
    while (true) {
        cout << "\n--- Gestione Campionato di Formula 1 ---" << endl;
        cout << "1. Aggiungi Pilota" << endl;
        cout << "2. Registra Risultati Gara" << endl;
        cout << "3. Mostra Classifica" << endl;
        cout << "4. Esci" << endl;

        int scelta;
        cout << "Scegli un'opzione: ";
        cin >> scelta;
        cin.ignore(); // Per evitare problemi con getline()

        if (scelta == 1) {
            if (numPiloti >= MAX_PILOTI) {
                cout << "Numero massimo di piloti raggiunto!" << endl;
                continue;
            }

            cout << "Nome Pilota: ";
            getline(cin, piloti[numPiloti].nome);
            cout << "Nome Scuderia: ";
            getline(cin, piloti[numPiloti].scuderia);
            piloti[numPiloti].punti = 0;
            numPiloti++;

            cout << "Pilota aggiunto con successo!" << endl;

        } else if (scelta == 2) {
            if (numPiloti == 0) {
                cout << "Nessun pilota registrato!" << endl;
                continue;
            }

            string risultati[MAX_PILOTI];
            cout << "\nInserisci i nomi dei piloti nell'ordine di arrivo:" << endl;
            for (int i = 0; i < numPiloti; i++) {
                cout << "Posizione " << i + 1 << ": ";
                getline(cin, risultati[i]);
            }

            // Assegnazione punti
            for (int posizione = 0; posizione < numPiloti; posizione++) {
                for (int j = 0; j < numPiloti; j++) {
                    if (piloti[j].nome == risultati[posizione]) {
                        if (posizione < 10) {
                            piloti[j].punti += punti_f1[posizione];
                        }
                        break;
                    }
                }
            }

            cout << "Risultati registrati con successo!" << endl;

        } else if (scelta == 3) {
            if (numPiloti == 0) {
                cout << "Nessun pilota registrato!" << endl;
                continue;
            }

            // Ordinamento classifica con sort()
            sort(piloti, piloti + numPiloti, confrontaPiloti);

            cout << "\nClassifica Piloti:" << endl;
            for (int i = 0; i < numPiloti; i++) {
                cout << i + 1 << ". " << piloti[i].nome << " (" << piloti[i].scuderia << ") - " << piloti[i].punti << " punti" << endl;
            }

        } else if (scelta == 4) {
            cout << "Uscita dal programma." << endl;
            break;

        } else {
            cout << "Scelta non valida, riprova." << endl;
        }
    }

    return 0;
}



