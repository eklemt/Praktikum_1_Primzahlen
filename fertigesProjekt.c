#define CRT_SECURE_NO_WARNINGS 

//Name:			Primzahlen
//Beschreibung:	Programm, welches eine Zahl vom Benutzer abfragt und mit dieser folgendes tut:
//				Ist die Zahl gerade oder ungerade 
//				Ist die Zahl eine Primzahl oder keine Primzahl 
//				Alle Primzahlen bis zur eingegebenen Zahl ausgibt
//				Eine Primfaktorzerlegung durchführt
//Autorinnen:	Emily Klemt, Carolin Altstaedt
//Datum:		7.11.2023
//Version:		1

#include <stdio.h>
#include <stdbool.h>

int main() {

	unsigned int eingegebeneNummer = 0; // Zahl die vom Benutzer eingegeben wir

	printf("Dieser Programmteil prüft die Zahl und nimmt eine Primfaktorzerlegung vor:\n");
	// Abfragen der Zahl vom Benutzer und Ausgabe der eingegebenen Zahl 
	printf("Gib eine ganzzahlige Zahl (x>=0) ein:\n");
	scanf_s("%u", &eingegebeneNummer);

	printf("Eingegebene Zahl = %u \n", eingegebeneNummer);

	// Zahl wird durch modulo 2 geteilt, um zu prüfen, ob sie gerade ist und anschließend die Info an den Benutzer ausgegeben 
	if (eingegebeneNummer % 2 == 0) {
		printf("%u ist gerade \n", eingegebeneNummer);
	}
	else {
		printf("%u ist ungerade \n", eingegebeneNummer);
	}

	// Primzahlprüfung: Zahl wird durch alle Zahlen bis zur Zahl/2 geteilt, und wenn es eine Zahl mit %0 gibt
	bool istPrimzahl = true; // boolsche Variable, die anzeigt, ob die Zahl eine Primzahl ist
	if (eingegebeneNummer <= 1) {
		istPrimzahl = false; // 1 und 0 sind keine Primzahlen 
	}
	else {
		for (int i = 2; i <= eingegebeneNummer / 2; i++) {
			if (istPrimzahl == true) {
				if (eingegebeneNummer % i == 0) {
					istPrimzahl = false;
				}
				else {
					istPrimzahl = true;
				}
			}
		}
		if (istPrimzahl == true) {
			printf("Deine Zahl ist eine Primzahl \n");
		}
		else {
			printf("Deine Zahl ist keine Primzahl \n");
		}
	}


	// Primzahlliste: In diesem Abschnitt wird die Lister aller Primzahlen bis zur userInputNumber bestimmt 

	int listOfPrimeNumbers[168]; // Array, der die Liste aller Primzahlen bis 1000 speichern kann
	bool istPrimzahlPrimzahlenliste = true; // boolsche Variable, die anzeigt, ob die Zahl eine Primzahl ist, für die Liste der Primzahlen
	int anzahlDerPrimzahlen = 0; //allgemeine Variable zum durchzählen der Primzahlen bis zur userInputNumber

	// Wenn der Nutzer eine zu hohe Zahl, als Primzahl angegeben hat
	if (eingegebeneNummer >= 1000) {
		printf("Eine Liste mit Primzahlen wird nur fuer Zahlen kleiner 1000 erstellt\n");
	}
	// Erstellung der Primzahlliste, Bestimmung der einzelnen Primzahl und Lager in dem Array
	else {
		for (int i = 2; i < eingegebeneNummer; i++) {
			for (int j = 2; j <= i / 2; j++) {
				if (istPrimzahlPrimzahlenliste == true) {
					if (i % j == 0) {
						istPrimzahlPrimzahlenliste = false;
					}
					else {
						istPrimzahlPrimzahlenliste = true;
					}
				}
			}

			if (istPrimzahlPrimzahlenliste == true) {
				listOfPrimeNumbers[anzahlDerPrimzahlen++] = i;
			}

		}
		printf("Liste der Primzahlen bis zur eingegebenen Zahl:\n");
		bool ersterDurchlauf = true; //Variable, die für eine andere Kommasetzung beim ersten Durchlauf sorgt
		for (int i = 0; i < anzahlDerPrimzahlen; i++) {
			if (ersterDurchlauf) {
				ersterDurchlauf = false;
			}
			else {
				printf(",");
			}
			printf("%d", listOfPrimeNumbers[i]);
		}
		printf("\n");
	}
	
	// Primfaktorzerlegung
	printf("Primfaktorzerlegung:\n");
	int rest = eingegebeneNummer; 
	bool ersterDurchlauf = true; 

	//Primfaktorzerlegung, wenn die Zahl eine Primzahl ist
	if (istPrimzahl) {
		// bei Primzahlen einfach 1 und userInput wieder ausgeben
		printf("1*%u \n", eingegebeneNummer);
	}
	// Primfaktorzerlegung, wenn die Zahl keine Primzahl ist
	else {
		for (int i = 2; rest > 1; i++)
			while (rest % i == 0) {
				rest = rest / i;
				if (ersterDurchlauf) {
					printf("%d", i);
					ersterDurchlauf = false;
				}
				else {
					printf("*%d", i);
				}
			}
	}

	/* Primfaktorzerlegung mit Array :
				//Primfaktorzerlegung, wenn die Zahl eine Primzahl ist
				if (isPrimeNumber) {
					bei Primzahlen einfach 1 und userInput wieder ausgeben
					printf("1*%u \n", userInputNumber);

				// Primfaktorzerlegung, wenn die Zahl keine Primzahl ist
				}
				else {
						bool firstrun = true; //Variable, die für eine andere Zeichensetzung beim ersten Durchlauf auch hier sorgt
						int rest = userInputNumber; // Zahl, die nach der Teilung durch den Primfaktor entsteht 
						int primfaktor = 0; // Primfaktor, durch den aktuell geteilt wird
						printf("%u:\n", userInputNumber);
						for (int i = 0; rest > 1; i++) {
							primfaktor = listOfPrimeNumbers[i];
							while (rest % primfaktor == 0) {
								rest = rest / primfaktor;
								if (firstrun) {
									printf("%d", primfaktor);
									firstrun = false;
								}
								else {
									printf("*%d", primfaktor);
								}
							}
						}
						printf("\n");
					//}
				*/

	// Euklidischer Algorithmus 

	int eingegebeneZahl1 = 0; //erste Zahl für den ggT
	int eingegebeneZahl2 = 0; //zweite Zahl für den ggT

	//Einlesen der zwei Zahlen vom Benutzer
	printf("\n\nMithilfe des euklidischen Algorithmus berechnet dieser Programmteil, den ggT:\n");
	printf("Gib dafuer nun die erste Zahl an:\n");
	scanf_s("%i", &eingegebeneZahl1); 
	printf("1.Zahl: %i\n", eingegebeneZahl1);
	printf("Gib dafuer nun die zweite Zahl an:\n");
	scanf_s("%i", &eingegebeneZahl2);
	printf("2.Zahl: %i\n", eingegebeneZahl1);

	//Zahlen nach ihrer Größe ordnen
	int größereZahl = 0; // größere eingegebene Zahl
	int kleinereZahl = 0; //kleinere eingegebene Zahl

	if (eingegebeneZahl2 > eingegebeneZahl1) {
		größereZahl = eingegebeneZahl2;
		kleinereZahl = eingegebeneZahl1;
	}
	else {
		größereZahl = eingegebeneZahl1;
		kleinereZahl = eingegebeneZahl2;
	}
	 
	// Errechnung des ggT
	// Errechnung des ggT, wenn die größere Zahle ein Vielfaches der kleineren ist 
	if (größereZahl % kleinereZahl == 0) {
		printf("Deine groeßere Zahl ist ein Vielfaches deiner kleineren Zahl. Der ggT ist: %i", kleinereZahl);
	}
	else {
		// Euklidischer Algorithmus, mit verschiedenen Resten, die innerhalb des Algorithmus wiedervwendet werden
		int rest1 = 0; //erster Rest im euklydischen Algorithmus
		int rest2 = kleinereZahl; //zweiter Rest im euklydischen Algorithmus
		rest1 = größereZahl % kleinereZahl;
		while (rest1 != 0 && rest2 != 0) {
			rest2 = rest2 % rest1;
			if (rest2 != 0) {
				rest1 = rest1 % rest2; 
			}
		}

		// Ausgabe des ggT
		if (rest1 == 0) {
			printf("Der ggT ist: %i", rest2);
		}
		else {
			printf("Der ggT ist: %i", rest1);
		}
	}

	return 0;
	}

	