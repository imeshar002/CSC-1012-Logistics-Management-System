#include <stdio.h>
#include "cities.h"
#include "distances.h"
#include "vehicles.h"
#include "delivery.h"
#include "calculations.h"
#include "leastcost.h"

int main()
{
    int choice;
    while(1)
    {
        printf("==== Logistics Management System ====\n");
        printf("1.Manage Cities\n");
        printf("2.Manage Distances\n");
        printf("3.Manage Vehicles\n");
        printf("4.Manage Deliveries\n");
        printf("5.Reports\n");
        printf("0.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        while(getchar()!='\n');

        switch(choice)
        {
        case 1:
        {
            printf("\n--- City Management ---\n");
            printf("1. Display Cities\n");
            printf("2. Add City\n");
            printf("3. Rename City\n");
            printf("4. Remove City\n");
            printf("0. Back to Main Menu\n");
            printf("Enter your choice: ");
            int cityChoice;
            scanf("%d", &cityChoice);
            while(getchar() != '\n');

            switch(cityChoice)
            {
            case 1:
                displayCities();
                break;
            case 2:
                addCity();
                break;
            case 3:
                renameCity();
                break;
            case 4:
                removeCity();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n\n");
            }
            break;
        }
        case 2:
        {
            printf("\n--- Distance Management ---\n");
            printf("1. Display Distances\n");
            printf("2. Set/Edit Distance\n");
            printf("0. Back to Main Menu\n");
            printf("Enter your choice: ");
            int distanceChoice;
            scanf("%d", &distanceChoice);
            while(getchar() != '\n');

            switch(distanceChoice)
            {
            case 1:
                displayDistances(totalCities);
                break;
            case 2:
                setDistance(totalCities);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n\n");
            }
            break;
        }


        case 3:
        {
            int vehicleChoice;
            printf("\n--- Vehicle Management ---\n");
            printf("1. Display Vehicles\n");
            printf("2. Get Vehicle Info\n");
            printf("0. Back to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d",&vehicleChoice);
            while(getchar()!='\n');
            switch(vehicleChoice)
            {
            case 1:
                displayVehicles();
                break;
            case 2:
            {
                int type;
                printf("Enter vehicle type (1-%d): ",TOTAL_VEHICLES);
                scanf("%d",&type);
                while(getchar()!='\n');
                int capacity, rate, speed, efficiency;
                getVehicleInfo(type-1,&capacity, &rate,&speed, &efficiency);
                printf("\nVehicle Info:\n");
                printf("Capacity: %d kg\n", capacity);
                printf("Rate per km: %d LKR\n", rate);
                printf("Average Speed: %d km/h\n", speed);
                printf("Fuel Efficiency: %d km/l\n\n", efficiency);
                break;
            }
            case 0:
                break;
            default:
                printf("Invalid choice!\n\n");
            }
            break;
        }
        case 4:
        {
            int deliveryChoice;
            while(1)
            {
                printf("\n--- Delivery Request Handling ---\n");
                printf("1. Add Delivery\n");
                printf("2. View Delivery Records\n");
                printf("0. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d",&deliveryChoice);
                while(getchar()!='\n');

                switch(deliveryChoice)
                {
                case 1:
                    addDelivery(totalCities,vehicleCapacities);
                    if(deliveryCount>0)
                    {
                        Delivery d=deliveries[deliveryCount-1];
                        int path[MAX_CITIES];
                        int minDistance=calculateLeastDistance(d.source-1,d.destination-1,totalCities,path);
                        int capacity,rate,speed,efficiency;
                        getVehicleInfo(d.vehicleType,&capacity,&rate,&speed,&efficiency);
                        calculateDelivery(d.source-1, d.destination-1, minDistance, d.weight, rate, speed, efficiency, 310);
                    }
                    break;
                case 2:
                    displayDeliveries();
                    break;
                case 0:
                    goto endDeliveryMenu;
                default:
                    printf("Invalid choice!\n\n");
                }
            }
endDeliveryMenu:
            break;
        }
                case 5:
                    showReports();
                    break;
        case 0:
            printf("Exiting program.\n");
            return 0;


        default:
            printf("Invalid choice!\n\n");
            break;

        }

    }
    return 0;
}




