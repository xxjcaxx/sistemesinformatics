#include <stdio.h>
#include <ctype.h>
#include <string.h>


// Escriu el binari del número que li pasem
void printbitssimple(int n) {
    unsigned int i;
    i = 1<<31;
    /*aquesta operació mou els bits a l'esquerra tantes vegades com la mida del número.
    Com en aquest cas són 32 bits, el 1 que és 0x00000001 es mou 31 bits i queda 0x80000000
    */
    while (i > 0) {
        if (n & i) // Este & lògic queda a 1 si en la posició del bit i a un 1
            printf("1");
        else
            printf("0");
        i >>= 1; // desplaçem el 1 a la dreta per a provar el següent bit
    }
}

void printbitsdoble(long long int n) {
    unsigned long long int i=1;
         i = i<<63;
         /*aquesta operació mou els bits a l'esquerra tantes vegades com la mida del número.
         Com en aquest cas són 32 bits, el 1 que és 0x00000001 es mou 31 bits i queda 0x80000000
         */
         while (i > 0) {
                 if (n & i) // Este & lògic queda a 1 si en la posició del bit i a un 1
                         printf("1");
                 else
                         printf("0");
                 i >>= 1; // desplaçem el 1 a la dreta per a provar el següent bit
         }
 }



int main()
{

double realdoble;
// El capturem amb tota la precisió possible
printf("Escriu un número amb decimals:\n");
scanf("%lf",&realdoble);

//El transformem en les altres representacions
float real=(float)realdoble;
int n = (int)realdoble;

printf("|        | Binari                          | Octal       | Hexadecimal | Decimal\n");
printf("| Sencer |");
// C no pot representar binari dirèctament, fa falta una funció feta a má.
printbitssimple(n);
printf(" |%12o |  %#010X | %i\n",n,n,n);


// primer de tot, cal fer un cast del float a int (els dos a 32 bits) per a que printf i la funció funcionen
unsigned int rr;
memcpy(&rr, &real, sizeof(rr));

printf("| Simple |");
printbitssimple(rr);
printf(" |%12o |  %#010x | %.20f\n",rr,rr,real);


unsigned long long int rrealdoble;
memcpy(&rrealdoble, &realdoble, sizeof(rrealdoble));

printf("| Doble  |");
printbitsdoble(rrealdoble);
printf(" | %llo |  %#018llX | %.20f\n ",rrealdoble,rrealdoble,realdoble);

return 0;
}

