#pragma once

#include<iostream>
#include<cstdlib>
#include<Windows.h>
#include<fstream>
#include <string>
#include <conio.h>
#include "sha256.h"


using namespace std;

const string FILE_DATA_ACCOUNTS = "D:\\accounts.txt";
const string FILE_DATA_PRODUCTION = "D:\\production.txt";
const int YEAR_RANGE = 60;

//Структура даты
struct date {             
    //День
    int day;
    //Месяц
    int month;
    //Год
    int year;
};

//ФИО рабочего
struct worker {         
    //Фамилия рабочего
    string surname_of_worker;
    //Имя рабочего
    string name_of_worker;
    //Отчество рабочего
    string patronymic_of_worker;
};
//Структра продукции(Дата, номер цеха, количество товара, ФИО ответственного, название продукта)
struct production { 
    //Дата
    struct date date;
    //Номер цеха
    int number_of_workshop;
    //Количество продукции
    int count_of_production;
    //ФИО рабочего
    struct worker worker;
    //Название продукции
    string name_of_production;
};
//Аккаунт
struct account {
    //Логин
    string login;
    //Пароль
    string password;
    //Роль (1 - admin, 0 - user)
    int role;       
    //Статус (1 - доступ есть, 0 - блокировка аккаунта, 2 - запрос на регистарцию)
    int accessLevel;  
};

/////////////////
void root();/////
/////////////////