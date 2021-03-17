//header only impametion of rational data type
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int den;
}ratio;

ratio ratio_add(ratio a,ratio b);
ratio ratio_sub(ratio a,ratio b);
ratio ratio_mul(ratio a,ratio b);
ratio ratio_div(ratio a,ratio b);

int ratio_equal(ratio a,ratio b);
int ratio_notequal(ratio a,ratio b);
int ratio_less(ratio a,ratio b);
int ratio_lessequal(ratio a,ratio b);
int ratio_greater(ratio a,ratio b);
int ratio_greaterequal(ratio a,ratio b);

ratio ratio_simplify(ratio a);
int gcd(int n, int d);

ratio ratio_add(ratio a,ratio b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    int d =  b.den * a.den;
    ratio c = {(a.num+b.num),d};
    c = ratio_simplify(c);
    return c;
}

ratio ratio_sub(ratio a,ratio b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    int d =  b.den * a.den;
    ratio c = {(a.num-b.num),d};
    c = ratio_simplify(c);
    return c;
}

ratio ratio_mul(ratio a,ratio b)
{
    ratio c = {(a.num * b.num),(a.den * b.den)};
    c = ratio_simplify(c);
    return c;
}

ratio ratio_div(ratio a,ratio b)
{   
    int m = 1;
    if(b.num < 0)
    {
        m = -1;
    }
    ratio c = {(a.num * (m * b.den)),(a.den * abs(b.num))};
    c = ratio_simplify(c);
    return c;
}

// a == b return 1
int ratio_equal(ratio a,ratio b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    if(a.num == b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// a != b return 1
int ratio_notequal(ratio a,ratio b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    if(a.num != b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// a < b return 1
int ratio_less(ratio a,ratio b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    if(a.num < b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// a <= b return 1
int ratio_lessequal(ratio a,ratio b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    if(a.num <= b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// a > b return 1
int ratio_greater(ratio a,ratio b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    if(a.num > b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// a >= b return 1
int ratio_greaterequal(ratio a,ratio b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    if(a.num >= b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

ratio ratio_simplify(ratio a)
{
    int g = gcd(a.num,a.den);
    ratio b = {(a.num/g),(a.den/g)};
    return b;
}

//finds greatest common divisor
int gcd(int n, int d)
{
    n = abs(n);
    d = abs(d);
    int gcd, remainder;
    while (n != 0)
    {
        remainder = d % n;
        d = n;
        n = remainder;
    }
    gcd = d;
    return gcd;
}