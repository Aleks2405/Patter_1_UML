#include <iostream>
#include "Factory.h"
#include "Factory_text.h"
#include "Text_editor.h"
#include "Factory_image.h"
#include "Image_editor.h"

int main()
{
    //создание графического редактора
    Factory_image* Factory_image_1 = new Factory_image;
    Editor* image_editor = Factory_image_1->create_editor();

    //тестирование графического редактора
    image_editor->create_file();//создать файл
    image_editor->open_file();//открыть файл
    image_editor->save_file();//сохранить файл
    image_editor->save_file_as();//сохранить файл как
    image_editor->close_file();//закрыть файл

    //создание текстового редактора
    Factory_text* Factory_text_1 = new Factory_text;
    Editor* text_editor = Factory_text_1->create_editor();

    //тестирование текстового редактора
    text_editor->create_file();//создать файл
    text_editor->open_file();//открыть файл
    text_editor->save_file();//сохранить файл
    text_editor->save_file_as();//сохранить файл как
    text_editor->print_file();//печать файла(в консоль)
    text_editor->close_file();//закрыть файл

    return 0;

}