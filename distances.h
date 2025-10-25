#ifndef DISTANCES_H
#define DISTANCES_H
#include "cities.h"

void displayDistances(int totalCities);
void setDistance(int totalCities);
extern int distanceMatrix[MAX_CITIES][MAX_CITIES];
extern int totalCities;
#endif // DISTANCES_H
