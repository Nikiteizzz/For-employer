#pragma once

#include "root.h"
#include "checks.h"
#include "admin_functions.h"
#include "coding.h"
#include "user_functions.h"


void adminPanelWithoutRegistr(account* arr, int count, account current_user);  //������ ��������������, ���� ��� �������� �� ����������� 1
void adminPanelWithRegistr(account* arr, int count, account current_user);     //������ ��������������, ���� ���� ������� �� ����������� 1
void userPanel(account current_user);                                          //������ ������������