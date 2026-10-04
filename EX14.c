#include <stdio.h>

int main()
{
    int n, i, largest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    largest = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }

    printf("Largest element = %d\n", largest);

    return 0;

--OUTPUT
Enter the number of elements: 5
Enter 5 elements:
25
10
45
30
20
Largest element = 45

}
