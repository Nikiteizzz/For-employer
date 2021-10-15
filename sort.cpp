#include "sort.h"

void sortByDate(production* arr, int count) {
    cout << "Как вы хотите отсортировать записи?\n1 - Сверху старые записи\n2 - Сверху новые записи\n0 - Отмена\nДействие: ";
    int mode;
    mode = checkNumericInRange(0, 2);
    switch (mode) {
    case 1: system("cls"); waningSortDay(arr, count); break;
    case 2: system("cls"); sortIncreaseDay(arr, count); break;
    }
}

void waningSortDay(production* arr, int count) {
    production buff;
    int day_buff_1, day_buff_2;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            day_buff_1 = arr[j].date.year * 10000 + arr[j].date.month * 100 + arr[j].date.day;
            day_buff_2 = arr[i].date.year * 10000 + arr[i].date.month * 100 + arr[i].date.day;
            if (day_buff_2 > day_buff_1) {
                swap(arr[j].count_of_production, arr[i].count_of_production);
                swap(arr[j].date, arr[i].date);
                swap(arr[j].name_of_production, arr[i].name_of_production);
                swap(arr[j].number_of_workshop, arr[i].number_of_workshop);
                swap(arr[j].worker, arr[i].worker);

            }
        }
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");
}

void sortIncreaseDay(production* arr, int count) {
    production buff;
    int day_buff_1, day_buff_2;
    for (int i = 0; i < count-1; i++) {
        for (int j = i + 1; j < count; j++) {
            day_buff_1 = arr[j].date.year * 10000 + arr[j].date.month * 100 + arr[j].date.day;
            day_buff_2 = arr[i].date.year * 10000 + arr[i].date.month * 100 + arr[i].date.day;
            if (day_buff_2 < day_buff_1) {
                swap(arr[j].count_of_production, arr[i].count_of_production);
                swap(arr[j].date, arr[i].date);
                swap(arr[j].name_of_production, arr[i].name_of_production);
                swap(arr[j].number_of_workshop, arr[i].number_of_workshop);
                swap(arr[j].worker, arr[i].worker);

            }
        }
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");
}

void sortByWorkshopNum(production* arr, int count) {
    system("cls");
    cout << "Как вы хотите отсортировать записи?\n1 - Сверху цеха с большим номером\n2 - Сверху цеха с меньшим номером\n0 - Отмена\nДействие: ";
    int mode;
    mode = checkNumericInRange(0, 2);
    switch (mode) {
    case 1: increaseSortWorkNum(arr, count); break;
    case 2: waningSortWorkNum(arr, count); break;
    }
}

void waningSortWorkNum(production* arr, int count) {
    production buff;
    for (int i = 0; i < count -1; i++) {
        for (int j = i + 1; j < count ; j++) {
            if (arr[j].number_of_workshop < arr[i].number_of_workshop) {
                swap(arr[j].count_of_production, arr[i].count_of_production);
                swap(arr[j].date, arr[i].date);
                swap(arr[j].name_of_production, arr[i].name_of_production);
                swap(arr[j].number_of_workshop, arr[i].number_of_workshop);
                swap(arr[j].worker, arr[i].worker);
            }
        }
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");
}

void increaseSortWorkNum(production* arr, int count) {
    production buff;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[j].number_of_workshop > arr[i].number_of_workshop) {
                swap(arr[j].count_of_production, arr[i].count_of_production);
                swap(arr[j].date, arr[i].date);
                swap(arr[j].name_of_production, arr[i].name_of_production);
                swap(arr[j].number_of_workshop, arr[i].number_of_workshop);
                swap(arr[j].worker, arr[i].worker);
            }
        }
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");
}