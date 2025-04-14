#include <bits/stdc++.h>
using namespace std;
struct Data{
    string pid;
    int at,bt,ct,tat,wt,rt,remaining;
};
struct GanttData{
    string pid;
    int start,end;
};
void calculate(Data a[],int n,int tq, vector<GanttData>&gantt)
{
    int time=0,complete=0, index=0;
    bool firstresponse[100]={false};
    queue<int>q;

    while(complete < n)
    {
        while(index < n && a[index].at <= time)
        {
            q.push(index);
            index++;
        }
        if(q.empty())
        {
            time++;
            continue;
        }
        int i = q.front();
        q.pop();
        if(!firstresponse[i])
        {
            a[i].rt = time - a[i].at;
            firstresponse[i]=true;
        }
        int execTime = min(tq,a[i].remaining);
        gantt.push_back({a[i].pid,time,time+execTime});
        time+=execTime;
        a[i].remaining-=execTime;
        while(index < n && a[index].at<=time)
        {
            q.push(index);
            index++;
        }
        if(a[i].remaining > 0)
        {
            q.push(i);
        }
        else
        {
            a[i].ct = time;
            a[i].tat = a[i].ct - a[i].at;
            a[i].wt = a[i].tat - a[i].bt;
            complete++;
        }
    }
}
void TablePrint(Data a[], int n) {
    cout << "\n Round Robin Scheduling Table View : \n";
    cout << "--------------------------------------------------------" << endl;
    cout << "| PID\t" << "| AT " << " | BT\t" << " | CT\t" << " | TAT\t" << " | WT\t" << " | RT\t| " << endl;
    cout << "--------------------------------------------------------" << endl;
    float total_wt = 0;
    for (int i = 0; i < n; i++) {
        cout << "| " << a[i].pid << "    | " << a[i].at << "   | " << a[i].bt << "\t | " << a[i].ct
             << "\t | " << a[i].tat << "\t | " << a[i].wt << "\t | " << a[i].rt << "   | " << endl;
        cout << "--------------------------------------------------------" << endl;
        total_wt += a[i].wt;
    }
    cout << fixed << setprecision(2) << "Average waiting time : " << (float)total_wt / n << " ms" << endl;
}
void GanttChart(const vector<GanttData> &gantt) {
    cout << "\nGantt Chart : \n";
    for (const auto &block : gantt) {
        cout << "| " << block.pid << " ";
    }
    cout << "|\n";
    for (const auto &block : gantt) {
        cout << block.start << "   ";
    }
    cout << gantt.back().end << endl;
}

int main()
{
    int n;
    cout<<"Enter the number of processes : ";
    cin>>n;
    int tq;
    cout<<"\nEnter time quantum : ";
    cin>>tq;
    Data process[n];
    vector<GanttData> gantt;
    cout<<"\nEnter process id(string), arrival time and burst time : \n";
    for(int i=0;i<n;i++)
    {
        cin>>process[i].pid>>process[i].at>>process[i].bt;
        process[i].remaining = process[i].bt;
    }
    calculate(process,n,tq,gantt);
    TablePrint(process,n);
    GanttChart(gantt);
    return 0;
}
