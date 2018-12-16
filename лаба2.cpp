// лаба2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h" 
#include <conio.h> 
#include <stdio.h> 
#include <clocale> 
#include <ctime> 
#include <iostream> 
#include <cstdlib> 

int main()
{
	setlocale(LC_ALL, "Rus");
	int max1;// наибольшее №1
	int max2;// №2
	int max3;// №3
	int max4;// №4
	int max5;// №5
	bool FLAG2 = true; // для основного цикла 
	int size; // размер массива 
	int celoe; // для ввода массива 
	int chet = 0; // для ввода 
	int menu = 0; // для главного меню 
	char enter = '\n';
	bool trtflag = false;// флаг для обработки
	bool flag = true; // флаг для цикла
	bool masflag = false; // проверка заполненности
	while (FLAG2)
	{ // Ввод размера массива 
		while (flag)
		{
			flag = false;
			printf("Программа нахождения пяти наибольших элементов одномерного массива целых чисел.\n");
			printf("---------------------------------------------\n");
			printf(" Введите размер массива \n");
			if (scanf_s("%d%c", &size, &enter) != 2 || enter != '\n')
			{ // Защита от ввода отрицательного числа 
				printf(" ОШИБКА: Некорректные данные \n");
				while (getchar() != '\n');
				flag = true;
			}
			else
			{
				if (size <= 4) 
				{ // Защита от ввода отрицательного числа 
					printf(" ОШИБКА: размер массива не может быть меньше 5 элементов \n");
					flag = true;
				}
				else
				{
				}
			}
		}
		int* mas = new int[size];
		do
		{ // МЕНЮ. 
			flag = true;
			printf(" MENU \n");
			printf("---------------------------------------------\n");
			printf(" 1. Ввод элементов массива \n");
			printf(" 2. Вывод массива \n");
			printf(" 3. Обработка массива \n");
			printf(" 4. Вывод результата \n");
			printf(" 5. Перезапуск или Выход из программы \n");
			printf("---------------------------------------------\n");
			if (scanf_s("%d%c", &menu, &enter) != 2 || enter != '\n')
			{ // Защита от ввода букв и цифр 
				printf("\n|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
				while (getchar() != '\n');
			}
			else
			{
				if (menu <= 0 || menu > 5)
				{ // Защита от ввода отрицательного числа 
					printf("\n|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
				}
				else
				{
					switch (menu)
					{
					case 1:
						int menu2; // переменная для меню ввода массива 
						printf(" Меню ввода массива \n");
						printf("---------------------------------------------\n");
						printf(" 1. Заполнить массив cвоими значениями  \n");
						printf(" 2. Заполнить массив случайными числами \n");
						printf(" 3. Выйти из данного пункта меню \n");
						printf("---------------------------------------------\n");
						if (scanf_s("%d%c", &menu2, &enter) != 2 || enter != '\n')
						{ // Защита от ввода букв и цифр, не в ходящих в диапозон
							printf("\n|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
							while (getchar() != '\n');
						}
						else
						{
							if (masflag == false)
							{
								if (menu2 < 0 || menu2 > 4) 
								{ // Защита от ввода отрицательного числа 
									printf("\n|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
								}
								else 
								{
									switch (menu2)
									{
									case 1: // Ввод в массив своих значений 
										while (chet < size)
										{ // Ввод массива 
											printf(" Введите целое значение элемента массива \n");
											if (scanf_s("%d%c", &celoe, &enter) != 2 || enter != '\n') 
											{
												while (getchar() != '\n');
												printf(" ОШИБКА: введены некорректные данные \n");
												continue;
											}
											else
											{
												mas[chet] = celoe;
											}
											++chet;
										}
										masflag = true;
										chet = 0;
										break;
									case 2: // Ввод массива случайные значения 
										int num;
										while (chet < size) // Ввод массива
										{
											num = rand() % RAND_MAX;
											mas[chet] = num;
											++chet;
										}
										masflag = true;
										chet = 0;
										break;
									case 3:
										break;
									}
								}
							}
							else
							{
								printf("\n\n ОШИБКА: Массив заполнен для ввода других значений перезапустите программу\n");
								printf(" Для продолжения нажмите ENTER \n");
								getchar();
							}
						}
						break;
					case 2:
						if (masflag == true)
						{
							for (int n = 0; n < size; ++n)
							{
								printf(" mas[%d]: %d \n", n, mas[n]);
							}
						}
						else
						{
							printf("ОШИБКА: Вы не ввели элементы массива \n");
							break;
						}
						break;
					case 3: // обработка массива 
						if (masflag == true)
						{
							trtflag = false;
							int min = mas[0];
							for (int n = 0; n < size; ++n)
							{
								if (mas[n] < min)
								{
									min = mas[n];
								}
							}
							max1 = min;
							max2 = max1;
							max3 = max2;
							max4 = max3;
							max5 = max4;
							for (int n = 0; n < size; ++n)
							{
								if (mas[n] > max1)
								{
									max5 = max4;
									max4 = max3;
									max3 = max2;
									max2 = max1;
									max1 = mas[n];
								}
								else if (mas[n] > max2)
								{
									max5 = max4;
									max4 = max3;
									max3 = max2;
									max2 = mas[n];
								}
								else if (mas[n] > max3)
								{
									max5 = max4;
									max4 = max3;
									max3 = mas[n];
								}
								else if (mas[n] > max4)
								{
									max5 = max4;
									max4 = mas[n];
								}
								else if (mas[n] > max5)
								{
									max5 = mas[n];
								}
							}
							trtflag = true;
						}
						else
						{
							printf("ОШИБКА: Вы не ввели элементы массива. Обработка массива недоступна\n");
							break;
						}
						break;
					case 4: // Вывод результата обработки
						if (masflag == true)
						{
							if (trtflag == true)
							{
								printf("\n\nЗначения наибольших эллементов массива:\n");
								printf(" Эллемент №1: %d\n", max1);
								printf(" Эллемент №2: %d\n", max2);
								printf(" Эллемент №3: %d\n", max3);
								printf(" Эллемент №4: %d\n", max4);
								printf(" Эллемент №5: %d\n", max5);
							}
							else
							{
								printf("\n ОШИБКА: Вы не обработали массив \n");
								printf(" Для обработки массива выберите пункт 3\n\n");
								break;
							}
						}
						else
						{
							printf("ОШИБКА: Вы не ввели элементы массива \n");
							break;
						}
						break;
					case 5:
						printf(" Хотите начать программу сначала? \n");
						printf("---------------------------------------------\n");
						printf(" 1.Да (Перезапуск программы) \n");
						printf(" 2.Нет (Выход из программы) \n");
						printf("\n 3.Выйти из данного пункта меню \n");
						printf("---------------------------------------------\n");
						int menu3;
						if (scanf_s("%d%c", &menu3, &enter) != 2 || enter != '\n')
						{
							printf("|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
							while (getchar() != '\n');
						}
						else
						{
							if (menu3 < 0 || menu3 > 5)
							{
								printf("|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
							}
							else
							{
								switch (menu3) {
								case 1:
									break;
								case 2:
									return 0;
								case 3:
									menu = 0;
									break;
								}
							}
						}
					}
				}
			}
		} while (menu != 5);
		masflag = false;
		delete[] mas;
	}
}