#include <iostream>
using namespace std;
#define WAIT      0
#define RUN       1
#define FINISH    2
struct PCB
{
    int processId;         //����ID
    int startTime;         //���̵���ʱ��
    int endTime;           //���̽���ʱ��
    int remainTime;        //����ʣ��ʱ��
    int processStatus;     //����״̬
    struct PCB* next;      //ָ����һ������
    PCB() : next(NULL) {}
};

class OperatorSystem
{
private:
    int timeSlice;         //ʱ��Ƭ
    PCB* head;      //�������ͷָ��

public:
    OperatorSystem() : head(new PCB) , timeSlice(0)
    {
        int jobNum;
        PCB* currentPcb = head;
        cout << "************************�������׼����ʼ��**********************" << endl;
        cout << "������Ҫ���еĽ�������";
        cin >> jobNum;
        cout << "������ʱ��Ƭ��С��";
        cin >> this->timeSlice;
        for (int i = 1 ; i <= jobNum ; i++)
        {
            PCB* newPcb = new PCB;
            cout << "��" << i << "������׼����ʼ��..." << endl;
            cout << "��������̵���ʱ�䣺";
            cin >> newPcb->startTime;
            cout << "��������̽���ʱ�䣺";
            cin >> newPcb->endTime;
            newPcb->remainTime = newPcb->endTime - newPcb->startTime;
            newPcb->processId = i;
            newPcb->processStatus = WAIT;
            newPcb->next = NULL;
            currentPcb->next = newPcb;
            currentPcb = newPcb;
        }
        cout << "************************������̳�ʼ�����**********************" << endl;
    }
    ~OperatorSystem()
    {
        PCB* currentPcb = head->next;
        while(head)
        {
            delete head;
            head = currentPcb;
            if (currentPcb)
                currentPcb = currentPcb->next;
        }
    }

    void showProcessStatus()
    {
        cout << "************************��������**********************" << endl;
        PCB* currentPcb = head->next;
        while(currentPcb)
        {
            cout << "��ǰ����IDΪ��" << currentPcb->processId;
            cout << " ��ǰ����״̬��";
            switch (currentPcb->processStatus)
            {
            case WAIT:
                cout << "����";
                break;
            case RUN:
                cout << "����";
                break;
            case FINISH:
                cout << "����";
                break;
            }
            cout << " ʣ��ʱ��Ϊ��" << currentPcb->remainTime;
            cout << endl;
            currentPcb = currentPcb->next;
        }
    }

    void runProcess()
    {
        while(true)
        {
            PCB* currentPcb = head->next;
            if (!currentPcb)
            {
                cout << "************************�������**********************" << endl;
                return;
            }
            while(currentPcb)
            {
                currentPcb->remainTime -= this->timeSlice;
                if (currentPcb->remainTime <= 0)
                    currentPcb->processStatus = FINISH;
                else
                    currentPcb->processStatus = RUN;
                this->showProcessStatus();
                if (currentPcb->processStatus == FINISH)
                {
                    PCB* pcb = currentPcb;
                    currentPcb = currentPcb->next;
                    deletePcb(pcb);
                }
                else
                {
                    currentPcb->processStatus = WAIT;
                    currentPcb = currentPcb->next;
                }
            }
        }
    }

    void deletePcb(PCB* deletePcb)
    {
        PCB* prePcb = head;
        PCB* currentPcb = head->next;
        while(currentPcb)
        {
            if (currentPcb == deletePcb);
            {
                prePcb->next = currentPcb->next;
                break;
            }
            prePcb = currentPcb;
            currentPcb = currentPcb->next;
        }
    }

};

int main()
{
    OperatorSystem op;
    op.runProcess();
    system("pause");
    return 0;
}