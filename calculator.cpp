#include <iostream>
#include <windows.h>
#include <string>
using namespace std; 



int main() {

  SetConsoleOutputCP(CP_UTF8);

  int operation;
  double result, integer_1, integer_2;

  const string BOLD_LINE = "====================================================";
  const string THIN_LINE = "----------------------------------------------------";
  const char TAB = '\t';
  const char NEW_LINE = '\n';

  cout << BOLD_LINE << NEW_LINE << NEW_LINE;

  cout << TAB << "Добро пожаловать в мой калькулятор" << NEW_LINE << NEW_LINE;

  cout << THIN_LINE << NEW_LINE << NEW_LINE;

  cout << TAB << "Введите 2 числа" << NEW_LINE << NEW_LINE;
  cout << "Первое число: ";
  cin >> integer_1;
  cout << "Второе число: ";
  cin >> integer_2;

  cout << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

  cout << TAB << "Выберите операцию" << NEW_LINE << NEW_LINE;

  cout << "1 - сложение (+)" << NEW_LINE;
  cout << "2 - вычетание (-)" << NEW_LINE;
  cout << "3 - умножение (*)" << NEW_LINE;
  cout << "4 - деление (/)" << NEW_LINE << NEW_LINE;

  cout << TAB << "Введите номер операции: ";
  cin >> operation;
  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

  switch (operation)
  {
    case 1:
    {
      result = integer_1 + integer_2;
      break;
    }
    case 2:
    {
      result = integer_1 - integer_2;
      break;
    }
    case 3:
    {
      result = integer_1 * integer_2;
      break;
    }
    case 4:
    {
      if (integer_2 == 0) {
        cout << "Деление на ноль невозможно";
        return 1;
      }
      result = integer_1 / integer_2;
      break;
    }
    default:
    {
      cout << "Вы выбрали не правильную операцию";
      exit(0);
      break;
    }
  }

  cout << "Результат: " << result << NEW_LINE << NEW_LINE;

  cout << BOLD_LINE;


  return 0;
}
