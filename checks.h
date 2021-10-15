#pragma once

#include "root.h"

string enterPassword();                                                        //Функция ввода пароля(замена на звёздочки)
string checkForEnters();                                                       //Проверка вводимой информации на пробелы
int checkNumeric();                                                            //Проерка ввода на численность
int checkNumericInRange(int a, int b);                                         //Проверка ввода числа в нужном диапазоне
int checkNumberCONST(int a, int b);                                            //Проверка вводимого числа на принадлежность одному из параметров
int checkNumberCONST(int a, int b, int c);                                     //Проверка вводимого числа на принадлежность одному из параметров
string checkForUniqueLogin(account* arr, int count);                           //Проверка уникальности вводимого логина    
string enterProdName();                                                        //Ввод наименования выпускаемого изделия (запрещён ввод символа "_")
int enterDay(int month, int year);                                             //Ввод дня (проверка по году и месяцу)
string enterTextInfo();                                                        //Проверка ввода текстовой информации
