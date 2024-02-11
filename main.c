#include "crystal.h"
#include "conversions.h"
#include "iolib/iolib.h"

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int array_length = 6;
    double* x = malloc(sizeof(double) * array_length);
    double* y = malloc(sizeof(double) * array_length);

    x[0] = 1.0;
    x[1] = 2.0;
    x[2] = 3.0;
    x[3] = 4.0;
    x[4] = 5.0;
    x[5] = 6.0;

    y[0] = 1.0;
    y[1] = 4.0;
    y[2] = 9.0;
    y[3] = 16.0;
    y[4] = 25.0;
    y[5] = 36.0;
    
    Model model = generate_model(x, y, array_length);

    char* input_string;
    double number;
    
    while(1)
    {
        printf("Enter number to predict: ");
        fflush(stdout);
        input_string = readstdinline();
        number = stod(input_string);

        printf("Prediction: %f\n\n", make_prediction(number, model));
    }
    return 0;
}
