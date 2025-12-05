#ifndef ASCII_OUTPUT_H
#define ASCII_OUTPUT_H

#include <stdio.h>

// Prints a horizontal bar for visualization
void print_bar(const char* label, double value, int max_length);

// Prints a table comparing two files
void print_metric_table(const char* file1, const char* file2,
                        double metrics1[], double metrics2[], int num_metrics);

#endif


