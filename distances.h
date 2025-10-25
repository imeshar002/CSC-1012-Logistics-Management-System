#ifndef DISTANCES_H
#define DISTANCES_H
#include "cities.h"
extern int distanceMatrix[MAX_CITIES][MAX_CITIES];
void displayDistances(int totalCities);
void setDistance(int totalCities);
void removeDistancesForCity(int removed_index,int totalCities);
extern int totalCities;
#endif // DISTANCES_H
