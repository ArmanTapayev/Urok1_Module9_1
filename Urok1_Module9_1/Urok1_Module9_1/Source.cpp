#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include"totalService.h"

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	printf("Работа содержит 6 вариантов.\n");
	printf("Для завершения наберите 0.\n");
	int n;
	do
	{
		printf("Введите номер варианта: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*	Поля структуры				Задача
				Фамилия						Определить средний возраст хоккеистов 
				Возраст						и вывести сведения о хоккеистах, возраст которых меньше 25 лет
				Количество игр 
				Количество заброшенных шайб
			*/

			int count = 6, sum = 0;
			printf("--- Информация о команде ---\n");
			hockeyPlayer *cmp = createTeam(&count);
			printf("Хоккеисты, возраст которых меьше 25 лет:\n");
			for (int i = 0; i < count; i++)
			{
				sum += cmp[i].age;
				if (cmp[i].age < 25)
					printInfoHockey(&cmp[i], 1);				
			}
			printf("Средний возраст хоккеистов: %0.2f\n", (float)sum/count);
			system("pause");
			system("cls");
		}break;

		case 2:
		{
			/*	Поля структуры	 Задача
				Наименование	 Определить общую стоимость всех товаров, выпущенных в текущем году и 
				Производитель	 вывести сведения об этих товарах.
				Год_выпуска 
				Количество
				Цена
			*/
			int count = 10, sum = 0, k=0;
			printf("--- Информация о товаре ---\n");
			goods *cmp = createArticle1();
			printf("Сведения о товарах, выпущенных в 2018 году:\n");
			for (int i = 0; i < count; i++)
			{
				if (cmp[i].year == 2018)
				{
					k++;
					sum += cmp[i].price;
					printInfoPrd(&cmp[i], 1);
				}
			}
			if (!k)
				printf("Товаров, выпущенных в 2018 году нет.\n");

			printf("Общая стоимость всех товаров, выпущенных в 2018 году: %d\n", sum);
			system("pause");
			system("cls");
		}break;

		case 3:
		{
			/*	Поля структуры	 Задача
				Наименование	 Определить среднюю стоимость товаров и товар с минимальной стоимостью.
				Количество
				Цена
				Производитель
				Дата_выпуска
			*/

			int count = 10, sum = 0, intMin;
			printf("--- Информация о товаре ---\n");
			goods3 *cmp = createArticle2();  
			int min = cmp[0].price;
			for (int i = 0; i < count; i++)
			{
				sum += cmp[i].price;
				if (cmp[i].price < min)
				{
					min = cmp[i].price;
					intMin = i;
				}
					
			}
			printf("Средний стоимость товаров: %0.2f\n", (float)sum / count);
			printf("Товар с минимальной стоимостью:\n");
			printInfoPrd2(&cmp[intMin], 1);
			system("pause");
			system("cls");
		}break;

		case 4:
		{
			/*	Поля структуры		Задача
				Фамилия				Определить самого младшего работника и напечатать сведения о нем.
				Год рождения 
				Должность 
				Зарплата
				Образование
			*/
			int count = 10, sum = 0;
			printf(" --- Информация по работнику --- \n");
			employee*cmp = createFile();
			int maxD = cmp[0].bdt.day, maxInd;
			int maxM = cmp[0].bdt.month;
			int maxY = cmp[0].bdt.month;
			for (int i = 0; i < count; i++)
			{
				if (cmp[i].bdt.year > maxY)
				{
					maxY = cmp[i].bdt.year;
					maxM = cmp[i].bdt.month;
					maxD = cmp[i].bdt.day;
					maxInd = i;
				}
				else if(cmp[i].bdt.year == maxY && cmp[i].bdt.month>maxM)
				{
					maxY = cmp[i].bdt.year;
					maxM = cmp[i].bdt.month;
					maxD = cmp[i].bdt.day;
					maxInd = i;
				}
				else if (cmp[i].bdt.year == maxY && cmp[i].bdt.month==maxM && cmp[i].bdt.month > maxM)
				{
					maxY = cmp[i].bdt.year;
					maxM = cmp[i].bdt.month;
					maxD = cmp[i].bdt.day;
					maxInd = i;
				}
				
			}
			printf("Самый младший работник:\n");
			printInfoEmpl(&cmp[maxInd], 1);
			system("pause");
			system("cls");
		}break;

		case 5:
		{
			/*	Поля структуры		    Задача
				Фамилия					Напечатать фамилии студентов, которые сдали математику на «95», 
				Группа					и определить их количество.
				Год рождения
				оценка по физике
				оценка по математике
				оценка по информатике
			*/
			int count = 10, sum = 0,k=0;
			printf(" --- Информация по студенту --- \n");
			student *cmp = createStudent(&count); 
			printf("Студенты, которые сдали математику на 95: \n");
			for (int i = 0; i < count; i++)
			{
				if (cmp[i].sub[1].rate > 95)
				{
					printInfoStd(&cmp[i], 1);
					k++;
				}
			}
			printf("Количество студентов: %d\n", k);
	
			system("pause");
			system("cls");
		}break;
		}
	} while (n != 0);
}