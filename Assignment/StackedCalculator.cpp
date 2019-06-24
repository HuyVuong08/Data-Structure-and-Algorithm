

#include <iostream>
#include <string>

#include "DataStructure.h"

using namespace std;


bool isDigit (char c) 
{
	return (c >= '0' && c <= '9');
}

bool isOperator (char c) 
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

bool isLetter (char c)
{
    return (c >= 'a' && c <='z' || c >= 'A' && c <='Z');
}

bool isDot (char c)
{
    return (c == '.');
}

bool isStopDecimal (char c)
{
    return (c == '|');
}

int getPrecedence (char c) 
{
	switch (c) 
    {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '(':
		case ')': return 3;
		default: return -1;
	}
}


float Operate (float val1, float val2, char op) 
{
	if (op == '+') return val1 + val2;
	if (op == '-') return val1 - val2;
	if (op == '*') return val1 * val2;
	return val1 / val2;
}

void RemoveSpaces(string & s) 
{ 
    char * c = new char [s.length()+1];
    strcpy (c, s.c_str());
    
    int count = 0; 
  
    for (int i = 0; c[i]; i++) 
        if (c[i] != ' ') 
            c[count++] = c[i]; 
                                    
    c[count] = '\0'; 
    s = c;
} 

bool Correct (string & s)
{
    RemoveSpaces(s);

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '-' && s[i+1] == '-')
        {
            s[i] = '+';
            s[i+1] = ' ';
        } 
        else if (s[i] == '+' && s[i+1] == '+')
        {
            s[i] = '+';
            s[i+1] = ' ';
        } 
        else if (s[i] == '-' && s[i+1] == '+' || s[i] == '+' && s[i+1] == '-')
        {
            s[i] = '-';
            s[i+1] = ' ';  
        }
        else if (isLetter (s[i])) return false;
    }
    RemoveSpaces(s);
    return true;
}

float getDecimal (Stack<int> decimal)
{
    float b = 0;
    int a = 0;
    
    while (!decimal.isEmpty())
    {
        decimal.Pop(a);
        b = (b + a) * 0.1;
    }

    return b;
}

float evaluate (string s) 
{
    Correct (s);
    
    Stack<float> vals;
    Stack<char> ops;
    Stack<int> decimals;
    
    float val = 0, b = 0;
    int pos = 0;
    
    bool dot = false;

    while (pos < s.length()) 
    {
        char spot = s[pos];
        if (isDigit (spot)) 
        {
            if (dot == true)
            {
                int a = (int)spot - '0';
                cout << "a = " << a << endl;
                decimals.Push (a);
                cout << endl;
                decimals.Print2Console ();
            }
            else if (dot == false)
                val = (val * 10) + (int)(spot - '0');
        }
        else if (isDot (spot))
        {
            dot = true;
        }
        else if (isOperator (spot)) 
        {
            if (dot == true)
            {
                b = getDecimal (decimals);
                val = val + b;
                dot = false;
                b = 0;    
            }
     
            if (spot == '(') 
            {
                ops.Push (spot);
                val = 0;
            }
            else if (vals.isEmpty()) 
            {
                vals.Push (val);
                ops.Push (spot);
                val = 0;
            }
            else if (spot == ')') 
            {
                vals.Push (val);
                while (ops.Peek () != '(') {
                    ops.Pop (spot);
                    vals.Pop (val);
                    float prev;
                    vals.Pop (prev);
                    val = Operate (prev, val, spot);
                    vals.Push (val);
                }

                float ignore1;
                char ignore2;

                vals.Pop (ignore1);
                ops.Pop (ignore2);
            }
            else 
            {
                char prev = ops.Peek();
                if (getPrecedence (spot) > getPrecedence (prev)) 
                {
                    vals.Push (val);
                    ops.Push (spot);
                    val = 0;
                }
                else 
                {
                    float preval;
                    vals.Pop (preval);
                    char prevop;
                    ops.Pop (prevop);
                    preval = Operate (preval, val, prevop);
                    vals.Push (preval);
                    ops.Push (spot);
                    val = 0; 
                }
            }
        }
        pos ++;
    }
    
    cout << endl;
    decimals.Print2Console ();

    while (!ops.isEmpty())
    {
        float prev;
        vals.Pop (prev);
        char spot;
        ops.Pop (spot);
        val = Operate (prev, val, spot);
    }
    return val;
}

int main () 
{
    string s = "6.12 - 3.45";

    //cout << "Please Enter an Arithmetic Expression: " << s;
    //cin >> s;

    if (Correct (s)) 
    {
        cout << s << '=' << evaluate (s) << endl;      
    }
    else
    {
        cout << "Invalid Expression" << endl;
    }

    return 0;
}