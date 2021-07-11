#include"Header.h"
class Graduate :public Student
{
	string subject;
	//Teacher instructor;
public:
	const string& get_subject()const
	{
		return subject;
	}
	void set_subject(const string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, double rating,
		const string& subject
	) :Student(last_name, first_name, age, specialty, group, rating)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void print()
	{
		Student::print();
		cout << "Тема дипломного проекта: " << subject << endl;
	}
};

ostream& operator<<(ostream& os, const Graduate& obj)
{
	os << (Student&)obj;
	return os << ". Тема диплома: " << obj.get_subject();
}
