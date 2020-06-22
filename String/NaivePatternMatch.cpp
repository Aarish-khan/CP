#include<iostream>
#include<string>
using namespace std;


void NaivePatternMatch(string text, string pattern)
{
	int text_size = text.size();
	int pattern_size = pattern.size();
	bool isFound = false;
	for(int i=0; i+pattern_size<=text_size; i++)
	{
		int current_i = i;
		//variable j, to traverse through pattern string
		int j=0;
		for(; j<pattern_size; j++)
		{
			if(text[current_i] == pattern[j])
				++current_i;
			else
				break;
		}
		if(j==pattern_size)
		{
			cout<<"pattern found at index "<<i<<"\n";
			isFound = true;
		}
	}
	if(!isFound)
		cout<<"Pattern doesn't exist in text";
}

int main()
{
	string text = "khanpqrishtinnfgotaarishdonhiofjtunbdsoaarishbcbcadefhioctumneqwotpazldeaarish";
	string pattern = "aarish";

	NaivePatternMatch(text,pattern);
}
