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
	printf("������ �������� 6 ���������.\n");
	printf("��� ���������� �������� 0.\n");
	int n;
	do
	{
		printf("������� ����� ��������: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*	���� ���������				������
				�������						���������� ������� ������� ���������� 
				�������						� ������� �������� � ����������, ������� ������� ������ 25 ���
				���������� ��� 
				���������� ����������� ����
			*/

			int count = 6, sum = 0;
			printf("--- ���������� � ������� ---\n");
			hockeyPlayer *cmp = createTeam(&count);
			printf("���������, ������� ������� ����� 25 ���:\n");
			for (int i = 0; i < count; i++)
			{
				sum += cmp[i].age;
				if (cmp[i].age < 25)
					printInfoHockey(&cmp[i], 1);				
			}
			printf("������� ������� ����������: %0.2f\n", (float)sum/count);
			system("pause");
			system("cls");
		}break;

		case 2:
		{
			/*	���� ���������	 ������
				������������	 ���������� ����� ��������� ���� �������, ���������� � ������� ���� � 
				�������������	 ������� �������� �� ���� �������.
				���_������� 
				����������
				����
			*/
			int count = 10, sum = 0, k=0;
			printf("--- ���������� � ������ ---\n");
			goods *cmp = createArticle1();
			printf("�������� � �������, ���������� � 2018 ����:\n");
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
				printf("�������, ���������� � 2018 ���� ���.\n");

			printf("����� ��������� ���� �������, ���������� � 2018 ����: %d\n", sum);
			system("pause");
			system("cls");
		}break;

		case 3:
		{
			/*	���� ���������	 ������
				������������	 ���������� ������� ��������� ������� � ����� � ����������� ����������.
				����������
				����
				�������������
				����_�������
			*/

			int count = 10, sum = 0, intMin;
			printf("--- ���������� � ������ ---\n");
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
			printf("������� ��������� �������: %0.2f\n", (float)sum / count);
			printf("����� � ����������� ����������:\n");
			printInfoPrd2(&cmp[intMin], 1);
			system("pause");
			system("cls");
		}break;

		case 4:
		{
			/*	���� ���������		������
				�������				���������� ������ �������� ��������� � ���������� �������� � ���.
				��� �������� 
				��������� 
				��������
				�����������
			*/
			int count = 10, sum = 0;
			printf(" --- ���������� �� ��������� --- \n");
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
			printf("����� ������� ��������:\n");
			printInfoEmpl(&cmp[maxInd], 1);
			system("pause");
			system("cls");
		}break;

		case 5:
		{
			/*	���� ���������		    ������
				�������					���������� ������� ���������, ������� ����� ���������� �� �95�, 
				������					� ���������� �� ����������.
				��� ��������
				������ �� ������
				������ �� ����������
				������ �� �����������
			*/
			int count = 10, sum = 0,k=0;
			printf(" --- ���������� �� �������� --- \n");
			student *cmp = createStudent(&count); 
			printf("��������, ������� ����� ���������� �� 95: \n");
			for (int i = 0; i < count; i++)
			{
				if (cmp[i].sub[1].rate > 95)
				{
					printInfoStd(&cmp[i], 1);
					k++;
				}
			}
			printf("���������� ���������: %d\n", k);
	
			system("pause");
			system("cls");
		}break;
		}
	} while (n != 0);
}