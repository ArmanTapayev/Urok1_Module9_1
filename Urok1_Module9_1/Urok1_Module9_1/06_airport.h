struct Passenger
{
	char fName[10];
	char lName[10];
};

struct Place
{
	int place;
	int ocup;
};

struct Plane
{
	Passenger psg;
	Place plc;
};
