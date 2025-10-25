#ifndef DELIVERY_H
#define DELIVERY_H
#define MAX_DELIVERIES 50
typedef struct {
    int source;
    int destination;
    int weight;
    int vehicleType;
}
Delivery;
extern Delivery deliveries[MAX_DELIVERIES];
extern int deliveryCount;
void addDelivery(int totalCities,int vehicleCapacities[]);
#endif // DELIVERY_H
