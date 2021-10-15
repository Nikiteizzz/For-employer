#pragma once

#include "root.h"

void decodeProductionName(production* arr, int count);                         //Изменение знаков "_" на пробелы для записи в переменную
void codeProductionName(production* arr, int count);                           //Изменение пробелов на знак "_" для записи в файл
