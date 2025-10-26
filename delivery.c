#include <stdio.h>
#include "delivery.h"
#include "vehicles.h"
#include "distances.h"
#include "cities.h"
#include "calculations.h"
Delivery deliveries[MAX_DELIVERIES];
int deliveryCount = 0;
void addDelivery(int totalCities,int vehicleCapacities[])
{
    if(deliveryCount >= MAX_DELIVERIES)
    {
        printf("Delivery limit reached!\n\n");
        return;
    }
    if(totalCities<2){
        printf("At least two cities are required to make a delivery.\n\n");
        return;
    }
    int source,destination,weight,vehicleType;
    printf("Enter source city index (1 to %d): ",totalCities);
    scanf("%d",&source);
    while(getchar()!='\n');
    printf("Enter destination city index (1 to %d): ",totalCities);
    scanf("%d",&destination);
    while(getchar()!='\n');
    if (source< 1||source>totalCities||destination<1||destination>totalCities)
    {
        printf("Invalid city numbers!\n\n");
        return;
    }
    if(source==destination){
        printf("Error: Source and destination cannot be the same!\n\n");
        return;
    }
    printf("Enter weight (kg): ");
    scanf("%d",&weight);
    while(getchar()!='\n');
    printf("Select vehicle type (1=Van, 2=Truck, 3=Lorry): ");
    scanf("%d",&vehicleType);
    while(getchar()!='\n');

    if(vehicleType<1||vehicleType>3){
        printf("Invalid vehicle type!\n\n");
        return;
    }
    if(weight>vehicleCapacities[vehicleType-1]){
        printf("Error: Weight exceeds selected vehicle capacity (%d kg)!\n",vehicleCapacities[vehicleType-1]);
        return;
    }
    deliveries[deliveryCount].source=source;
    deliveries[deliveryCount].destination=destination;
    deliveries[deliveryCount].weight=weight;
    deliveries[deliveryCount].vehicleType=vehicleType;
    deliveryCount++;
    printf("Delivery added successfully!\n");

    int distance=distanceMatrix[source-1][destination-1];
    if(distance<=0){
        printf("Warning: Distance between %s and %s not set yet.\n\n");
        return;
}
int capacity,rate,speed,efficiency;
getVehicleInfo(vehicleType,&capacity,&rate,&speed,&efficiency);
calculateDelivery(source-1, destination-1, distance, weight, rate, speed, efficiency, 310);

}
