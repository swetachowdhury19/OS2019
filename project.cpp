#include<iostream>
using namespace std;
#include<conio.h>



class Process{
	int arraival_time,Brust_time;
	int completion_time,tat;
	int waiting_time;
	int priority;
	
	public:
		static int time;
	void input(int,int);
	void static c_time(Process []);
	void  static output(Process []);
	void static p_time(Process []);
			 
};
void Process:: input(int arraival_time,int Brust_time)
	{
		this->Brust_time=Brust_time;
		this->arraival_time=arraival_time;
	}
	void Process:: c_time(Process p[])
	{
		
		//*******  COMPLETION TIME CALCULATION ******
		p[0].completion_time=p[0].Brust_time;
		p[1].completion_time=p[0].completion_time+p[1].Brust_time;
		p[2].completion_time=p[1].completion_time+p[2].Brust_time;
		p[3].completion_time=p[2].completion_time+p[3].Brust_time;
		
		//*******  TURNAROUND TIME CALCULATION ******
		
		p[0].tat=p[0].completion_time-p[0].arraival_time;
		p[1].tat=p[1].completion_time-p[1].arraival_time;
		p[2].tat=p[2].completion_time-p[2].arraival_time;
		p[3].tat=p[3].completion_time-p[3].arraival_time;
