//distances.c

#include <stdio.h>
#include "distances.h"

int distanceMatrix[MAX_CITIES][MAX_CITIES]={0};

void displayDistances(int totalCities){
    if(totalCities==0){
        printf("No cities have been added yet. No distances to show.\n\n");
        return;
    }
    printf("\nDistance Table:\n\n");
    printf("       ");
    for(int cityIndex=0; cityIndex<totalCities;cityIndex++){
        printf("%5d",cityIndex+1);
    }
    printf("\n");
    for(int row=0;row<totalCities;row++){
        printf("%5d",row+1);
        for(int col=0;col<totalCities;col++){
            printf("%5d",distanceMatrix[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}
void setDistance(int totalCities){
    if(totalCities<2){
        printf("Need at least two cities to set a distance!\n\n");
        return;
    }
    int cityFrom, cityTo, kmDistance;
    printf("Enter the source city number (1-%d): ",totalCities);
    scanf("%d",&cityFrom);
    while(getchar()!='\n');
    printf("Enter the destination city number (1-%d): ",totalCities);
    scanf("%d",&cityTo);
    while(getchar()!='\n');
    if(cityFrom<1||cityFrom>totalCities||cityTo<1||cityTo>totalCities){
        printf("Invalid city numbers!\n\n");
        return;
    }
    if(cityFrom==cityTo){
        printf("Distance from a city to itself is always 0.\n\n");
        return;
    }
    printf("Enter the distance between city %d and city %d (km):",cityFrom,cityTo);
    scanf("%d",&kmDistance);
    while(getchar()!='\n');

    distanceMatrix[cityFrom-1][cityTo-1]=kmDistance;
    distanceMatrix[cityTo-1][cityFrom-1]=kmDistance;

    printf("Distance successfully updated!\n\n");
}
