#include <stdio.h>
#include "vehicles.h"

char vehicleNames[3][20]= {"Van","Truck","Lorry"};
int vehicleCapacities[3]= {1000,5000,10000};
int vehicleRates[3]= {30,40,80};
int vehicleSpeeds[3]= {60,50,45};
int vehicleFuelEfficiency[3]= {12,6,4};

void displayVehicles()
{
    printf("Available Vehicles:\n\n");
    for(int i=0; i<3; i++)
    {
        printf("%d. %s\n",i+1,vehicleNames[i]);
        printf("  Capacity: %d kg\n",vehicleCapacities[i]);
        printf("  Rate per km: %d LKR\n",vehicleRates[i]);
        printf("  Average Speed: %d km",vehicleSpeeds[i]);
        printf("  Fuel Efficiency: %d km/l\n\n",vehicleFuelEfficiency[i]);
    }
}
void getVehicleInfo(int vehicleType,int* capacity, int* rate, int* speed, int* fuelEfficiency){
    int idx;
    if(vehicleType<1||vehicleType>3){
        *capacity=0;
        *rate=0;
        *speed=0;
        *fuelEfficiency=0;
        return;
    }
    idx=vehicleType-1;
    *capacity=vehicleCapacities[idx];
    *rate=vehicleRates[idx];
    *speed=vehicleSpeeds[idx];
    *fuelEfficiency=vehicleFuelEfficiency[idx];
}
