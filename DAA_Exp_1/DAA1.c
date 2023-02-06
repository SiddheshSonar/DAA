#include <stdio.h>
#include <math.h>

unsigned long long fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        // for (int i = n - 1; i > 0; i--)
        // {
        //     n = n * i;
        // }
        return n * fact(n - 1);
    }
}

float func1(int n)
{
    //(3/2)^n
    return pow(1.5, n);
}

int func2(int n)
{
    // n^3
    return pow(n, 3);
}

float func3(int n)
{
    //(lg^2)*n
    return pow(log2(n), 2);
}

float func4(int n)
{
    // sqrt(log(n))
    return sqrt(log2(n));
}

float func5(int n)
{
    // n log n
    return n * log2(n);
}

float func6(int n)
{
    // ln ln n
    return log(log(n));
}

float func7(int n)
{
    // log n
    return log2(n);
}

float func8(int n)
{
    // 2^n
    return pow(2, n);
}

float func9(int n)
{
    // ln n
    return log(n);
}

int func10(int n)
{
    // n+5
    return n + 10;
}

void print1(int start, int end, int inc, int (*func)())
{
    for (int i = start; i <= end; i = i + inc)
    {
        printf("%d = %d\n", i, func(i));
    }
}
void print2(int start, int end, int inc, float (*func)())
{
    for (int i = start; i <= end; i = i + inc)
    {
        printf("%d = %f\n", i, func(i));
    }
}

void print3(int start, int end, int inc, unsigned long long (*func)())
{
    for (int i = start; i <= end; i = i + inc)
    {
        printf("%d = %lld\n", i, func(i));
    }
}

int (*intf)(int);
float (*floatf)(int);
unsigned long long (*longf)(int);
int main()
{
    printf("\n(3/2)^n\n\n");
    floatf = func1;
    print2(0, 100, 10, floatf);
    printf("\nn^3\n\n");
    intf = func2;
    print1(0, 100, 10, intf);
    printf("\n(lg^2)*n\n\n");
    floatf = func3;
    print2(0, 100, 10, floatf);
    printf("\nsqrt(log(n))\n\n");
    floatf = func4;
    print2(0, 100, 10, floatf);
    printf("\nn log n\n\n");
    floatf = func5;
    print2(0, 100, 10, floatf);
    printf("\nln ln n\n\n");
    floatf = func6;
    print2(0, 100, 10, floatf);
    printf("\nlog n\n\n");
    floatf = func7;
    print2(0, 100, 10, floatf);
    printf("\n2^n\n\n");
    floatf = func8;
    print2(0, 100, 10, floatf);
    printf("\nln n\n\n");
    floatf = func9;
    print2(0, 100, 10, floatf);
    printf("\nn+5\n\n");
    intf = func10;
    print1(0, 100, 10, intf);
    printf("\nn!\n\n");
    longf = fact;
    print3(0, 20, 2, longf);
    return 0;
}


