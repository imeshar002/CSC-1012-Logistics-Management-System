#include <stdio.h>
#include "delivery.h"
Delivery deliveries[MAX_DELIVERIES];
int deliveryCount = 0;
void addDelivery(int totalCities,int vehicleCapacities[])
{
    if(deliveryCount >= MAX_DELIVERIES)
    {
        printf("Delivery limit reached!\n\n");
        return;
    }
    int source,destination,weight,vehicleType;
    printf("Enter source city index (0 to %d): ",totalCities-1);
    scanf("%d",&source);
    while(getchar()!='\n');
    printf("Enter destination city index (0 to %d): ",totalCities-1);
    scanf("%d",&destination);
    while(getchar()!='\n');
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
}
