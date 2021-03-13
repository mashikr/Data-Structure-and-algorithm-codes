#include <stdio.h>

int pow (int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return pow (m * m, n / 2);
    else
        return m * pow (m * m, (n - 1) / 2);
}

int pow1 (int m, int n)
{
    if (n == 0)
        return 1;

    return pow1 (m, n - 1) * m;
}

int main ()
{
    int res = pow (5, 3);
    int res1 = pow1 (5, 3);

    printf("%d\n", res);
    printf("%d\n", res1);

    return 0;
}
