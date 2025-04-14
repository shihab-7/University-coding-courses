#include <bits/stdc++.h>
using namespace std;
struct Data{
    string pid;
    int at,bt,priority,wt,tat,ct,rt;
};
void InputView(Data a[],int n)
{
    cout<<"\nInputView : "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"| PID | AT | Priority | BT |\n";
    cout<<"----------------------------\n";
    for(int i=0;i<n;i++)
    {
        cout<<"| "<<a[i].pid<<"  | "<<a[i].at<<"  |   "<<a[i].priority<<"      | "<<a[i].bt<<"  |"<<endl;
    }
    cout<<"----------------------------\n";
}
bool compare(Data a,Data b)
{
    if(a.priority==b.priority)
        return a.at < b.at;
    return a.priority < b.priority;
}
bool cmp(Data a,Data b)
{
    return a.at < b.at;
}
void Calculate(Data a[],int n)
{
    sort(a,a+n,cmp);

    int time=0;
    a[0].ct = a[0].at + a[0].bt;
    a[0].tat = a[0].ct - a[0].at;
    a[0].wt = a[0].tat - a[0].bt;
    a[0].rt = a[0].wt;
    time = a[0].ct;

    sort(a+1,a+n,compare);

    for(int i=1;i<n;i++)
    {
        int start_time = max(time,a[i].at);
        a[i].ct = start_time + a[i].bt;
        a[i].tat = a[i].ct - a[i].at;
        a[i].wt = a[i].tat - a[i].bt;
        a[i].rt = start_time - a[i].at;
        time = a[i].ct;
    }
}
void GanttChart(Data a[],int n)
{
    cout<<"\nGantt Chart : \n\n";
    for(int i=0;i<n;i++)
    {
        cout<<"| "<<a[i].pid;
    }
    cout<<"|\n";
    int t = 0;
    for(int i=0;i<n;i++)
    {
        cout<<t<<"  ";
        t = a[i].ct;
    }
    cout<<t<<endl;
}
void TablePrint(Data a[],int n)
{
    cout<<"\n Priority Scheduling (Non-Preemptive) Table view : \n";
    cout<<"-------------------------------------------------------------------"<<endl;
    cout << "| PID\t" <<"| AT "<<" | BT\t" << " | CT\t" << " | TAT\t" << " | WT\t" << " | RT\t| "<<"Priority|" << endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    int tmp=0;
    for (int i = 0; i < n; i++)
    {
        cout<<"| " << a[i].pid<<"    | " <<a[i].at<< "   | "<< a[i].bt << "\t | " << a[i].ct
        << "\t | " << a[i].tat << "\t | " << a[i].wt << "\t | " << a[i].rt<< "    | " <<a[i].priority<<" \t  |"<< endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        tmp+=a[i].wt;
    }
    cout<<fixed<<setprecision(2)<<"Average waiting time : "<<(float)tmp/n<<" ms"<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of process : ";
    cin >> n;
    Data process[n];
    cout<<"\nEnter process id(string) , arrival time, priority and burst time : \n";
    for(int i=0;i<n;i++)
    {
        cin>>process[i].pid>>process[i].at>>process[i].priority>>process[i].bt;
    }
    InputView(process,n);
    Calculate(process,n);
    GanttChart(process,n);
    TablePrint(process,n);
    return 0;
}