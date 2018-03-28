#include <iostream>
#include <vector>
#include <set>
using namespace std;
class CSet
{
private:
    int numLen;
    int *num;
public:
    CSet(int iLen) : numLen(iLen)
    {
        num = new int[numLen];
    }
    void input()
    {
        cout << "Please input " << numLen << " numbers:";
        for (int i = 0 ; i < numLen ; i++)
        {
            cin >> num[i];           
        }
    }
    void show()
    {
        for (int i = 0 ; i < numLen ; i++)
        {
            cout << num[i] << " ";
        }
        cout << endl;
    }
    CSet operator+ (const CSet& c1)
    {
        set<int> s;
        for (int i = 0 ; i < numLen ; i++)
        {
            s.insert(this->num[i]);
        }
        for (int i = 0 ; i < c1.numLen ; i++)
        {
            s.insert(c1.num[i]);
        }
        int len = s.size();
        CSet t(len);
        set<int>::iterator it;
        int j = 0;
        for (it = s.begin() ; it != s.end() ; it++)
        {
            t.num[j] = *it;
            j++;
        }
        return t;
    }
    CSet operator- (const CSet& c1)
    {
        set<int> s;
        set<int>::iterator it;
        for (int i = 0 ; i < numLen ; i++)
        {
            s.insert(num[i]);
        }
        for (int i = 0 ; i < c1.numLen ; i++)
        {
            if (s.count(c1.num[i]) == 1)
            {
                for (it = s.begin() ; it != s.end() ; it++)
                {
                    if (*it == c1.num[i])
                    {
                        s.erase(it);
                        break;
                    }
                }    
            }
        }
        int len = s.size();
        CSet t(len);
        int j = 0;
        for (it = s.begin() ; it != s.end() ; it++)
        {
            t.num[j] = *it;
            j++;
        }
        return t;
    }
    CSet operator* (const CSet& c1)
    {
        set<int> s;
        vector<int> v;
        vector<int>::iterator it;
        for (int i = 0 ; i < numLen ; i++)
        {
            s.insert(num[i]);
        }
        for (int i = 0 ; i < c1.numLen ; i++)
        {
            if (s.count(c1.num[i]) == 1)
            {
                v.push_back(c1.num[i]);
            }
        }
        int len = v.size();
        CSet t(len);
        int j = 0;
        for (it = v.begin() ; it != v.end() ; it++)
        {
            t.num[j] = *it;
            j++;
        }
        return t;
    }
    ~CSet()
    {
        delete[] num;
        cout << "delete over." << endl;
    }
};
int main()
{
    int len1 , len2;
    cout << "Please input two number :";
    cin >> len1 >> len2;

    CSet c1(len1);
    c1.input();
    CSet c2(len2);
    c2.input();

    CSet c3 = c1+c2;
    cout << "c1 + c2: "; 
    c3.show();
    
    CSet c4 = c1-c2;
    cout << "c1 - c2: "; 
    c4.show();

    CSet c5 = c1*c2;
    cout << "c1 * c2: "; 
    c5.show();

    system("pause");
    return 0;
}