#include <stdio.h>
#include "delivery.h"
#include "distances.h"
#include "reports.h"
void showReports()
{
    printf("\n===== Performance Reports =====\n");
    if (deliveryCount==0)
    {
        printf("No deliveries recorded yet.\n\n");
        return;
    }
    double totalDistance=0,totalTime=0,totalRevenue=0,totalProfit=0;
    double longestRoute=0,shortestRoute=1e9;
    int totalDeliveries=deliveryCount;
    for (int i = 0; i < deliveryCount; i++)
    {
        totalDistance += deliveries[i].distance;
        totalTime += deliveries[i].time;
        totalRevenue += deliveries[i].revenue;
        totalProfit += deliveries[i].profit;
        if (deliveries[i].distance > longestRoute)
            longestRoute = deliveries[i].distance;
        if (deliveries[i].distance < shortestRoute)
            shortestRoute = deliveries[i].distance;
    }
    printf("Total Deliveries Completed : %d\n", totalDeliveries);
    printf("Total Distance Covered     : %.2f km\n", totalDistance);
    printf("Average Delivery Time      : %.2f hours\n", totalTime / totalDeliveries);
    printf("Total Revenue              : %.2f LKR\n", totalRevenue);
    printf("Total Profit               : %.2f LKR\n", totalProfit);
    printf("Longest Route Completed    : %.2f km\n", longestRoute);
    printf("Shortest Route Completed   : %.2f km\n", shortestRoute);
    printf("=================================\n\n");
}

