#pragma once

#include "root.h"
#include "work_with_arr_and_file.h"
#include "checks.h"
#include "sha256.h"

account logging(account* arr, int count);                                      //Функция входа в аккаунт
void askForRegistration();                                                     //Создание запроса на регистрацию аккаунта            