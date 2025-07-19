#include<stdio.h>
#include<math.h>
int main()
{
    double r;
    scanf("%lf", &r);
    double pi = acos(-1);
    double area = pi * r * r;
    double cc = 2 * pi * r;
    printf("%.6lf %.6lf", area, cc);
    return 0;
}