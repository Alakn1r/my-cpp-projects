#include <iostream>
#include <windows.h>
#include <string>
#include <random>
#include <chrono>
#include <limits>

using namespace std; 


// Функция для безопасного ввода числа
int getNumber() {
    int number;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите число: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

int inventory (int money, bool sword, bool rusti_sword, bool armor, const char NEW_LINE, const string INVENTORI_LINE, char TAB)
{
cout << NEW_LINE << NEW_LINE << INVENTORI_LINE << NEW_LINE;
     cout << TAB << "ИНВЕНТАРЬ" << NEW_LINE << NEW_LINE;
     cout << "Деньги - " << money << NEW_LINE;
     if (armor)
     {
      cout << "Броня - есть" << NEW_LINE;
     }
     else
     {
      cout << "Броня - нет" << NEW_LINE;
     }
     if (sword)
     {
      cout << "Оружие - меч" << NEW_LINE;
     }
     else if (rusti_sword)
     {
      cout << "Оружие - ржавый меч" << NEW_LINE;
     }
     else
     {
      cout << "Оружие - нет" << NEW_LINE;
     }

     cout << INVENTORI_LINE << NEW_LINE << NEW_LINE;
     return(0);
}

int ending (bool armor, bool house, int ending_number, int number_of_koushi_games, const char NEW_LINE)
{
                      if (!armor)
                      {
                        cout << R"(
Из-за отсутствия брони, ты получил сильные 
увечья и половину денег ты потратил на лечение.
                        )" << NEW_LINE;
                      }
                      if (!house)
                      {
                        cout << R"(
Так как ты продал дом, тебе пришлось купить новый 
дом, потратив половину всех денег.  
                        )" << NEW_LINE;
                      }
                      if (ending_number == 1)
                      {
                        cout << R"(
Но ты вспомнил, что продал душу дьяволу. Из-за дня 
в день, ты жалел о своём поступке. Ты начал сходить 
с ума. И однажды, ты не выдержал и отправился служить 
в церковь, в надежде замолить грехи и исправиться.
                        )" << NEW_LINE;
                      }

                      if (number_of_koushi_games > 2)
                      {
                        cout << R"(
Вспомнил как ты играл в кости, ты захотел сыграть ещё 
и ещё и ещё, со временем ты стал зависим от азартных игр.                        
                        )" << NEW_LINE;
                      }
  return 0;
}

