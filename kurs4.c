#include <stdio.h>
#include <math.h>
const double eps = 0.00001;

double f1(double x) {
    return exp(x) + log(x) - 10 * x;
}
double F1(double x) {
    return log(10 * x - log(x));
}
double f1p(double x) {
    return exp(x) + 1/x - 10;
}

double f2(double x) {
    return cos(x) - exp(-x * x * 0.5) + x - 1;
}
double F2(double x) {
    return 1 - cos(x) + exp(-x * x * 0.5);
}
double f2p(double x) {
    return -sin(x) + exp(-x * x * 0.5) * x + 1;
}

double f3(double x) {
    return 1 - x + sin(x) - log(1 + x);
}
double F3(double x) {
    return 1 + sin(x) - log(1 + x);
}
double f3p(double x) {
    return -1 + cos(x) - 1/(1 + x);
}
// Dichotomy
double Dichotomy(double f(double x), double a, double b) {
    double c;
    while (fabs(a - b) > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) > 0)
            a = c;
        else b = c;
    }
    return c;
}
// Iteration
double Iteration(double f(double x), double a, double b) {
    double x = (a + b) / 2;
    double x1 = x + 1;
    while (fabs(x - x1) > eps) {
        x1 = x;
        x = f(x);
    }
    return x;
}
// Newton
double Newton(double f(double x), double fd(double y), double a,
double b) {
    double x = (a + b) / 2;
    double x1 = x - (f(x) / fd(x));
    while (fabs(x1 - x) > eps) {
        x = x1;
        x1 = x - (f(x) / fd(x));
    }
    return x;
}
//Hord
double Hord(double f(double x), double a, double b) {
    double c;
    while (fabs(a - b) > eps) {
        c = a - f(a) * (b - a) / (f(b) - f(a));
        a = b;
        b = c;
    }
    return c;
}
int main() {
    printf("e^x + ln(x) - 10x = 0\n");
    printf("Newton	=> %.4f\n", Newton(f1, f1p, 3, 4)); 
    printf("Iteration => %.4f\n", Iteration(F1, 3, 4));
    printf("Dihotomia => %.4f\n", Dichotomy(f1, 3, 4));
    printf("Hordes	=> %.4f\n\n", Hord(f1, 3, 4));



    printf("cos(x) - e^(-(X^2) / 2) + x - 1 = 0\n");
    printf("Newton	=> %.4f\n", Newton(f2, f2p, 1, 2)); 
    printf("Iteration => %.4f\n", Iteration(F2, 1, 2));
    printf("Dihotomia => %.4f\n", Dichotomy(f2, 1, 2));
    printf("Hordes	=> %.4f\n\n", Hord(f2, 1, 2));

    printf("1 - x + sin(x) - ln(1 + x) = 0\n");
    printf("Newton	=> %.4f\n", Newton(f3, f3p, 1, 1.5)); 
    printf("Iteration => %.4f\n", Iteration(F3, 1, 1.5));
    printf("Dihotomia => %.4f\n", Dichotomy(f3, 1, 1.5));
    printf("Hordes	=> %.4f\n", Hord(f3, 1, 1.5));

    return 0;
}