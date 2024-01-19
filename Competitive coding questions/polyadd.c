#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct poly
{
    int coeff;
    int exp;
};

struct poly * polyAdd(struct poly p1[], struct poly p2[], int s1, int s2, struct poly p3[])
{
    int index = 0;
    for (int i = 0; i < s1 + s2; i++)
    {
        if (p1[i].exp == p2[i].exp)
        {
            p3[index].coeff = p1[i].coeff + p2[i].coeff;
            p3[index].exp = p1[i].exp;
        }
        else if (p1[i].exp > p2[i].exp)
        {
            p3[index].coeff = p1[i].coeff;
            p3[index].exp = p1[i].exp;
        }
        else if (p1[i].exp < p2[i].exp)
        {
            p3[index].coeff = p2[i].coeff;
            p3[index].exp = p2[i].exp;
        }
        printf("p3 [i].coeff, p3[i].exp = %d, %d\n", p3[i].coeff, p3[i].exp); 
        index++;
    }
    return p3;
}

int main()
{
    struct poly poly1[5], poly2[3], poly3[10];
    poly1[0].coeff = 2;
    poly1[0].exp = 6;
    poly1[1].coeff = 2;
    poly1[1].exp = 4;
    poly1[2].coeff = 2;
    poly1[2].exp = 2;
    poly1[3].coeff = 2;
    poly1[3].exp = 1;
    poly1[4].coeff = 2;
    poly1[4].exp = 0;

    poly2[0].coeff = 3;
    poly2[0].exp = 5;
    poly2[1].coeff = 3;
    poly2[1].exp = 4;
    poly2[2].coeff = 3;
    poly2[2].exp = 3;

    polyAdd(poly1, poly2, 5, 3, poly3); 
    return 0;
}