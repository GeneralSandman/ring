#include <iostream>
#include <memory>
#include <queue>
using namespace std;

class A
{
  private:
    int m;

  public:
    A(int m) { cout << "construct\n"; }
    ~A() { cout << "distory\n"; }
};

void test()
{
    {
        deque<shared_ptr<A>> res;
        shared_ptr<A> tmp;
        for (int i = 0; i < 3; i++)
        {
            tmp = shared_ptr<A>(new A(i));
            res.push_back(tmp);
        }

        cout << "end----------------\n";
    }
    cout << "+++++++++++++++++++" << endl;
    {
        deque<shared_ptr<A>> res;
        shared_ptr<A> tmp;
        for (int i = 0; i < 3; i++)
        {
            tmp = make_shared<A>(A(i));
            res.push_back(tmp);
        }

        cout << "end----------------\n";
    }
}

shared_ptr<A> re(){
    return nullptr;
}
int main()
{
    shared_ptr<A> p=re();
    if(p==nullptr){
        cout<<"p is nullptr"<<endl;
    }
    return 0;
}