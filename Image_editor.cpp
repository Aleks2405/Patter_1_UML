#include "Image_editor.h"

void Image_editor::create_file()
{
	string path;//ïóòü
	string file_name;//èìÿ ôàéëà

	cout << "Enter path: ";
	cin >> path;
	cout << "Enter filename: ";
	cin >> file_name;

	set_path_to_file(path + file_name);//ïîëíûé ïóòü ê ôàéëó
	set_path_to_buffer(path + "buff.bmp	");//ê áóôåðó, áóôåð âñåãäà bmp

	ofstream create_buff(get_path_to_buffer(), ios::binary);// ñîçäàåì áóôåð äëÿ çàïèñè

	if (!create_buff.is_open())//ïðîâåðêà îòêðûò ëè ôàéë
	{
		std::cout << "Error! File was not open!\n";//ÍÅÒ
	}

	return;
}

void Image_editor::open_file()
{
	string path;//ïóòü
	string file_name;//èìÿ ôàéëà

	if (get_path_to_file() != "" || get_path_to_buffer() != "")//Åñëè óæå îòêðûò êàêîé-ëèáî ôàéë
	{
		char answer;//ïðåäëîæèòü ñîõðàíåíèå ïåðåä çàêðûòèåì
		do
		{
			cout << "Are you want to keep the current file? Y/N";
			cin >> answer;
		} while (tolower(answer) != 'y' && tolower(answer) != 'n');
		switch (tolower(answer))
		{
		case 'y'://ñîõðàíèòü
			save_file();
			close_file();
			break;
		case 'n'://íåò
			close_file();
			break;
		}
	}
	cout << "Enter path: ";
	cin >> path;
	cout << "Enter filename: ";
	cin >> file_name;

	set_path_to_file(path + file_name);//ïîëíûé ïóòü ê ôàéëó
	set_path_to_buffer(path + "buff.bmp");//ê áóôåðó

	ifstream opened_file(get_path_to_file().c_str(), ios::binary);//ôàéë, îòêðûâàåì äëÿ ÷òåíèÿ
	ofstream opened_buffer(get_path_to_buffer().c_str(), ios::binary);//áóôôåð, îòêðûâàåì â ðåæèìå çàïèñè

	if (!opened_buffer.is_open() || !opened_file.is_open())//íå óäàëîñü îòêðûòü áóôåð èëè ôàéë
	{
		opened_file.close();
		opened_buffer.close();
		std::cout << "Error! File was not open!\n";
	}

	opened_buffer << opened_file.rdbuf();//êîïèðóåì äàííûå èç ôàéëà â áóôåð

	return;
}

void Image_editor::save_file()
{
	ofstream file;
	file.open(get_path_to_file(), ios::binary);//ôàéë, îòêðûâàåì â ðåæèìå çàïèñè
	ifstream buffer;
	buffer.open(get_path_to_buffer(), ios::binary);//áóôåð, îòêðûâàåì â ðåæèìå ÷òåíèÿ
	if (file.is_open() && buffer.is_open())
		file << buffer.rdbuf();//êîïèðóåì èç áóôåðà â ôàéë
	else
		cout << "Error! Can't save the file!\n";
	return;
}

void Image_editor::save_file_as()//ñîõðàíåíèå â âûáðàííîì ôîðìàòå
{
	string new_file_name = "";//íîâîå èìÿ ôàéëà(ïîëíûé ïóòü)
	do
	{
		cout << "New filename: ";
		cin >> new_file_name;
	} while (new_file_name == "");//ïîêà ââîäÿò ïóñòóþ ñòðîêó

	set_path_to_file(new_file_name);//íîâîå èìÿ ôàéëà(ïîëíûé ïóòü)
	save_file();//ñîõðàíÿåì

	return;
}

void Image_editor::print_file()
{
	/*Çàãëóøêà*/
	cout << "The file is printed.\n";

	return;
}


void Image_editor::close_file()
{
	//çàêðûâàåì áóôåð
	if (get_path_to_buffer() != "")
	{
		ofstream close_buffer(get_path_to_buffer());
		close_buffer.close();
		close_buffer.clear();

		if (close_buffer.is_open())//åñëè âñå åùå îòêðûò
		{
			cout << "Error! The File is open!\n";
		}
		else
			std::cout << "Åhe buffer has been closed. Testing complete!\n";//òåñò
	}
	//çàêðûâàåì ôàéë
	if (get_path_to_file() != "")
	{
		ofstream close_file(get_path_to_buffer());
		close_file.close();
		close_file.clear();

		if (close_file.is_open())//åñëè âñå åùå îòêðûò
		{
			cout << "Error! The File is open!\n";
		}
		else
			std::cout << "Åhe file has been closed. Testing complete!\n";//òåñò
	}
	if (remove(path_to_buffer.c_str()))//óäàëÿåì áóôåð
		cerr << "Error! Can't delete file!\n";//íå óäàëèëñÿ
	set_path_to_buffer("");//èíèöèàëèçèðóåì ïîëÿ ïóñòûìè ñòðîêàìè
	set_path_to_file("");//"---"---"

	return;
}

void Image_editor::set_path_to_file(string path_to_file)//ñåòòåð ïîëÿ ïóòè ê ôàéëó
{
	this->path_to_file = path_to_file;

	return;
}

void Image_editor::set_path_to_buffer(string path_to_buffer)//ñåòòåð ïîëÿ ïóòè ê áóôåðó
{
	this->path_to_buffer = path_to_buffer;

	return;
}

string Image_editor::get_path_to_file()//ãåòòåð ïîëÿ ïóòè ê ôàéëó
{
	return path_to_file;
}

string Image_editor::get_path_to_buffer()//ãåòòåð ïîëÿ ïóòè ê áóôåðó
{
	return path_to_buffer;
}

Image_editor::~Image_editor()//dtor
{
}