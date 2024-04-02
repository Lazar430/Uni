#ifndef RANDOM_H
#define RANDOM_H

unsigned* makeRandArray(unsigned seed, unsigned n);

int* makeRandLimitArray(int seed, unsigned n, int a, int b);

int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned));

#endif
