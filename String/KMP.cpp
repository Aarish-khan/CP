#include <iostream>
#include <string>
using namespace std;

void computeLPS(string pattern, int *lps){

	int pattern_size = pattern.size();

	int len = 0; //moves only if there is matching character found ahead
	int i = 1; //moves continuosly to check if the current character is equal to character at len
	lps[0] = 0;

	while(i<pattern_size)
	{
		if(pattern[i]==pattern[len])
		{
			lps[i] = len+1;
			len++; i++;
		}
		else
		{
			if(len!=0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMP(string text, string pattern){

	int text_size = text.size();
	int pattern_size = pattern.size();

	int lps[pattern_size];
	computeLPS(pattern,lps);

	int i = 0; //text pointer
	int j = 0; //pattern pointer
	while(i < text_size)
	{
		if(text[i]==pattern[j]){
			i++; j++;
		}
		if(j==pattern_size)
		{
			cout<<"patern found from index "<<i <<" to "<<i+j<<endl;
			j = lps[j-1];
		}

		else if(i<text_size && text[i]!=pattern[j])
		{
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}

	}
}


int main()
{
	string text = "khanpqrishtinnfgotaarishdonhiofjtunbdsoaarishbcbcadefhioctumneaarishqwotpazldeaarish";
	string pattern = "aarish";

	KMP(text,pattern);
}
