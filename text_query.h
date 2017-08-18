#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_
#include<string>
#include<fstream>
#include<memory>
#include<map>
#include<set>
#include<vector>
#include"query_result.h"

class TextQuery
{
	public:
		using line_no = std::vector<std::string>::size_type;
		TextQuery(std::ifstream &);
		QueryResult query(const std::string&) const;  //对this指针进行底层const限制的原因是该类类型对象作为调用对象其中数据唯一依赖的点就是文件，文件确定，在该对象构造完后就不应该改变
	private:
		std::shared_ptr<std::vector<std::string>> file;     //智能指针指向一个vector<string>容器，容器中每个元素存储输入文件中的每一行
		std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;   //map容器以每个搜索词为关键字寻找相应的一个set容器，该set容器存储该搜索词在输入文件出现的行号
};
#endif
