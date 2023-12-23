#include <iostream>
#include <cstring>
#include <windows.h>
#define  _CRT_SECURE_NO_WARNINGS

const int locale = 1251; // Номер русской кодовой таблицы
const int dlina = 10; // Максимальная длина всех массивов в программе

int occurrencesFinder(char s[dlina], char s1[dlina]) { // Функция нахождения вхождений строки в строку
	if (strlen(s) >= strlen(s1)) { // Смотрим корректны ли входные значения

		int len = strlen(s); // Находим длины строк
		int len1 = strlen(s1); 
		int searchLen = len - len1 + 1; // Находим длину в которой есть смыл искать вхождения
		int occurrences = 0; //Объявляем переменную, отвечающую за колличество вхождений

		for (int i = 0; i < searchLen; i++) { // Инициализируем цикл со счетчиком
			int estLiSovpadene = 1; // Объявляем флаг, отвечающую за вхождение строки в строку

			for (int j = 0; j < len1; j++) { // Цикл поиска вхожднний
				if (s[i + j] != s1[j]) { // Строим не совпадают значения
					estLiSovpadene = 0; // Присваеваем флагу 0
				}
			}

			if (estLiSovpadene == 1) { // Смотрим есть ли совпадение
				occurrences ++;
			}
		}

        std::cout << "Количество вхождений: " << occurrences << std::endl; // Выводим в консоль колличество вхождений
        return 0;
	}
    std::cout << "Ошибка! Невозмозможно подсчитать колличесвто вхождений, т. к. строка для поиска короче искомой строки." << std::endl; // Выводим в консоль ошибку из-за некорректных входных данных
    return 0;
}

void replaceSubstrings(char s[], const char s1[], const char s2[]) //Функция замены в строке одной подстрок на другие
{
    int sLen = std::strlen(s); //Находим длину строки, подстрок
    int s1Len = std::strlen(s1);
    int s2Len = std::strlen(s2);

    int replacements = 0;

    // Подсчет количества вхождений подстроки1 в строку
    const char* ptr = s;
    while ((ptr = std::strstr(ptr, s1)) != nullptr) // Подсчитываем колличество вхождений подстроки в строку
    {
        replacements++;
        ptr += s1Len;
    }
    int zamen = replacements;
    // Создание новой строки с заменой вхождений подстроки1 на подстроку2
    char newStr[dlina]; // Объявляем новую строку, которая будет результатом
    int newStrIndex = 0;

    for (int i = 0; i < sLen; i++)
    {
        if (std::strncmp(&s[i], s1, s1Len) == 0) { // Копируем в строку подстроку
            strcpy(&newStr[newStrIndex], s2);
            newStrIndex += s2Len;
            i += s1Len - 1;
            replacements--;
        }
        else {
            newStr[newStrIndex] = s[i]; // Присваеваем элемент новой строке, который не входит в искомую подстроку
            newStrIndex++;
        }

        if (replacements == 0) { // Копируем конец строки в новую строку 
            strcpy(&newStr[newStrIndex], &s[i + 1]);
            break;
        }
        
        if (std::strlen(newStr)+ s2Len > dlina) { //Проверяем новую строку на переполненность 
            std::cout << "Ошибка! Невозможно полностью заменить вхождения, программа заменила все в пределах допустимой длины строки. " << std::endl; //Выводим сообщения об ошибке
            break;
        }
    }

    std::cout << "Новая строка: " << newStr << "\nБыло произведено " << zamen - replacements << " замены" << std::endl; //Выводим итог
}

int main()
{
    SetConsoleCP(locale); // Подключаем русскую кодовую таблицу
	SetConsoleOutputCP(locale);
    

    char s[dlina]; //Объявляем главную строку, искомую подстроку, и подстроку для вставки
    char s1[dlina];
    char s2[dlina];

    std::cout << "Введите строку: "; // Считываем строки
    std::cin.getline(s, dlina);

    std::cout << "Введите подстроку1: ";
    std::cin.getline(s1, dlina);

    std::cout << "Введите подстроку2: ";
    std::cin.getline(s2, dlina);

    occurrencesFinder(s, s1); // Подсчитываем вхождения строки в строку
    replaceSubstrings(s, s1, s2); // Заменяем одну подстроку на другую в строке 

    return 0;
}

