#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include"totalService.h"

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
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

		case 6:
		{
			char *firstName = (char*)malloc(10 * sizeof(char));
			char *lastName = (char*)malloc(10 * sizeof(char));
			int n;
			int ind, plcInd;
			int count = 12, sum = 0, k = 0, tempPr=1;
			Plane * psg = createPlace(&count);
			Plane *temp = createPlace(&tempPr);
			//printInfoPln(psg, count);
			printf("-------------------------------------------------------------------------\n");
			printf("*** ���������� � ����������� �� ���� ������������ Colossus Airlines. ***\n");
			printf("-------------------------------------------------------------------------\n");
			do
			{
				printf("-------------------------------------------------------------------------\n");
				printf("0. ������ ���� ����.\n");
				printf("1. ���������� ��������� ����.\n");
				printf("2. ������ ������ ��������� ����.\n");
				printf("3. ���������� ������ ������� ����.\n");
				printf("4. ��������� �����.\n");
				printf("5. ������� ����������� �����.\n");
				printf("6. ����� �� ���������.\n");
				printf("-------------------------------------------------------------------------\n");
				printf("�������� ����� ����: ");
				scanf("%d", &n);
				switch (n)
				{
					case 0:
					{   printf("-------------------------------------------------------------------------\n");
						printf("������ ���� ����������:\n");
						printf("-------------------------------------------------------------------------\n");
						printInfoPln(psg, count);
						system("pause");
						system("cls");
					}break;

					case 1:
					{
						for (int  i = 0; i < count; i++)
						{
							if (psg[i].plc.ocup==0)
								k++;
						}
						printf("-------------------------------------------------------------------------\n");
						printf("���������� ��������� ����: %d\n", k);
						printf("-------------------------------------------------------------------------\n");
						system("pause");
						system("cls");
					}break;

					case 2:
					{
						printf("-------------------------------------------------------------------------\n");
						printf("������ ��������� ����:\n", k);
						printf("-------------------------------------------------------------------------\n");
						for (int i = 0; i < count; i++)
						{
							if (psg[i].plc.ocup == 0)
								printInfoPln(&psg[i], 1);
						}
						system("pause");
						system("cls");
					}break;

					case 3:
					{
						printf("-------------------------------------------------------------------------\n");
						printf("���������� ������ ������� ����:\n", k);
						printf("-------------------------------------------------------------------------\n");
						for (int i = 0; i < count-1; i++)
						{
							for (int j = i+1; j < count; j++)
							{
								if (strcmp(psg[i].psg.fName, psg[j].psg.fName)>0)
								{
									*temp= psg[i];
									psg[i]= psg[j];
									psg[j]=*temp;
								}
							}
						}
						for (int i = 0; i < count; i++)
						{
							if (psg[i].plc.ocup == 1)
								printInfoPln(&psg[i], 1);
						}
						//printInfoPln(psg, count);
						system("pause");
						system("cls");
					}break;

					case 4:
					{
						
						//int ind, plcInd;
						printf("������� ���: ");
						scanf("%s", firstName);
						printf("������� �������: ");
						scanf("%s", lastName);
						for (int i = 0; i < count; i++)
						{
							if (psg[i].plc.ocup == 0)
							{
								ind = i;
								plcInd=psg[i].plc.place;
								psg[i].plc.ocup = 1;
								strcpy(psg[i].psg.fName, firstName);
								strcpy(psg[i].psg.lName, lastName);
								break;
							}
							
						}
						printf("-------------------------------------------------------------------------\n");
						printf("%s %s, ��� ��������� ����� �%d.\n",
							firstName, lastName, plcInd);
						printf("-------------------------------------------------------------------------\n");
						printInfoPln(&psg[ind], 1);
						/*printf("������ ���� ����������:\n");
						printInfoPln(psg, count);*/
						system("pause");
						system("cls");

					}break;

					case 5:
					{	
						//plcInd = psg[i].plc.place;
						psg[ind].plc.ocup = 0;
						strcpy(psg[ind].psg.fName, "None");
						strcpy(psg[ind].psg.lName, "None");
						printf("-------------------------------------------------------------------------\n");
						printf("%s %s, ���� ����� ������������.\n", firstName, lastName);
						printf("-------------------------------------------------------------------------\n");
						/*printf("������ ���� ����������:\n");
						printInfoPln(psg, count);*/
						system("pause");
						system("cls");
					}break;

					case 6:
					{   printf("-------------------------------------------------------------------------\n");
						printf("����� �������!\n");
						printf("-------------------------------------------------------------------------\n");
						n = 6;
						system("pause");
						system("cls");
					}break;

					default:
						printf("�������� ����� ����:\n");
						system("pause");
						system("cls");
					break;
				}

			} while (n != 6);
			
		system("pause");
		system("cls");
		}break;
		}
	} while (n != 0);
}