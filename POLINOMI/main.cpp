#include <iostream>
#include <cmath> // Per abs() e pow()
#include <conio.h> // Per getch()
#include "graphics2.h" // Per la funziona grafica
#include <cstdlib> // Per tolower()
#include <windows.h> // Per ShowWindow();
#include <string>
using namespace std;

/*
    Questo progetto e' stato fatto principalamente per la risoluzione dei polinomi cha hanno un grado compreso tra 0 e 3.

    Questo programma permette di: 
    0. Inserire i due polinomi
    1. Sommare due polinomi;
    2. Sottrare due polinomi;
    3. Moltiplicare due polinomi;
    4. Cercare gli zeri dei due polinomi;
    5. Cercare il loro punto di intersezione;
    6. Rappresentarli graficamente;
*/

int main() {
    // Costanti per stabilire il range massimo dei polinomi
    const int MAX = 4, MAX2 = 16;
    
    // Costanti per la grandezza della finstra
    const int WIDTH = 759, HEIGHT = 659;
    
    // Variabili utilizzati per stabilire i gradi massimi dei vari polinomi
    int gradoMaxPolinomio1, gradoMaxPolinomio2, gradoMax, index;

    // Array che contengono i valori dei due polinomi
    int polinomio1[MAX]{0}, polinomio2[MAX]{0};

    // Array che contengono i valori delle operazioni tra il primo e il secondo polinomio
    int polinomioSomma[MAX]{0}, polinomioDifferenza[MAX]{0}, gradoPolinomio[MAX2]{0}, polinomioProdotto[MAX2]{0}, polinomioProdottoSomma[MAX2]{0};

    // Variabili utilizzati per la risoluzione di un'equazione di primo grado
    int termineNoto, terminePrimoGrado;
    bool isImpossibile, isIndeterminato;

    // Variabili utilizzati per trovare i punti di intersezione e per la risoluzione di un equazione di secondo grado
    float deltaDecimal, x1, x2, y1, y2, aDecimal, bDecimal, cDecimal, termineNotoDecimal, terminePrimoGradoDecimal;
    
    // Punti prestabiliti per il grafico
    float punti[4096];
    int valori; // Per determinare il numero di punti che vuoi inserire nel grafica
    
    // Variabili per la graphica
    int graphDriver = 0, graphMode = 0;

	// Stringhe utilizzate per la visualizzazione dei polinomi nella finestra del grafico
	string pol1, pol2;

    char opzione, userExit, opzioneGrafica;
    bool isFirstTime = true, isRunning = true, isZero, isFailed;

    cout.precision(3); // Stabili 3 numeri significativi in caso dei numeri decimali

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
                cout << "\033[3mInserisci il grado massimo del primo polinomio:       \033[0m";
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
                        cout << "\033[3m\nInserisci il coefficiente di grado x^" << i << ":       \033[0m";
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
                        cout << "\033[3m\nInserisci il termine noto:       \033[0m";
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
            cout << "\n\n\033[32mP(1): \033[0m";
            
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
                cout << "\n\033[3mInserisci il grado massimo del secondo polinomio:       \033[0m";
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
                        cout << "\n\033[3mInserisci il coefficiente di grado x^" << i << ":       \033[0m";
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
                        cout << "\n\033[3mInserisci il termine noto:       \033[0m";
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
            cout << "\n\n\033[32mP(2): \033[0m";
        
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
        cout << "\033[36m" << "|  \033[32m[5]\033[0m" << " Ricerca e visualizzazione degli zeri                                     " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[6]\033[0m" << " Ricerca e visualizzazione dei punti di intersezione                      " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[7]\033[0m" << " Rappresentazione grafica dei polinomi                                    " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[8]\033[0m" << " Esci dal programma                                                       " << "\033[36m|\n";
        cout << "\033[36m" << "---------------------------------------------------------------------------------\033[0m\n\n";

        cout << "\033[1m Scegli un opzione \033[36m\n>>\033[0m ";
        opzione = getch();

        switch (opzione) {
            case '1': {
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
                    cout << "\033[3mInserisci il grado massimo del primo polinomio:       \033[0m";
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
                            cout << "\n\033[3mInserisci il coefficiente di grado x^" << i << ":       \033[0m";
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
                            cout << "\n\033[3mInserisci il termine noto:       \033[0m";
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
                cout << "\n\n\033[32mP(1): \033[0m";
                
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
                    cout << "\n\033[3mInserisci il grado massimo del secondo polinomio:       \033[0m";
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
                            cout << "\n\033[3mInserisci il coefficiente di grado x^" << i << ":       \033[0m";
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
                            cout << "\n\033[3mInserisci il termine noto:       \033[0m";
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
                cout << "\n\n\033[32mP(2): \033[0m";
                
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
       	 	}
            case '2': {
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
        	}
            case '3': {
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
        	}
            case '4': {
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
            }
            case '5': {
                system("cls");
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
                cout << "\033[36m|"<< "\033[1m                     RICERCA E VISUALIZZAZIONE DEGLI ZERI                      " << "\033[1m|\033[0m\n";
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";
                
                cout << "\033[32mQuesti sono i polinomi che hai inserito: \033[0m\n\n";
                isZero = true;

                cout << "P(1) = ";
                
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

                cout << "  P(2) = ";

				// assegna il segno (+, -) al primo numero del primo polinomio
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

                if (isZero) {
                    cout << "\033[1m" << 0 << "\033[0m";
                }

                cout << "\n\n\033[32mLe soluzioni/e del P(1) sono/e': \033[0m\n";
                if (polinomio1[MAX - 1] == 0) {
                    if (polinomio1[MAX - 2] != 0) {
                        aDecimal = polinomio1[MAX - 2], bDecimal = polinomio1[MAX - 3], cDecimal = polinomio1[MAX - 4];
                
                        deltaDecimal = pow(bDecimal, 2) - 4 * cDecimal * aDecimal;
					
						if (deltaDecimal > 0) {
							x1 = (-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal);
                        	x2 = (-bDecimal - sqrt(deltaDecimal)) / (2 * aDecimal);
                        	
                        	// Gestione output delle soluzioni del polinomio di secondo grado
                        	cout << "\nx(1) = " << "\033[1m" << x1 <<"\033[0m";
                        	cout << "\nx(2) = " << "\033[1m" << x2 <<"\033[0m";
                        } else if (deltaDecimal == 0) {
                        	x1 = (-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal);

							cout << "\nx(1) e x(2) = " << "\033[1m" << x1 << "\033[0m";
                        } else {
                            cout << "\n\033[31mNon sono presenti soluzioni per questo polinomio!\033[0m";
                        }
                    } else {
                        termineNotoDecimal = polinomio1[MAX - 4], terminePrimoGradoDecimal = polinomio1[MAX - 3];
			            isImpossibile = false, isIndeterminato = false;

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
                            cout << "\n\033[31mIl polinomio risulta indeterminato!\033[0m";
                        } else if (isImpossibile) {
                            cout << "\n\033[31mIl polinomio risulta impossibile!\033[0m";
                        } else {
                            cout << "\nx(1) = " << "\033[1m" << termineNotoDecimal / terminePrimoGradoDecimal << "\033[0m";
                        } 
                    }
                } else {
                    cout << "\n\033[31mNon e' possibile trovare le soluzioni di un polinomio di 3 grado!\n\033[0m";
                }

                cout << "\n\n\033[32mLe soluzioni/e del P(2) sono/e': \033[0m\n";
                if (polinomio2[MAX - 1] == 0) {
                    if (polinomio2[MAX - 2] != 0) {
                        aDecimal = polinomio2[MAX - 2], bDecimal = polinomio2[MAX - 3], cDecimal = polinomio2[MAX - 4];
                
                        deltaDecimal = pow(bDecimal, 2) - 4 * cDecimal * aDecimal;

                        if (deltaDecimal > 0) {
                            x1 = (-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal);
                        	x2 = (-bDecimal - sqrt(deltaDecimal)) / (2 * aDecimal);
                        	
                        	// Gestione output delle soluzioni del polinomio di secondo grado
                        	cout << "\nx(1) = " << "\033[1m" << x1 <<"\033[0m\n";
                        	cout << "\nx(2) = " << "\033[1m" << x2 <<"\033[0m\n";
                        } else if (deltaDecimal == 0) {
                            x1 = (-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal);

							cout << "\nx(1) e x(2) = " << "\033[1m" << x1 << "\033[0m\n";
                        } else {
                            cout << "\n\033[31mNon sono presenti soluzioni per questo polinomio!\033[0m";
                        }
                	} else {
                        termineNotoDecimal = polinomio2[MAX - 4], terminePrimoGradoDecimal = polinomio2[MAX - 3];
			            isImpossibile = false, isIndeterminato = false;

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
                            cout << "\n\033[31mIl polinomio risulta indeterminato!\033[0m";
                        } else if (isImpossibile) {
                            cout << "\n\033[31mIl polinomio risulta impossibile!\033[0m";
                        } else {
                            cout << "\nx(1) = " << "\033[1m" << termineNotoDecimal / terminePrimoGradoDecimal << "\033[0m";
                        } 
                	}
                } else {
                    cout << "\n\033[31mNon e' possibile trovare le soluzioni di un polinomio di 3 grado!\033[0m";
                }

                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            }
            case '6': {
                system("cls");
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
                cout << "\033[36m|"<< "\033[1m              RICERCA E VISUALIZZAZIONE DEI PUNTI DI INTERSEZIONE              " << "\033[1m|\033[0m\n";
                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";

                // Calcolo della differnza dei due polinomi
                for (int i = MAX - 1; i >= 0; i--) {
                    polinomioDifferenza[i] = polinomio1[i] - polinomio2[i];
                }

                cout << "\033[32mQuesti sono i polinomi che sono stati inseriti dall'utente: \033[0m\n\n";
                isZero = true;

                cout << "P(1) = ";
                
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

                cout << "  P(2) = ";

				// assegna il segno (+, -) al primo numero del primo polinomio
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

                            cout << "1: (x, y) = " << "(" << "\033[1m" << x1 << ", " << y1 << "\033[0m" << ")" << "\n";
                            cout << "2: (x, y) = " << "(" << "\033[1m" << x2 << ", " << y2 << "\033[0m" << ")";

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

                            cout << "1: (x, y) = " << "(" << "\033[1m" << x1 << ", " << y1 << "\033[0m" << ")" << "\n";
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

                            cout << "1: (x, y) = " << "(" << "\033[1m" << x1 << ", " << y1 << "\033[0m" << ")" << "\n";
                        }
                    }
                } else {
                    cout << "\033[31mNon e' possibile trovare il punto di intersezione perche' e' presente un polinomio di 3 grado!\033[0m";
                }
                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            }
            case '7': {
        		system("cls");
	            cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
	            cout << "\033[36m|"<< "\033[1m                            RAPPRESENTAZIONE GRAFICA                           " << "\033[1m|\033[0m\n";
	            cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";
        		
        		cout << "\033[31mSi consiglia di far generare piu' di 5 punti (-5, 5) per una migliore visualizzazione dei polinomi.\033[0m\n";
        		cout << "\033[31mSe si vuole chiudere la finestra del grafico premere un qualsiasi tasto. NON CHIUDERE LA FINESTRA CON LA X!\033[0m\n";
        		cout << "\033[31mAlcuni polinomi non saranno ben rappresentati perche' alcuni di essi crescescono di valore molto rapidamente.\033[0m\n\n";
            	
            	index = 0;
            	pol1 = "", pol2 = "";
            	
            	
            	/*
					1. opzione punto di intersezione
					2. Direttrice e fuoco e vertice 
					3. Cercare dati su la funzione di secondo grado
				*/
            	
        		cout << "\033[1mQuanti punti vorresti generare? \033[0m";
        		cin >> valori;
            	
            	// punti che vanno da -n a n
            	for (float i = -valori; i <= valori; i += 0.2) {
            		punti[index] = i;
            		index++;
				}
            	
            	initgraph(&graphDriver, &graphMode, "", WIDTH, HEIGHT);

            	setcolor(WHITE); // imposta il colore degli assi a bianco
            	line(WIDTH / 2, 0, WIDTH / 2, HEIGHT); // Asse delle ordinate
            	line(0, HEIGHT / 2, WIDTH, HEIGHT / 2); // Asse delle ascisse
            	
            	// Rappresentazione grafica del primo polinomio
            	
            	// Inserisci i punti all'interno del grafico
            	setcolor(GREEN); // imposta il colore del primo polinomio a rosso
            	for (int i = 0; i < index; i++) {
            		y1 = 0;
            		for (int j = gradoMaxPolinomio1; j >= 0; j--) {
            			if (polinomio1[j] != 0) {
                            // i deve essere diverso da zero per evitare situzine 0^0
                            if (j != 0) 
                                y1 += pow(punti[i], j) * polinomio1[j];
                            else 
                                y1 += polinomio1[j];
                        }
                        
					}
					if (WIDTH / 2 + punti[i] * 24 < WIDTH && HEIGHT / 2 + y1 * 24 * - 1 < HEIGHT) {
						circle(WIDTH / 2 + punti[i] * 24, HEIGHT / 2 + y1 * 24 * - 1, 3);
					}
				}
				
				// Rappresentazione grafica del secondo polinomio
            	
            	// Inserisci i punti all'interno del grafico
            	setcolor(YELLOW); // imposta il colore del secondo polinomio a giallo
            	for (int i = 0; i < index; i++) {
            		y1 = 0;
            		for (int j = gradoMaxPolinomio2; j >= 0; j--) {
            			if (polinomio2[j] != 0) {
                            // i deve essere diverso da zero per evitare situzine 0^0
                            if (j != 0) 
                                y1 += pow(punti[i], j) * polinomio2[j];
                            else 
                                y1 += polinomio2[j];
                        }
                        
					}
					if (WIDTH / 2 + punti[i] * 24 < WIDTH && HEIGHT / 2 + y1 * 24 * - 1 < HEIGHT) {
						circle(WIDTH / 2 + punti[i] * 24, HEIGHT / 2 + y1 * 24 * - 1, 3);
					}
				}
				
				// Creazione della stringa contenente il primo polinomio
				pol1 += "P(1) = ";
				
				if (polinomio1[gradoMaxPolinomio1] != 0) {
                    if (polinomio1[gradoMaxPolinomio1] > 0) {
                    	pol1 += "+";
					} else {
						pol1 += "-";
					}
                }
				
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                        	pol1 += to_string(abs(polinomio1[i])) + "x^" + to_string(i) + " ";
                        } else {
                            pol1 += to_string(abs(polinomio1[i]));
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        if (polinomio1[i - 1] > 0) {
                        	pol1 += "+ ";
						} else {
							pol1 += "- ";
						}
                    }
                }
                
                setcolor(GREEN);
                outtextxy(450, 600, pol1.c_str());
                
                // Creazione della stringa contenente il secondo polinomio
                pol2 += "P(2) = ";
				
				if (polinomio2[gradoMaxPolinomio2] != 0) {
                    if (polinomio2[gradoMaxPolinomio2] > 0) {
                    	pol2 += "+";
					} else {
						pol2 += "-";
					}
                }
				
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        isZero = false;
                        if (i != 0) {
                        	pol2 += to_string(abs(polinomio2[i])) + "x^" + to_string(i) + " ";
                        } else {
                            pol2 += to_string(abs(polinomio2[i]));
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        if (polinomio2[i - 1] > 0) {
                        	pol2 += "+ ";
						} else {
							pol2 += "- ";
						}
                    }
                }
                
                setcolor(YELLOW);
                outtextxy(450, 620, pol2.c_str());
				
				ShowWindow(GetConsoleWindow(), SW_HIDE);
            	getchg();
            	ShowWindow(GetConsoleWindow(), SW_SHOW);
            	closegraph();
            	system("cls");
            	break;
        	}
            case '8': {
            	system("cls");
            	cout << "Sei sicuro di voler uscire? (\033[32my\033[0m, \033[31mN\033[0m);\n";
            	cin >> userExit;
            	
            	if (tolower(userExit) != 'n') {
            		system("cls");
	                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
	                cout << "\033[36m|"<< "\033[1m                GRAZIE PER AVER PROVATO IL NOSTRO PROGRAMMA!                   " << "\033[1m|\033[0m\n";
	                cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n\n";
	                
	                isRunning = false;
				} else {
					system("cls");
				}
                break;
        	}
            default: {
            	system("cls");
                cout << "\033[31mL'opzione inserita non e' disponibile. Riprovare per favore!\033[0m\n";
                break;
        	}
        }
    }
    return 0;
}
