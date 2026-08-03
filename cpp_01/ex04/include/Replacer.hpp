#ifndef REPLACER_H
#define REPLACER_H

# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>

class Replacer
{
	private:
		std::string _if_filename;
		std::string _to_find;
		std::string _to_replace; //string to replace in haystack
		std::string _result; //replaced haystack

	public:
		Replacer(void);
		~Replacer(void);
		Replacer(std::string filename, std::string to_find, std::string to_replace);

		void set_if_filename(std::string filename);
		void set_to_find(std::string haystack);
		void set_to_replace(std::string needle);
		void set_result(std::string result);

		std::string get_if_filename(void);
		std::string get_to_find(void);
		std::string get_to_replace(void);
		std::string get_result(void);
		
		void add_result(std::string line);
		std::string replace_str(void);
		
} ;

#endif