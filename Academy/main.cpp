#include "Header.h"

//#define INHERITANCE_BASICS

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INHERITANCE_BASICS
	/*Human human("Тупенко", "Василий", 18);
human.print();*/
	Student stud("Тупенко", "Василий", 18, "РПО", "BV_123", 43.4);
	stud.print();
	Teacher Albert("Einstein", "Albert", 150, "Astrophisics", 120);
	Albert.print();
	cout << Albert.get_last_name() << endl;
	Albert.get_first_name();
#endif // INHERITANCE_BASICS
	//				POINTERS TO BASE CLASS
	Human* group[] =
	{
		new Student("Васильев", "Александр", 23, "РПО", "ПВ_011", 90),
		new Student("Васильева", "Маргарита", 25, "РПО", "ПВ_011", 90),
		new Teacher("Ковтун", "Олег", 36, "Разработка приложений на C++", 6),
		new Student("Ивлев", "Александр", 25, "РПО", "ПВ_011", 95),
		//new Graduate("Рахманин", "Николай", 28, "РПО", "ПВ_011", 98, "Разработка кросплатформенной обучающей игры"),
		new Teacher("Романов", "Андрей", 30, "HardwarePC", 5),
		new Student("Нусс", "Дмирий", 22, "РПО", "ПВ_011", 100),
		new Student("Борн", "Евгений", 35, "РПО", "ПВ_011", 99),
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		//cout << *group[i] << endl;
		//cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		//cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}