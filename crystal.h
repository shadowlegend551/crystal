#ifndef CRYSTAL_H
#define CRYSTAL_H

typedef struct Model
{
    double slope;
    double yintercept;
} Model;


typedef struct SecondDegree
{
    // ax^2 + bx + c
    double a;
    double b;
    double c;
} SecondDegree;

Model generate_model(double* x_set, double* y_set, int DATASET_LENGTH);

double mse(double* set, int set_length, double (*prediction_function)(double));

double make_prediction(double x, Model model);

#endif
