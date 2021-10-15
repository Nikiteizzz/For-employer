#include "root.h"
#include "work_with_arr_and_file.h"
#include "checks.h"
#include "panels.h"
#include "authorization.h"
#include "sha256.h"

void root() {
    int count_of_accounts, count_of_production, mode;
    account current_user;
    bool regFlag;
    while (true) {
        cout << "1 - Войти в аккаунт\n2 - Регистрация\n0 - Выйти из программы\nДействие: ";
        mode = checkNumberCONST(0, 1, 2);
        if (mode == 1) {
            system("cls");
            count_of_accounts = getCountOfAccounts();
            if (count_of_accounts > 0) {
                account* arr_of_accounts = new account[count_of_accounts];
                getArrOfAccounts(arr_of_accounts, count_of_accounts);
                current_user = logging(arr_of_accounts, count_of_accounts);
                if (current_user.accessLevel == 1) {
                    if (current_user.role == 1) {
                        regFlag = checkRegRequest(arr_of_accounts, count_of_accounts);
                        if (regFlag == false) {
                            adminPanelWithoutRegistr(arr_of_accounts, count_of_accounts, current_user);
                        }
                        else {
                            adminPanelWithRegistr(arr_of_accounts, count_of_accounts, current_user);
                        }
                    }
                    else {
                        userPanel(current_user);
                    }
                }
                else {
                    cout << "Не удалось войти в этот аккаунт, так как он либо заблокирован, либо находится на этапе регистрации. Обратитесь к администратору!" << endl;
                    system("pause");
                    system("cls");
                }
            }
            else if (count_of_accounts == 0) {
                cout << "Файл был найден, однако в файле не найдено ни одного аккаунта. В него были добавлены стандартные данные для входа в админ аккаунт!" << endl;
                addAdminAccount();
            }
            else {
                cout << "Файл не был найден. Он будет создан по адресу: " << FILE_DATA_ACCOUNTS << endl;
                addAdminAccount();
            }
        }
        else if (mode == 2) {
            askForRegistration();
        }
        else {
            break;
        }
    }
}