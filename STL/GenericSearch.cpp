#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book{
public:
	string name;
	int price;

	Book(string name, int price){
		this->name = name;
		this->price = price;
	}
	Book(){

	}
};
//class to compare two books
class BookCompare{

public:
	bool operator()(Book A, Book B){
		return A.name == B.name;
	}

};
template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator begin, ForwardIterator end, T key, Compare cmp){

	while(begin!=end){
		if(cmp(*begin,key))
			return begin;

		begin++;
	}
	return end;
}

int main(){

	Book b1("python", 100);
	Book b2("c++", 150);
	Book b3("c", 156);
	Book b4(b1);

	vector<Book> vec;

	vec.push_back(b1);
	vec.push_back(b2);
	vec.push_back(b3);
	vec.push_back(b4);

	BookCompare cmp;
	Book Booktofind("c++",160);
	auto it = search(vec.begin(), vec.end(), Booktofind, cmp);

	if(it!=vec.end())
		cout<<"book is present in library";
	else
		cout<<"book not found";

}
