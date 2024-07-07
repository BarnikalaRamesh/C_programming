/* Find smallest and largest number in an array */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
        int arr[30];
        int i;
        int smallest, largest;

        /* assign array elements randomly */
        printf("Assigning array with random values\n");

        srand(getpid());
        for (i = 0; i < 30; i++) {
                arr[i] = rand()%100;
        }
        printf("printing array values:\n");
        for (i = 0; i < 30; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");

        smallest = arr[0];
        largest = arr[0];

        for (i = 1; i < 30; i++) {
                if (arr[i] < smallest)
                        smallest = arr[i];
                else if (arr[i] > largest)
                        largest = arr[i];
        }
        printf("smallest number = %d\nlargest number = %d\n", smallest, largest);
        return 0;

}