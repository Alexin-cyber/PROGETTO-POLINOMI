#include <iostream>
#include <cmath> // Per la funzione abs() e per la funzione pow()
#include <conio.h> // Per getch()
#include "graphics2.h" // Per la funziona grafica
using namespace std;

int main() {
    // Costanti per stabilire il range massimo dei polinomi
    const int MAX = 4, MAX2 = 16;
    
    // Variabili utilizzati per stabilire i gradi massimi dei vari polinomi
    int gradoMaxPolinomio1, gradoMaxPolinomio2, gradoMax, index;

    // Variabili utilizzati per la risoluzione di un'equazione di secondo grado
    int delta, numeratore1, numeratore2, denominatore1, denominatore2, resto, mcd1, mcd2, mcdDenominatore, a, b, c;

    // Array che contengono i valori dei due polinomi
    int polinomio1[MAX]{0}, polinomio2[MAX]{0};

    // Array che contengono i valori delle operazioni tra il primo e il secondo polinomio
    int polinomioSomma[MAX]{0}, polinomioDifferenza[MAX]{0}, gradoPolinomio[MAX2]{0}, polinomioProdotto[MAX2]{0}, polinomioProdottoSomma[MAX2]{0};

    // Variabili utilizzati per la semplificazione delle radici
    int parteInterna, parteEsterna, cont, numeratore, denominatore, n;

    // Variabili utilizzati per la risoluzione di un'equazione di primo grado
    int termineNoto, terminePrimoGrado;
    bool isImpossibile, isIndeterminato;

    // Variabili utilizzati per trovare i punti di intersezione
    float deltaDecimal, numeratoreDecimal, denominatoreDecimal, x1, x2, y1, y2, aDecimal, bDecimal, cDecimal, termineNotoDecimal, terminePrimoGradoDecimal;
    
    // Variabili per la graphica
    int graphDriver = 0, graphMode = 0;

    char opzione;
    bool isFirstTime = true, isRunning = true, isZero, isFailed;

    cin.precision(3); // Stabili 3 numeri significativi in caso dei numeri decimali

    cout << "\033[36m  _____   ____  _      _____ _   _  ____  __  __ _____\n";
    cout << " |  __ \\ / __ \\| |    |_   _| \\ | |/ __ \\|  \\/  |_   _|\n";
    cout << " | |__) | |  | | |      | | |  \\| | |  | | \\  / | | |  \n";
    cout << " |  ___/| |  | | |      | | | . ` | |  | | |\\/| | | |  \n";
    cout << " | |    | |__| | |____ _| |_| |\\  | |__| | |  | |_| |_ \n";
    cout << " |_|     \\____/|______|_____|_| \\_|\\____/|_|  |_|_____|\n";
    cout << "          [ PROGRAMMA PER RISOLVERE I POLINOMI ]\n";
    cout << "-------------------------------------------------------\033[0m\n\n";

    cout << "PROGRAMMA FATTO DA:\n";
    cout << " - EDOSA EZEKIEL\n";
    cout << " - GAMBERA GABRIELE\n";
    cout << " - CAMMARATA GABRIELE\n\n";

    cout << "\033[4mPremere qualsiasi tasto per continuare...\033[0m";
    getch();
    system("cls");

    while (isRunning) {
        if (isFirstTime) {
            cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
            cout << "\033[36m|"<< "\033[1m                        PRIMA ACQUISIZIONE DEI POLINOMI                        " << "\033[1m|\033[0m\n";
            cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";

            // Controllo input del grado massimo del primo polinomio
            do {
                isFailed = false;
                cout << "Inserisci il grado massimo del primo polinomio: ";
                cin >> gradoMaxPolinomio1;

                // Controllo in caso l'utente metta un valore diverso da un numero
                if (cin.fail()) {
                    cin.clear(); // Elimina l'errore
                    cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                    isFailed = true;

                    cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                } else if (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0) {
                    cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                }
            } while (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0 || isFailed);

            // Gestione input del primo polinomio
            for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                if (i > 0) {
                    do {
                        isFailed = false;
                        cout << "\nInserisci il coefficiente di grado x^" << i << ": ";
                        cin >> polinomio1[i];

                        if (cin.fail()) {
                            cin.clear(); // Elimina l'errore
                            cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                            isFailed = true;

                            cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                        } 
                    } while (isFailed);
                } else {
                    do {
                        isFailed = false;
                        cout << "\nInserisci il termine noto: ";
                        cin >> polinomio1[i];

                        if (cin.fail()) {
                            cin.clear(); // Elimina l'errore
                            cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                            isFailed = true;

                            cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                        } 
                    } while (isFailed);
                }
            }
            
            // Gestione output del primo polinomio
            cout << "\n\n\033[32mPrimo polinomio: \033[0m";
            
            // assegna il segno (+, -) al primo numero del primo polinomio
            if (polinomio1[gradoMaxPolinomio1] != 0) {
                cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
            }
            
            cout << "\033[1m";
            for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                if (polinomio1[i] != 0) {
                    isZero = false;
                    if (i != 0) {
                        cout << abs(polinomio1[i]) << "x^" << i << " ";
                    } else {
                        cout << abs(polinomio1[i]);
                    }
                }
                
                if (i != 0 && polinomio1[i - 1] != 0) {
                    cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                }
            }
            cout << "\033[0m";
            
            if (isZero) {
                cout << "\033[1m" << 0 << "\033[0m";
            }


            cout << "\n";
            do {
                isFailed = false;
                cout << "\nInserisci il grado massimo del secondo polinomio:  ";
                cin >> gradoMaxPolinomio2;
                
                // Controllo in caso l'utente metta un valore diverso da un numero
                if (cin.fail()) {
                    cin.clear(); // Elimina l'errore
                    cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                    isFailed = true;

                    cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                } else if (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0) {
                    cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                }
                    
            } while (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0 || isFailed);

            isZero = true;
            
            // Gestione input del secondo polinomio
            for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                if (i > 0) {
                    do {
                        isFailed = false;
                        cout << "\nInserisci il coefficiente di grado x^" << i << ": ";
                        cin >> polinomio2[i];

                        // Controllo in caso l'utente metta un valore diverso da un numero
                        if (cin.fail()) {
                            cin.clear(); // Elimina l'errore
                            cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                            isFailed = true;

                            cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                        }
                    } while (isFailed);
                } else {
                    do {
                        isFailed = false;
                        cout << "\nInserisci il termine noto: ";
                        cin >> polinomio2[i];

                        // Controllo in caso l'utente metta un valore diverso da un numero
                        if (cin.fail()) {
                            cin.clear(); // Elimina l'errore
                            cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                            isFailed = true;

                            cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                        }
                    } while (isFailed);
                }
            }
            
            // Gestione output del primo polinomio
            cout << "\n\n\033[32mSecondo polinomio: \033[0m";
        
            // assegna il segno (+, -) al primo numero del secondo polinomio
            if (polinomio2[gradoMaxPolinomio2] != 0) {
                cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
            }
            
            cout << "\033[1m";
            for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                if (polinomio2[i] != 0) {
                    isZero = false;
                    if (i != 0) {
                        cout << abs(polinomio2[i]) << "x^" << i << " ";
                    } else {
                        cout << abs(polinomio2[i]);
                    }
                }
                
                if (i != 0 && polinomio2[i - 1] != 0) {
                    cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                }
            }
            cout << "\033[0m";
            
            if (isZero)
                cout << "\033[1m" << 0 << "\033[0m";
            
            cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
	        getch();
	        system("cls");
            isFirstTime = false;
        }

        cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
        cout << "\033[36m|"<< "\033[1m                                 MENU PRINCIPALE                               " << "\033[1m|\033[0m\n";
        cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
        cout << "\033[36m" << "|  \033[32m[1]\033[0m" << " Acquisizione dei polinomi                                                " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[2]\033[0m" << " Somma di polinomi                                                        " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[3]\033[0m" << " Differenza di polinomi                                                   " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[4]\033[0m" << " Prodotto di polinomi                                                     " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[5]\033[0m" << " Ricerca e visualizzazione degli zeri (frazionari/interi)                 " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[6]\033[0m" << " Ricerca e visualizzazione dei punti di intersezione (decimali/interi)    " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[7]\033[0m" << " Rappresentazione grafica dei polinomi                                    " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[8]\033[0m" << " Esci dal programma                                                       " << "\033[36m|\n";
        cout << "\033[36m" << "---------------------------------------------------------------------------------\033[0m\n\n";

        cout << "\033[1m Scegli un opzione \033[36m\n>>\033[0m ";
        cin >> opzione;

        switch (opzione) {
            case '1':
                system("cls");
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
                cout << "\033[36m|"<< "\033[1m                           ACQUISIZIONE DEI POLINOMI                           " << "\033[1m|\033[0m\n";
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";

                // Riassegnamento dei valori di defualt
                for (int i = 0; i < MAX; i++) {
                    polinomio1[i] = 0;
                    polinomio2[i] = 0;
                }

                // Controllo input del grado massimo del primo polinomio
                do {
                    isFailed = false;
                    cout << "Inserisci il grado massimo del primo polinomio: ";
                    cin >> gradoMaxPolinomio1;

                    // Controllo in caso l'utente metta un valore diverso da un numero
                    if (cin.fail()) {
                        cin.clear(); // Elimina l'errore
                        cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                        isFailed = true;

                        cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                    } else if (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0) {
                        cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                    }
                } while (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0 || isFailed);

                // Gestione input del primo polinomio
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (i > 0) {
                        do {
                            isFailed = false;
                            cout << "\nInserisci il coefficiente di grado x^" << i << ": ";
                            cin >> polinomio1[i];

                            if (cin.fail()) {
                                cin.clear(); // Elimina l'errore
                                cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                                isFailed = true;

                                cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                            } 
                        } while (isFailed);
                    } else {
                        do {
                            isFailed = false;
                            cout << "\nInserisci il termine noto: ";
                            cin >> polinomio1[i];

                            if (cin.fail()) {
                                cin.clear(); // Elimina l'errore
                                cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                                isFailed = true;

                                cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                            } 
                        } while (isFailed);
                    }
                }
                isZero = true;

                // Gestione output del primo polinomio
                cout << "\n\n\033[32mPrimo polinomio: \033[0m";
                
                // assegna il segno (+, -) al primo numero del primo polinomio
                if (polinomio1[gradoMaxPolinomio1] != 0) {
                    cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                }
                
                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio1[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio1[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";
                
                if (isZero) {
                    cout << "\033[1m" << 0 << "\033[0m";
                }

                cout << "\n";
                do {
                    isFailed = false;
                    cout << "\nInserisci il grado massimo del secondo polinomio:  ";
                    cin >> gradoMaxPolinomio2;
                    
                    // Controllo in caso l'utente metta un valore diverso da un numero
                    if (cin.fail()) {
                        cin.clear(); // Elimina l'errore
                        cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                        isFailed = true;

                        cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                    } else if (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0) {
                        cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                    }
                        
                } while (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0 || isFailed);
            
                // Gestione input del secondo polinomio
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (i > 0) {
                        do {
                            isFailed = false;
                            cout << "\nInserisci il coefficiente di grado x^" << i << ": ";
                            cin >> polinomio2[i];

                            // Controllo in caso l'utente metta un valore diverso da un numero
                            if (cin.fail()) {
                                cin.clear(); // Elimina l'errore
                                cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                                isFailed = true;

                                cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                            }
                        } while (isFailed);
                    } else {
                        do {
                            isFailed = false;
                            cout << "\nInserisci il termine noto: ";
                            cin >> polinomio2[i];

                            // Controllo in caso l'utente metta un valore diverso da un numero
                            if (cin.fail()) {
                                cin.clear(); // Elimina l'errore
                                cin.ignore(1000, '\n'); // Consuma tutti i caratteri nel buffer fino a \n
                                isFailed = true;

                                cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                            }
                        } while (isFailed);
                    }
                }
                isZero = true;
                // Gestione output del secondo polinomio
                cout << "\n\n\033[32mSecondo polinomio: \033[0m";
                
                // assegna il segno (+, -) al secondo numero del secondo polinomio
                if (polinomio2[gradoMaxPolinomio2] != 0) {
                    cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
                }
                
                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio2[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio2[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";
                
                if (isZero)
                    cout << "\033[1m" << 0 << "\033[0m";

                cout << "\033[0m";
                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            case '2':
                system("cls");
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
                cout << "\033[36m|"<< "\033[1m                              SOMMA DI POLINOMI                                " << "\033[1m|\033[0m\n";
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";

                // Riassegnamento dei valori di defualt
                for (int i = 0; i < MAX; i++) {
                    polinomioSomma[i] = 0;
                }
                
                // Calcolo della somma dei due polinomi
                for (int i = MAX - 1; i >= 0; i--) {
                    polinomioSomma[i] = polinomio1[i] + polinomio2[i];
                }
                
                // individuazione del grado massimo tra i due polinomi
                if (gradoMaxPolinomio1 > gradoMaxPolinomio2) {
                    gradoMax = gradoMaxPolinomio1;
                } else {
                    gradoMax = gradoMaxPolinomio2;
                }

                // Gestione output del polinomio somma
                cout << "\033[32mLa somma tra i due polinomi equivale a: \033[0m\n\n";
                isZero = true;

                cout << "(";

                // assegna il segno (+, -) al primo numero del primo polinomio
                if (polinomio1[gradoMaxPolinomio1] != 0) {
                    cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                }
                
                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio1[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio1[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";
                
                if (isZero) {
                    cout << "\033[1m" << 0 << "\033[0m";
                }

                isZero = true;

                cout << ") + (";

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio2[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio2[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";
                
                if (isZero)
                    cout << "\033[1m" << 0 << "\033[0m";

                cout << ") = ";
				
                isZero = true;

                // assegna il segno (+, -) al primo numero del polinomio somma
                if (polinomioSomma[gradoMax] != 0) {
                    if (polinomioSomma[gradoMax] > 0) {
                        cout << "+";
                    } else  {
                        cout << "-";
                    }   
                }

                cout << "\033[1m";
                for (int i = gradoMax; i >= 0; i--) {
                    if (polinomioSomma[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomioSomma[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomioSomma[i]);
                        }
                    }
                    
                    if (i != 0 && polinomioSomma[i - 1] != 0) {
                        cout << (polinomioSomma[i - 1] > 0 ? "+ " : "- ");
                    }
                }
	            cout << "\033[0m";
	        	
                if (isZero)
                    cout << "\033[1m" << 0 << "\033[0m";
				
                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            case '3':
                system("cls");
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
                cout << "\033[36m|"<< "\033[1m                           DIFFERENZA DI POLINOMI                              " << "\033[1m|\033[0m\n";
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";

                // Riassegnamento dei valori di defualt
                for (int i = 0; i < MAX; i++) {
                    polinomioDifferenza[i] = 0;
                }
                
                // Calcolo della differnza dei due polinomi
                for (int i = MAX - 1; i >= 0; i--) {
                    polinomioDifferenza[i] = polinomio1[i] - polinomio2[i];
                }
                
                // individuazione del grado massimo tra i due polinomi
                if (gradoMaxPolinomio1 > gradoMaxPolinomio2) {
                    gradoMax = gradoMaxPolinomio1;
                } else {
                    gradoMax = gradoMaxPolinomio2;
                }

                // Gestione output del polinomio differenza
                cout << "\033[32mLa differenza tra i due polinomi equivale a: \033[0m\n\n";
                isZero = true;

                cout << "(";

                // assegna il segno (+, -) al primo numero del primo polinomio
                if (polinomio1[gradoMaxPolinomio1] != 0) {
                    cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                }
                
                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio1[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio1[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";
                
                if (isZero) {
                    cout << "\033[1m" << 0 << "\033[0m";
                }

                cout << ") - (";

                isZero = true;

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio2[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio2[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";
                
                if (isZero)
                    cout << "\033[1m" << 0 << "\033[0m";

                cout << ") = ";

	                // assegna il segno (+, -) al primo numero del polinomio differenza
	                if (polinomioDifferenza[gradoMax] != 0) {
	                    if (polinomioDifferenza[gradoMax] > 0) {
	                        cout << "+";
	                    } else  {
	                        cout << "-";
	                    }   
	                }

                    isZero = true;
	
	                cout << "\033[1m";
	                for (int i = gradoMax; i >= 0; i--) {
	                    if (polinomioDifferenza[i] != 0) {
                            isZero = false;
	                        if (i != 0) {
	                            cout << abs(polinomioDifferenza[i]) << "x^" << i << " ";
	                        } else {
	                            cout << abs(polinomioDifferenza[i]);
	                        }
	                    }
	                    
	                    if (i != 0 && polinomioDifferenza[i - 1] != 0) {
	                        cout << (polinomioDifferenza[i - 1] > 0 ? "+ " : "- ");
	                    }
	                }
	                cout << "\033[0m";

                    if (isZero) {
                        cout << "\033[1m" << 0 << "\033[0m";
                    }
	        		
                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            case '4':
                system("cls");
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
                cout << "\033[36m|"<< "\033[1m                            PRODOTTO DI POLINOMI                               " << "\033[1m|\033[0m\n";
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";

                index = 0;
                // Riassegnamento dei valori di defualt
                for (int i = 0; i < MAX2; i++) {
                    gradoPolinomio[i] = 0;
                    polinomioProdotto[i] = 0;
                    polinomioProdottoSomma[i] = 0;
                }
            
                // Calcolo del prodotto tra i due polinomi
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    for (int j = gradoMaxPolinomio2; j >= 0; j--) {
                        if (polinomio1[i] != 0 && polinomio2[j] != 0) {
                            polinomioProdottoSomma[index] = polinomio1[i] * polinomio2[j];
                            gradoPolinomio[index] = i + j;
                            index++;
                        }
                    }
                }

                gradoMax = gradoMaxPolinomio1 + gradoMaxPolinomio2;
                index = 0;

                // Somma i monomi simili all'interno del polinomio prodotto
                for (int i = 0; i < MAX2; i++) {
                    for (int j = 0; j < MAX2; j++) {
                        if (gradoPolinomio[j] == gradoMax) {
                            polinomioProdotto[index] += polinomioProdottoSomma[j];
                        }
                    }

                    index++;
                    gradoMax--;
                    if (gradoMax < 0) break;
                }

                // Gestione output del polinomio prodotto
                cout << "\033[32mIl prodotto tra i due polinomi equivale a: \033[0m\n\n";
                gradoMax = gradoMaxPolinomio1 + gradoMaxPolinomio2;
                index = 0;
                isZero = true;

                cout << "(";

                // assegna il segno (+, -) al primo numero del primo polinomio
                if (polinomio1[gradoMaxPolinomio1] != 0) {
                    cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                }
                
                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio1[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio1[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";
                
                if (isZero) {
                    cout << "\033[1m" << 0 << "\033[0m";
                }

                cout << ") * (";

                isZero = true;

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio2[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio2[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";
                
                if (isZero)
                    cout << "\033[1m" << 0 << "\033[0m";

                cout << ") = ";

                isZero = true;
	
                // assegna il segno (+, -) al primo numero del polinomio prodotto
                if (polinomioProdotto[index] != 0) {
                    if (polinomioProdotto[index] > 0) {
                        cout << "+";
                    } else  {
                        cout << "-";
                    }   
                }

                cout << "\033[1m";
                for (int i = gradoMax; i >= 0; i--) {
                    if (polinomioProdotto[index] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomioProdotto[index]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomioProdotto[index]);
                        }
                    }
                    
                    if (i != 0 && polinomioProdotto[index + 1] != 0) {
                        cout << (polinomioProdotto[index + 1] > 0 ? "+ " : "- ");
                    }
                    index++;
                }
                cout << "\033[0m";

                if (isZero) {
                    cout << "\033[1m" << 0 << "\033[0m";
                }
           	 		    
                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            case '5':
                system("cls");
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
                cout << "\033[36m|"<< "\033[1m                     RICERCA E VISUALIZZAZIONE DEGLI ZERI                      " << "\033[1m|\033[0m\n";
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";

                cout << "\033[32mLe soluzioni/e del primo polinomio sono/e': \033[0m\n";
                if (polinomio1[MAX - 1] == 0) {
                    if (polinomio1[MAX - 2] != 0) {
                        a = polinomio1[MAX - 2], b = polinomio1[MAX - 3], c = polinomio1[MAX - 4];
                        delta = pow(b, 2) - 4 * a * c;

                        if (pow(sqrt(delta), 2) != delta && delta > 0) { // verifica se la radice è perfetta o meno
                            parteInterna = 1, parteEsterna = 1, numeratore = -b, denominatore = 2 * a;

                            n = delta;

                            // Semplificazione della radice
                            for (int i = 2; i <= delta; i++) {
                                cont = 0; 

                                while (n % i == 0) {
                                    n /= i;
                                    cont++;
                                }

                                if (cont > 0) {
                                    if (cont % 2 == 0) {
							            parteEsterna *= pow(i, cont / 2);
                                    } else {
                                        if (cont > 1)
                                            parteEsterna *= pow(i, cont / 2);
                                        parteInterna *= i;
                                    }
                                }
                            }

                            mcd1 = abs(numeratore);
				            mcd2 = abs(parteEsterna);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            numeratore = numeratore / mcd2;
				            parteEsterna = parteEsterna / mcd2;

                            mcd1 = abs(mcd2);
				            mcdDenominatore = abs(denominatore);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra mcd del numeratore e la parte esterna e il denominarore
                            while (mcd1 % mcdDenominatore > 0) {
                                resto = mcd1 % mcdDenominatore;
                                mcd1 = mcdDenominatore;

                                if (resto != 0)
                                    mcdDenominatore = resto;
                            }

                            mcd2 = mcd2 / mcdDenominatore;
				            denominatore = denominatore / mcdDenominatore;

                            // Gestione output delle soluzione del polinomio di secondo grado
                            if (denominatore == 1 && b == 0) {
                                cout << "\nx(1) = " << "\033[1m" << " + " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << " - " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\033[0m\n";
                            } else if (mcd2 % denominatore != 0) {
                                cout << "\nx(1) = "  << "\033[1m" << "(" << mcd2 * numeratore << " + " << parteEsterna * mcd2 << "*" <<"sqrt(" << parteInterna << ")" << ")" << "/" << denominatore << "\033[0m\n";
                                cout <<  "\nx(2) = " << "\033[1m" << "(" << mcd2 * numeratore << " - " << parteEsterna * mcd2 << "*" <<"sqrt(" << parteInterna << ")" << ")" << "/" << denominatore << "\033[0m";
                            } else {
                                cout << "\nx(1) = " << "\033[1m" << numeratore << " + " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore << " - " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\033[0m";
                            }
                        } else if (delta > 0) {
                            numeratore1 = -b + sqrt(delta);
                            numeratore2 = -b - sqrt(delta);

                            denominatore1 = 2 * a;
                            denominatore2 = 2 * a;

                            mcd1 = abs(numeratore1);
                            mcd2 = abs(denominatore1);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il primo numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            numeratore1 = numeratore1 / mcd2;
                            denominatore1 = denominatore1 / mcd2;

                            mcd1 = abs(numeratore2);
                            mcd2 = abs(denominatore2);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il secondo numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            numeratore2 = numeratore2 / mcd2;
                            denominatore2 = denominatore2 / mcd2;

                            // Gestione output delle soluzioni del polinomio di secondo grado
                            if (numeratore1 % denominatore1 != 0 && numeratore2 % denominatore2 != 0) {
                                cout << "\nx(1) = " << "\033[1m" << numeratore1 << "/" << denominatore1 << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore2 << "/" << denominatore2 << "\033[0m";
                            } else if (numeratore1 % denominatore1 != 0 && numeratore2 % denominatore2 == 0) {
                                cout << "\nx(1) = " << "\033[1m" << numeratore1 << "/" << denominatore1 << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore2 << "\033[0m";
                            } else if (numeratore1 % denominatore1 == 0 && numeratore2 % denominatore2 != 0) {
                                cout << "\nx(1) = " << "\033[1m" << numeratore1 << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore2 << "/" << denominatore2 << "\033[0m";
                            } else {
                                cout << "\nx(1) = " << "\033[1m" << numeratore1 << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore2 << "\033[0m";
                            }
                        } else if (delta == 0) {
                            numeratore1 = -b;
                            denominatore1 = 2 * a;

                            mcd1 = abs(numeratore1);
                            mcd2 = abs(denominatore1);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il primo numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            numeratore1 = numeratore1 / mcd2;
                            denominatore1 = denominatore1 / mcd2;

                            if (numeratore1 % denominatore1 != 0)
                                cout << "\nx(1) e x(2) = " << "\033[1m" << numeratore1 << "/" << denominatore1 << "\033[0m\n";
                            else 
                                cout << "\nx(1) e x(2) = " << "\033[1m" << numeratore1 << "\033[0m";
                        } else {
                            cout << "\n\033[31mNon sono presenti soluzioni per questo polinomio!\033[0m";
                        }
                    } else {
                        termineNoto = polinomio1[MAX - 4], terminePrimoGrado = polinomio1[MAX - 3];
			            isImpossibile = false, isIndeterminato = false;

                        if (termineNoto > 0 && terminePrimoGrado > 0) {
                            termineNoto = -termineNoto;
                        } else if (termineNoto < 0 && terminePrimoGrado > 0) {
                            termineNoto = abs(termineNoto);
                        } else if ((termineNoto > 0 && terminePrimoGrado < 0) || (termineNoto < 0 && terminePrimoGrado < 0)) {
                            terminePrimoGrado = abs(terminePrimoGrado);
                        } else if (termineNoto == 0 && terminePrimoGrado == 0) {
                            isIndeterminato = true;
                        } else if (termineNoto != 0 && terminePrimoGrado == 0) {
                            isImpossibile = true;
                        }

                        if (!isImpossibile && !isIndeterminato) {
                            mcd1 = abs(termineNoto);
                            mcd2 = abs(terminePrimoGrado);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il secondo numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            termineNoto = termineNoto / mcd2;
                            terminePrimoGrado = terminePrimoGrado / mcd2;
                        }

                        if (isIndeterminato) {
                            cout << "\n\033[31mIl polinomio risulta indeterminato!\033[0m\n";
                        } else if (isImpossibile) {
                            cout << "\n\033[31mIl polinomio risulta impossibile!\033[0m";
                        } else if (termineNoto % terminePrimoGrado != 0){
                            cout << "\nx(1) = " << "\033[1m" << termineNoto << "/" << terminePrimoGrado << "\033[0m\n";
                        } else {
                            cout << "\nx(1) = " << "\033[1m" << termineNoto << "\033[0m";
                        } 
                    }
                } else {
                    cout << "\n\033[31mNon e' possibile trovare le soluzioni di un polinomio di 3 grado!\n\033[0m";
                }

                cout << "\n\n\033[32mLe soluzioni/e del secondo polinomio sono/e': \033[0m\n";
                if (polinomio2[MAX - 1] == 0) {
                    if (polinomio2[MAX - 2] != 0) {
                        a = polinomio2[MAX - 2], b = polinomio2[MAX - 3], c = polinomio2[MAX - 4];
                        delta = pow(b, 2) - 4 * a * c;

                        if (pow(sqrt(delta), 2) != delta && delta > 0) { // verifica se la radice è perfetta o meno
                            parteInterna = 1, parteEsterna = 1, numeratore = -b, denominatore = 2 * a;

                            n = delta;

                            // Semplificazione della radice
                            for (int i = 2; i <= delta; i++) {
                                cont = 0; 

                                while (n % i == 0) {
                                    n /= i;
                                    cont++;
                                }

                                if (cont > 0) {
                                    if (cont % 2 == 0) {
							            parteEsterna *= pow(i, cont / 2);
                                    } else {
                                        if (cont > 1)
                                            parteEsterna *= pow(i, cont / 2);
                                        parteInterna *= i;
                                    }
                                }
                            }

                            mcd1 = abs(numeratore);
				            mcd2 = abs(parteEsterna);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            numeratore = numeratore / mcd2;
				            parteEsterna = parteEsterna / mcd2;

                            mcd1 = abs(mcd2);
				            mcdDenominatore = abs(denominatore);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra mcd del numeratore e la parte esterna e il denominarore
                            while (mcd1 % mcdDenominatore > 0) {
                                resto = mcd1 % mcdDenominatore;
                                mcd1 = mcdDenominatore;

                                if (resto != 0)
                                    mcdDenominatore = resto;
                            }

                            mcd2 = mcd2 / mcdDenominatore;
				            denominatore = denominatore / mcdDenominatore;

                            // Gestione output delle soluzione del polinomio di secondo grado
                            if (denominatore == 1 && b == 0) {
                                cout << "\nx(1) = " << "\033[1m" << " + " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << " - " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\033[0m\n";
                            } else if (mcd2 % denominatore != 0) {
                                cout << "\nx(1) = "  << "\033[1m" << "(" << mcd2 * numeratore << " + " << parteEsterna * mcd2 << "*" <<"sqrt(" << parteInterna << ")" << ")" << "/" << denominatore << "\033[0m\n";
                                cout <<  "\nx(2) = " << "\033[1m" << "(" << mcd2 * numeratore << " - " << parteEsterna * mcd2 << "*" <<"sqrt(" << parteInterna << ")" << ")" << "/" << denominatore << "\033[0m";
                            } else {
                                cout << "\nx(1) = " << "\033[1m" << numeratore << " + " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore << " - " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\033[0m";
                            }
                        } else if (delta > 0) {
                            numeratore1 = -b + sqrt(delta);
                            numeratore2 = -b - sqrt(delta);

                            denominatore1 = 2 * a;
                            denominatore2 = 2 * a;

                            mcd1 = abs(numeratore1);
                            mcd2 = abs(denominatore1);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il primo numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            numeratore1 = numeratore1 / mcd2;
                            denominatore1 = denominatore1 / mcd2;

                            mcd1 = abs(numeratore2);
                            mcd2 = abs(denominatore2);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il secondo numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            numeratore2 = numeratore2 / mcd2;
                            denominatore2 = denominatore2 / mcd2;

                            // Gestione output delle soluzioni del polinomio di secondo grado
                            if (numeratore1 % denominatore1 != 0 && numeratore2 % denominatore2 != 0) {
                                cout << "\nx(1) = " << "\033[1m" << numeratore1 << "/" << denominatore1 << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore2 << "/" << denominatore2 << "\033[0m";
                            } else if (numeratore1 % denominatore1 != 0 && numeratore2 % denominatore2 == 0) {
                                cout << "\nx(1) = " << "\033[1m" << numeratore1 << "/" << denominatore1 << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore2 << "\033[0m";
                            } else if (numeratore1 % denominatore1 == 0 && numeratore2 % denominatore2 != 0) {
                                cout << "\nx(1) = " << "\033[1m" << numeratore1 << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore2 << "/" << denominatore2 << "\033[0m";
                            } else {
                                cout << "\nx(1) = " << "\033[1m" << numeratore1 << "\033[0m\n";
                                cout << "\nx(2) = " << "\033[1m" << numeratore2 << "\033[0m";
                            }
                        } else if (delta == 0) {
                            numeratore1 = -b;
                            denominatore1 = 2 * a;

                            mcd1 = abs(numeratore1);
                            mcd2 = abs(denominatore1);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il primo numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            numeratore1 = numeratore1 / mcd2;
                            denominatore1 = denominatore1 / mcd2;

                            if (numeratore1 % denominatore1 != 0)
                                cout << "\nx(1) e x(2) = " << "\033[1m" << numeratore1 << "/" << denominatore1 << "\033[0m\n";
                            else 
                                cout << "\nx(1) e x(2) = " << "\033[1m" << numeratore1 << "\033[0m";
                        } else {
                            cout << "\n\033[31mNon sono presenti soluzioni per questo polinomio!\033[0m";
                        }
                    } else {
                        termineNoto = polinomio2[MAX - 4], terminePrimoGrado = polinomio2[MAX - 3];
			            isImpossibile = false, isIndeterminato = false;

                        if (termineNoto > 0 && terminePrimoGrado > 0) {
                            termineNoto = -termineNoto;
                        } else if (termineNoto < 0 && terminePrimoGrado > 0) {
                            termineNoto = abs(termineNoto);
                        } else if ((termineNoto > 0 && terminePrimoGrado < 0) || (termineNoto < 0 && terminePrimoGrado < 0)) {
                            terminePrimoGrado = abs(terminePrimoGrado);
                        } else if (termineNoto == 0 && terminePrimoGrado == 0) {
                            isIndeterminato = true;
                        } else if (termineNoto != 0 && terminePrimoGrado == 0) {
                            isImpossibile = true;
                        }

                        if (!isImpossibile && !isIndeterminato) {
                            mcd1 = abs(termineNoto);
                            mcd2 = abs(terminePrimoGrado);

                            // Algoritmo di Euclide utilizzato per calcolare MCD tra il secondo numeratore e il denominarore
                            while (mcd1 % mcd2 > 0) {
                                resto = mcd1 % mcd2;
                                mcd1 = mcd2;

                                if (resto != 0)
                                    mcd2 = resto;
                            }

                            termineNoto = termineNoto / mcd2;
                            terminePrimoGrado = terminePrimoGrado / mcd2;
                        }

                        if (isIndeterminato) {
                            cout << "\n\033[31mIl polinomio risulta indeterminato!\033[0m";
                        } else if (isImpossibile) {
                            cout << "\n\033[31mIl polinomio risulta impossibile!\033[0m";
                        } else if (termineNoto % terminePrimoGrado != 0){
                            cout << "\nx(1) = " << "\033[1m" << termineNoto << "/" << terminePrimoGrado << "\033[0m\n";
                        } else {
                            cout << "\nx(1) = " << "\033[1m" << termineNoto << "\033[0m";
                        } 
                    }
                } else {
                    cout << "\n\033[31mNon e' possibile trovare le soluzioni di un polinomio di 3 grado!\033[0m";
                }

                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            case '6':
                system("cls");
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
                cout << "\033[36m|"<< "\033[1m              RICERCA E VISUALIZZAZIONE DEI PUNTI DI INTERSEZIONE              " << "\033[1m|\033[0m\n";
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";

                // Calcolo della differnza dei due polinomi
                for (int i = MAX - 1; i >= 0; i--) {
                    polinomioDifferenza[i] = polinomio1[i] - polinomio2[i];
                }

                cout << "\033[32mQuesti sono i polinomi che sono stati inseriti dall'utente: \033[0m\n\n";

                cout << "y = ";
                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio1[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio1[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";

                if (isZero) {
                    cout << "\033[1m" << 0 << "\033[0m";
                }

                isZero = true;

                cout << "  y = ";

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                            cout << abs(polinomio2[i]) << "x^" << i << " ";
                        } else {
                            cout << abs(polinomio2[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";

                if (isZero) {
                    cout << "\033[1m" << 0 << "\033[0m";
                }

                cout << "\n\n\033[32mIl punto di intersezione dei seguenti polinomi e': \033[0m\n\n";

                if (polinomioDifferenza[MAX - 1] == 0) {
                    if (polinomioDifferenza[MAX - 2] != 0) {
                        aDecimal = polinomioDifferenza[MAX - 2], bDecimal = polinomioDifferenza[MAX - 3], cDecimal = polinomioDifferenza[MAX - 4];
                        y1 = 0, y2 = 0;
                        deltaDecimal = pow(bDecimal, 2) - 4 * aDecimal * cDecimal;

                        if (deltaDecimal > 0) {
                            x1 = (-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal);
                            x2 = (-bDecimal - sqrt(deltaDecimal)) / (2 * aDecimal);

                            for (int i = MAX - 2; i >= 0; i--) {
                                if (polinomio1[i] != 0) {
                                    // i deve essere diverso da zero per evitare situzine 0^0
                                    if (i != 0) {
                                        y1 += pow(x1, i) * polinomio1[i];
                                        y2 += pow(x2, i) * polinomio1[i];
                                    } else {
                                        y1 += polinomio1[i];
                                        y2 += polinomio1[i];
                                    }
                                }
                            }

                            cout << "P(1)(x, y) = " << "(" << "\033[1m" << x1 << ", " << y1 << "\033[0m" << ")" << "\n";
                            cout << "P(2)(x, y) = " << "(" << "\033[1m" << x2 << ", " << y2 << "\033[0m" << ")";

                        } else if (deltaDecimal == 0) {
                            x1 = -bDecimal / (2 * aDecimal);

                            for (int i = MAX - 2; i >= 0; i--) {
                                if (polinomio1[i] != 0) {
                                    // i deve essere diverso da zero per evitare situzine 0^0
                                    if (i != 0) 
                                        y1 += pow(x1, i) * polinomio1[i];
                                    else 
                                        y1 += polinomio1[i];
                                }
                            }

                            cout << "P(1)(x, y) = " << "(" << "\033[1m" << x1 << ", " << y1 << "\033[0m" << ")" << "\n";
                        } else {
                            cout << "\033[31mI due polinomi non si intersecano in nessun punto!\033[0m";
                        }
                    } else {
                        isImpossibile = false, isIndeterminato = false;
                        termineNotoDecimal = polinomioDifferenza[MAX - 4], terminePrimoGradoDecimal = polinomioDifferenza[MAX - 3];
                        y1 = 0;

                        if (termineNotoDecimal > 0 && terminePrimoGradoDecimal > 0) {
                            termineNotoDecimal = -termineNotoDecimal;
                        } else if (termineNotoDecimal < 0 && terminePrimoGradoDecimal > 0) {
                            termineNotoDecimal = abs(termineNotoDecimal);
                        } else if ((termineNotoDecimal > 0 && terminePrimoGradoDecimal < 0) || (termineNotoDecimal < 0 && terminePrimoGradoDecimal < 0)) {
                            terminePrimoGradoDecimal = abs(terminePrimoGradoDecimal);
                        } else if (termineNotoDecimal == 0 && terminePrimoGradoDecimal == 0) {
                            isIndeterminato = true;
                        } else if (termineNotoDecimal != 0 && terminePrimoGradoDecimal == 0) {
                            isImpossibile = true;
                        }

                        if (isIndeterminato) {
                            if (polinomio1[MAX - 2] != 0 && polinomio2[MAX - 2] != 0) {
                                cout << "\033[31mLe due parabole sono coincidenti!\033[0m";
                            } else {
                                cout << "\033[31mLe due rette sono coincidenti!\033[0m";
                            }
                        } else if (isImpossibile) {
                            cout << "\033[31mLe due rette sono parallele!\033[0m";
                        } else {
                            x1 = termineNotoDecimal / terminePrimoGradoDecimal;

                            for (int i = MAX - 2; i >= 0; i--) {
                                if (polinomio1[i] != 0) {
                                    // i deve essere diverso da zero per evitare situzine 0^0
                                    if (i != 0) 
                                        y1 += pow(x1, i) * polinomio1[i];
                                    else 
                                        y1 += polinomio1[i];
                                }
                            }

                            cout << "P(1)(x, y) = " << "\n(" << "\033[1m" << x1 << ", " << y1 << "\033[0m" << ")" << "\n";
                        }
                    }
                } else {
                    cout << "\031[31mNon e' possibile trovare il punto di intersezione perché e' presente un polinomio di 3 grado!\033[0m";
                }
                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            case '7':
            	initgraph(&graphDriver, &graphMode, "", 640, 520);
            	getchg();
            	closegraph();
            	break;
            case '8': 
                isRunning = false;
                break;
            default:
                cout << "\033[31mL'opzione inserita non e' disponibile. Riprovare per favore!\033[0m\n";
                break;
        }
    }

    system("pause");
    return 0;
}