int main() 
{

  SetConsoleOutputCP(CP_UTF8);

  const string BOLD_LINE = "====================================================";
  const string THIN_LINE = "----------------------------------------------------";
  const string INVENTORI_LINE = "****************************************************";
  const char TAB = '\t';
  const char NEW_LINE = '\n';

  int continuation = 1;

  while (continuation == 1)
  { 
      int location_number, action_number, bet_amount, dice_1, dice_2, player_amount, opponents_total;
      int money = 5;
      int ending_number = 0;
      int stolen_money = 0;
      int number_of_koushi_games = 0;
      bool game_replay = true;
      bool restart_game = false;
      bool leave_location = false;
      bool leave_location_market = false;
      bool leave_location_market_merchant = false;
      bool leave_location_tavern = false;
      bool leave_the_game_of_dice = false;
      bool sword = false;
      bool rusti_sword = false;
      bool armor = false;
      bool house = true;
      bool action_help_the_merchant = false;
      bool act_of_begging = false;
      bool action_satanist = false;


    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1, 6); // кубик от 1 до 6


    cout << BOLD_LINE <<NEW_LINE << NEW_LINE;

    cout << TAB << "Добро пожаловать в мою игру" << NEW_LINE << NEW_LINE;

    cout << THIN_LINE << NEW_LINE << NEW_LINE;

    cout << R"(
Ты обычный крестьянин, гончар, который сводит концы
с концами, живёшь в маленьком доме на окраине  города.
Однажды идя по улице ты встретил объявление, расклеенные
по всему городу. В нём было написано, что недалеко от
города в болоте обитает тролль, который время от 
времени нападал на проходящих мимо торговых караванов и 
король хочет избавиться от него. За его убийство король
предлагал награду в 100 монет. Так как у тебя были большие 
проблемы с деньгами, ты решил выполнить заказ.
    )";

    do 
    {

     inventory(money, sword, rusti_sword, armor, NEW_LINE, INVENTORI_LINE, TAB);
    

     cout << TAB << "Куда стоит пойти?" << NEW_LINE << NEW_LINE;
     cout << "1 - на рынок" << NEW_LINE;
     cout << "2 - в таверну" << NEW_LINE;
     cout << "3 - отправиться на болото" << NEW_LINE << NEW_LINE;
     cout << "Введите номер локации: ";

     location_number = getNumber();

     cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

     switch (location_number)
     {
       case 1:      // рынок
       {

        inventory(money, sword, rusti_sword, armor, NEW_LINE, INVENTORI_LINE, TAB);

        cout << R"(
Придя на рынок ты осмотрелся, вокруг было много людей, 
кто-то пришёл покупать, кто-то продавать, были люди
которые пришли клянчить деньги. Среди множества купцов, 
ты нашёл купца у которого можно купить снаряжение для 
похода на тролля. В общем множестве криков и разговорах, 
ты услышал, что один из торговцев просил подменить его 
ненадолго.        
        )";

        inventory(money, sword, rusti_sword, armor, NEW_LINE, INVENTORI_LINE, TAB);

        do
        {
        leave_location_market = false;
        cout << THIN_LINE << NEW_LINE << NEW_LINE;

        cout << TAB << "Чем стоит заняться?" << NEW_LINE << NEW_LINE;
        cout << "1 - поторговаться с торговцем" << NEW_LINE;
        cout << "2 - помочь торговцу" << NEW_LINE;
        cout << "3 - пойти попрошайничать" <<NEW_LINE;
        cout << "4 - выйти с рынка" << NEW_LINE << NEW_LINE;
        cout << TAB << "Введите действие: ";

        action_number = getNumber();
        
        switch (action_number)
        {
          case 1:      // торговля с торговцем
          {
            do {
            
            leave_location_market_merchant = false;

            cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
            
            cout << "В ассортименте у торговца была лёгкая броня," << NEW_LINE;
            cout << "железный меч. Узнав что у тебя проблемы с деньгами," << NEW_LINE;
            cout << "торговец предложил продать дом." << NEW_LINE << NEW_LINE;
            
            inventory(money, sword, rusti_sword, armor, NEW_LINE, INVENTORI_LINE, TAB);
            
            cout << THIN_LINE << NEW_LINE <<NEW_LINE;

            cout << "1 - Купить меч - 10 монет" << NEW_LINE;
            cout << "2 - Купить броню - 15 монет" << NEW_LINE;
            cout << "3 - Продать дом - 15 монет" << NEW_LINE;
            cout << "4 - Покинуть торговца" << NEW_LINE << NEW_LINE;
            cout << TAB << "Введите номер действия: ";

            action_number = getNumber();

            cout << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

            switch (action_number)
            {
              case 1:      // покупка меча
              {
                if (sword)
                {
                  cout << "У тебя уже есть меч" << NEW_LINE;
                  continue;
                }
                else if (money < 10)
                {
                  cout << "У тебя не хватает денег" << NEW_LINE;
                  continue;
                }
                else
                {
                  money -= 10;
                  cout << "Ты купил меч!" << NEW_LINE;
                  sword = true;
                  continue;
                }
              }
              case 2:      // покупка брони
              {
                if (armor)
                {
                  cout << "У тебя уже есть броня" << NEW_LINE;
                  continue;
                }
                else if (money < 15)
                {
                  cout << "У тебя не хватает денег" << NEW_LINE;
                  continue;
                }
                else
                {
                  money -= 15;
                  cout << "Ты купил броню!" << NEW_LINE;
                  armor = true;
                  continue;
                }
              }
              case 3:      // продажа дома
              {
                if (house)
                {
                  cout << "Ты продал дом" << NEW_LINE;
                  house = false;
                  money += 15;
                  continue;
                }
                else
                {
                  cout << "Ты уже продал дом" << NEW_LINE;
                  continue;
                }             
              }
              case 4:      // уйти от торговца
              {
                leave_location_market_merchant = true;
                break;
              }
              default:
              {
                cout << "Команда не распознана" << NEW_LINE;
                continue;
              }
            }
           } while (!leave_location_market_merchant && !restart_game);
           break;


          }
          case 2:      // помочь торговцу
          {
            cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
            if (action_help_the_merchant)
            {
              cout << "Ты уже помог торговцу" << NEW_LINE << NEW_LINE;
            }
            else
            {
              cout << R"(
Подойдя к торговцу, он попросил подменить его на 
15 минут, за что он заплатит 5 монет, на что ты 
согласился. Когда торговец ушёл, ты заметил что 
под столом у него спрятаны деньги.
)" << NEW_LINE << NEW_LINE;
              action_help_the_merchant = true;
              money += 5;
              
              cout << THIN_LINE << NEW_LINE << NEW_LINE;

              cout << TAB << "Стоит ли украсть деньги?" << NEW_LINE << NEW_LINE;
              cout << "1 - да" << NEW_LINE;
              cout << "2 - нет" << NEW_LINE << NEW_LINE;
              cout << TAB << "Введите номер действия: ";

              action_number = getNumber();

              cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

              switch (action_number)
              {
                case 1:
                {;
                  cout << "Сколько денег стоит украсть: ";
                  stolen_money = getNumber();
                  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

                  if (stolen_money <= 5 && stolen_money > 0)
                  {
                    cout << "Вернувшись торговец не заметил что ты украл " << stolen_money << " монет" << NEW_LINE << " и заплатил 5 монет" << NEW_LINE << NEW_LINE;
                    money += stolen_money;
                  }
                  else if (stolen_money > 5)
                  {
                    cout << R"(
Вернувшись торговец заметил что ты украл деньги.
Он схватил тебя и потащил к проходящим мимо стражи.
Стражники посадили тебя в мрачную темницу. Через
2 недели тебя выпустили, ты узнал что тролля уже 
убили и ты вернулся к своей скучной бедной жизни.
                    )" << NEW_LINE;
                    goto restart;
                  }
                  else
                  {
                    cout << "Ты передумал и решил не красть деньги." << NEW_LINE;
                    cout << "Вернувшись торговец поблагодарил тебя и заплатил 5 монет." << NEW_LINE << NEW_LINE;
                  }
                  break;
                }
                case 2:
                {
                  cout << "Вернувшись торговец поблагодарил тебя и заплатил 5 монет." << NEW_LINE << NEW_LINE;
                  break;
                }
                default:
                {
                  cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
                  continue;
                }
              }

            }
            break;

          }
          case 3:      // попрошайничать
          {
            cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
            if (act_of_begging)
            {
              cout << "Ты уже попрошайничал" << NEW_LINE << NEW_LINE;
            }
            else
            {
              cout << R"(
Решив попрошайничать, ты ходил по всему рынку, 
крича, что собираешь деньги на убийство тролля, 
прошёл час, ты насобирал 5 монет.
              )" << NEW_LINE;
              money += 5;
              act_of_begging = true;
            }
            break;

          }
          case 4:      // выйти с рынка
          {
            leave_location_market = true;
            continue;
          }
          default:
          {
            cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
            cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
            continue;
          }
        } 

        } while (!leave_location_market && !restart_game);
        continue;       

       }
       case 2:      // таверна
       {
        cout << R"(
Когда ты вошёл в таверну, ты увидел отдыхающих 
людей, кто-то играл в кости. В углу таверны ты 
увидел женщину в чёрном, которая подзывала всех, 
но без успеха.
        )";

        inventory(money, sword, rusti_sword, armor, NEW_LINE, INVENTORI_LINE, TAB);

        do
        {
        
        cout << THIN_LINE << NEW_LINE << NEW_LINE;

        cout << TAB << "Чем стоит заняться?" << NEW_LINE << NEW_LINE;
        cout << "1 - сыграть в кости" << NEW_LINE;
        cout << "2 - подойти к женщине" << NEW_LINE;
        cout << "3 - выйти из таверны" << NEW_LINE << NEW_LINE;
        cout << TAB << "Введите номер действие: ";
        action_number = getNumber();

        cout << THIN_LINE << NEW_LINE << NEW_LINE;

        switch (action_number)
        {
          case 1:      //  игра в кости
          {
            cout << R"(
Сев за стол, ты начал играть с мужиком в кости. 
Правило просты, игроки делают ставки, бросают 
по 2 кубика, у кого выпадет больше, тот забирает 
деньги. 
            )" << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

            cout << TAB << "Стоит ли сыграть?" << NEW_LINE << NEW_LINE;
            cout << "1 - да" << NEW_LINE;
            cout << "2 - нет" << NEW_LINE << NEW_LINE;
            cout << TAB << "Введите номер действия: ";
            action_number = getNumber();

            cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

            switch (action_number)
            {
              case 1:      // игра в кости
              {
                do
                {
                  leave_the_game_of_dice = false;
                  
                  number_of_koushi_games += 1;

                  cout << THIN_LINE << NEW_LINE;
                  cout << "Денег - " << money;
                  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

                  cout << "Введите сумму ставки: ";
                  bet_amount = getNumber();

                  if (bet_amount <= 0)
                  {
                    cout << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
                    cout << "Хорошая попытка";
                    cout << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
                    continue;
                  }

                  if (bet_amount > 50)
                  {
                    cout << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
                    cout << "Слишком большая ставка";
                    cout << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
                    continue;
                  }

                  dice_1 = distribution(generator);
                  dice_2 = distribution(generator);
                  player_amount = dice_1 + dice_2;

                  cout << NEW_LINE << "У тебя выпало: " << player_amount << NEW_LINE;

                  dice_1 = distribution(generator);
                  dice_2 = distribution(generator);
                  opponents_total = dice_1 + dice_2;

                  cout << "У соперника выпало: " << opponents_total << NEW_LINE << NEW_LINE;

                  if (player_amount > opponents_total)
                  {
                    cout << TAB << "Ты выиграл " << bet_amount << " монет!" << NEW_LINE << NEW_LINE;
                    money += bet_amount;
                  }
                  else if (player_amount < opponents_total)
                  {
                    cout << TAB << "Ты проиграл" << NEW_LINE;

                    cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
                    
                    if (money - bet_amount < 0)
                    {
                      cout << R"(
У тебя не хватает денег, чтобы заплатить за 
проигрыш. Увидев ,что ты не можешь расплатиться, 
мужик с которым ты играл впал в ярость и избил 
тебя, так сильно, что ты умер от полученных травм. 
                      )" << NEW_LINE;
                      goto restart;
                    }
                    else
                    {
                      money -= bet_amount;
                    }
                  }
                  else
                  {
                    cout << TAB << "Ничья" << NEW_LINE << NEW_LINE;
                  }
                if (restart_game)
                  {

                  }
                else
                  {
                    cout << TAB << "Продолжить игру в кости?" << NEW_LINE << NEW_LINE;
                    cout << "1 - да" << NEW_LINE;
                    cout << "2 - нет" << NEW_LINE << NEW_LINE;
                    cout << TAB << "Введите номер действия: ";
                    action_number = getNumber();

                      switch (action_number)
                      {
                        case 1:
                        {
                          cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
                          break;
                        }
                        case 2:
                        {
                          cout << NEW_LINE;
                          leave_the_game_of_dice = true;
                          break;
                        }
                        default:
                        {
                          cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
                          continue;
                        }
                      }
                    }
                    
                } while (!leave_the_game_of_dice && !restart_game);
                
                break;
              }
              case 2:
              {            // выход с игры в кости
                continue;
              }
              default:
              {
                cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
                continue;
              }
            }

            break;
          }
          case 2:      // подойти к гадалке
          {
            if (action_satanist)
            {
              cout << "Ты уже подходил к культистке" << NEW_LINE;
            }
            else 
            {
              action_satanist = true;
              cout << R"(
Подойдя к женщине, ты увидел, что она сумасшедшая. 
Женщина держит в руках бумагу, где предлагается 
продать душу дьяволу. Она настойчиво просит подписать 
контракт, предлагая заплатить 15 монет.
              )" << NEW_LINE << NEW_LINE;

              cout << THIN_LINE << NEW_LINE << NEW_LINE;
              
              cout << TAB << "Стоит ли продать душу?" << NEW_LINE << NEW_LINE;
              cout << "1 - конечно!" << NEW_LINE;
              cout << "2 - нет!" << NEW_LINE << NEW_LINE;
              cout << TAB << "Введите номер действия: ";
              action_number = getNumber();

              switch (action_number)
              {
                case 1:
                {
                  money += 15;

                  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;
                  cout << "Ты забрал самые лёгкие 15 монет в своей жизни" << NEW_LINE << NEW_LINE;
                  ending_number = 1;
                  break;
                }
                case 2:
                {
                  cout << NEW_LINE;
                  break;
                }
                default:
                {
                  cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
                  continue;
                }
              }
            }

            break;
          }
          case 3:      // выйти из таверны
          {
            leave_location_tavern = true;

            break;
          }
           default:
          {
            cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
            continue;
          }

        }
      } while (!leave_location_tavern && !restart_game);
      continue;

       }
       case 3:      // болото
       {
        inventory(money, sword, rusti_sword, armor, NEW_LINE, INVENTORI_LINE, TAB);

        cout << "До болото просто так не добраться." << NEW_LINE;
        cout << "Нужно нанять кучера за 5 монет." << NEW_LINE;

        cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

        cout << TAB << "Стоит ли отправиться на болото?" << NEW_LINE << NEW_LINE;
        cout << "1 - да" << NEW_LINE;
        cout << "2 - нет" << NEW_LINE << NEW_LINE;

        cout << TAB << "Введите номер действия: ";
        action_number = getNumber();

        cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

        switch (action_number)
        {
          case 1:
          {
            if (money - 5 < 0)
            {
              cout << "Недостаточно денег";
              continue;
            }
            else
            {
              money -= 5;
              cout << R"(
Прибыв на болот, ты сразу заметил людей в чёрной 
одежде и с масками на лицах, кажется это бандиты. 
Они просят подойти. Но рядом с тобой канава в которую 
можно спрыгнуть и сбежать от бандитов.
              )" << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

              cout << TAB << "Что стоит сделать?" << NEW_LINE << NEW_LINE;
              cout << "1 - Убежать от бандитов" << NEW_LINE;
              cout << "2 - Подойти к бандитам" << NEW_LINE << NEW_LINE;
              cout << TAB << "Введите номер действия: ";
              action_number = getNumber();
              cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

              switch (action_number)
              {
                case 1:
                {
                  cout << R"(
Когда ты начал убегать от бандитов по канаве,
возле дерева ты заметил воткнутый в землю
ржавый меч.                  
)";
                  if (sword)
                  {
                    cout << "Так как у тебя был нормальный меч, ты прошёл мимо" << NEW_LINE << NEW_LINE;
                  }
                  else
                  {
                    cout << "Так как у тебя не было меча, ты забрал этот" << NEW_LINE << NEW_LINE;
                    rusti_sword = true;
                  }
                  if (sword)
                  {
                    cout << R"(
Ты отважно идёшь убивать тролля. Бой был очень 
трудным, но с трудом ты победил. Вернувшись в 
город ты пошёл к королю, узнав что ты в одиночку 
одолел тролля король был очень удивлён, он вручил 
тебе награду.
                    )" << NEW_LINE;

                    ending (armor, house, ending_number, number_of_koushi_games, NEW_LINE);
                    goto restart;
                    
                  }
                  else if (rusti_sword && !sword)
                  {
                    cout << R"(
Ты отважно идёшь убивать тролля. Ты бежишь
к троллю замахиваешься и первым ударом твой
ржавый меч ломаеться и тебя убивает тролль.
                    )" << NEW_LINE;
                    goto restart;
                  }
                  break;
                }
                case 2:
                {
                  cout << R"(
Подойдя к бандитам, они рассказали, что собираются 
убить тролля и предлагаю тебе присоединиться к ним, 
а награду поделить поровну.
                  )";
                  cout << NEW_LINE << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

                  cout << TAB << "Стоит ли присоедениться?" << NEW_LINE << NEW_LINE;
                  cout << "1 - Присоедениться" << NEW_LINE;
                  cout << "2 - Не присоединятся" << NEW_LINE << NEW_LINE;
                  cout << TAB << "Введите номер действия: ";
                  action_number = getNumber();

                  cout << NEW_LINE << THIN_LINE << NEW_LINE << NEW_LINE;

                  switch (action_number)
                  {
                  case 1:
                  {
                    if (sword)
                    {
                      cout << R"(
Вы вместе идёте убивать тролля. Бой был долгим и 
сложным, но в итоге вам удалось победить тролля. 
Вернувшись в город, вы пошли к королю, он отдал 
вам деньги и бандиты как и обещали отдали половину 
награды.
                      )" << NEW_LINE;
                      ending (armor, house, ending_number, number_of_koushi_games, NEW_LINE);
                      goto restart;

                    }
                    else
                    {
                      cout << R"(
Вы вместе идёте убивать тролля. Когда ты пришёл
к троллю, ты понял что без оружия ты ему ничего
не сделаешь. и весь остальной бой ты стоял в 
стороне. Победив бандиты бросили тебя на болоте, 
так как ты бездействовал.
                      )" << NEW_LINE;
                      ending (armor, house, ending_number, number_of_koushi_games, NEW_LINE);
                      goto restart;
                    }
                    break;
                  }
                  case 2:
                  {
                    if (sword)
                    {
                    cout << R"(
Ты отказался от команды и отважно идёшь убивать
тролля. Бой был очень трудным, но с трудом ты
победил. Вернувшись в город ты пошёл к королю,
узнав что ты в одиночку одолел тролля король
был очень удивлён, он вручил тебе награду.
                    )" << NEW_LINE;
                     ending (armor, house, ending_number, number_of_koushi_games, NEW_LINE);
                     goto restart;
                    }
                    else
                    {
                      cout << R"(
Ты отважно идёшь убивать тролля. Когда ты
подошёл к троллю, ты вспомнил, что забыл о
такой мелочи как оружие, тролль без
сопротивления убивает тебя.
                      )" << NEW_LINE;
                      goto restart;
                    }
                    break;
                  }
                  default:
                  {
                    cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
                    continue;
                  }
                }
                break;
                
              }
            

                default:
                {
                  cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
                  continue;
                }
              }
            }
            break;
            } 
          
          case 2:
          {
            continue;
          }
          default:
          {
            cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
            continue;
          }
        }
       }
       default:
       {
        cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
        continue;
       }
       break;      
     }
    }while (!leave_location && !restart_game);

    restart:

    cout << NEW_LINE << NEW_LINE << BOLD_LINE << NEW_LINE << NEW_LINE;
     do
     {
     cout << TAB << "Хотите сыграть в игру ещё раз?";
     cout << NEW_LINE << NEW_LINE;
     cout << "1 - да" << NEW_LINE;
     cout << "2 - нет" << NEW_LINE << NEW_LINE;
     cout << TAB << "Введите номер действия: ";
     action_number = getNumber();

     if (action_number == 2)
     {
      continuation = 0;
      game_replay = false;
      cout << NEW_LINE << BOLD_LINE;
     }
     else if (action_number == 1)
     {
      game_replay = false;
     }
     else
     {
      cout << "Команда не распознана" << NEW_LINE << NEW_LINE;
      continue;
     }
    } while (game_replay);

  }

  return 0;
}
