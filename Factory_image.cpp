#include "Factory_image.h"

Editor* Factory_image::create_editor()
{
    return new Image_editor;
}