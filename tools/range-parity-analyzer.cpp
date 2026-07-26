#include <iostream>
#include <windows.h>
#include <string>
using namespace std; 



int main() 
{

  SetConsoleOutputCP(CP_UTF8);

  const string BOLD_LINE = "====================================================";
  const string THIN_LINE = "----------------------------------------------------";
  const char TAB = '\t';
  const char NEW_LINE = '\n';

  int min_number, max_number, number_selection;
  int suitable_numbers = 0;
  int sum_numbers = 0;
  int continuation = 1;

  while (continuation == 1)
  { 
  suitable_numbers = 0;
  sum_numbers = 0;

  cout << BOLD_LINE << NEW_LINE << NEW_LINE;

  cout << "Это программма определяющая количество и сумму"<< NEW_LINE;
  cout << "четных или не чётных чисел диапазона" << NEW_LINE << NEW_LINE;

  cout << THIN_LINE << NEW_LINE << NEW_LINE;

  cout << TAB << "Введите диапазон чисел" << NEW_LINE << NEW_LINE;

  cout << "От: ";
  cin >> min_number;
  cout << "До: ";
  cin >> max_number;

  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

  cout << TAB << "Выберите сумму каких чисел вы хотите увидеть" << NEW_LINE <<NEW_LINE;

  cout << "1 - чётных" << NEW_LINE;
  cout << "2 - не чётных" << NEW_LINE << NEW_LINE;
  cout << "Введите номер чисел: ";
  cin >> number_selection;

  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

  switch (number_selection)
  {
  case 1:
  {
        while (min_number <= max_number)
    {
      if (min_number % 2 == 0)
      {
        sum_numbers += min_number;
        suitable_numbers++;
        min_number++;
      }
      else
      {
        min_number++;
      }   
    } 
    break;
  }
  case 2:
  {
        while (min_number <= max_number)
    {
      if (min_number % 2 != 0)
      {
        sum_numbers += min_number;
        suitable_numbers++;
        min_number++;
      }
      else
      {
        min_number++;
      }   
    } 
    break;
  }
    default:
  {
    cout << "Вы ввели не правильное число";
    break;
  }

  }
  cout << "Количесто чисел: " << suitable_numbers << NEW_LINE;
  cout << "Их сумма: " << sum_numbers << NEW_LINE << NEW_LINE;
  cout << THIN_LINE << NEW_LINE << NEW_LINE;

  cout << TAB << "Хотите продолжить?" << NEW_LINE << NEW_LINE;
  cout << "1 - да" << NEW_LINE;
  cout << "2 - нет" << NEW_LINE << NEW_LINE;

  cout << TAB << "Введите номер операции: ";
  cin >> continuation;
  cout << NEW_LINE;

 }

 cout << NEW_LINE << BOLD_LINE;

  


  return 0;
}
