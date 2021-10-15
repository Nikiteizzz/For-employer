#pragma once

#include "root.h"
#include "checks.h"
#include "work_with_arr_and_file.h"
#include "sort.h"
#include "searches.h"
#include "edit_info.h"

void addProdInfoInArr(production*& arr, int& count);                           //���������� ���������� � ����������� ��������� � ������
void deleteProdInfo(production*& arr, int& count);                             //�������� ���������� � ����������� ��������� �� �������
void editProdInfo(production* arr, int count);                                 //��������� ���������� � ����������� ��������� � �������
void individualTask(production* arr, int count);                               //������������� �������
void searchInProducton(production* arr, int count);                            //����� ���������� � ��������� � �������
void sortArr(production* arr, int count);									   //����������
void showProdArrElem(production element);                                      //����� �� ����� ���������� � ��������� �� ��������� ������
void showArrOfProd(production* arr, int count);                                //����� �� ����� ������� � ����������� � ����������� ����������