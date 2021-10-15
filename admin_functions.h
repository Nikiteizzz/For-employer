#pragma once

#include "root.h"
#include "checks.h"
#include "work_with_arr_and_file.h"

void viewAccountInfo(account* arr, int count);                                 //�������� ���������� ��� ���� ���������
void deleteAccontFromData(account*& arr, int& count, account current_user);    //�������� �������� �� �������
void editInfoaCC(account* arr, int count, account current_user);               //��������� ������ ���������� ��������
void addAccountInArr(account*& arr, int& count);                               //���������� �������� � ������
void registerNewAccount(account*& arr, int& count);                            //������� ��� ����������� ������ ��������      
