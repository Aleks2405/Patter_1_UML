#pragma once
#include "Editor.h"
class Text_editor : public Editor
{
public:
		void create_file();
		void open_file();
		void save_file();
		void save_file_as();
		void print_file();
		void close_file();

		void set_path_to_file(string);//ñåòòåð ïóòè ê ôàéëó
		void set_path_to_buffer(string);//ñåòòåð ïóòè ê áóôåðó

		string get_path_to_file();//ãåòòåð ïóòè ê ôàéëó
		string get_path_to_buffer();//ãåòòåð ïóòè ê áóôåðó

		~Text_editor();//äòîð

private:
	string path_to_file;//ïóòü ê ôàéëó
	string path_to_buffer;//ïóòü ê áóôåðó
	};
