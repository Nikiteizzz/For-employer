#include "edit_info.h"
#include "ctime"

void editProdWorker(production& element) {
    system("cls");
    cout << "�������: " << element.worker.surname_of_worker << endl;
    cout << "���: " << element.worker.name_of_worker << endl;
    cout << "��������: " << element.worker.patronymic_of_worker << endl;
    cout << "��� ������ �� ������ ��������:\n1 - �������\n2 - ���\n3 - ��������" << endl;
    cout << "��������: ";
    int mode = checkNumericInRange(1, 3);
    switch (mode) {
    case 1: cout << "������� ����� �������: "; element.worker.surname_of_worker = enterTextInfo(); cout << "��������� �������!" << endl; system("pause"); system("cls"); break;
    case 2: cout << "������� ����� ���: "; element.worker.name_of_worker = enterTextInfo(); cout << "��������� �������!" << endl; system("pause"); system("cls"); break;
    case 3: cout << "������� ����� ��������: "; element.worker.patronymic_of_worker = enterTextInfo(); cout << "��������� �������!" << endl; system("pause"); system("cls"); break;
    }
}

void editDate(production& element) {
    system("cls");
    int buffYear = time(NULL) / 31536000 + 1970;
    cout << "���: " << element.date.year << endl;
    cout << "�����: " << element.date.month << endl;
    cout << "����: " << element.date.day << endl;
    cout << "��� �� ������ ��������:\n1 - ���\n2 - �����\n3 - ����\n��������: ";
    int mode;
    mode = checkNumericInRange(1, 3);
    switch (mode) {
    case 1: cout << "������� ����� ���: "; element.date.year = checkNumericInRange(buffYear - YEAR_RANGE, buffYear); cout << "��������� �������!" << endl; system("pause"); system("cls"); break;
    case 2: cout << "������� ����� �����: "; element.date.month = checkNumericInRange(1, 12); cout << "��������� �������!" << endl; system("pause"); system("cls"); break;
    case 3: cout << "������� ����� ����"; element.date.day = enterDay(element.date.month, element.date.year); cout << "��������� �������" << endl; system("pause"); system("cls"); break;
    }
}
