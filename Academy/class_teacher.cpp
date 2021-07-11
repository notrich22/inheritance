#include"Header.h"
class Teacher : public Human
{
	string specialty;
	unsigned int experience;
public:
	int evil;
	const string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//				Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		this->specialty = specialty;
		this->experience = experience;
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		this->age = 123;
		//cout << "TDestructor:\t" << this << endl;
	}
	//			Methods:
	void print()
	{
		Human::print();
		cout << "специальность: " << specialty << ", опыт преподавания: " << experience << " лет" << endl;
	}
};
ostream& operator<<(ostream& os, const Teacher& obj)
{
	os << (Human&)obj << " ";
	os << ", специальность: " << obj.get_specialty()
		<< ", опыт преподавания: " << obj.get_experience() << " лет";
	return os;
}
