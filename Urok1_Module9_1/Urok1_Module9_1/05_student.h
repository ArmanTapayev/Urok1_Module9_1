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
	char name[15];
	char groupe[15];
	subject sub[3];
};


