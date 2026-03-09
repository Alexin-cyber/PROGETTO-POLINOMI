#include <iostream>
#include <cmath> // Per la funzione abs() e per la funzione pow()
#include <conio.h>
using namespace std;

int main() {
    const int MAX = 4, MAX2 = 16;
    int gradoMaxPolinomio1, gradoMaxPolinomio2, gradoMax, index;
    int polinomio1[MAX]{0}, polinomio2[MAX]{0}, polinomioSomma[MAX]{0}, polinomioDifferenza[MAX]{0}, gradoPolinomio[MAX2]{0}, polinomioProdotto[MAX2]{0}, polinomioProdottoSomma[MAX2]{0};
    char opzione;
    bool isFirstTime = true, isRunning = true;

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
                cout << "Inserisci il grado massimo del primo polinomio: ";
                cin >> gradoMaxPolinomio1;
                
                if (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0) {
                    cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                }
            } while (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0);

            // Gestione input del primo polinomio
            for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                if (i > 0) {
                    cout << "\nInserisci il coefficiente di grado x^" << i << ": ";
                    cin >> polinomio1[i];
                } else {
                    cout << "\nInserisci il termine noto: ";
                    cin >> polinomio1[i];
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

            cout << "\n";
            do {
                cout << "\nInserisci il grado massimo del secondo polinomio:  ";
                cin >> gradoMaxPolinomio2;
                
                if (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0)
                    cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
            } while (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0);
            
            // Gestione input del secondo polinomio
            for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                if (i > 0) {
                    cout << "\nInserisci il coefficiente di grado x^" << i << ": ";
                    cin >> polinomio2[i];
                } else {
                    cout << "\nInserisci il termine noto: ";
                    cin >> polinomio2[i];
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
                    cout << "Inserisci il grado massimo del primo polinomio: ";
                    cin >> gradoMaxPolinomio1;
                    
                    if (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0) {
                        cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                    }
                } while (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0);

                // Gestione input del primo polinomio
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (i > 0) {
                        cout << "\nInserisci il coefficiente di grado x^" << i << ": ";
                        cin >> polinomio1[i];
                    } else {
                        cout << "\nInserisci il termine noto: ";
                        cin >> polinomio1[i];
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

                cout << "\n";
                do {
                    cout << "\nInserisci il grado massimo del secondo polinomio:  ";
                    cin >> gradoMaxPolinomio2;
                    
                    if (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0)
                        cout << "\033[31mIl grado massimo del polinomio deve essere compreso tra 0 e 3, riprova!\033[0m\n";
                } while (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0);
                
                // Gestione input del secondo polinomio
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (i > 0) {
                        cout << "\nInserisci il coefficiente di grado x^" << i << ": ";
                        cin >> polinomio2[i];
                    } else {
                        cout << "\nInserisci il termine noto: ";
                        cin >> polinomio2[i];
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

                cout << "(";

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        if (i != 0) {
                            cout << abs(polinomio1[i]) << "x^" << i;

                            if (polinomio1[i - 1] != 0) {
                                cout << " ";
                            }
                        } else {
                            cout << abs(polinomio1[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";

                cout << ") + (";

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        if (i != 0) {
                            cout << abs(polinomio2[i]) << "x^" << i;

                            if (polinomio2[i - 1] != 0) {
                                cout << " ";
                            }
                        } else {
                            cout << abs(polinomio2[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";

                cout << ") = ";

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
                
                // Calcolo della somma dei due polinomi
                for (int i = MAX - 1; i >= 0; i--) {
                    polinomioDifferenza[i] = polinomio1[i] - polinomio2[i];
                }
                
                // individuazione del grado massimo tra i due polinomi
                if (gradoMaxPolinomio1 > gradoMaxPolinomio2) {
                    gradoMax = gradoMaxPolinomio1;
                } else {
                    gradoMax = gradoMaxPolinomio2;
                }

                // Gestione output del polinomio somma
                cout << "\033[32mLa differenza tra i due polinomi equivale a: \033[0m\n\n";

                cout << "(";

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        if (i != 0) {
                            cout << abs(polinomio1[i]) << "x^" << i;

                            if (polinomio1[i - 1] != 0) {
                                cout << " ";
                            }
                        } else {
                            cout << abs(polinomio1[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";

                cout << ") - (";

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        if (i != 0) {
                            cout << abs(polinomio2[i]) << "x^" << i;

                            if (polinomio2[i - 1] != 0) {
                                cout << " ";
                            }
                        } else {
                            cout << abs(polinomio2[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";

                cout << ") = ";

                // assegna il segno (+, -) al primo numero del polinomio somma
                if (polinomioDifferenza[gradoMax] != 0) {
                    if (polinomioDifferenza[gradoMax] > 0) {
                        cout << "+";
                    } else  {
                        cout << "-";
                    }   
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

                cout << "(";

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio1; i >= 0; i--) {
                    if (polinomio1[i] != 0) {
                        if (i != 0) {
                            cout << abs(polinomio1[i]) << "x^" << i;

                            if (polinomio1[i - 1] != 0) {
                                cout << " ";
                            }
                        } else {
                            cout << abs(polinomio1[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio1[i - 1] != 0) {
                        cout << (polinomio1[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";

                cout << ") * (";

                cout << "\033[1m";
                for (int i = gradoMaxPolinomio2; i >= 0; i--) {
                    if (polinomio2[i] != 0) {
                        if (i != 0) {
                            cout << abs(polinomio2[i]) << "x^" << i;

                            if (polinomio2[i - 1] != 0) {
                                cout << " ";
                            }
                        } else {
                            cout << abs(polinomio2[i]);
                        }
                    }
                    
                    if (i != 0 && polinomio2[i - 1] != 0) {
                        cout << (polinomio2[i - 1] > 0 ? "+ " : "- ");
                    }
                }
                cout << "\033[0m";

                cout << ") = ";

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

                cout << "\n\n\033[4mPremere qualsiasi tasto per continuare...\033[0m";
                getch();
                system("cls");
                break;
            case '5':
            case '6':
            case '7':
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
