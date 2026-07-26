#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <limits>

using namespace std; 

struct Message
{
    string sender;
    string receiver;
    string text;
};

struct User
{
    string login;
    string password;
};


int getNumber() {   // защита от дурака
    int number;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}


void saveUsers(User users[], int userCount)   // сохранение пользователей
{
  ofstream file;
  file.open("users.txt");

  if (!file.is_open())
  {
    cout << "Save error" << endl;
    return;
  }
  else
  {
    for(int i = 0; i < userCount; i++)
    {
      file << users[i].login << endl;
      file << users[i].password << endl;
    }
    file.close();
  }
}


int loadUsers(User users[])   // загрузка пользователей
{
  ifstream file;
  file.open("users.txt");

  if (!file)
  {
    return 0;
  }

  int userCount = 0;

  while (userCount < 100 && getline(file, users[userCount].login))
  {
    getline(file, users[userCount].password);
    userCount++;
  }
  file.close();
  return userCount;
}


void saveToFile(Message messages[], int count)   // сохранение  сообщений
{
  ofstream file;
  file.open("chat_history.txt");

  if (!file.is_open())
  {
    cout << "Save error" << endl;
    return;
  }
  else
  {
    for(int i = 0; i < count; i++)
    {
      file << messages[i].sender << endl;
      file << messages[i].receiver << endl;
      file << messages[i].text << endl;
    }
    file.close();
  }
}

int loadFromFile(Message messages[])   // загрузка сообщений
{
  ifstream file("chat_history.txt");
  
  if(!file)
  {
    return 0;
  }

  int count = 0;

  while(count < 100 && getline(file, messages[count].sender))
  {
    getline(file, messages[count].receiver);
    getline(file, messages[count].text);
    count++;
  }
  file.close();
  return count;
}


int main() 
{


  const string BOLD_LINE = "====================================================";
  const string THIN_LINE = "----------------------------------------------------";
  const char TAB = '\t';
  const char NEW_LINE = '\n';

  const int size = 100;

  User users[100];
  Message messages[100];


  string currentUser;

  string newLogin;
  string newPassword;
  bool loginExists = false;
  bool authorization = false;
  bool passwordWrong = false;

  int count = 0;
  int continuation = 1;
  int action_number;
  int userCount = 0;

  count = loadFromFile(messages);
  userCount = loadUsers(users);

  cout << BOLD_LINE << NEW_LINE << NEW_LINE;

  cout << TAB << "Welcome to Chat Directory";

  while(!authorization)
  {
  
  cout << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

  cout << TAB << "What do you want to do?" << NEW_LINE << NEW_LINE;   // вход в программу

  cout << "1 - Login" << NEW_LINE;
  cout << "2 - Register" << NEW_LINE;
  cout << "3 - Exit" << NEW_LINE << NEW_LINE;

  cout << TAB << "Enter action number: ";
  action_number = getNumber();

  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE; 
  
  
  switch (action_number)
  {
    case 1:
    {
      passwordWrong = false;
      cout << "Enter login: ";
      getline(cin, newLogin);

      for(int i = 0; i < userCount; i++)
      {
        if(users[i].login == newLogin)
        {
          cout << "Enter password: ";
          getline(cin, newPassword);
          
          if(users[i].password == newPassword)
          {
            cout << NEW_LINE << TAB << "You have successfully logged in!" << NEW_LINE;
            currentUser = users[i].login;
            authorization = true;
            break;
          }
          else
          {
            passwordWrong = true;
            continue;
          }
        }
      }
      if (passwordWrong) 
      {
        cout << NEW_LINE << TAB << "Incorrect password!";
      } 
      else if (!authorization) 
      {
        cout << NEW_LINE << TAB << "User not found";
      }
      break;
    }
    case 2:
    {
      if (userCount >= 100) 
      {
        cout << "User database is full!" << NEW_LINE;
        break;
      }
      loginExists = false;
      cout << "Enter login: ";
      getline(cin, newLogin);
      
      for(int i = 0; i < userCount; i++)
      {
        if(users[i].login == newLogin)
        {
          loginExists = true;
        }
      }
      if(loginExists)
        {
          cout << NEW_LINE << TAB << "That username is taken";
          continue;
        }
      else
        {
          cout << "Enter password: ";
          getline(cin, newPassword);

          users[userCount].login = newLogin;
          users[userCount].password = newPassword;
          currentUser = users[userCount].login;
          userCount++;
          saveUsers(users, userCount);
          cout << NEW_LINE << TAB << "You have successfully logged in";
          authorization = true; 
        }
      break;
    }
    case 3:
    {
      exit(0);
    }
    default:
    {
      cout << "Command not recognized";
      continue;
    }
  }
  }


  while (continuation == 1)
  {

  cout << NEW_LINE << BOLD_LINE;

  cout << NEW_LINE << NEW_LINE;

  cout << TAB << "What do you want to do?" << NEW_LINE << NEW_LINE;   // меню действий

  cout << "1 - Send a message" << NEW_LINE;
  cout << "2 - Show all messages" << NEW_LINE;
  cout << "3 - Delete a message" << NEW_LINE;
  cout << "4 - Find a message" << NEW_LINE;
  cout << "5 - Exit" << NEW_LINE << NEW_LINE;

  cout << TAB << "Enter action number: ";
  action_number = getNumber();

  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

  switch (action_number)
  {
    case 1:   // отправить сообщение
    {
      if (count < 100)
      {

        messages[count].sender = currentUser;
        cout << NEW_LINE << "Enter receiver: ";
        getline (cin, messages[count].receiver);
        cout << NEW_LINE << "Enter text: ";
        getline (cin, messages[count].text);

        count++;

        saveToFile(messages, count);

        cout << NEW_LINE << TAB << "Message sent!" << NEW_LINE;
      }
      else
      {
        cout << "Database is full!";
      }

      break;
    }
    case 2:   // показать все сообщения
    {
      for (int i = 0; i < count; i++)
      {
        cout << i + 1 << ". " << messages[i].sender << " -> " << messages[i].receiver << ": " << messages[i].text << NEW_LINE;
      }
      break;
    }
    case 3:   // удалить сообщения
    {
      int index;
      cout << "Enter message number: ";
      index = getNumber();
      cout << NEW_LINE << TAB;
      index--;

      if (index >= 0 && index < count)
      {
        for(int i = index; i < count - 1; i++)
        {
          messages[i].sender = messages[i + 1].sender;
          messages[i].receiver = messages[i + 1].receiver;
          messages[i].text = messages[i + 1].text;
        }
        cout << "Message deleted!";
        count--;

        saveToFile(messages, count);
      }
      else
      {
        cout << "Invalid number";
      }
      break;
    }
    case 4:   // поиск по точному совпадению
    {
      string query;

      cout << "Enter exact message text: ";
      getline(cin, query);
      cout << NEW_LINE << NEW_LINE;
      
      bool found = false;

      for(int i = 0; i < count; i++)
      {
        if(messages[i].text.find(query) != string::npos)
        {
          cout << i + 1 << ". " << messages[i].sender << " -> " << messages[i].receiver << ": " << messages[i].text << NEW_LINE;
          found = true;
        }
      }
      if (!found)
      {
        cout << "Nothing found" << NEW_LINE;
      }
      break;
    }
    case 5:   // выйти
    {
      continuation = 0;
      break;
    }
    default:
    {
      cout << "Command not recognized";
      continue;
    }
  }

  }

  return 0;
}
