#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Editor
{
public:
	virtual void create_file() = 0;
	virtual void open_file() = 0;
	virtual void save_file() = 0;
	virtual void save_file_as() = 0;
	virtual void print_file() = 0;
	virtual void close_file() = 0;
	virtual ~Editor()
	{

	}
}; 
