#include <math.h>
#include <stdio.h>
int main()
{ double x, d, S, S1, eps=1., a=-1.0, b=1.0, h=(b-a)/10.;
  int n;
  while(1.+eps>1.) eps/=2.;
  printf("Машинное эпсилон = %.21f\n",eps);
  printf("---------------------------------------------------------------\n");
  printf("|     x    |           S          |          S1          |  n |\n");
  printf("|----------|----------------------|----------------------|----|\n");
  for(x=a;x<0.001;x+=h)
  { S=d=x/9; n=1;
    while(fabs(d)>eps)
    { d=-d*x*x/9;
      S+=d; n++;
    }
    printf("|  %.3f  | %.17f | %.17f | %2d |\n", x, S, x/(9+x*x), n);
  }
  for(x=0;x<b+0.001;x+=h)
    {
      S=d=x/9; n=1;
      while(fabs(d)>eps)
    { d=-d*x*x/9;
      S+=d; n++;
    }
  printf("|   %.3f  |  %.17f |  %.17f | %2d |\n", x, S, x/(9+x*x), n);
    }
   printf("---------------------------------------------------------------\n");
   return 0;
}
