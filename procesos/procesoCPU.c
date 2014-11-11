#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */

int frequency_of_primes (int n) {
  int i,j;
  int freq=n-1;
  for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;
}

int main (int argc, char* argv[])
{
  clock_t t;
  int f;
  char* id=argv[1];
  int n=atoi(argv[2]);
  t = clock();
  printf ("ID %s Calculating %d...\n",id,n);
  f = frequency_of_primes (n);
//  printf ("The number of primes lower than 100,000 is: %d\n",f);
  t = clock() - t;
  float tiempo = (float) t/CLOCKS_PER_SEC;
  printf ("ID %s It took me %d clicks (%f seconds).\n",id,(int) t,tiempo);
  return 0;
}

