//Фамилия
//Группа
//Год рождения
//оценка по физике
//оценка по математике
//оценка по информатике

struct subject
{
	char nameSub[15];
	int rate;
};

struct student
{
	char name[10];
	char groupe[3];
	subject sub[3];
	birthDate bdt;
};


