#include<stdio.h>
#include<math.h>
double eta(double rou, double rou0, double L, double g, double d, double D, double h, double t)
{
    double a = (rou - rou0) * d * d * g * t / (18 * (1 + 2.4 * d / D) * (1 + 3.3 * d / 2 / h) * L);
    return a;
}
double ua(double A[], int n, double t)
{
    double a = 0;
    for (int i = 0; i < n; i++)
    {
        a = a + A[i];
    }
    a = a / n;
    double b = 0;
    for (int i = 0; i < n; i++)
    {
        b += (A[i] - a) * (A[i] - a);
    }
    b /= n * (n - 1);
    double c = 0;
    c = t * sqrt(b);
    return c;
}
double u(double ua, double data)
{
    double ub = 0;
    ub = data / sqrt(3);
    double a = 0;
    a = sqrt(ua * ua + ub * ub);
    return a;
}
double ue(double eta, double d, double t, double L, double ud, double ut, double uL)
{
    double a = 0;
    a = (2 / d) * (2 / d) * ud * ud + 1 / t / t * ut * ut + 1 / L / L * uL * uL;
    double b = 0;
    b = eta * sqrt(a);
    return b;
}
double A(double B[], int n)//Ć˝žůÖľ
{
    double a = 0;
    for (int i = 0; i < n; i++)
        a += B[i];
    a = a / n;
    return a;
}
int main()
{
    double xa[3] = { 0.1751,0.1728,0.1728 };
    printf("%f\n", A(xa, 3));
    printf("%f\n", ua(xa, 3, 1.32));
    printf("%f\n", u(ua(xa, 3, 1.32), 0.0003));
}
