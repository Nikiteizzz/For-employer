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

//��������� ����
struct date {             
    //����
    int day;
    //�����
    int month;
    //���
    int year;
};

//��� ��������
struct worker {         
    //������� ��������
    string surname_of_worker;
    //��� ��������
    string name_of_worker;
    //�������� ��������
    string patronymic_of_worker;
};
//�������� ���������(����, ����� ����, ���������� ������, ��� ��������������, �������� ��������)
struct production { 
    //����
    struct date date;
    //����� ����
    int number_of_workshop;
    //���������� ���������
    int count_of_production;
    //��� ��������
    struct worker worker;
    //�������� ���������
    string name_of_production;
};
//�������
struct account {
    //�����
    string login;
    //������
    string password;
    //���� (1 - admin, 0 - user)
    int role;       
    //������ (1 - ������ ����, 0 - ���������� ��������, 2 - ������ �� �����������)
    int accessLevel;  
};

/////////////////
void root();/////
/////////////////