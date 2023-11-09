 /***

Name:			Primzahlen
Beschreibung:	Programm, welches eine Zahl vom Benutzer abfragt und mit dieser folgendes tut:
				Ist die Zahl gerade oder ungerade 
				Ist die Zahl eine Primzahl oder keine Primzahl 
				Alle Primzahlen bis zur eingegebenen Zahl ausgibt
				Eine Primfaktorzerlegung durchführt
Autorinnen:	    Emily Klemt, Carolin Altstaedt
Datum:		    7.11.2023
Version:		1

***/

#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int main() {
    bool istPrimzahl = true; // Ergebnis der Primzalprüfung wird hier gespeichert, Standard = true
    bool primzahlListenElement = true; // Liste der Primzahlen wird ausgegeben anhand des Werts dieser Variable
    unsigned int userEingabeZahl; // Eingabe des Users wird in dieser Variable gespeichert



    //initiale Abfrage einer User-Eingabe (positive Zahl, bestimmt durch %u für unsigned integer),
    printf("Gib eine Zahl (x >= 0) ein: \n");
    scanf("%u", &userEingabeZahl);  



    //Sicherheitsabfrage, ob Eingabe wirklich positiv ist, ansonsten wird das programm nicht fortgesetzt.
    if(userEingabeZahl < 0) {
        printf("Bitte nicht diese Zahl, sie muss x >= 0 entsprechen.");
        return 0;
    } else {
        //Ausgabe der User-Eingabe
        printf("Deine Zahl ist: %d \n", userEingabeZahl);
    } 



    /*
    Aufgabe 2: 
    Prüfen ob Eingabe eine gerade oder ungerade Zahl ist mittels %-Modulo
    Ausgabe des Ergebnisses der Prüfung
    */
    if(userEingabeZahl % 2 == 0) {
        printf("Deine Zahl ist gerade  \n");
    } else {
        printf("Deine Zahl ist UNgerade  \n");
    }



    /*
    Aufgabe 3: 
    Prüfen ob Eingabezahl eine Primzahl
    Ausgabe des Ergebnisses der Prüfung
    */
    if (userEingabeZahl <= 1) {
        istPrimzahl = false; // 1 und 0 sind keine Primzahlen und werden in der weiteren Prüfung vernachlässigt
    } else {
        for (int i = 2; i <= userEingabeZahl/2; i++) { 
            if (userEingabeZahl % i == 0) { 
                istPrimzahl = false;
                break; // Schleife an dieser Stelle beenden, Teilen ohne Rest hat einmal funktioniert, Eingabe kann keine Primzahl sein
            }
        }
    }


    if(istPrimzahl == true) {
        printf("Deine Zahl IST eine Primzahl  \n");
    } else {
        printf("Deine Zahl ist KEINE Primzahl  \n");
    }
    /*
    Ende Aufgabe 3
    */



    //Sicherheitsabfrage, wenn Eingabe > 1000 wird das Programm nicht fortgesetzt.
    if(userEingabeZahl > 1000) {
        printf("Zahl muss zum finden der Primfaktoren für deine Zahl kleiner als 1000 sein!\n");
        return 0;
    } else {
        /*
        Aufgabe 4: 
        Erstellen einer Liste aller Primzahlen bis zur eingegebenen Zahl
        */
        printf("Primzahlen bis zu deiner Zahl:\n");
        // schleife beginnt bei 1, da 0 keine Primzahl ist, und somit ausgeschlossen werden kann
        for (int i = 2; i < userEingabeZahl; i++) { 

            // Schleife prüft jede Zahl bis zur Eingabezahl, ob das Teilen durch einen anderen Teiler als 1 oder sich selbst
            // teilbar ist -> dann keine Primzahl
            for (int a = 2; a <= i/2; a++) { 
                if (i % a == 0) { 
                    primzahlListenElement = false; 
                    break; 
                } else {
                    primzahlListenElement = true; 
                }
            } 

            if(primzahlListenElement) {
                //Zahl als Primzahl bis zur Eingabezahl in selber Iteration ausgeben
                printf("%d ", i);
            }

        } 
        /*
        Ende Aufgabe 4 
        */


        printf("\n\n"); // nur Formatierung


        /*
        Aufgabe 5: 
        Primfaktoren zur Eingabezahl finden
        */
        if(istPrimzahl) {
            // bei Primzahlen einfach 1 und Eingabezahl als Teiler wieder ausgeben
            printf("(Primzahl) Deine Primfaktoren sind: 1 und %d \n", userEingabeZahl);
        } else {
            // Primfaktoren ermitteln
            printf("(keine Primzahl) Deine Primfaktoren sind: ");

            
            // Alle Zahlen bis zur Eingabezahl iterieren und prüfen, ob es sich dabei um eine Primzahl handelt
            for (int divisor = 2; divisor <= userEingabeZahl; divisor++) { 

                bool teilerIstPrimzahl = true; // variable hier für jede Schleife neu definieren, damit Standardwert für jede Iteration verwendet wird.
                
                // 1 und 0 sind keine Primzahlen und werden in der weiteren Prüfung vernachlässigt
                for (int i = 2; i <= divisor/2; i++) { 
                    if (divisor % i == 0) { 
                        teilerIstPrimzahl = false;
                        break; // Schleife an dieser Stelle beenden
                    }
                }
                
                if(teilerIstPrimzahl) {
                    /*
                    Ermittelten Primfaktor nutzen und Eingabezahl damit solange teilen bis Rest nicht 0 ist.
                    Solange ohne Rest geteilt werden kann wird Teiler als Primfaktor ausgegeben.
                    */
                    while (userEingabeZahl%divisor == 0) { 
                        printf("%d ", divisor); 
                        userEingabeZahl = userEingabeZahl/divisor; 
                    } 
                } else {
                    // Zahl die in dieser Iteration geprüft wurde ist keine Primzahl und wird ignoriert - die Schleife wird fortgesetzt
                    continue;
                }
                
            } 
        }
        /*
        Ende Aufgabe 5
        */



        return 0;
    }
    
}