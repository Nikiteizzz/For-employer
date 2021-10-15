#include "coding.h"

void decodeProductionName(production* arr, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < arr[i].name_of_production.length(); j++) {
            if (arr[i].name_of_production[j] == '_') {
                arr[i].name_of_production[j] = ' ';
            }
        }
    }
}

void codeProductionName(production* arr, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < arr[i].name_of_production.length(); j++) {
            if (arr[i].name_of_production[j] == ' ') {
                arr[i].name_of_production[j] = '_';
            }
        }
    }
}
