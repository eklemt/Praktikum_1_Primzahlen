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
            isPrimeNumber = false; // 1 and any negative number are not prime
        } else {
            for (int i = 2; i <= userInputNumber/2; i++) { 
                if (userInputNumber % i == 0) { 
                    isPrimeNumber = false;
                    break; // No need to continue checking
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
                // return 1 and user input as Primfaktoren
                printf("(Primzahl) Deine Primfaktoren sind: 1 und %d \n", userInputNumber);
            } else {
                printf("(keine Primzahl) Deine Primfaktoren sind: ");
                if(userInputNumber % 2) {
                    while(userInputNumber % 2 == 0){
                    printf("%3d", 2);
                    }
                } else {
                    for(int i = 3; i <= userInputNumber; i+2) {
                        while(userInputNumber % i == 0) {
                            printf("%3d", i);
                        }
                    }
                }
            }

            
            

        }
    }
        

    

   
}