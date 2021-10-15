#pragma once

#include "root.h"

int getCountOfAccounts();                                                      //Получает количество аккаунтов в файле
void getArrOfAccounts(account* arr, int count);                                //Заполняет массив аккаунтами из файла
void writeArrInFile(account* arr, int count);                                  //Запись массива аккаунтов в файл
int getCountOfProduction();                                                    //Получение количества записей о выпускаемой продукции из файла
void getArrOfProduction(production* arr, int count);                           //Заполнение массива информацией о выпускаемой продукции
void writeProdArrInFile(production* arr, int count);                           //Запись массива с информацией о выпскаемой продукцией в файл
void deleteUserWithNumber(account*& arr, int& count, int chosenAccount);       //Удаление пользователя из массива с заданным номером, передаваемым в функцию
void addAdminAccount();                                                        //В случае отсутствия каких-либо аккаунтов в файле создаёт аккаунт администратора с данными для входа "admin" "admin"
bool checkRegRequest(account* arr, int count);                                 //Поиск запросов на регистрацию