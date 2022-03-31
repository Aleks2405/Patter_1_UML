#pragma once
#include "Editor.h"



class Factory
{
public:
	virtual Editor* create_editor() = 0;
	virtual ~Factory()
	{

	}
};
