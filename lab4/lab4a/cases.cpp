using namespace std;

#include <cctype>
#include <iostream>
#include <string>
#include <cstring>

void lower(string &s)
{
    int i = 0;
    while (i < s.size())
    {
        s[i] = tolower(s[i]);
        //changes current character of s to lowercase version
        i++;
    }
    cout << s << endl;
}

void upper(string &s)
{
    int i = 0;
    while (i < s.size())
    {
        s.replace(i,1,1,toupper(s[i]));
        //replaces current character in s with uppercase version
        i++;
    }
    cout << s << endl;
}

string capitalise(const string &s)
{
    int i = 0;
    string capitalised = s;
    bool firstLetterFound = false;
    while (i < capitalised.size())  //whilst i is in string s
    {
        if (!firstLetterFound)  //if first letter has not been found
        {
            if (isalpha(capitalised[i]))  //if current character is a letter
            {
                capitalised.replace(i,1,1,toupper(capitalised[i]));
                //the first letter is capitalized
                firstLetterFound = true; //firstLetterFound set to true
            }
        }
        else
        {
            capitalised.replace(i,1,1,tolower(capitalised[i]));
            //every letter after the first one set to lowercase instead
        }
        i++;
    }
    return capitalised;
}

int main()
{

    string a = "pOtAtO";
    cout << a << endl;
    lower(a);
    upper(a);
    cout << capitalise(a) << endl << endl;
    string b = "OK THATS cool I guess";
    cout << b << endl;
    lower(b);
    upper(b);
    cout << capitalise(b) << endl << endl;
    string c = "    hmm I wonder what time it is";
    cout << c << endl;
    lower(c);
    upper(c);
    cout << capitalise(c) << endl << endl;
    return 0;
}
