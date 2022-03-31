#include "Factory_text.h"
#include "Text_editor.h"
Editor* Factory_text::create_editor()
{
	return new Text_editor;
}