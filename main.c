#include <stdio.h>
#include "cities.h"

int main() {
    printf("Testing city management...\n\n");

    addCity();
    displayCities();
    renameCity();
    displayCities();
    removeCity();
    displayCities();

    return 0;
}
