#include <stdio.h>

int main()
{
   if (0.1 + 0.2 != 0.3) {	
      printf("0.1 + 0.2 NO és igual a 0.3!!\n");}
   else {
      printf("0.1 + 0.2 és igual a 0.3\n");
   }

   float cerocoma1 = 0.1;
   float cerocoma2 = 0.2;
   if (cerocoma1+cerocoma2 != 0.3) {      
      printf("Utilitzan float, 0.1 + 0.2 NO és igual a 0.3!!\n");}
   else {
      printf("Utilitzan float, 0.1 + 0.2 és igual a 0.3\n");
   }  
   
   float cerocoma3 = 0.3;
   if (cerocoma1+cerocoma2 != cerocoma3) {      
      printf("Utilitzan float en 0.3, 0.1 + 0.2 NO és igual a 0.3!!\n");}
   else {
      printf("Utilitzan float en 0.3, 0.1 + 0.2 és igual a 0.3\n");
   }  

   double cerocoma1d = 0.1;
   double cerocoma2d = 0.2;
   double cerocoma3d = 0.3;
   if (cerocoma1d+cerocoma2d != cerocoma3d) {      
      printf("Utilitzan double en 0.3, 0.1 + 0.2 NO és igual a 0.3!!\n");}
   else {
      printf("Utilitzan double en 0.3, 0.1 + 0.2 és igual a 0.3\n");
   }  
   return 0;
}
