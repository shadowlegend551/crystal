#include <stdlib.h>

#include "crystal.h"

double avg(double* array, const int LENGTH)
{
    double sum = 0;

    for(int i = 0; i < LENGTH; i++)
    {
        sum += array[i];
    }

    return sum / LENGTH;
}


double yintercept(double* x_set, double* y_set, int DATASET_LENGTH, double slope)
{
    double MEAN_X = avg(x_set, DATASET_LENGTH);
    double MEAN_Y = avg(y_set, DATASET_LENGTH);

    return MEAN_Y - slope * MEAN_X;
}


double ordinary_least_squares(double* x_set, double* y_set, int DATASET_LENGTH)
{

    double MEAN_X = avg(x_set, DATASET_LENGTH);
    double MEAN_Y = avg(y_set, DATASET_LENGTH);

    double sum_of_slopes = 0;
    double sum_of_squares = 0;

    double x, y;

    for(int i = 0; i < DATASET_LENGTH; i++)
    {
        x = x_set[i];
        y = y_set[i];

        // Numerator.
        sum_of_slopes += (x - MEAN_X) * (y - MEAN_Y);

        // Denominator.
        sum_of_squares += (x - MEAN_X) * (x - MEAN_X);
    }
    
    return sum_of_slopes / sum_of_squares;
}


Model generate_model(double* x_set, double* y_set, int DATASET_LENGTH)
{
    double slope = ordinary_least_squares(x_set, y_set, DATASET_LENGTH);
    double interc = yintercept(x_set, y_set, DATASET_LENGTH, slope);

    Model model;
    model.slope = slope;
    model.yintercept = interc;

    return model;
}


double make_prediction(double x, Model model)
{
    return x * model.slope + model.yintercept;
}


double mse(double* set, int set_length, double (*prediction_function)(double))
{
    double* sums = malloc(sizeof(double) * set_length);
    if(!sums)
    {
        free(sums);
        exit(1);
    }
}