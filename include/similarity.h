#ifndef SIMILARITY_H
#define SIMILARITY_H

float cosine_similarity(float *a, float *b, int n);
float euclidean_distance(float *a, float *b, int n);
float jaccard_similarity(int a_only, int b_only, int common);
int edit_similarity(const char *s1, const char *s2);

#endif
