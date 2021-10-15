#pragma once

#include "root.h"
#include "checks.h"
#include "user_functions.h"

void searchByName(production* arr, int count);                                 //Поиск по имени
void searchByDate(production* arr, int count);                                 //Поиск по дате
void searchByWorkshopNum(production* arr, int count);                          //Поиск по номеру цеха
void searchByWorkerName(production* arr, int count);                           //Поиск по ФИО ответственного