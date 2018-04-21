#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<locale.h>
#include "totalService.h"

void createName(char * name, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (i == 0)
			*(name + i) = (char)(65 + rand() % 24);
		else
			*(name + i) = (char)(97 + rand() % 24);
	}
	*(name + len) = '\0';
}

void generateDate(birthDate *date)
{
	date->day = 1 + rand() % 31;
	date->month = 1 + rand() % 12;
	date->year = 1940 + rand() % 60;
}

/* variant 1 */
void printInfoHockey(hockeyPlayer *team, int len)
{
	//printf("--- Информация о команде ---\n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d %s: возраст %d, количество голов: %d; количество игр: %d\n",
			i + 1,
			team[i].fullName,
			team[i].age,
			team[i].countGoal,
			team[i].countGame
			);
	}
}

hockeyPlayer *createTeam(int *count)
{
	hockeyPlayer *team = (hockeyPlayer*)calloc(*count, sizeof(hockeyPlayer));

	if (team != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName(team[i].fullName, 10);
			team[i].age = 20 + rand() % 8;
			team[i].countGame = 1 + rand() % 20;
			team[i].countGoal = 1 + rand() % 100;
		}
		printInfoHockey(team, *count);
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return team;
}

/* variant 2 */
void printInfoPrd(goods *article, int len)
{
	//printf("--- Информация о товаре ---\n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d Наименование %s; Производитель %s; Год выпуска: %d; Количество: %d; Цена: %d\n",
			i + 1,
			article[i].name,	//Наименование
			article[i].maker,	//Производитель
			article[i].year,	//Год_выпуска
			article[i].quantity,//Количество
			article[i].price);	//Цена
	}
}

goods *createArticle1()
{
	goods *article = (goods*)calloc(10, sizeof(goods));
	if (article != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			createName(article[i].name, 5);
			createName(article[i].maker, 5);
			article[i].year = 2014 + rand() % 5;
			article[i].quantity = 1 + rand() % 1000;
			article[i].price = 100 + rand() % 5000;
		}
		printInfoPrd(article, 10);
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return article;
}

/* variant 3 */
void printInfoPrd2(goods3 *article, int len)
{
	//printf("--- Информация о товаре ---\n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d Наименование: %s; Количество: %d; Цена: %d; Производитель: %s; Дата выпуска: %d.%d.%d\n",
			i + 1,
			article[i].name,
			article[i].quantity,
			article[i].price,
			article[i].maker,
			article[i].crtDate.day,
			article[i].crtDate.month,
			article[i].crtDate.year);
	}
}

goods3 *createArticle2()
{
	goods3 *article = (goods3*)calloc(10, sizeof(goods3));
	if (article != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			createName(article[i].name, 5);
			article[i].quantity = 100 + rand() % 1000;
			article[i].price = 1000 + rand() % 5000;
			createName(article[i].maker, 5);
			generateDate(&article[i].crtDate);
			/*generateDate(&article[i].crtDate.month);
			generateDate(&article[i].crtDate.year);*/
		}
		printInfoPrd2(article, 10);

	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return article;
}

/* variant 4 */
void generatePosition(ocupation * pos)
{
	int rnd = 1 + rand() % 20;
	char srnd[3];
	_itoa(rnd, srnd, 10);
	//strcat(pos, "Должность #");
	strcpy(pos->ocup, "Должность #");
	strcat(pos->ocup, srnd);
}

void generateEducation(education *ed)
{
	int rnd = 1 + rand() % 3;
	switch (rnd)
	{
	case 1:
		strcpy(ed->grade, "Начальное");
		break;

	case 2:
		strcpy(ed->grade, "Среднее");
		break;

	case 3:
		strcpy(ed->grade, "Высшее");
		break;
	}
}

void printInfoEmpl(employee *file, int len)
{
	//printf(" --- Информация по работнику --- \n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d Фамилия: %s; Год рождения: %d.%d.%d; Должность: %s; Зарплата: %d; Образование: %s\n",
			i + 1,
			file[i].lastName,
			file[i].bdt.day,
			file[i].bdt.month,
			file[i].bdt.year,
			file[i].ocp.ocup,
			file[i].salary,
			file[i].ed->grade);
	}
}

employee *createFile()
{
	employee *file = (employee*)calloc(10, sizeof(employee));
	if (file != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			createName(file[i].lastName, 10);
			generateDate(&file[i].bdt);
			generatePosition(&file[i].ocp);
			file[i].salary = 100000 + rand() % 500000;
			generateEducation(file[i].ed);
		}
		printInfoEmpl(file, 10);
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return file;
}

/* variant 5 */
void generateSubject(subject *sub, int num)
{
	sub->rate = 75 + rand() % 25;

	switch (num)
	{
	case 0:
		strcpy(sub->nameSub, "Физика ");
		break;

	case 1:
		strcpy(sub->nameSub, "Математика ");
		break;

	case 2:
		strcpy(sub->nameSub, "Информатика ");
		break;
	}
}

void printInfoStd(student * students, int len)
{
	//printf(" --- Информация по студенту --- \n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d. %s (%s)\n",
			i + 1,
			students[i].name,
			students[i].groupe);
		for (int j = 0; j < 3; j++)
		{
			printf("-->%s\t%d\n",
				students[i].sub[j].nameSub,
				students[i].sub[j].rate);
		}
		printf("\n");
	}
}

student * createStudent(int *count)
{
	student *st = (student*)malloc(*count * sizeof(student));
	if (st != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName(st[i].name, 10);
			createName(st[i].groupe, 3);
			for (int j = 0; j < 3; j++)
			{
				generateSubject(&st[i].sub[j], j);
			}

		}
		printInfoStd(st, *count);
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return st;
}

/* variant 6 */	
void printInfoPln(Plane * pln, int len)
{
	//printf(" --- Информация по месту --- \n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d. Фамилия: %s, Имя: %s, Место: %d, Бронь: %d\n",
			i + 1,
			pln[i].psg.fName,
			pln[i].psg.lName,
			pln[i].plc.place,
			pln[i].plc.ocup);

		//printf("\n");
	}
}

Plane * createPlace(int *count)
{
	Plane *pl = (Plane*)calloc(*count, sizeof(Plane));
	if (pl != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName(pl[i].psg.fName, 10);
			createName(pl[i].psg.lName, 10);
			pl[i].plc.place = i + 1;
			pl[i].plc.ocup = 0+rand()%2;
			if (pl[i].plc.ocup == 0)
			{
				strcpy(pl[i].psg.fName, "None");
				strcpy(pl[i].psg.lName, "None");
			}
		}
		//printInfoPln(pl, *count);
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return pl;
}