#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

RootCalc(double x, int k, double e, double y, double b);
main()
{

    int k;
    double x, e;
    double y = 1.0;
    double b = 1.0;

    char x_n[50]; // Creating arrays to temporarily store input. Part of the bug fix for getting a number or character stuck in scanf

    char k_n[10];

    char e_n[18];

    while (1)
    { // simple check
        printf("Enter a number you want to get a root from: ");
        fgets(x_n, sizeof(x_n)-1, stdin); // Receiving unformatted input
        x = strtod(x_n, NULL); // Formatting
        

        printf("Enter the k-power of a root: ");
        fgets(k_n, sizeof(k_n)-1, stdin);
        k = strtod(k_n, NULL);
        

        printf("Enter precision : ");
        fgets(e_n, sizeof(e_n)-1, stdin);
        e = strtod(e_n, NULL);
        

        if (k > 0 && k % 2 == 0 && x < 0)
        {
            printf("\nError. If a root has even power, x must be greater or equal zero. Try again. \n\n");
        }

        else if (k == 0)
        {
            printf("\nError. Power cannot be equal zero or have a floating point. Try again. \n\n");
        }

        else if (e <= 0 || e > 1)
        {
            printf("\nError. Precision must be between 1.00e-15 and 1. Try again. \n"); // Explanation: if the accuracy is higher than e-15, the program loops. To avoid this, a limit is necessary.
        }

        else if (k < 0)
        {

            if (k % 2 == 0 && x <= 0)
            {
                printf("\nError. If a root has an even negative power, x must be greater than zero. Try again. \n\n");
            }
            else if (k % 2 != 0 && x == 0)
            {
                printf("\nError. If a root has an odd negative power, x must not be equal zero. Try again. \n\n");
            }
            else
            {               // Explanation: the program cannot handle negative powers of a root properly. Therefore, using the properties, it is converted to a favourable form.
                k = abs(k); // abs is used to calculate the absolute value of integer numbers
                x = 1 / x;
                break;
            }
        }

        else
        { // If all conditions are met, the check cycle stops and the program moves on
            break;
        }
    }

    RootCalc(x, k, e, y, b);

    return 0;
}
RootCalc(double x, int k, double e, double y, double b)
{
    int itt = 1; // Iteration counter
    while (fabs(b) >= e)
    {

        if (x == 0 || x == 1)
        { // Basic case 1.
            printf("y = %f", x);
            break;
        }
        else if (k == 1)
        { // Basic case 2.
            printf("y = %f", x);
            break;
        }

        else
        { // Çàãàëüíà ôóíêö³ÿ
            double yk = pow(y, k - 1);

            b = (1.0 / k) * ((x / yk) - y);
            y = y + b;

            printf("Iteration: %d\n", itt);
            printf("delta: %0.10f\n", b); // Increase output accuracy to 10 decimal places
            printf("y = %0.10f\n\n", y);
        }
        itt = itt + 1;
    }
}
