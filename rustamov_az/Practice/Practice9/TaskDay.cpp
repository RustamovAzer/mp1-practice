#include "TaskDay.h"

taskday::taskday() : task()
{
	get_type(1);
	description = "";
	
}

taskday::taskday(taskday& x) : task(x)
{
	 get_type(x.set_type());

	 description = x.description;
}

taskday::~taskday()
{

}

time taskday::get_start()
{
	return time();
}

time taskday::get_end()
{
	return time();
}

void taskday::print()
{
	std::cout << "|" << description << "| [" << start_day << "]" << std::endl;
}

void taskday::print(std::ofstream& s)
{

}
