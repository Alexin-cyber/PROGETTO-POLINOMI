#include <iostream>
#include <cmath> // Per abs() e pow()
#include <conio.h> // Per getch()
#include "graphics2.h" // Per la funziona grafica
#include <cstdlib> // Per tolower()
#include <windows.h> // Per ShowWindow();
#include <string> // Per to_string()
using namespace std;

/*
    Questo progetto e' stato fatto principalamente per la risoluzione dei polinomi cha hanno un grado compreso tra 0 e 3.

    Questo programma permette di: 
    0. Inserire i due polinomi
    1. Sommare due polinomi: P(1) + P(2);
    2. Sottrare due polinomi: P(1) - P(2);
    3. Moltiplicare due polinomi: P(1) * P(2);
    4. Cercare gli zeri dei due polinomi: P(x) = 0;
    5. Cercare il loro punto di intersezione;
    6. Rappresentarli graficamente;

*/

int main() {
    // Costanti per stabilire il range massimo degli array
    const int MAX = 4, MAX2 = 16, MAX3 = 7;
    
    // Costanti per la dimensione della finestra della grafica
    const int WIDTH = 667, HEIGHT = 667;
    
    // Variabili per stabilire i gradi massimi dei vari polinomi
    int gradoMaxPolinomio1, gradoMaxPolinomio2, gradoMax, index;

    // Array che contengono i valori dei due polinomi inseriti dall'utente
    int polinomio1[MAX]{0}, polinomio2[MAX]{0};

    // Array che contengono i valori delle operazioni
    int polinomioSomma[MAX]{0}, polinomioDifferenza[MAX]{0}, gradoPolinomio[MAX2]{0}, polinomioProdotto[MAX3]{0}, polinomioProdottoSomma[MAX2]{0};

    // Variabili per la risoluzione di un'equazione di primo grado
    int termineNoto, terminePrimoGrado;
    bool isImpossibile, isIndeterminato;

    // Variabili per trovare i punti di intersezione e per la risoluzione di un equazione di secondo grado
    double deltaDecimal, x1, x2, y1, y2, yGrafica, aDecimal, bDecimal, cDecimal, termineNotoDecimal, terminePrimoGradoDecimal;
    
    // Variabili che contegono i punti che servono per rappresentare i polinomi
    double punti[150];
    
    // Variabili per la creazione della finestra per la grafica
    int graphDriver = 0, graphMode = 0;

	// Stringhe utilizzate per la visualizzazione di testo nella grafica
	string pol1, pol2;

    // Variabili per la gestione degli errori e del corretto funzionamento del programma
    char opzione, userExit, userChoice;
    bool isFirstTime = true, isRunning = true, isFailed;

    // Considera solo 3 numeri significati per (double)
    cout.precision(3); 

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
                            cin.clear();
                            cin.ignore(1000, '\n');
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
                            cin.clear();
                            cin.ignore(1000, '\n');
                            isFailed = true;

                            cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                        } 
                    } while (isFailed);
                }
            }
            
            // Gestione output del primo polinomio
            cout << "\n\n\033[32mP(1): \033[0m";
            
            if (polinomio1[MAX - 1] == 0 && polinomio1[MAX - 2] == 0 && polinomio1[MAX - 3] == 0 && polinomio1[MAX - 4] == 0) {
                cout << "\033[1m" << 0 << "\033[0m\n";
            } else {
                // assegna il segno (+, -) al primo numero del primo polinomio
                if (polinomio1[gradoMaxPolinomio1] != 0) {
                    cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                }
                
                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
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
                cout << "\033[0m\n";
            }

            do {
                isFailed = false;
                cout << "\n\033[3mInserisci il grado massimo del secondo polinomio:       \033[0m";
                cin >> gradoMaxPolinomio2;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
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

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            isFailed = true;

                            cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                        }
                    } while (isFailed);
                } else {
                    do {
                        isFailed = false;
                        cout << "\n\033[3mInserisci il termine noto:       \033[0m";
                        cin >> polinomio2[i];

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            isFailed = true;

                            cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                        }
                    } while (isFailed);
                }
            }
            
            // Gestione output del primo polinomio
            cout << "\n\n\033[32mP(2): \033[0m";
        
            if (polinomio2[MAX - 1] == 0 && polinomio2[MAX - 2] == 0 && polinomio2[MAX - 3] == 0 && polinomio2[MAX - 4] == 0) {
                cout << "\033[1m" << 0 << "\033[0m";
            } else {
                // assegna il segno (+, -) al primo numero del secondo polinomio
                if (polinomio2[gradoMaxPolinomio2] != 0) {
                    cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
                }
                
                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
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
            }

            cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
	        getch();
	        system("cls");
            isFirstTime = false;
        }

        cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
        cout << "\033[36m|"<< "\033[1m                                 MENU PRINCIPALE                               " << "\033[1m|\033[0m\n";
        cout << "\033[36m" << "---------------------------------------------------------------------------------" << "\033[0m\n";
        cout << "\033[36m" << "|  \033[32m[1]\033[0m" << " Acquisizione dei polinomi                                                " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[2]\033[0m" << " Somma di polinomi -> P(1) + P(2)                                         " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[3]\033[0m" << " Differenza di polinomi -> P(1) - P(2)                                    " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[4]\033[0m" << " Prodotto di polinomi -> P(1) * P(2)                                      " << "\033[36m|\n";
        cout << "\033[36m" << "|  \033[32m[5]\033[0m" << " Ricerca e visualizzazione degli zeri -> P(x) = 0                         " << "\033[36m|\n";
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

                do {
                    isFailed = false;
                    cout << "\033[3mInserisci il grado massimo del primo polinomio:       \033[0m";
                    cin >> gradoMaxPolinomio1;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        isFailed = true;

                        cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                    } else if (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0) {
                        cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                    }
                } while (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0 || isFailed);

                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (i > 0) {
                        do {
                            isFailed = false;
                            cout << "\n\033[3mInserisci il coefficiente di grado x^" << i << ":       \033[0m";
                            cin >> polinomio1[i];

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
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
                                cin.clear();
                                cin.ignore(1000, '\n');
                                isFailed = true;

                                cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                            } 
                        } while (isFailed);
                    }
                }

                cout << "\n\n\033[32mP(1): \033[0m";
                
                if (polinomio1[MAX - 1] == 0 && polinomio1[MAX - 2] == 0 && polinomio1[MAX - 3] == 0 && polinomio1[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m\n";
                } else {

                    if (polinomio1[gradoMaxPolinomio1] != 0) {
                        cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                        if (polinomio1[i] != 0) {
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
                    cout << "\033[0m\n";
                }

                do {
                    isFailed = false;
                    cout << "\n\033[3mInserisci il grado massimo del secondo polinomio:       \033[0m";
                    cin >> gradoMaxPolinomio2;
                    
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        isFailed = true;

                        cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                    } else if (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0) {
                        cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                    }
                        
                } while (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0 || isFailed);
            
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (i > 0) {
                        do {
                            isFailed = false;
                            cout << "\n\033[3mInserisci il coefficiente di grado x^" << i << ":       \033[0m";
                            cin >> polinomio2[i];

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                isFailed = true;

                                cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                            }
                        } while (isFailed);
                    } else {
                        do {
                            isFailed = false;
                            cout << "\n\033[3mInserisci il termine noto:       \033[0m";
                            cin >> polinomio2[i];

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                isFailed = true;

                                cout << "\033[31mAttenzione! Il programma non accetta caratteri o altro, ma solo NUMERI! Riprova!\033[0m\n";
                            }
                        } while (isFailed);
                    }
                }

                cout << "\n\n\033[32mP(2): \033[0m";
                
                if (polinomio2[MAX - 1] == 0 && polinomio2[MAX - 2] == 0 && polinomio2[MAX - 3] == 0 && polinomio2[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio2[gradoMaxPolinomio2] != 0) {
                        cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                        if (polinomio2[i] != 0) {
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
                }
 
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

                cout << "(";

                if (polinomio1[MAX - 1] == 0 && polinomio1[MAX - 2] == 0 && polinomio1[MAX - 3] == 0 && polinomio1[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio1[gradoMaxPolinomio1] != 0) {
                        cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                        if (polinomio1[i] != 0) {
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
                }

                cout << ") + (";

				if (polinomio2[MAX - 1] == 0 && polinomio2[MAX - 2] == 0 && polinomio2[MAX - 3] == 0 && polinomio2[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio2[gradoMaxPolinomio2] != 0) {
                        cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                        if (polinomio2[i] != 0) {
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
                }

                cout << ") = ";

                if (polinomioSomma[MAX - 1] == 0 && polinomioSomma[MAX - 2] == 0 && polinomioSomma[MAX - 3] == 0 && polinomioSomma[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomioSomma[gradoMax] != 0) {
                        cout << (polinomioSomma[gradoMax] > 0 ? "+" : "-");
                    }

                    cout << "\033[1m";
                    for (int i = gradoMax; i >= 0; i--) {
                        if (polinomioSomma[i] != 0) {
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
                }
				
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

                for (int i = 0; i < MAX; i++) {
                    polinomioDifferenza[i] = 0;
                }
                
                // Calcolo della differnza dei due polinomi
                for (int i = MAX - 1; i >= 0; i--) {
                    polinomioDifferenza[i] = polinomio1[i] - polinomio2[i];
                }
                
                if (gradoMaxPolinomio1 > gradoMaxPolinomio2) {
                    gradoMax = gradoMaxPolinomio1;
                } else {
                    gradoMax = gradoMaxPolinomio2;
                }

                // Gestione output del polinomio differenza
                cout << "\033[32mLa differenza tra i due polinomi equivale a: \033[0m\n\n";

                cout << "(";

                if (polinomio1[MAX - 1] == 0 && polinomio1[MAX - 2] == 0 && polinomio1[MAX - 3] == 0 && polinomio1[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio1[gradoMaxPolinomio1] != 0) {
                        cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                        if (polinomio1[i] != 0) {
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
                }

                cout << ") - (";

				if (polinomio2[MAX - 1] == 0 && polinomio2[MAX - 2] == 0 && polinomio2[MAX - 3] == 0 && polinomio2[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio2[gradoMaxPolinomio2] != 0) {
                        cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                        if (polinomio2[i] != 0) {
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
                }

                cout << ") = ";

                if (polinomioDifferenza[MAX - 1] == 0 && polinomioDifferenza[MAX - 2] == 0 && polinomioDifferenza[MAX - 3] == 0 && polinomioDifferenza[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomioDifferenza[gradoMax] != 0) {
                        cout << (polinomioDifferenza[gradoMax] > 0 ? "+" : "-");
                    }

                    cout << "\033[1m";
                    for (int i = gradoMax; i >= 0; i--) {
                        if (polinomioDifferenza[i] != 0) {
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

                cout << "(";

                if (polinomio1[MAX - 1] == 0 && polinomio1[MAX - 2] == 0 && polinomio1[MAX - 3] == 0 && polinomio1[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio1[gradoMaxPolinomio1] != 0) {
                        cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                        if (polinomio1[i] != 0) {
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
                }

                cout << ") * (";

				if (polinomio2[MAX - 1] == 0 && polinomio2[MAX - 2] == 0 && polinomio2[MAX - 3] == 0 && polinomio2[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio2[gradoMaxPolinomio2] != 0) {
                        cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                        if (polinomio2[i] != 0) {
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
                }

                cout << ") = ";
	
                if (polinomioProdotto[MAX3 - 1] == 0 && polinomioProdotto[MAX3 - 2] == 0 && polinomioProdotto[MAX3 - 3] == 0 && polinomioProdotto[MAX3 - 4] == 0 && polinomioProdotto[MAX3 - 5] == 0 && polinomioProdotto[MAX3 - 6] == 0 && polinomioProdotto[MAX3 - 7] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomioProdotto[index] != 0) {
                        cout << (polinomioProdotto[index] > 0 ? "+" : "-");
                    }

                    cout << "\033[1m";
                    for (int i = gradoMax; i >= 0; i--) {
                        if (polinomioProdotto[index] != 0) {
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

                cout << "P(1) = ";
                
                if (polinomio1[MAX - 1] == 0 && polinomio1[MAX - 2] == 0 && polinomio1[MAX - 3] == 0 && polinomio1[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio1[gradoMaxPolinomio1] != 0) {
                        cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                        if (polinomio1[i] != 0) {
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
                }

                cout << "  P(2) = ";

				if (polinomio2[MAX - 1] == 0 && polinomio2[MAX - 2] == 0 && polinomio2[MAX - 3] == 0 && polinomio2[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio2[gradoMaxPolinomio2] != 0) {
                        cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                        if (polinomio2[i] != 0) {
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
                }

                cout << "\n\n\033[32mLe soluzioni/e del P(1) sono/e': \033[0m\n";
                if (polinomio1[MAX - 1] == 0) {
                    if (polinomio1[MAX - 2] != 0) {
                        aDecimal = polinomio1[MAX - 2], bDecimal = polinomio1[MAX - 3], cDecimal = polinomio1[MAX - 4];
                
                        deltaDecimal = pow(bDecimal, 2) - 4 * cDecimal * aDecimal;

                        // E' stato sommato + 0.0 per evitare che stampi lo zero negativo -> -0
					
						if (deltaDecimal > 0) {
							x1 = ((-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal)) + 0.0;
                        	x2 = ((-bDecimal - sqrt(deltaDecimal)) / (2 * aDecimal)) + 0.0;
                        	
                        	// Gestione output delle soluzioni del polinomio di secondo grado
                        	cout << "\nx(1) = " << "\033[1m" << x1 <<"\033[0m";
                        	cout << "\nx(2) = " << "\033[1m" << x2 <<"\033[0m";
                        } else if (deltaDecimal == 0) {
                        	x1 = (-bDecimal / (2 * aDecimal)) + 0.0;

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
                            x1 = ((-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal)) + 0.0;
                        	x2 = ((-bDecimal - sqrt(deltaDecimal)) / (2 * aDecimal)) + 0.0;
                        	
                        	// Gestione output delle soluzioni del polinomio di secondo grado
                        	cout << "\nx(1) = " << "\033[1m" << x1 <<"\033[0m\n";
                        	cout << "\nx(2) = " << "\033[1m" << x2 <<"\033[0m\n";
                        } else if (deltaDecimal == 0) {
                            x1 = (-bDecimal / (2 * aDecimal)) + 0.0;

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

                for (int i = MAX - 1; i >= 0; i--) {
                    polinomioDifferenza[i] = polinomio1[i] - polinomio2[i];
                }

                cout << "\033[32mQuesti sono i polinomi che sono stati inseriti dall'utente: \033[0m\n\n";

                cout << "P(1) = ";
                
                if (polinomio1[MAX - 1] == 0 && polinomio1[MAX - 2] == 0 && polinomio1[MAX - 3] == 0 && polinomio1[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio1[gradoMaxPolinomio1] != 0) {
                        cout << (polinomio1[gradoMaxPolinomio1] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                        if (polinomio1[i] != 0) {
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
                }

                cout << "  P(2) = ";

				if (polinomio2[MAX - 1] == 0 && polinomio2[MAX - 2] == 0 && polinomio2[MAX - 3] == 0 && polinomio2[MAX - 4] == 0) {
                    cout << "\033[1m" << 0 << "\033[0m";
                } else {
                    if (polinomio2[gradoMaxPolinomio2] != 0) {
                        cout << (polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-");
                    }
                    
                    cout << "\033[1m";
                    for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                        if (polinomio2[i] != 0) {
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
                }

                cout << "\n\n\033[32mIl punto di intersezione dei seguenti polinomi e': \033[0m\n\n";

                if (polinomioDifferenza[MAX - 1] == 0 && polinomio1[MAX - 1] == 0 && polinomio2[MAX - 1] == 0) {
                    if (polinomioDifferenza[MAX - 2] != 0) {
                        aDecimal = polinomioDifferenza[MAX - 2], bDecimal = polinomioDifferenza[MAX - 3], cDecimal = polinomioDifferenza[MAX - 4];
                        y1 = 0, y2 = 0;
                        deltaDecimal = pow(bDecimal, 2) - 4 * aDecimal * cDecimal;

                        if (deltaDecimal > 0) {
                            x1 = ((-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal)) + 0.0;
                            x2 = ((-bDecimal - sqrt(deltaDecimal)) / (2 * aDecimal)) + 0.0;

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
                            x1 = (-bDecimal / (2 * aDecimal)) + 0.0;

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
        		
        		cout << "\033[31mSe si vuole chiudere la finestra del grafico premere un qualsiasi tasto, ma non premere l'icona per chiuderla.\033[0m\n";
        		cout << "\033[31mAlcuni polinomi non saranno ben rappresentati perche' alcuni di essi crescescono di valore molto rapidamente.\033[0m\n";
        		cout << "\033[31mIl punto di intersezione tra i due polinomi verra' indicata con un cerchio di colore ciano.\033[0m\n";
        		cout << "\033[31mL'unita' che e' stata scelta e' 1:33\033[0m\n\n";
            	
            	index = 0;
            	pol1 = "", pol2 = "";
            	double yGraficaPre, xGraficaPre;
            	bool exception = false;
            	
            	for (int i = MAX - 1; i >= 0; i--) {
                    polinomioDifferenza[i] = polinomio1[i] - polinomio2[i];
                }
                
        		cout << "\033[1mSicuro di voler continuare? (\033[32my\033[0m, \033[31mN\033[0m): \033[0m";
        		cin >> userChoice;
        		
        		if (tolower(userChoice) != 'y') {
        			system("cls");
        			continue;
				}
            	
            	// punti che vanno da -n a n
            	for (float i = -15; i <= 15; i += 0.2) {
            		punti[index] = i;
            		index++;
				}
            	
            	initgraph(&graphDriver, &graphMode, "", WIDTH, HEIGHT);

            	setcolor(DARKGRAY); // imposta il colore degli assi a bianco
            	line(WIDTH / 2, 0, WIDTH / 2, HEIGHT); // Asse delle ordinate
            	line(0, HEIGHT / 2, WIDTH, HEIGHT / 2); // Asse delle ascisse
            	
            	// Genera delle linee nell'asse delle ascisse 
            	setcolor(WHITE); // Imposta il colore delle lineette a magenta
            	for (int i = 33; i < WIDTH / 2; i += 33) {
            		line(WIDTH / 2 + i, HEIGHT / 2 - 8, WIDTH / 2 + i, HEIGHT / 2 + 8);
            		line(WIDTH / 2 - i, HEIGHT / 2 - 8, WIDTH / 2 - i, HEIGHT / 2 + 8);
				}
				
				// Genera delle linee nell'asse delle ordinate 
            	for (int i = 33; i < HEIGHT / 2; i += 33) {
                    line(WIDTH / 2 - 8, HEIGHT / 2 + i, WIDTH / 2 + 8, HEIGHT / 2 + i);
                    line(WIDTH / 2 - 8, HEIGHT / 2 - i, WIDTH / 2 + 8, HEIGHT / 2 - i);
				}

                // Inserisci i caratteri y e x all'interno del grafico
                outtextxy(WIDTH / 2 + 20, 10, "y");
                outtextxy(WIDTH - 30, HEIGHT / 2 + 20, "x");
                
                // Rappresentazione del punto di intersezione 
                setcolor(CYAN);
            	if (polinomioDifferenza[MAX - 1] == 0 && polinomio1[MAX - 1] == 0 && polinomio2[MAX - 1] == 0) {
                    if (polinomioDifferenza[MAX - 2] != 0) {
                        aDecimal = polinomioDifferenza[MAX - 2], bDecimal = polinomioDifferenza[MAX - 3], cDecimal = polinomioDifferenza[MAX - 4];
                        y1 = 0, y2 = 0;
                        deltaDecimal = pow(bDecimal, 2) - 4 * aDecimal * cDecimal;

                        if (deltaDecimal > 0) {
                            x1 = ((-bDecimal + sqrt(deltaDecimal)) / (2 * aDecimal)) + 0.0;
                            x2 = ((-bDecimal - sqrt(deltaDecimal)) / (2 * aDecimal)) + 0.0;

                            for (int i = MAX - 2; i >= 0; i--) {
                                if (polinomio1[i] != 0) {
                                    if (i != 0) {
                                        y1 += pow(x1, i) * polinomio1[i];
                                        y2 += pow(x2, i) * polinomio1[i];
                                    } else {
                                        y1 += polinomio1[i];
                                        y2 += polinomio1[i];
                                    }
                                }  
                            }
                            
                            circle(WIDTH / 2 + x1 * 33, HEIGHT / 2 + y1 * 33 * - 1, 5); 
	                		circle(WIDTH / 2 + x2 * 33, HEIGHT / 2 + y2 * 33 * - 1, 5);
                        } else if (deltaDecimal == 0) {
                            x1 = (-bDecimal / (2 * aDecimal)) + 0.0;

                            for (int i = MAX - 2; i >= 0; i--) {
                                if (polinomio1[i] != 0) {
                                    if (i != 0) 
                                        y1 += pow(x1, i) * polinomio1[i];
                                    else 
                                        y1 += polinomio1[i];
                                }
                            }
                            
                            circle(WIDTH / 2 + x1 * 33, HEIGHT / 2 + y1 * 33 * - 1, 5); 
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

                        if (isIndeterminato || isImpossibile) {
                            exception = true;
                        } else {
                            x1 = termineNotoDecimal / terminePrimoGradoDecimal;

                            for (int i = MAX - 2; i >= 0; i--) {
                                if (polinomio1[i] != 0) {
                                    if (i != 0) 
                                        y1 += pow(x1, i) * polinomio1[i];
                                    else 
                                        y1 += polinomio1[i];
                                }
                            }
                            
                            circle(WIDTH / 2 + x1 * 33, HEIGHT / 2 + y1 * 33 * - 1, 5);
                        }
                    }
                }
            
            	// Rappresentazione grafica del primo polinomio
            	setcolor(GREEN); // Imposta il colore del primo polinomio a verde
            	for (int i = 0; i < index; i++) {
            		yGrafica = 0;
            		for (int j = gradoMaxPolinomio1; j >= 0; j--) {
            			if (polinomio1[j] != 0) {
                            if (j != 0) 
                                yGrafica += pow(punti[i], j) * polinomio1[j];
                            else 
                                yGrafica += polinomio1[j];
                        }
                        
					}
                    // Inserisci i punti all'interno del grafico
					if (WIDTH / 2 + punti[i] * 33 < WIDTH && HEIGHT / 2 + yGrafica * 33 * - 1 < HEIGHT) {
						circle(WIDTH / 2 + punti[i] * 33, HEIGHT / 2 + yGrafica * 33 * - 1, 3);	
					}
				}
				
				// Rappresentazione grafica del secondo polinomio
            	
            	setcolor(YELLOW); // Imposta il colore del secondo polinomio a giallo
            	for (int i = 0; i < index; i++) {
            		yGrafica = 0;
            		for (int j = gradoMaxPolinomio2; j >= 0; j--) {
            			if (polinomio2[j] != 0) {
                            if (j != 0) {
                            	yGrafica += pow(punti[i], j) * polinomio2[j];
							} else {
								yGrafica += polinomio2[j];
							}
                        }
                        
					}
					if (WIDTH / 2 + punti[i] * 33 < WIDTH && HEIGHT / 2 + yGrafica * 33 * - 1 < HEIGHT) {
						circle(WIDTH / 2 + punti[i] * 33, HEIGHT / 2 + yGrafica * 33 * - 1, 3);
					}
				}
				
				// Creazione della stringa contenente il primo polinomio
				pol1 += "P(1) = ";
				
                if (polinomio1[MAX - 1] == 0 && polinomio1[MAX - 2] == 0 && polinomio1[MAX - 3] == 0 && polinomio1[MAX - 4] == 0) {
                    pol2 += "0";
                } else {
                    if (polinomio1[gradoMaxPolinomio1] != 0) {
                        pol1 += (polinomio1[gradoMaxPolinomio1] > 0) ? "+" : "-";
                    }

                    for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                        if (polinomio1[i] != 0) {
                            if (i != 0) {
                                pol1 += to_string(abs(polinomio1[i])) + "x^" + to_string(i) + " ";
                            } else {
                                pol1 += to_string(abs(polinomio1[i]));
                            }
                        }
                        
                        if (i != 0 && polinomio1[i - 1] != 0) {
                            pol1 += polinomio1[i - 1] > 0 ? "+ " : "- ";
                        }
                    }
                }
				
                setcolor(GREEN);
                outtextxy(10, 600, pol1.c_str());
                
                // Creazione della stringa contenente il secondo polinomio
                pol2 += "P(2) = ";
				
                if (polinomio2[MAX - 1] == 0 && polinomio2[MAX - 2] == 0 && polinomio2[MAX - 3] == 0 && polinomio2[MAX - 4] == 0) {
                    pol2 += "0";
                } else {
                    if (polinomio2[gradoMaxPolinomio2] != 0) {
                        pol2 += polinomio2[gradoMaxPolinomio2] > 0 ? "+" : "-";
                    }
				
                    for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                        if (polinomio2[i] != 0) {
                            if (i != 0) {
                                pol2 += to_string(abs(polinomio2[i])) + "x^" + to_string(i) + " ";
                            } else {
                                pol2 += to_string(abs(polinomio2[i]));
                            }
                        }
                        
                        if (i != 0 && polinomio2[i - 1] != 0) {
                            pol2 += polinomio2[i - 1] > 0 ? "+ " : "- ";
                        }
                    }
                }
				
                setcolor(YELLOW);
                outtextxy(10, 620, pol2.c_str());
				
				ShowWindow(GetConsoleWindow(), SW_HIDE);
            	getchg();
            	ShowWindow(GetConsoleWindow(), SW_SHOW);
            	closegraph();
            	system("cls");
            	break;
        	}
            case '8': {
            	system("cls");
            	cout << "Sei sicuro di voler uscire? (\033[32my\033[0m, \033[31mN\033[0m): ";
            	userExit = getch();
            	
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
