#include "Replacer.hpp"

Replacer::Replacer(void) {}
Replacer::~Replacer(void) {}
Replacer::Replacer(
	std::string filename,
	std::string to_find,
	std::string to_replace) : _if_filename(filename),
							  _to_find(to_find),
							  _to_replace(to_replace) {}

void Replacer::set_if_filename(std::string filename)
{ 
	this->_if_filename = filename; 
}
void Replacer::set_to_find(std::string haystack) 
{
	this->_to_find = haystack; 
}
void Replacer::set_to_replace(std::string needle)
{
	this->_to_replace = needle;
}
void Replacer::set_result(std::string result)
{
	this->_result = result;
}

std::string Replacer::get_if_filename(void){ return this->_if_filename; }
std::string Replacer::get_to_find(void) { return this->_to_find; }
std::string Replacer::get_to_replace(void) { return this->_to_replace; }
std::string Replacer::get_result(void) { return this->_result; }

void Replacer::add_result(std::string line)
{
	std::string o_result = this->get_result();
	this->set_result(o_result + line);
}

std::string Replacer::replace_str(void)
{
	std::string line;
	std::ifstream file;
	std::string replaced_line_name = this->get_if_filename() + ".replace";
	std::ofstream replaced_file(replaced_line_name.c_str());

	file.open(this->_if_filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Unable to read file " << this->_if_filename << std::endl;
		return "";
	}
	this->_result.clear();

	while (std::getline(file, line))
	{
		std::size_t flag = line.find(this->get_to_find());
		while (flag != std::string::npos)
		{
			std::string sbstr1 = line.substr(0, flag);
			std::string sbstr2 = line.substr(flag + this->get_to_find().length(), line.length());
			std::string final = sbstr1 + this->get_to_replace() + sbstr2;
			line = final;
			flag = line.find(this->get_to_find());
		}
		if (flag == std::string::npos)
		{
			this->add_result(line + "\n");
		}
	}
	file.close();
	if (!replaced_file.is_open())
	{
		std::cerr << "Unable to open output file" << std::endl;
		return "";
	}
	replaced_file << this->get_result();
	replaced_file.close();
	return this->_result;
}