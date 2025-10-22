//cities.c

#include <stdio.h>
#include <string.h>
#include "cities.h"

char cityList[MAX_CITIES][MAX_CITY_LENGTH];
int totalCities=0;

void displayCities(){
if(totalCities==0){
    printf("No cities have been added yet\n\n");
    return;
}
printf("Available cities:\n\n");
for (int i=0;i<totalCities;i++)
{
    printf("%d.%s\n",i+1,cityList[i]);
}
}
void addCity(){
if (totalCities>=MAX_CITIES){
printf("Maximum city count reached. Unable to add more cities.\n\n");
return;
}
char newName[MAX_CITY_LENGTH];
printf("Enter the name of the city: ");
fgets(newName,MAX_CITY_LENGTH,stdin);
newName[strcspn(newName, "\n")]='\0';

for(int i=0;i<totalCities;i++){
    if(strcmp(cityList[i],newName)==0){
        printf("This is an already existing city!\n\n");
        return;
    }
}
strcpy(cityList[totalCities], newName);
totalCities++;
printf("City added successfully.\n\n");
}

void renameCity(){
    if(totalCities==0){
        printf("No cities to rename!\n\n");
        return;
    }
    displayCities();
    int cityNum;
    printf("Enter the city number to rename: ");
    scanf("%d",&cityNum);
    while(getchar()!='\n');

    if(cityNum<1||cityNum>totalCities){
        printf("Invalid number!\n\n");
        return;
    }
    char newName[MAX_CITY_LENGTH];
    printf("Enter the name of the city: ");
    fgets(newName,MAX_CITY_LENGTH,stdin);
    newName[strcspn(newName, "\n")]='\0';

    for(int i=0;i<totalCities;i++){
        if(strcmp(cityList[i],newName)==0){
            printf("This city already exists!\n\n");
            return;
        }
    }
    strcpy(cityList[cityNum-1],newName);
    printf("City renamed successfully.\n\n");
}

void removeCity(){
    if(totalCities==0){
        printf("No cities available to remove.\n\n");
        return;
    }
    displayCities();
    int cityNum;
    printf("Enter city number to remove: ");
    scanf("%d",&cityNum);
    while(getchar()!='\n');

    if(cityNum<1||cityNum>totalCities){
        printf("Invalid number!\n\n");
        return;
    }
    for(int i=cityNum-1;i<totalCities-1;i++){
        strcpy(cityList[i],cityList[i+1]);
    }
    totalCities--;
    printf("City removed successfully.\n\n");
}
