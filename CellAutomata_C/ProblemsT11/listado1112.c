#include <stdio.h>

static inline
double sqr(double x)
{
    return x*x;
}

double lorenciana(double x, double x0, double y0, double w)
{
    double y, den;
    
    den = 1+sqr(x-x0)/(w*w);
    y=y0/den;
    
    return y;
}

int main(int argc, char** argv)
{
    double x, y, xa, xb, dx;
    double x0, y0, w;
    int npts;
    FILE *fout;
    
    fout = fopen("funcion.dat","w");
    
    printf("Intervalo [a,b]: ");
    printf(" a = ");
    scanf(" %lf", &xa);
    printf(" b= ");
    scanf(" %lf", &xb);
    printf("Numero de punts en l'interval: ");
    printf(" N = ");
    scanf(" %d", &npts);
    
    printf("Parametros de la lorenziana: " 
            "Y(X) = Y0/(1+(X-X0)^2/W^2\n");
    printf(" Y0= ");
    scanf(" %lf", &y0);
    printf(" X0= ");
    scanf(" %lf", &x0);
    printf(" W= ");
    scanf(" %lf", &w);
    
    dx = (xb-xa)/npts;
    
    for(x=xa;x<xb;x+=dx)
    {
        y = lorenciana(x,x0,y0,w);
        
        fprintf(fout, "%g\t%g\n", x,y);
    }
    
    fclose(fout);
    
    return 0;
}
