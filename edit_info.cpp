#include "edit_info.h"
#include "ctime"

void editProdWorker(production& element) {
    system("cls");
    cout << "Фамилия: " << element.worker.surname_of_worker << endl;
    cout << "Имя: " << element.worker.name_of_worker << endl;
    cout << "Отчество: " << element.worker.patronymic_of_worker << endl;
    cout << "Что именно вы хотите изменить:\n1 - фамилия\n2 - имя\n3 - отчество" << endl;
    cout << "Действие: ";
    int mode = checkNumericInRange(1, 3);
    switch (mode) {
    case 1: cout << "Введите новую фамилию: "; element.worker.surname_of_worker = enterTextInfo(); cout << "Выполнено успешно!" << endl; system("pause"); system("cls"); break;
    case 2: cout << "Введите новое имя: "; element.worker.name_of_worker = enterTextInfo(); cout << "Выполнено успешно!" << endl; system("pause"); system("cls"); break;
    case 3: cout << "Введите новое отчество: "; element.worker.patronymic_of_worker = enterTextInfo(); cout << "Выполнено успешно!" << endl; system("pause"); system("cls"); break;
    }
}

void editDate(production& element) {
    system("cls");
    int buffYear = time(NULL) / 31536000 + 1970;
    cout << "Год: " << element.date.year << endl;
    cout << "Месяц: " << element.date.month << endl;
    cout << "День: " << element.date.day << endl;
    cout << "Что вы хотите изменить:\n1 - год\n2 - месяц\n3 - день\nДействие: ";
    int mode;
    mode = checkNumericInRange(1, 3);
    switch (mode) {
    case 1: cout << "Введите новый год: "; element.date.year = checkNumericInRange(buffYear - YEAR_RANGE, buffYear); cout << "Выполнено успешно!" << endl; system("pause"); system("cls"); break;
    case 2: cout << "Введите новый месяц: "; element.date.month = checkNumericInRange(1, 12); cout << "Выполнено успешно!" << endl; system("pause"); system("cls"); break;
    case 3: cout << "Введите новый день"; element.date.day = enterDay(element.date.month, element.date.year); cout << "Выполнено успешно" << endl; system("pause"); system("cls"); break;
    }
}
