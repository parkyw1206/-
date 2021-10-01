#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char **argv)
{
  vector < vector < char >>words;
  int line = 0, width = 15;
  string tempStr = "", returnStr = "";

  while (getline (cin, tempStr) )
    {
      words.push_back (vector<char> ());
      for (int i = 0; i < width; i++)
	{
	  if (tempStr[i])
	    {
	      words[line].push_back (tempStr[i]);
	    }
	  else
	    {
	      for (int j = i; j < width; j++)
		    {
        	  words[line].push_back(' ');
        	}
        	  i = width;
	    }

	}
      line++;
    }

  for (int i = 0; i < width; i++)
    {
      for (int j = 0; j < 5; j++)
	{
	  if (words[j][i] != ' ')
	    returnStr += words[j][i];
	}
    }
  cout << returnStr;
  return 0;
}
