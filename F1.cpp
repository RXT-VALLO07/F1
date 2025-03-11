#include <iostream>
#include <string>

using namespace std;

// Costanti per il numero massimo di piloti
const int MAX_PILOTI = 20;

// Struttura per memorizzare le informazioni di un pilota
struct Pilota {
    string nome;
    string scuderia;
    int punti;
};

// Array per memorizzare i piloti
Pilota piloti[MAX_PILOTI];
int numPiloti = 0;  // Contatore per i piloti registrati

// Tabella punteggi per i primi 10 classificati
int punti_f1[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

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

        if (scelta == 1) {
            if (numPiloti >= MAX_PILOTI) {
                cout << "Numero massimo di piloti raggiunto!" << endl;
                continue;
            }

            cout << "Nome Pilota: ";
            cin >> piloti[numPiloti].nome;
            cout << "Nome Scuderia: ";
            cin >> piloti[numPiloti].scuderia;
            piloti[numPiloti].punti = 0;
            numPiloti++;

            cout << "Pilota aggiunto con successo!" << endl;

        } else if (scelta == 2) {
            if (numPiloti == 0) {
                cout << "Nessun pilota registrato!" << endl;
                continue;
            }

            string risultati[MAX_PILOTI];
            cout << "\nInserisci i nomi dei piloti nell'ordine di arrivo (uno per riga):" << endl;
            for (int i = 0; i < numPiloti; i++) {
                cout << "Posizione " << i + 1 << ": ";
                cin >> risultati[i];
            }

            // Assegnazione dei punti ai piloti
            for (int posizione = 0; posizione < numPiloti; posizione++) {
                for (int j = 0; j < numPiloti; j++) {
                    if (piloti[j].nome == risultati[posizione]) {
                        if (posizione < 10) { // Solo i primi 10 ricevono punti
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

            // Ordinamento della classifica con Bubble Sort
            for (int i = 0; i < numPiloti - 1; i++) {
                for (int j = 0; j < numPiloti - i - 1; j++) {
                    if (piloti[j].punti < piloti[j + 1].punti) {
                        Pilota temp = piloti[j];
                        piloti[j] = piloti[j + 1];
                        piloti[j + 1] = temp;
                    }
                }
            }

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

