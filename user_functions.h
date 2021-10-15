#pragma once

#include "root.h"
#include "checks.h"
#include "work_with_arr_and_file.h"
#include "sort.h"
#include "searches.h"
#include "edit_info.h"

void addProdInfoInArr(production*& arr, int& count);                           //Добавление информации о выпускаемой продукции в массив
void deleteProdInfo(production*& arr, int& count);                             //Удаление информации о выпускаемой продукции из массива
void editProdInfo(production* arr, int count);                                 //Изменение информации о выпускаемой продукции в массиве
void individualTask(production* arr, int count);                               //Индвидуальное задание
void searchInProducton(production* arr, int count);                            //Поиск информации о продукции в массиве
void sortArr(production* arr, int count);									   //Сортировка
void showProdArrElem(production element);                                      //Вывод на экран информации о продукции из выбранной записи
void showArrOfProd(production* arr, int count);                                //Вывод на экран массива с информацией о выпускаемой продукцией