for(int nby = 0; nby < raggioMax; nby++ ){
                           	circle(WIDTH / 2 + x1 * 33, HEIGHT / 2 + y1 * 33 * - 1, parametro1); 
	                		circle(WIDTH / 2 + x2 * 33, HEIGHT / 2 + y2 * 33 * - 1, parametro1);
	                		parametro1--;
							}
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
                outtextxy(10, 580, pol1.c_str());
                
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
                outtextxy(10, 600, pol2.c_str());
				
				setcolor(RED);
				outtextxy(10, 620, intersezione.c_str());
				
				ShowWindow(GetConsoleWindow(), SW_HIDE);
            	getchg();
            	ShowWindow(GetConsoleWindow(), SW_SHOW);
            	closegraph();
            	system("cls");
            	
            	
				break;
