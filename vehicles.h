#ifndef VEHICLES.H
#define VEHICLES_H
#define TOTAL_VEHICLES 3
extern char vehicleNames[TOTAL_VEHICLES][20];
extern int vehicleCapacities[TOTAL_VEHICLES];
extern int vehicleRates[TOTAL_VEHICLES];
extern int vehicleSpeeds[TOTAL_VEHICLES];
extern int vehicleFuelEfficiency[TOTAL_VEHICLES];

void displayVehicles();
void getVehicleInfo(int vehicleType, int* capacity, int* rate, int* speed,int* fuelEfficiency);

#endif // VEHICLES
