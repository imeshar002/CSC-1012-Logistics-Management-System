#include <stdio.h>
#include "calculations.h"
#include "cities.h"
void calculateDelivery(int source,int destination,int distance,int weight,int rate,int speed,int efficiency,int fuelPrice
){
    if(distance<=0||rate<=0||speed<=0||efficiency<=0){
            printf("Invalid parameters for delivery calculation,\n\n");
            return;
    }
    double deliveryCost=distance*rate*(1+(weight/10000.0));
    double estimatedTime=(double)distance/speed;
    double fuelUsed=(double)distance/efficiency;
    double fuelCost=fuelUsed*fuelPrice;
    double totalOperationalCost=deliveryCost+fuelCost;
    double profit=deliveryCost*0.25;
    double customerCharge=totalOperationalCost+profit;

    printf("\n============================================\n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("----------------------------------------------\n");
    printf("From: %s\n",cityList[source]);
    printf("To: %s\n",cityList[destination]);
    printf("Weight: %d kg\n",weight);
    printf("----------------------------------------------\n");
    printf("Base Cost: %d × %d × (1 + %d/10000) = %.2f LKR\n", distance, rate, weight, deliveryCost);
    printf("Fuel Used: %.2f L\n",fuelUsed);
    printf("Fuel Cost: %.2f LKR\n",fuelCost);
    printf("Operational Cost: %.2f LKR\n",totalOperationalCost);
    printf("Profit: %.2f LKR\n",profit);
    printf("Customer Charge: %.2f LKR\n",customerCharge);
    printf("Estimated Time: %.2f hours\n",estimatedTime);
    printf("===============================================\n");
}
