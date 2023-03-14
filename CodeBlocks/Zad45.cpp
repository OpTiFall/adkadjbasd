#include <iostream>
using namespace std;

class Queue
{
    private:
   // string *writings;

    int lastIndex;

    public:
    Queue():Queue(0) { }

    Queue(int size)
    {
       // writings = new string[size];
      //  this->lastIndex = size-1;
    }
    ~Queue()
    {
//        delete writings;
    }

  /*  void add(string writing)
    {
        string *temp;
        temp = new string[lastIndex+1];
        for(int i = 0; i < lastIndex+1;i++)
        {
            temp[i] = writings[i];
        }
        writings = new string[lastIndex+2];
        for(int i = 0 ; i < lastIndex+1;i++)
        {
            writings[i] = temp[i];
        }
        writings[lastIndex+1] = writing;

        delete temp;
    }
    */

};
 int main()
{
        Queue firstQueue;
        cout << "check";
        return 0;
}
