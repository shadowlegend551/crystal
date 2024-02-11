#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conversions.h"

// Returns base*10^power
int ten_pow(int base, int power)
{
    for(int i = 1; i < power; i++)
    {
        base *= 10;
    }

    return base;
}


// Converts a character to a digit.
int ctoi(char character)
{
    // A number character in ASCII is 48 bigger than its numerical value.
    // 0's ASCII value is 48 so we can use it.
    return (int)character - '0';
}

int stoi(char* string)
{
    int is_negative = 0;
    int power_of_ten = 0;
    int return_value = 0;

    // If integer is negative, set is_negative flag and skip "-".
    if(*string == '-')
    {
        is_negative = 1;
        string++;
    }

    char* string_iterator = string;

    while(*string_iterator != '\0')
    {
        power_of_ten++;
        string_iterator++;
    }

    for(; power_of_ten > 0; power_of_ten--)
    {
        return_value += ten_pow(ctoi(*string), power_of_ten);
        string++;
    }

    return_value = is_negative ? return_value*-1 : return_value;
    return return_value;


}

char* dtos(double number)
{
    // Minus-sign is 1 character, 32-bit integer is 10 characters,
    // decimal point is one character and the decimal part is 15.
    // Total maximum length is thus 26.
    int STRING_MAX_LENGTH = 26;

    char* string = malloc(STRING_MAX_LENGTH);
    sprintf(string, "%f", number);
    return string;

}

double stod(char* string)
{
    char* whole_part_ptr = string;
    char* whole_part_end = string;
    int whole_length = 0;

    // Convert the whole part to double.
    while(*whole_part_end && *whole_part_end != '.')
    {

        whole_part_end++;
        whole_length++;
    }

    whole_part_ptr = malloc(whole_length+1);
    strncpy(whole_part_ptr, string, whole_length);
    whole_part_ptr[whole_length] = '\0';

    double whole_part = stoi(whole_part_ptr);
    free(whole_part_ptr);

    // Convert the fraction part, if it exists.
    if(*whole_part_end)
    {
        char* fraction_part_begin = whole_part_end+1;
        char* fraction_part_end = fraction_part_begin;
        int fraction_length = 0;

        while(*fraction_part_end)
        {
            fraction_length++;
            fraction_part_end++;
        }

        char* fraction_part_ptr = malloc(fraction_length+1);
        strncpy(fraction_part_ptr, fraction_part_begin, fraction_length);
        fraction_part_ptr[fraction_length] = '\0';

        double fraction_part = stoi(fraction_part_ptr);
        free(fraction_part_ptr);

        // Same as fraction_part * 10^-fraction_length.
        for(int i = 0; i < fraction_length; i++)
        {
            fraction_part /= 10;
        }
        return whole_part + fraction_part;
    }

    return whole_part;
}
