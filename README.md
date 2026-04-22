# CodeDNA++

A C program that checks how similar two C files are by looking at 9 different things about the code.

## What it does

You give it .c files, it tells you how similar they are using 4 different similarity formulas and gives an average score.

## How to run

```bash
make
./codedna

    What you can do:
Compare 2 files

Compare multiple files (2-10)

Compare all .c files in a folder

    How it works:
Reads the .c files

Breaks the code into tokens (words, operators, etc.)

Extracts 9 metrics:

Lexical: keywords, operators, identifiers, comments

Structural: lines of code, function count, cyclomatic complexity, nesting depth, statement length

Builds a feature vector (9 numbers)

Calculates 4 similarities: Cosine, Euclidean, Jaccard, Manhattan

Averages them to get a hybrid score

Shows results in a table with bar graphs

    Sample files:
The test folder has 3 sample files:

sample1.c - math operations (add, subtract, multiply, divide)

sample2.c - string stuff (reverse string, count vowels)

sample3.c - matrix operations (print matrix, transpose)

    Results:
When you compare sample1 and sample2 (math vs string) you get around 0.71 hybrid similarity.
When you compare sample1 and sample3 (both math) you get around 0.79.
So it works.

    References I used :

McCabe (1976) - for cyclomatic complexity

Singhal (2001) - for cosine similarity

Deza & Deza (2009) - for Euclidean distance

Jaccard (1901) - for Jaccard similarity

Aggarwal (2001) - for Manhattan distance  (used instead of Levenshtein edit distance because Manhattan works better for numerical vectors and high-dimensional data)

Fedorov (2024) - for hybrid similarity

    Project stats :
1235 lines of code

21 .c files

20 .h files

No external libraries

Files
text
CodeDNA++/
├── include/ (all header files)
├── src/ (all source files)
├── test/ (sample .c files)
└── Makefile
            Author:
            Fahmida Hossain
            Exam Roll: 245446
            IIT, University of Dhaka

            Supervisor: Toukir Ahammed
        