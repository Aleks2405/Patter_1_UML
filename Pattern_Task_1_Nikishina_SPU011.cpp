#include <iostream>
#include "Factory.h"
#include "Factory_text.h"
#include "Text_editor.h"
#include "Factory_image.h"
#include "Image_editor.h"

int main()
{
    //�������� ������������ ���������
    Factory_image* Factory_image_1 = new Factory_image;
    Editor* image_editor = Factory_image_1->create_editor();

    //������������ ������������ ���������
    image_editor->create_file();//������� ����
    image_editor->open_file();//������� ����
    image_editor->save_file();//��������� ����
    image_editor->save_file_as();//��������� ���� ���
    image_editor->close_file();//������� ����

    //�������� ���������� ���������
    Factory_text* Factory_text_1 = new Factory_text;
    Editor* text_editor = Factory_text_1->create_editor();

    //������������ ���������� ���������
    text_editor->create_file();//������� ����
    text_editor->open_file();//������� ����
    text_editor->save_file();//��������� ����
    text_editor->save_file_as();//��������� ���� ���
    text_editor->print_file();//������ �����(� �������)
    text_editor->close_file();//������� ����

    return 0;

}