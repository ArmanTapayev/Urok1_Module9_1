#include"01_hockey.h"
#include"02_product.h"
#include"03_product.h"
#include"04_employee.h"
#include"05_student.h"
#include"06_airport.h"

/* variant 1 */
void createName(char *name, int len);
void generateDate(birthDate *date);
void printInfoHockey(hockeyPlayer *team, int len);
hockeyPlayer *createTeam(int *count);

/* variant 2 */
void printInfoPrd(goods *article, int len);
goods *createArticle1();

/* variant 3 */
//void generateDate(birthDate *date);
void printInfoPrd2(goods3 *article, int len);
goods3 *createArticle2();

/* variant 4 */
void generatePosition(ocupation * pos);
void generateEducation(education *ed);
void printInfoEmpl(employee *file, int len);
employee *createFile();

/* variant 5 */
void generateSubject(subject *sub, int num);
void printInfoStd(student * students, int len);
student * createStudent(int *count);

/* variant 6 */
void printInfoPln(Plane * pln, int len);
Plane * createPlace(int *count);

