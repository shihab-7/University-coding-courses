#include <bits/stdc++.h>
using namespace std;
void Inputdata(vector<string>&pid,vector<int>&at, vector<int>&bt)
{
    cout << "PID\t | " << "AT\t | " << "BT |" << endl;
    cout<<"_______________________"<<endl;
    for (int i = 0; i < pid.size(); i++)
    {
        cout << pid[i] << "\t | " << at[i] << "\t | " << bt[i]<<"  |" << endl;
    }
}
void ATsort(vector<string>&pid,vector<int>&at, vector<int>&bt)
{
    for (int i = 0; i < pid.size(); i++)
    {
        for (int j = 0; j < pid.size(); j++)
        {
            if (at[i] < at[j])
            {
                swap(pid[i], pid[j]);
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
            }
        }
    }
}
void GanttChart(vector<string>&pid,vector<int>&bt)
{
    for(int i=0;i<pid.size();i++)
    {
        cout<<"| "<<pid[i]<<" ";
    }
    cout<<"|"<<endl;
    int Time = 0;
    cout<<Time;
    for(int i=0;i<pid.size();i++)
    {
        Time+=bt[i];
        cout<<"    "<<Time;
    }
    cout<<endl;
}
void FCFS(vector<string>&pid,vector<int>&at,vector<int>&bt,vector<int>&ct,vector<int>&tat,vector<int>&wt,vector<int>&rt)
{
    // rt= start time-at , tat=ct-at, wt=tat-bt
     int tmp_ct = 0;
    for (int i = 0; i < pid.size(); i++) {
        if (at[i] > tmp_ct) {
            tmp_ct = at[i];
        }
        rt[i] = tmp_ct - at[i];
        tmp_ct += bt[i];
        ct[i] = tmp_ct;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    } 
    cout << "PID\t" << " | AT\t" << " | BT\t" << " | CT\t" << " | TAT\t" << " | WT\t" << " | RT|" << endl;
    cout<<"______________________________________________________"<<endl;
    for (int i = 0; i < pid.size(); i++)
    {
        cout << pid[i] << "\t | " << at[i] << "\t | " << bt[i] << "\t | " << ct[i]
        << "\t | " << tat[i] << "\t | " << wt[i] << "\t | " << rt[i]<< " |" << endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of processes to run : ";
    cin >> n;
    cout<<endl<<"Enter "<<n<<" times  ProcessID  AT  BT : "<<endl;
    vector<string> processID(n);
    vector<int>AT(n),BT(n);
    for(int i=0; i<n; i++)
    {
        cin >> processID[i]>>AT[i]>>BT[i];
    }
    cout<<endl;
    cout<<"Input View : "<<endl;
    Inputdata(processID,AT,BT);
    ATsort(processID,AT,BT);
    cout<<endl<<"Gantt Chart : "<<endl;
    GanttChart(processID,BT);
    vector<int>CT(n),TAT(n),WT(n),RT(n);
    cout<<endl<<"FCFS Table : "<<endl;
    FCFS(processID,AT,BT,CT,TAT,WT,RT);
    return 0;
}