#include <bits/stdc++.h>
using namespace std;

stack<char> operators;

int priority(char c)
{
    switch(c)
    {
        case '(':
            return 0;
        case '+':
        case '-':
        case '–':
        case ')':
            return 1;
        case 'x':
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
  }
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
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
        while( i < expr.length() && (isDigit(expr[i]) || isSign(expr[i])))
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

//void printStack(stack<char> s){
 //while(s.size() != 0) {cout << s.top(); s.pop();}
//}

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
           // onp += ' ';
        }
        else
        {
            p = priority(e[0]);
            if(p == 0) {operators.push(e[0]);}
            else if(p == 1 && e[0] == ')')
            {
                while(!operators.empty() && operators.top() != '(')
                {
                    onp += operators.top();
                 //   onp += ' ';
                    operators.pop();
                }
                if(operators.top() == '(') {operators.pop();}
            }
            else if(operators.size() == 0 || (priority(operators.top()) < p)) { operators.push(e[0]);}
            else
            {
                while(operators.size() != 0 && priority(operators.top()) >= p)
                {
                    onp += operators.top();
                 //   onp += ' ';
                    operators.pop();
                }
                operators.push(e[0]);
            }
        }
    }
    while(operators.size() != 0)
    {
        onp += operators.top();
       //onp += ' ';
        operators.pop();
    }

    return onp;
}

double solve(double a, double b, char o){
    switch(o){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
  }
}

double CalculateResult(string onp){
    vector<string> elements = getElements(onp);
    stack<double> numbers;
    //cout << "fromONP size elements " << elements.size() << endl;
    double a, b, r;
    for(auto e: elements)
    {
        //cout << e << " ";
        if(isDigit(e[0])){ numbers.push(stoi(e)); }
        else
        {
            cout << numbers.size() << endl;
            if(numbers.size() < 2){ //return -1; }}}
            }
            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();
            r = solve(b, a, e[0]);
            numbers.push(r);
        }

    }
    if(numbers.size() != 1) { cout << "error" << endl;}
    return numbers.top();
}

int main()
{
    int m = 0;
    cin >> m;
    for(int i = 0; i < m;i++)
    {
        string e;
        cin >> e;
        cout << toONP(e) << endl;
        //cout << CalculateResult(e) <<endl;
    }
    return 0;
}
