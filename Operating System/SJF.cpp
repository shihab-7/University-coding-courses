#include <bits/stdc++.h>
using namespace std;

struct processes{
    int pid;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};
void display_input(processes p[],int n)
{

    cout<<"\nInput View :"<<"\n--------------\n"<<"| PID\t| BT |\n";
    cout<<"--------------\n";
    for(int i=0;i<n;i++)
    {
        cout<<"| p"<<p[i].pid<<"\t| "<<p[i].bt<<"  |\n";
        cout<<"--------------\n";
    }
}
void GanttChart(processes p[],int n)
{
    cout<<"\nGantt Chart View :\n\n"<<"|";
    for(int i=0;i<n;i++)
    {
        cout<<"p"<<p[i].pid<<"\t|";
    }
    cout<<"\n0";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<p[i].ct;
    }
    cout<<endl;
}
bool compare(processes a,processes b)
{
    return a.bt < b.bt;
}
void calculate(processes p[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        p[i].rt = sum;
        sum += p[i].bt;
        p[i].ct = sum;
        p[i].tat = p[i].ct;
        p[i].wt = p[i].tat-p[i].bt;
    }
}
void SJF_table(processes p[],int n)
{
    cout<<"\n SJF (shortest job first) Table view : \n";
    cout<<"----------------------------------------------"<<endl;
    cout << "| PID\t" <<" | BT\t" << " | CT\t" << " | TAT\t" << " | WT\t" << " | RT|" << endl;
    cout<<"----------------------------------------------"<<endl;
    int tmp=0;
    for (int i = 0; i < n; i++)
    {
        cout<<"| p" << p[i].pid<<"    " << " | "<< p[i].bt << "\t | " << p[i].ct
        << "\t | " << p[i].tat << "\t | " << p[i].wt << "\t | " << p[i].rt<< " |" << endl;
        cout<<"----------------------------------------------"<<endl;
        tmp+=p[i].wt;
    }
    cout<<fixed<<setprecision(2)<<"Average waiting time : "<<(float)tmp/n<<" ms"<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of processes to run : ";
    cin >> n;
    processes data[n];
    cout<<endl<<"Enter Burst Time of each process : ";
    for(int i=0; i<n; i++)
    {
        data[i].pid = i+1;
        cin >> data[i].bt;
    }
    display_input(data,n);
    sort(data,data+n,compare);
    calculate(data,n);
    GanttChart(data,n);
    SJF_table(data,n);
    return 0;
}
