#include <stdio.h>
#include <stdlib.h>
  
int main()
{
    while(1)
    {
       // Reservant memòria sense alliberar-la
       int *ptr = (int *)malloc(sizeof(int));
    }
    // En /var/log/syslog es veurà quan es mata al procés.
    // Mentre s'executa es pot mirar i analitzar htop, per exemple.
}
