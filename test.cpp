#include <iostream>
#include <cmath> // per la funzione abs() e per la funzione pow()
using namespace std;

int main() {
	const int MAX = 4, MAX2 = 16;
	int polinomio1[MAX] = {0}, polinomio2[MAX] = {0}, polinomioSomma[MAX] = {0}, polinomioDifferenza[MAX] = {0}, gradoPolinomio[MAX2] = {0}, polinomioProdotto[MAX2] = {0}, polinomioProdottoSomma[MAX2] = {0};
	int gradoMaxPolinomio1, gradoMaxPolinomio2, gradoMax, index = 0;
	
	// Controllo input del grado massimo del primo polinomio
	do {
		cout << "INSERISCI IL GRADO MASSIMO DEL PRIMO POLINOMIO: ";
		cin >> gradoMaxPolinomio1;
		
		if (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0)
			cout << "IL POLINOMIO DEVE AVERE UN GRADO MINIMO DI 0 E UN GRADO MASSIMO DI 3. RIPROVARE PER FAVORE!\n";
	} while (gradoMaxPolinomio1 > 3 || gradoMaxPolinomio1 < 0);
	
	cout << "\n";
	
	// Gestione input del primo polinomio
	for (int i = gradoMaxPolinomio1; i >= 0; i--) {
		if (i > 0) {
			cout << "INSERISCI IL COEFFICIENTE DI X^" << i << ": ";
			cin >> polinomio1[i];
		} else {
			cout << "INSERISCI IL TERMINE NOTO: ";
			cin >> polinomio1[i];
		}
	}
	
	// Gestione output del primo polinomio
	cout << "\nPRIMO POLINOMIO: ";
	
	// assegna il segno (+, -) al primo numero del primo polinomio
	if (polinomio1[gradoMaxPolinomio1] > 0)
		cout << "+";
	else if (polinomio1[gradoMaxPolinomio1] < 0)
		cout << "-";
	
	for (int i = gradoMaxPolinomio1; i >= 0; i--) {
		if (polinomio1[i] != 0 && i != 0)
			cout << abs(polinomio1[i]) << "x^" << i << " ";
		else if (i == 0 && polinomio1[i] != 0)
			cout << abs(polinomio1[i]);
		
		if (i != 0) {
			if (polinomio1[i - 1] > 0)
				cout << "+ ";
			else if (polinomio1[i - 1] < 0)
				cout << "- ";
		}
	}
	
	cout << "\n\n";
	
	// Controllo input del grado massimo del secondo polinomio
	do {
		cout << "INSERISCI IL GRADO MASSIMO DEL SECONDO POLINOMIO: ";
		cin >> gradoMaxPolinomio2;
		
		if (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0)
			cout << "IL POLINOMIO DEVE AVERE UN GRADO MINIMO DI 0 E UN GRADO MASSIMO DI 3. RIPROVARE PER FAVORE!\n\n";
	} while (gradoMaxPolinomio2 > 3 || gradoMaxPolinomio2 < 0);
	
	cout << "\n";
	
	// Gestione input del secondo polinomio
	for (int i = gradoMaxPolinomio2; i >= 0; i--) {
		if (i > 0) {
			cout << "INSERISCI IL COEFFICIENTE DI X^" << i << ": ";
			cin >> polinomio2[i];
		} else {
			cout << "INSERISCI IL TERMINE NOTO: ";
			cin >> polinomio2[i];
		}
	}
	
	// Gestione output del primo polinomio
	cout << "\nSECONDO POLINOMIO: ";
	
	// assegna il segno (+, -) al primo numero del secondo polinomio
	if (polinomio2[gradoMaxPolinomio2] > 0)
		cout << "+";
	else if (polinomio2[gradoMaxPolinomio2] < 0)
		cout << "-";
	
	for (int i = gradoMaxPolinomio2; i >= 0; i--) {
		if (polinomio2[i] != 0 && i != 0)
			cout << abs(polinomio2[i]) << "x^" << i << " ";
		else if (i == 0 && polinomio2[i] != 0)
			cout << abs(polinomio2[i]);
		
		if (i != 0) {
			if (polinomio2[i - 1] > 0)
				cout << "+ ";
			else if (polinomio2[i - 1] < 0)
				cout << "- ";
		}
	}
	// Calcolo della somma e della differenza dei due polinomi
	
	for (int i = MAX - 1; i >= 0; i--) {
		polinomioSomma[i] = polinomio1[i] + polinomio2[i];
		polinomioDifferenza[i] = polinomio1[i] - polinomio2[i];
	}
	
	// individuazione del grado massimo tra i due polinomi
	if (gradoMaxPolinomio1 > gradoMaxPolinomio2)
		gradoMax = gradoMaxPolinomio1;
	else
		gradoMax = gradoMaxPolinomio2;
		
	// Gestione output del polinomio somma
	cout << "\n\nLA SOMMA TRA I DUE POLINOMI EQUIVALE A: ";

	// assegna il segno (+, -) al primo numero del polinomio somma
	if (polinomioSomma[gradoMax] > 0 && polinomioSomma[gradoMax] != 0)
		cout << "+";
	else if (polinomioSomma[gradoMax] < 0 && polinomioSomma[gradoMax] != 0)
		cout << "-";
	
	for (int i = gradoMax; i >= 0; i--) {
		if (polinomioSomma[i] != 0 && i != 0)
			cout << abs(polinomioSomma[i]) << "x^" << i << " ";
		else if (i == 0 && polinomioSomma[i] != 0)
			cout << abs(polinomioSomma[i]);
		
		if (i != 0) {
			if (polinomioSomma[i - 1] > 0)
				cout << "+ ";
			else if (polinomioSomma[i - 1] < 0)
				cout << "- ";
		}
	}
	
	// Gestione output del polinomio differenza
	cout << "\n\nLA DIFFERENZA TRA I DUE POLINOMI EQUIVALE A: ";

	// assegna il segno (+, -) al primo numero del polinomio differenza
	if (polinomioDifferenza[gradoMax] > 0 && polinomioDifferenza[gradoMax] != 0)
		cout << "+";
	else if (polinomioDifferenza[gradoMax] < 0 && polinomioDifferenza[gradoMax] != 0)
		cout << "-";
	
	for (int i = gradoMax; i >= 0; i--) {
		if (polinomioDifferenza[i] != 0 && i != 0)
			cout << abs(polinomioDifferenza[i]) << "x^" << i << " ";
		else if (i == 0 && polinomioDifferenza[i] != 0)
			cout << abs(polinomioDifferenza[i]);
		
		if (i != 0) {
			if (polinomioDifferenza[i - 1] > 0)
				cout << "+ ";
			else if (polinomioDifferenza[i - 1] < 0)
				cout << "- ";
		}
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
	cout << "\n\nIL PRODOTTO TRA I DUE POLINOMI EQUIVALE A: ";
	gradoMax = gradoMaxPolinomio1 + gradoMaxPolinomio2;
	index = 0;

	// assegna il segno (+, -) al primo numero del polinomio prodotto
	if (polinomioProdotto[index] > 0 && polinomioProdotto[index] != 0)
		cout << "+";
	else if (polinomioProdotto[index] < 0 && polinomioProdotto[index] != 0)
		cout << "-";

	for (int i = gradoMax; i >= 0; i--) {
		if (polinomioProdotto[index] != 0 && i != 0)
			cout << abs(polinomioProdotto[index]) << "x^" << i << " ";
		else if (i == 0 && polinomioProdotto[index] != 0)
			cout << abs(polinomioProdotto[index]);
		
		if (i != 0) {
			if (polinomioProdotto[index + 1] > 0)
				cout << "+ ";
			else if (polinomioProdotto[index + 1] < 0)
				cout << "- ";
		}

		index++;
	}

	// Ricerca degli zeri nel primo Polinomio
	
	cout << "\n\nGLI ZERI DEL PRIMO POLINOMIO SONO: ";
	if (polinomio1[MAX - 1] == 0) {
		if (polinomio1[MAX - 2] != 0) {
			int delta, numeratore1, numeratore2, denominatore1, denominatore2, resto, mcd1, mcd2, mcd3;
			int a = polinomio1[MAX - 2], b = polinomio1[MAX - 3], c = polinomio1[MAX - 4];

			delta = pow(b, 2) - 4 * a * c;

			// Verifica se la radice è perfetta o meno
			if (sqrt(sqrt(delta) * sqrt(delta)) != delta && delta > 0) {
				int parteInterna = 1, parteEsterna = 1, cont, resto, numeratore, denominatore;

				resto = delta;
				// Semplificazione della radice
				for (int i = 2; i <= delta; i++) {
					cont = 0;
					while (resto % i == 0) {
						resto = resto / i;
						cont++;
					}

					if (cont > 0) {
						if (cont % 2 == 0) {
							parteEsterna *= pow(i, cont / 2);
						} else {
							parteInterna *= i;
							if (cont > 1)
								parteEsterna *= pow(i, cont / 2);
						}
					}
				}

				numeratore = -b;
				denominatore = 2 * a;

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
				mcd3 = abs(denominatore);

				// Algoritmo di Euclide utilizzato per calcolare MCD tra mcd del numeratore e la parte esterna e il denominarore
				while (mcd1 % mcd3 > 0) {
					resto = mcd1 % mcd3;
					mcd1 = mcd3;

					if (resto != 0)
						mcd3 = resto;
				}

				mcd2 = mcd2 / mcd3;
				denominatore = denominatore / mcd3;

				if (denominatore == 1 && b == 0) {
					cout << "\nX1 =>" << " + " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\n";
					cout << "\nX2 =>" << " - " << parteEsterna << "*" << "sqrt(" << parteInterna << ")";
				} else {
					if (mcd2 % denominatore != 0) {
						cout << "\nX1 => " << "(" << mcd2 * numeratore << " + " << parteEsterna * mcd2 << "*" <<"sqrt(" << parteInterna << ")" << ")" << "/" << denominatore << "\n";
						cout <<  "\nX2 => " << "(" << mcd2 * numeratore << " - " << parteEsterna * mcd2 << "*" <<"sqrt(" << parteInterna << ")" << ")" << "/" << denominatore;
					} else {
						cout << "\nX1 => " << numeratore << " + " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\n";
						cout << "\nX2 => " << numeratore << " - " << parteEsterna << "*" << "sqrt(" << parteInterna << ")";
					}
				}
			} else {
				if (delta > 0) {
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
						cout << "\nX1 => " << numeratore1 << "/" << denominatore1 << "\n";
						cout << "\nX2 => " << numeratore2 << "/" << denominatore2 << "\n";
					} else if (numeratore1 % denominatore1 != 0 && numeratore2 % denominatore2 == 0) {
						cout << "\nX1 => " << numeratore1 << "/" << denominatore1 << "\n";
						cout << "\nX2 => " << numeratore2 << "\n";
					} else if (numeratore1 % denominatore1 == 0 && numeratore2 % denominatore2 != 0) {
						cout << "\nX1 => " << numeratore1 << "\n";
						cout << "\nX2 => " << numeratore2 << "/" << denominatore2 << "\n";
					} else {
						cout << "\nX1 => " << numeratore1 << "\n";
						cout << "\nX2 => " << numeratore2 << "\n";
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
						cout << "\nX1 e X2 => " << numeratore1 << "/" << denominatore1 << "\n";
					else 
						cout << "\nX1 e X2 => " << numeratore1 << "\n";
				} else {
					cout << "NON SONO PRESENTI SOLUZIONI PER QUESTO POLINOMIO!";
				}
			}
		} else {
			int termineNoto = polinomio1[MAX - 4], terminePrimoGrado = polinomio1[MAX - 3], mcd1, mcd2, resto;
			bool isImpossibile = false, isIndeterminato = false;

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
				cout << "\nIL POLINOMIO RISULTA INDETERMINATO!";
			} else if (isImpossibile) {
				cout << "\nIL POLINOMIO RISULTA IMPOSSIBILE";
			} else {
				if (termineNoto % terminePrimoGrado != 0)
					cout << "\nX1 => " << termineNoto << "/" << terminePrimoGrado << "\n";
				else 
					cout << "\nX1 => " << termineNoto << "\n";
			} 
		}
	} else {
		cout << "\nNON E' POSSIBILE TROVARE GLI ZERI NEL PRIMO POLINOMIO PERCHE' MAGGIORE DI 2";
	}

	cout << "\n\nGLI ZERI DEL SECONDO POLINOMIO SONO: ";
	// Ricerca degli zeri nel secondo Polinomio
	if (polinomio2[MAX - 1] == 0) {
		if (polinomio2[MAX - 2] != 0) {
			int delta, numeratore1, numeratore2, denominatore1, denominatore2, resto, mcd1, mcd2, mcd3;
			int a = polinomio2[MAX - 2], b = polinomio2[MAX - 3], c = polinomio2[MAX - 4];

			delta = pow(b, 2) - 4 * a * c;

			// Verifica se la radice è perfetta o meno
			if (sqrt(sqrt(delta) * sqrt(delta)) != delta && delta > 0) {
				int parteInterna = 1, parteEsterna = 1, cont, resto, numeratore, denominatore;

				resto = delta;
				// Semplificazione della radice
				for (int i = 2; i <= delta; i++) {
					cont = 0;
					while (resto % i == 0) {
						resto = resto / i;
						cont++;
					}

					if (cont > 0) {
						if (cont % 2 == 0) {
							parteEsterna *= pow(i, cont / 2);
						} else {
							parteInterna *= i;
							if (cont > 1)
								parteEsterna *= pow(i, cont / 2);
						}
					}
				}

				numeratore = -b;
				denominatore = 2 * a;

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
				mcd3 = abs(denominatore);

				// Algoritmo di Euclide utilizzato per calcolare MCD tra mcd del numeratore e la parte esterna e il denominarore
				while (mcd1 % mcd3 > 0) {
					resto = mcd1 % mcd3;
					mcd1 = mcd3;

					if (resto != 0)
						mcd3 = resto;
				}

				mcd2 = mcd2 / mcd3;
				denominatore = denominatore / mcd3;

				if (denominatore == 1 && b == 0) {
					cout << "\nX1 =>" << " + " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\n";
					cout << "\nX2 =>" << " - " << parteEsterna << "*" << "sqrt(" << parteInterna << ")";
				} else {
					if (mcd2 % denominatore != 0) {
						cout << "\nX1 => " << "(" << mcd2 * numeratore << " + " << parteEsterna * mcd2 << "*" <<"sqrt(" << parteInterna << ")" << ")" << "/" << denominatore << "\n";
						cout <<  "\nX2 => " << "(" << mcd2 * numeratore << " - " << parteEsterna * mcd2 << "*" <<"sqrt(" << parteInterna << ")" << ")" << "/" << denominatore;
					} else {
						cout << "\nX1 => " << numeratore << " + " << parteEsterna << "*" << "sqrt(" << parteInterna << ")" << "\n";
						cout << "\nX2 => " << numeratore << " - " << parteEsterna << "*" << "sqrt(" << parteInterna << ")";
					}
				}
			} else {
				if (delta > 0) {
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
						cout << "\nX1 => " << numeratore1 << "/" << denominatore1 << "\n";
						cout << "\nX2 => " << numeratore2 << "/" << denominatore2 << "\n";
					} else if (numeratore1 % denominatore1 != 0 && numeratore2 % denominatore2 == 0) {
						cout << "\nX1 => " << numeratore1 << "/" << denominatore1 << "\n";
						cout << "\nX2 => " << numeratore2 << "\n";
					} else if (numeratore1 % denominatore1 == 0 && numeratore2 % denominatore2 != 0) {
						cout << "\nX1 => " << numeratore1 << "\n";
						cout << "\nX2 => " << numeratore2 << "/" << denominatore2 << "\n";
					} else {
						cout << "\nX1 => " << numeratore1 << "\n";
						cout << "\nX2 => " << numeratore2 << "\n";
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
						cout << "\nX1 e X2 => " << numeratore1 << "/" << denominatore1 << "\n";
					else 
						cout << "\nX1 e X2 => " << numeratore1 << "\n";
				} else {
					cout << "\nNON SONO PRESENTI SOLUZIONI PER QUESTO POLINOMIO!";
				}
			}
		} else {
			int termineNoto = polinomio2[MAX - 4], terminePrimoGrado = polinomio2[MAX - 3], mcd1, mcd2, resto;
			bool isImpossibile = false, isIndeterminato = false;

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
				cout << "\nIL POLINOMIO RISULTA INDETERMINATO!";
			} else if (isImpossibile) {
				cout << "\nIL POLINOMIO RISULTA IMPOSSIBILE";
			} else {
				if (termineNoto % terminePrimoGrado != 0)
					cout << "\nX1 => " << termineNoto << "/" << terminePrimoGrado << "\n";
				else 
					cout << "\nX1 => " << termineNoto << "\n";
			} 
		}
	} else {
		cout << "\nNON E' POSSIBILE TROVARE GLI ZERI NEL SECONDO POLINOMIO PERCHE' MAGGIORE DI 2";
	}

	// Punto di intersezione tra i due polinomi
	if (polinomioDifferenza[MAX - 1] == 0) {
		if (polinomioDifferenza[MAX - 2] != 0) {
			float delta, numeratore, denominatore, x1, x2, y1 = 0, y2 = 0;
			float a = polinomioDifferenza[MAX - 2], b = polinomioDifferenza[MAX - 3], c = polinomioDifferenza[MAX - 4];

			delta = pow(b, 2) - 4 * a * c;

			if (delta > 0) {
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);

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

				cout << "\n(" << x1 << ", " << y1 << ")" << "\n";
				cout << "(" << x2 << ", " << y2 << ")" << "\n";

			} else if (delta == 0) {
				x1 = -b / (2 * a);

				for (int i = MAX - 2; i >= 0; i--) {
					if (polinomio1[i] != 0) {
						// i deve essere diverso da zero per evitare situzine 0^0
						if (i != 0) 
							y1 += pow(x1, i) * polinomio1[i];
						else 
							y1 += polinomio1[i];
					}
				}

				cout << "\n(" << x1 << ", " << y1 << ")" << "\n";
			} else {
				cout << "I DUE POLINOMI NON SI INTERSECANO!";
			}
		} else {
			float termineNoto = polinomioDifferenza[MAX - 4], terminePrimoGrado = polinomioDifferenza[MAX - 3], x1, y1;
			float isImpossibile = false, isIndeterminato = false;

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

			if (isIndeterminato) {
				cout << "LE DUE RETTE SONO COINCIDENTI!";
			} else if (isImpossibile) {
				cout << "LE DUE RETTE SONO PARALLELE!";
			} else {
				x1 = termineNoto / terminePrimoGrado;

				for (int i = MAX - 2; i >= 0; i--) {
					if (polinomio1[i] != 0) {
						// i deve essere diverso da zero per evitare situzine 0^0
						if (i != 0) 
							y1 += pow(x1, i) * polinomio1[i];
						else 
							y1 += polinomio1[i];
					}
				}
				cout << "\n(" << x1 << ", " << y1 << ")" << "\n";
			}
		}
	} else {
		cout << "\nNON E' POSSIBILE TROVARE IL PUNTO DI INTERSEZIONE DI UN POLINOMIO DI 3 GRADO!";
	}

	return 0;
}