#pragma once

#include "root.h"

int getCountOfAccounts();                                                      //�������� ���������� ��������� � �����
void getArrOfAccounts(account* arr, int count);                                //��������� ������ ���������� �� �����
void writeArrInFile(account* arr, int count);                                  //������ ������� ��������� � ����
int getCountOfProduction();                                                    //��������� ���������� ������� � ����������� ��������� �� �����
void getArrOfProduction(production* arr, int count);                           //���������� ������� ����������� � ����������� ���������
void writeProdArrInFile(production* arr, int count);                           //������ ������� � ����������� � ���������� ���������� � ����
void deleteUserWithNumber(account*& arr, int& count, int chosenAccount);       //�������� ������������ �� ������� � �������� �������, ������������ � �������
void addAdminAccount();                                                        //� ������ ���������� �����-���� ��������� � ����� ������ ������� �������������� � ������� ��� ����� "admin" "admin"
bool checkRegRequest(account* arr, int count);                                 //����� �������� �� �����������