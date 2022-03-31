#pragma once
#include "Factory.h"

// êîíêðåòíàÿ ôàáðèêà (òåêñò-ðåäàêòîð)

class Factory_text :
    public Factory
{
public:
    virtual Editor* create_editor();
    ~Factory_text()
    {

    }
}