#pragma once
#include "Factory.h"
#include "Image_editor.h"



class Factory_image :
    public Factory
{
public:
    Editor* create_editor();
    ~Factory_image()
    {

    }


}