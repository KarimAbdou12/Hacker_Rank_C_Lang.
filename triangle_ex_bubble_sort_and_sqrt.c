
>> ques. <<
 =========
 
You are given  triangles, specifically, their sides a,b  and c.
Print them in the same style but sorted by their areas from the smallest one to the largest one.
It is guaranteed that all the areas are different.
The best way to calculate a area of a triangle with sides a,b and c is Heron's formula:

P =(a+b+c)/2;
S=( p*(p-a)*(p-b)*(p-c) ) ^ 0.5    >>   sqrt();


ex:

Sample Input 0

3
7 24 25
5 12 13
3 4 5

Sample Output 0

3 4 5
5 12 13
7 24 25


Explanation :

The area of the first triangle is 84 .
The area of the second triangle is 30 .
The area of the third triangle is 6 .
So the sorted order is the reverse one.

/****************************************/

>> answer <<
 ==========


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;


double calculate_area(triangle t) {
    double p = (t.a + t.b + t.c) / 2.0;
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}


void sort_by_area(triangle* tr, int n) 
{
    
    double areas[n];
    for (int i = 0; i < n; i++) 
    {
        areas[i] = calculate_area(tr[i]);
    }

    // bubble sort
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (areas[j] > areas[j + 1]) 
            {
                // sort areas
                double temp_area = areas[j];
                areas[j] = areas[j + 1];
                areas[j + 1] = temp_area;

                // sort triangle
                triangle temp_tr = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp_tr;
            }
        }
    }

    
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
