#pragma once
#include "Editor.h"
class Image_editor :
	public Editor
{
public:
	void create_file();//ñîçäàòü
	void open_file();//îòêðûòü
	void save_file();//ñîõðàíèòü
	void save_file_as();//ñîõðàíèòü êàê
	void print_file();//ïå÷àòü?
	void close_file();//çàêðûòü

	void set_path_to_file(string);//ñåòòåð ïóòè ê ôàéëó
	void set_path_to_buffer(string);//ñåòòåð ïóòè ê áóôåðó

	string get_path_to_file();//ãåòòåð ïóòè ê ôàéëó
	string get_path_to_buffer();//ãåòòåð ïóòè ê áóôåðó

	~Image_editor();
private:
	string path_to_file;//ïóòü ê ôàéëó
	string path_to_buffer;//ïóòü ê áóôåðó
};
