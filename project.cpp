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

		
				//*******  WAITING TIME CALCULATION     ******
		
		p[0].waiting_time=p[0].tat-p[0].Brust_time;
		p[1].waiting_time=p[1].tat-p[1].Brust_time;
		p[2].waiting_time=p[2].tat-p[2].Brust_time;
		p[3].waiting_time=p[3].tat-p[3].Brust_time;
		
		//*******  PRIORITY  CALCULATION      *******
		
		p[0].priority=1+(p[0].waiting_time/p[0].Brust_time);
		p[1].priority=1+(p[1].waiting_time/p[1].Brust_time);
		p[2].priority=1+(p[2].waiting_time/p[2].Brust_time);
		p[3].priority=1+(p[3].waiting_time/p[3].Brust_time);
		
			}
	void  Process:: output(Process p[])
	{
			cout<<"\n\n\n     =======================================================================================================================\n";
		cout<<"     ||----------------------------------->>>>>   OPERATING SYSTEM PROJECT    <<<<<---------------------------------------||\n";
		cout<<"     =======================================================================================================================\n";
		cout<<"     ||  PROCESS ||  ARRIVAL TIME  || BRUST TIME ||  COMPLETION TIME  ||  PRIORITY  || TURNAROUND TIME  ||  WAITING TIME  ||\n ";
		cout<<"     ======================================================================================================================\n";
		cout<<"     ||   P"<<0<<"     ||       "<<p[0].arraival_time<<"        ||     "<<p[0].Brust_time<<"     ||      "<<p[0].completion_time<<"           ||       "<<p[0].priority<<"    ||     "<<p[0].tat<<"           ||       "<<p[0].waiting_time<<"        ||\n"; 
		cout<<"     =======================================================================================================================\n";
		cout<<"     ||   P"<<1<<"     ||       "<<p[1].arraival_time<<"        ||     "<<p[1].Brust_time<<"     ||      "<<p[1].completion_time<<"           ||       "<<p[1].priority<<"    ||     "<<p[1].tat<<"           ||       "<<p[1].waiting_time<<"       ||\n"; 
		cout<<"     =======================================================================================================================\n";
		cout<<"     ||   P"<<2<<"     ||       "<<p[2].arraival_time<<"       ||     "<<p[2].Brust_time<<"     ||      "<<p[2].completion_time<<"           ||       "<<p[2].priority<<"    ||     "<<p[2].tat<<"           ||       "<<p[2].waiting_time<<"       ||\n"; 
		cout<<"     =======================================================================================================================\n";
		cout<<"     ||   P"<<3<<"     ||       "<<p[3].arraival_time<<"       ||     "<<p[3].Brust_time<<"     ||      "<<p[3].completion_time<<"          ||       "<<p[3].priority<<"    ||     "<<p[3].tat<<"          ||       "<<p[3].waiting_time<<"       ||\n"; 
		cout<<"     =======================================================================================================================\n";
		cout<<"     ||                                                                                   Avg.TAT=="<<p[0].tat+p[1].tat+p[2].tat+p[3].tat<<"      A.W.T =="<<p[0].waiting_time+p[1].waiting_time+p[2].waiting_time+p[3].waiting_time<<"   ||\n";
		cout<<"     =======================================================================================================================\n\n";
	}
void Process::p_time(Process p[])
{
	time=0;
		p[0].completion_time=p[0].Brust_time;
		time=p[0].completion_time;
	for(int i=5;i>=0;i--)
	{
		for(int j=1;j<4;j++)
		{
			if(p[j].priority==i)
			{
					p[j].completion_time=time+p[j].Brust_time;
					time+=p[j].Brust_time;
			}
		}
	}

			//*******  TURNAROUND TIME CALCULATION ******
		
		p[0].tat=p[0].completion_time-p[0].arraival_time;
		p[1].tat=p[1].completion_time-p[1].arraival_time;
		p[2].tat=p[2].completion_time-p[2].arraival_time;
		p[3].tat=p[3].completion_time-p[3].arraival_time;
		
		
		//*******  WAITING TIME CALCULATION     ******
		
		p[0].waiting_time=p[0].tat-p[0].Brust_time;
		p[1].waiting_time=p[1].tat-p[1].Brust_time;
		p[2].waiting_time=p[2].tat-p[2].Brust_time;
		p[3].waiting_time=p[3].tat-p[3].Brust_time;
		
		
		//******  OUTPUT ******
		cout<<"\n\n     =======================================================================================================================\n";
		cout<<"     ||--------------------------------->>>>>>>>>  WHEN PRIORITY COMES IN TO THE PICTURE  <-------------------------------||\n";
		cout<<"     =======================================================================================================================\n\n";
		output(p);
		
}

int Process::time=0;
int main()
{
	int i;
	Process p[4];
	Process::c_time(p);
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0:
				p[i].input(0,20);
				break;
			case 1:
				p[i].input(5,36);
				break;
			case 2:
				p[i].input(13,19);
				break;
			case 3:
				p[i].input(17,42);
				break;
			default :
				break;
		}
	}
	Process::c_time(p);
	Process::output(p);
	getch();
	Process::p_time(p);
	getch();
}
