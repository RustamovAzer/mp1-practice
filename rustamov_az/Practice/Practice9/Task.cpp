#include "Task.h"

task::task()
{
	type = -1;
	description = "";
}

task::task(task& x)
{
	type = x.type;
	description = x.description;
}

unsigned task::set_type()
{
	return type;
}

void task::get_type(unsigned _type)
{
	type = _type;
}

time task::set_start(time x)
{
	return time();
}

time task::set_end(time x)
{
	return time();
}

void task::get_title()
{
	std::cout << description;
}

task::~task()
{

}