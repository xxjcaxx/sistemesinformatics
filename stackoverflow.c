#include <stdio.h>
  
void foo(int x)
{
    if (x == 1)
       return;
    x = 6;
    foo(x);
}
  
int main()
{
   int x = 5;
   foo(x);
}


