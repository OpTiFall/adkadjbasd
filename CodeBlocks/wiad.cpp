#include <bits/stdc++.h>
using namespace std;

stack<char> operators;

int priority(char c)
{
    switch(c)
    {
        case '<':
        case '>':
            return 0;
        case '!':
        case '?':
            return 1;
        default:
            return -1;
  }
}

bool isSign(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

vector<string> getElements(string expr) {
    vector<string> elements;
    string s;
    for(int i = 0; i < expr.length(); i++)
    {
        while( i < expr.length() && isSign(expr[i]))
        {
            s += expr[i++];
        }
        if(s.size() > 0)
        {
            elements.push_back(s);
            s.clear();
        }
        if(expr[i] == ' ') {}
        else if(priority(expr[i]) >= 0)
        {
            s += expr[i];
            elements.push_back(s);
            s.clear();
        }
    }
    if(s.size() > 0)
    {
        elements.push_back(s);
        s.clear();
    }
    return elements;
}

string toONP(string expr) {

    vector<string> elements = getElements(expr);
    string onp;
    //for(auto e: elements) cout << e << endl;
    int p;

    for(auto e: elements)
    {
        if(e.size() == 0) { continue; }
        if(isSign(e[0]))
        {
            onp += e;
          //  onp += ' ';
        }
        else
        {
            p = priority(e[0]);
           if(p == 0)
            {
                operators.push(e[0]);
               /* while(!operators.empty())
                {
                    //operators.push(e[0]);
                    onp +=  operators.top();
                    onp += ' ';
                    operators.pop();
                }
                */
            }
            else if(p == 1)
            {
              /*   while(operators.size() != 0 && priority(operators.top()) >= p)
                {
                    onp += operators.top();
                    onp += ' ';
                    operators.pop();
                }
                */
              //  onp += e[0];
               // operators.push(e[0]);
            }
         //   else if(operators.size() == 0 || (priority(operators.top()) < p)) { operators.push(e[0]);}
          /*  else
            {
                while(operators.size() != 0 && priority(operators.top()) >= p)
                {
                    onp += operators.top();
                    onp += ' ';
                    operators.pop();
                }
                operators.push(e[0]);
            }

            */


        }
    }
    while(operators.size() != 0)
    {
        onp += operators.top();
        onp += ' ';
        operators.pop();
    }

   return onp;
}

char solve(char a, char b, char o){
    switch(o){
        case '<':
            return a-1;
        case '>':
            return a+1;
        case '?':
            if(a > b) {return a;}
            if(a < b) {return b;}
        case '!':
            if(a > b) {return b;}
            if(a < b) {return a;}
        default: return '~';
  }
}

double CalculateResult(string onp){
    vector<string> elements = getElements(onp);
    stack<char> chars;
    char a, b, r;
    for(auto e: elements)
    {
       if(isSign(e[0])){ chars.push(stoi(e)); }
        else
        {
            //cout << chars.size() << endl;
            if(chars.size() < 2){ return -1; }

            a = chars.top();
            chars.pop();
            b = chars.top();
            chars.pop();
          //  r = solve(b, a, e[0]);
            chars.push(r);

        }


    }
    if(chars.size() != 1) { cout << "error" << endl;}
    return chars.top();
}

int main()
{
    cout << toONP("a>dh?<bg!") << endl;
    cout << CalculateResult(toONP("a>dh?<bg!"));
    return 0;
}
