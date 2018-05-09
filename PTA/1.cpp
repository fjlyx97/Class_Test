#include <iostream>
using namespace std;
typedef struct
{
    int radio;
    int index;
}mul;
mul m1[10001];
mul m2[10001];
mul m3[10001];
int main()
{
    int n , m;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> m1[i].radio >> m1[i].index;  
    }
    cin >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> m2[i].radio >> m2[i].index;
    }
    int i = 1 , j = 1;
    int k = 0;
    if (m1[1].index >= m2[1].index)
    {
        for (i = 1 ; i <= n ; i++)
        {
            for (j = 1 ; j <= m ; j++)
            {
                int flag = 1;
                for (int l = 1 ; l <= k ; l++)
                {
                    if (m1[i].index+m2[j].index == m3[l].index)
                    {
                        flag = 0;
                        m3[l].radio += m1[i].radio*m2[j].radio;
                        break;
                    }
                }
                if (flag)
                {
                    k++;
                    m3[k].radio = m1[i].radio*m2[j].radio; 
                    m3[k].index = m1[i].index+m2[j].index;
                }
            }
        }
    }
    else
    {
        for (j = 1 ; j <= m ; j++)
        {
            for (i = 1 ; i <= n ; i++)
            {
                int flag = 1;
                for (int l = 1 ; l <= k ; l++)
                {
                    if (m1[i].index+m2[j].index == m3[l].index)
                    {
                        flag = 0;
                        m3[l].radio += m1[i].radio*m2[j].radio;
                        break;
                    }
                }
                if (flag)
                {
                    k++;
                    m3[k].radio = m1[i].radio*m2[j].radio; 
                    m3[k].index = m1[i].index+m2[j].index;
                }
            }
        }
    }
    for (int l = 1 ; l < k ; l++)
    {
        if (m3[l].radio == 0)
        {
            cout << 0 << " " << 0 << " ";
            continue;
        }
        cout << m3[l].radio << " " << m3[l].index << " ";
    }
    if (m3[k].radio == 0)
    {
        cout << 0 << " " << 0 << endl;
    }
    else
    {
        cout << m3[k].radio << " " << m3[k].index << endl;
    }
    i = 1;
    j = 1;
    k = 1;

    while ( i <= n && j <= m)
    {
        if (m1[i].index == m2[j].index)
        {
            m3[k].radio = m1[i].radio+m2[j].radio;
            m3[k].index = m1[i].index;
            i++;
            j++;
            k++;
        }
        else if (m1[i].index > m2[j].index)
        {
            m3[k].radio = m1[i].radio;
            m3[k].index = m1[i].index;
            i++;
            k++;
        }
        else
        {
            m3[k].radio = m2[j].radio;
            m3[k].index = m2[j].index;
            j++;
            k++;
        }
    }
    while (i <= n)
    {
        m3[k].index = m1[i].index;
        m3[k].radio = m1[i].radio;
        i++;
        k++;
    }
    while (j <= m)
    {
        m3[k].index = m2[j].index;
        m3[k].radio = m2[j].radio;
        j++;
        k++;
    }
    k--;
    for (int l = 1 ; l < k ; l++)
    {
        if (m3[l].radio == 0)
        {
            cout << 0 << " " << 0 << " ";
            continue;
        }
        cout << m3[l].radio << " " << m3[l].index << " ";
    }
    if (m3[k].radio == 0)
    {
        cout << 0 << " " << 0;
    }
    else
        cout << m3[k].radio << " " << m3[k].index;
    system("pause");
    return 0;
}