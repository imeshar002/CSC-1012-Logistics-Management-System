#include <stdio.h>
#include "distances.h"
#include "leastcost.h"
int visitedCities[MAX_CITIES];
int shortestDistance;
int shortestPath[MAX_CITIES];
int currentPath[MAX_CITIES];

void explorePaths(int currentCity,int destinationCity,int totalCities,int pathLength,int distanceSoFar){
    if(currentCity==destinationCity){
        if(distanceSoFar<shortestDistance){
            shortestDistance=distanceSoFar;
            for(int i=0;i<=pathLength;i++){
                shortestPath[i]=currentPath[i];
            }
    }
     return;
    }
    for(int nextCity=0;nextCity<totalCities;nextCity++){
        if(!visitedCities[nextCity]&&distanceMatrix[currentCity][nextCity]>0){
            visitedCities[nextCity]=1;
            currentPath[pathLength+1]=nextCity;
            explorePaths(nextCity,destinationCity,totalCities,pathLength+1,distanceSoFar+distanceMatrix[currentCity][nextCity]);
            visitedCities[nextCity]=0;
        }
    }
}
int calculateLeastDistance(int sourceCity,int destinationCity,int totalCities,int pathResult[]){
    shortestDistance=1000000;
    visitedCities[sourceCity]=1;
    currentPath[0]=sourceCity;
    explorePaths(sourceCity,destinationCity,totalCities,0,0);
    for(int i=0;i<totalCities;i++){
        pathResult[i]=shortestPath[i];
    }
    return shortestDistance;
}
