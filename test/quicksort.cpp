#include <iostream>
#include <ctime>
using namespace std;
#define LISTMAXSIZE 10
typedef int ElemType;

struct Sqlist
{
    ElemType* elem;
    int listSize;
    int listLength;

    Sqlist() 
    {
        this->elem = new ElemType[LISTMAXSIZE];
        this->listSize = LISTMAXSIZE;
        this->listLength = 0;
    }

    ~Sqlist()
    {
        delete[] this->elem;
    }

    void ShowList()
    {
        for (int i = 0 ; i < this->listLength ; i++)
        {
            cout << this->elem[i] << " ";
        }
        cout << endl;
    }

    void InsertNum(ElemType num)
    {
        this->elem[this->listLength++] = num;
    }

    void QuickSort(int left , int right)
    {
        if (left > right)
            return;
        int an = this->elem[left];
        int i = left;
        int j = right;
        while (i != j)
        {
            while(this->elem[j] >= an && i < j)
                j--;
            while(this->elem[i] <= an && i < j)
                i++;
            swap(this->elem[i],this->elem[j]);
        }
        swap(this->elem[i],this->elem[left]);
        QuickSort(left,i-1);
        QuickSort(i+1,right);
    }
};

int main()
{
    srand(time(0));
    Sqlist* root = new Sqlist;
    for (int i = 0 ; i < 10 ; i++)
    {
        root->InsertNum(rand() % 1000);
    }
    root->ShowList();
    root->QuickSort(0,root->listLength-1);
    root->ShowList();

    delete root;
    system("pause");
    return 0;
}