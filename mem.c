/*
*
* Aquest programa analitza la seua segmentació i els PFN
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* sysconf(3) */

int c=10; //variable global

int main(void)
{
    int a=10; // Variable de la funció main. Aquestes variables es guarden en la pila.
    int* b = malloc(sizeof(int)); // Els punters es reserven en el heap o monticle.
    *b=10;
    static int d=10; // Variable estàtica.

    int pid = getpid();
    int page_size=sysconf(_SC_PAGESIZE);

    printf("El meu PID és %d\n",pid);
    printf("La mida de pàgina d'aquest sistema és %ld bytes.\n",sysconf(_SC_PAGESIZE));
    
    FILE *infile,*pagemap;
    char ruta[25];
    snprintf(ruta, sizeof ruta,"/proc/%d/maps",pid); //construir la ruta de maps
    infile = fopen(ruta,"r"); // Obrir com a lectura el maps

    snprintf(ruta, sizeof ruta,"/proc/%d/pagemap",pid); //construir la ruta de pagemap
    pagemap = fopen(ruta,"rb"); // Obrir com a lectura en mode binary
    // Aquest fitxer conté 64 bits per pàgina lógica e informa sobre el PFN
    
     if ( infile != NULL )
     {
          char line [ 128 ]; // O qualsevol altre màxim de mida de linia
          while ( fgets ( line, sizeof line, infile ) != NULL ) /* read a line */
          {
               char *p, *pf, *tipus ; // p = pàgina inicial, pf = pàgina final 
               p = strtok(line,"-"); // strtok guarda en p la linia fins al -
               printf("\nEl segment va de: %s ",p);
               pf = strtok(NULL," ");
               printf("a: %s ",pf);
               
	       unsigned long base = strtol(p,NULL,16);
               unsigned long base_map=(base/page_size)*8; // Ara necessite buscar la base en el pagemap  
	       // i Cada pàgina ocupa 64 bits o 8 bytes
               printf("primer PFN: ");
               long long my_record;
               fseek(pagemap,base,SEEK_SET);
               fread(&my_record,sizeof(long long),1,pagemap);
               printf("%llx",my_record); // mostra long long en hexadecimal
            
           /*
                * Bits 0-54  page frame number (PFN) if present
                * Bits 0-4   swap type if swapped
                * Bits 5-54  swap offset if swapped
                * Bit  55    pte is soft-dirty (see Documentation/vm/soft-dirty.txt)
                * Bits 56-60 zero
                * Bit  61    page is file-page or shared-anon
                * Bit  62    page swapped
                * Bit  63    page present
            * Per tant, si la pàgina està en memòria es pot trobar en el PFN per la mida de la pàgina
            */

            tipus = strtok(NULL,""); // El funcionament de strtok necessita NULL en la següent cridada
            if (strstr(tipus, "stack") != NULL) { //busca stack o heap en la línia p
                printf(" (pila)"); // com que la pila creix cap a baix, la primera pàgina normalment no té res
                unsigned long i = base;
		unsigned long k = strtol(pf,NULL,16);
		printf("\n La pila te una mida de: %lx bytes",(k-i));

		for(i;i<=k;i=i+page_size){
		 //   printf("\n   %lx",i);
		    unsigned long base_pila = (i/page_size)*8;
                    long long pila_record;
		    fseek(pagemap,base_pila,SEEK_SET);
                    fread(&pila_record,sizeof(long long),1,pagemap);
		    if(pila_record != 0x600000000000000) 
			    printf("  %lx: %llx \n",i,pila_record); // mostra long long en hexadecimal

		}
	    }
            if (strstr(tipus, "heap") != NULL) {
                printf(" (monticle)");
            }
          }
        fclose ( infile );
    }
        else
    {
        perror ("infile");
    }


    printf("\nLa variable a está en %p\n",&a);
    printf("La variable b está en %p\n",b);
    printf("La variable c está en %p\n",&c);
    printf("La variable d está en %p\n",&d);
        return 0;
}
