#include <iostream>
using namespace std;
#define WAIT      0
#define RUN       1
#define FINISH    2
struct PCB
{
    int processId;         //进程ID
    int startTime;         //进程到达时间
    int endTime;           //进程结束时间
    int remainTime;        //进程剩余时间
    int processStatus;     //进程状态
    struct PCB* next;      //指向下一个任务
    PCB() : next(NULL) {}
};

class OperatorSystem
{
private:
    int timeSlice;         //时间片
    PCB* head;      //任务队列头指针

public:
    OperatorSystem() : head(new PCB) , timeSlice(0)
    {
        int jobNum;
        PCB* currentPcb = head;
        cout << "************************任务进程准备初始化**********************" << endl;
        cout << "请输入要运行的进程数：";
        cin >> jobNum;
        cout << "请输入时间片大小：";
        cin >> this->timeSlice;
        for (int i = 1 ; i <= jobNum ; i++)
        {
            PCB* newPcb = new PCB;
            cout << "第" << i << "个进程准备初始化..." << endl;
            cout << "请输入进程到达时间：";
            cin >> newPcb->startTime;
            cout << "请输入进程结束时间：";
            cin >> newPcb->endTime;
            newPcb->remainTime = newPcb->endTime - newPcb->startTime;
            newPcb->processId = i;
            newPcb->processStatus = WAIT;
            newPcb->next = NULL;
            currentPcb->next = newPcb;
            currentPcb = newPcb;
        }
        cout << "************************任务进程初始化完毕**********************" << endl;
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
        cout << "************************进程运行**********************" << endl;
        PCB* currentPcb = head->next;
        while(currentPcb)
        {
            cout << "当前进程ID为：" << currentPcb->processId;
            cout << " 当前进程状态：";
            switch (currentPcb->processStatus)
            {
            case WAIT:
                cout << "就绪";
                break;
            case RUN:
                cout << "运行";
                break;
            case FINISH:
                cout << "结束";
                break;
            }
            cout << " 剩余时间为：" << currentPcb->remainTime;
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
                cout << "************************运行完毕**********************" << endl;
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