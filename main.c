#include <stdio.h>
#include <stdbool.h>

int main() {

    // variablen auf true setzen, print nicht in if else

    bool isPrimeNumber = true;
    bool primeNumberList = true;
    int userInputNumber;

    printf("Gib eine Zahl (x >= 0) ein: \n");

    scanf("%i", &userInputNumber);  


    if(userInputNumber < 0) {
        printf("Bitte nicht diese Zahl, sie muss x >= 0 entsprechen:");
    } else {
        printf("Deine Zahl ist: %d \n", userInputNumber);

        // ist die Zahl gerade ? userInputNumber%2 = 0?
        // deine zahl ist gerade
        // deine zahl ist ungerade

        if(userInputNumber % 2 == 0) {
            printf("Deine Zahl ist gerade  \n");
        } else {
            printf("Deine Zahl ist UNgerade  \n");
        }





        if (userInputNumber <= 1) {
            isPrimeNumber = false; // 1 und 0 sind keine Primzahlen
        } else {
            for (int i = 2; i <= userInputNumber/2; i++) { 
                if (userInputNumber % i == 0) { 
                    isPrimeNumber = false;
                    break; // Schleife an dieser Stelle beenden
                }
            }
        }


        if(isPrimeNumber == true) {
            printf("Deine Zahl IST eine Primzahl  \n");
        } else {
            printf("Deine Zahl ist KEINE Primzahl  \n");
        }







        if(userInputNumber > 1000) {
            printf("Zahl zu gr0ß, sry!  \n");
        } else {

            // schleife beginnt bei 1, da 0 keine Primzahl ist, und somit ausgeschlossen werden kann
            for (int i = 2; i < userInputNumber; i++) { 

                // allePrimzahlen;
                // allePrimzahlen = "1,3,7"
                // printf("%d", i);

                for (int a = 2; a <= i/2; a++) { 
  
                    if (i % a == 0) { 
                        primeNumberList = false; 
                        break; 
                    } else {
                        primeNumberList = true; 
                    }

                } 

                if(primeNumberList) {
                    printf("Primzahl: %d \n", i);
                }

            } 

            if(isPrimeNumber) {
                // bei Primzahlen einfach 1 und userInput wieder ausgeben
                printf("(Primzahl) Deine Primfaktoren sind: 1 und %d \n", userInputNumber);
            } else {
                printf("(keine Primzahl) Deine Primfaktoren sind: ");

                // solange durch zwei teilen, bis modulo != 0
                while (userInputNumber%2 == 0) { 
                    printf("%d ", 2); 
                    userInputNumber = userInputNumber/2; 
                }

                // i + 2, da gerade teiler übersprungen werden, wir haben ja schon durch zwei geteilt, schleife beginnt bei 3
                for (int i = 3; i*i <= userInputNumber; i = i+2) 
                { 
                    // While i divides n, print i and divide n
                    // während wir durch den schleifenindex mit modulo = 0 teilen können, teiler ausgeben und weiter durch selben teiler teilen 
                    while (userInputNumber%i == 0) 
                    { 
                        printf("%d ", i); 
                        userInputNumber = userInputNumber/i; 
                    } 
                } 
                // This condition is to handle the case when n  
                // is a prime number greater than 2 
                if (userInputNumber > 2) 
                    printf ("%d ", userInputNumber); 
            }

        }
    }
        

    

   
}