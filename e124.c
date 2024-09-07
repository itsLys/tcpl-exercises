/*

#include <stdio.h>

int main() {
    int i, n = 10;
    printf("Numbers from 1 to %d:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    int sum = 0;
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    printf("Sum of numbers from 1 to %d is %d\n", n, sum);

    return 0;
}

*/

#include <stdio.h>
int main()
{
	int i = 0;
	int c;
	while ((c = getchar()) != EOF)
		i++;
	printf("\n%d\n", i);
}
