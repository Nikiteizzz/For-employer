#pragma once

#include "root.h"

string enterPassword();                                                        //������� ����� ������(������ �� ��������)
string checkForEnters();                                                       //�������� �������� ���������� �� �������
int checkNumeric();                                                            //������� ����� �� �����������
int checkNumericInRange(int a, int b);                                         //�������� ����� ����� � ������ ���������
int checkNumberCONST(int a, int b);                                            //�������� ��������� ����� �� �������������� ������ �� ����������
int checkNumberCONST(int a, int b, int c);                                     //�������� ��������� ����� �� �������������� ������ �� ����������
string checkForUniqueLogin(account* arr, int count);                           //�������� ������������ ��������� ������    
string enterProdName();                                                        //���� ������������ ������������ ������� (�������� ���� ������� "_")
int enterDay(int month, int year);                                             //���� ��� (�������� �� ���� � ������)
string enterTextInfo();                                                        //�������� ����� ��������� ����������
