#include <iostream>

using namespace std;

template <class S, class T>
class Pair
{
private:
    S s;
    T t;
public:

    Pair(S a, T b): s(a), t(b) {};
    //member variable 's' set to value and type of parameter 'a'
    //member variable 't' set to value and type of parameter 'b'

    S getFirst() const
    {
        return s;
        //just returns 's' member variable
    };
    T getSecond() const
    {
        return t;
        //just returns 't' member variable
    };

    void setFirst(const S &s)
    {
        this->s = s;
        //allows the 's' item of this object to be overwritten by the 's' parameter
    }

    void setSecond(const T &t)
    {
        this->t = t;
        //allows the 't' item of this object to be overwritten by 't' parameter
    }
    template <class S1, class T1> friend ostream& operator<<(ostream& o, const Pair<S1,T1> &p);
    //basically allows an ostream friend function so you can 'cout<<pairObject'
};

template <class S1, class T1>::
ostream& operator<<(ostream& o, const Pair<S1,T1> &p)
{
    o << '(' << p.getFirst() << ", " << p.getSecond() << ')';
    return o;
}

int main()
{
    Pair<char,char> p1('p','q');
    cout << p1.getFirst() << endl;
    cout << p1.getSecond() << endl;
    cout << p1 << endl << endl;

    Pair<int,int> p2(4,2);
    cout << p2.getFirst() << endl;
    cout << p2.getSecond() << endl;
    cout << p2 << endl << endl;

    Pair<string,int> p3("nice meme",420);
    cout << p3.getFirst() << endl;
    cout << p3.getSecond() << endl;
    cout << p3 << endl << endl;

    cout << p1 << endl;
    p1.setFirst('x');
    cout << p1 << endl;
    p1.setSecond('d');
    cout << p1 << endl;
    return 0;
}
