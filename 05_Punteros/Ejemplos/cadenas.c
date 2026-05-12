#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(int argc, char const *argv[])
{
    int N = 20; // Numero de muestras
    double A = 1.0; //Amplitud
    double f = 1.0; // Frecuencia de la señal en (Hz)
    double fs = 40.0; // Frecuencia de muestreo en (Hz)
    int n;
    double t,muestras[N], *muestra;
    int ancho = 60;
    int centro = ancho/2, punto,i;
    muestra = muestras;
    for(n=0;n<N;n++){
        t = n / fs;
        muestras[n] = A * sin(2 * PI * f * t);
        printf("Muestra %d: %f\n",n,muestras[n]);
        
    }

    for (n = 0; n < N*2; n++)
    {
        punto = (int)(*((n<N)? muestra+n: muestra+(n-N)) * (ancho / 2.0) * ((n<N)?1:-1)) + centro;
        for (i = 0; i <= ancho; i++)
        {
            if (i == centro && i == punto)
            {
                printf("+");
            }
            else if (i == centro)
            {
                printf("|");
            }
            else if (i == punto)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
