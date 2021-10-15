#pragma once

#include "root.h"
#include "checks.h"
#include "work_with_arr_and_file.h"

void viewAccountInfo(account* arr, int count);                                 //Просмотр информации обо всех аккаунтах
void deleteAccontFromData(account*& arr, int& count, account current_user);    //Удаление аккаунта из массива
void editInfoaCC(account* arr, int count, account current_user);               //Изменение данных выбранного аккаунта
void addAccountInArr(account*& arr, int& count);                               //Добавление аккаунта в массив
void registerNewAccount(account*& arr, int& count);                            //Функция для регистрации нового аккаунта      
