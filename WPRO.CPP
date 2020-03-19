//compiled in turbo!
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>
#include<stdio.h>
#include<iomanip.h>
#include<fstream.h>


void main()
{
int rsummin=0,ssummin=0,usummin=0,rdevsummin=0,sdevsummin=0,udevsummin=0;
float rsumsec=0,ssumsec=0,usumsec=0,rdevsumsec=0,sdevsumsec=0,udevsumsec=0;
int rcount=0,scount=0,ucount=0;
clrscr();
char word[50],string[50],stringreal[100][50],stringuser[100][50],stringsys[100][50];
ifstream fin("timestat.txt",ios::in);

       int i=0,j=0,k=0;
	for(i,j,k; ; )
       {
	     fin>>word;
       if (i==100&&k==100&&j==100) break;
		if (strcmp(word,"real")==0)
		{
	      fin>>stringreal[i];

	      i++;
		}
	 else
	if (strcmp(word,"user")==0)
		{
		      fin>>stringuser[j];

		      j++;

		}
	else
	if (strcmp(word,"sys")==0)
		{
			fin>>stringsys[k];

			k++;
		}
	}
	fin.close();
for(int l=0;l<100;l++)

{

	int rmin[100],umin[100],smin[100];
	float rsec[100],ssec[100],usec[100];
	char rch[10],uch[10],sch[10];
	rch[0]=stringreal[l][0];
	sch[0]=stringsys[l][0];
	uch[0]=stringuser[l][0];
	rmin[l]=atoi(rch);
	umin[l]=atoi(uch);
	smin[l]=atoi(sch);
	rsummin=rsummin+rmin[l];
	ssummin=ssummin+smin[l];
	usummin=usummin+umin[l];

	char rsecs[100][6],ssecs[100][6],usecs[100][6];
	rsecs[l][5]='\0';
	ssecs[l][5]='\0';
	usecs[l][5]='\0';

	for(int z=0;z<5;z++)
	{
		rsecs[l][z]=stringreal[l][z+2];
		usecs[l][z]=stringuser[l][z+2];
		ssecs[l][z]=stringsys[l][z+2];
	}
	rsec[l]=atof(rsecs[l]);
	ssec[l]=atof(ssecs[l]);
	usec[l]=atof(usecs[l]);

	rsumsec=rsumsec+rsec[l];
	ssumsec=ssumsec+ssec[l];
	usumsec=usumsec+usec[l];

}

for(int l1=0;l1<100;l1++)
	{
	int rmin[100],umin[100],smin[100];
	float rsec[100],ssec[100],usec[100];
	char rch[10],uch[10],sch[10];
	rch[0]=stringreal[l1][0];
	sch[0]=stringsys[l1][0];
	uch[0]=stringuser[l1][0];
	rmin[l1]=atoi(rch);
	umin[l1]=atoi(uch);
	smin[l1]=atoi(sch);
	rdevsummin=rdevsummin+pow((rmin[l1]-(rsummin/100)),2);
	udevsummin=udevsummin+pow((umin[l1]-(usummin/100)),2);
	sdevsummin=sdevsummin+pow((smin[l1]-(ssummin/100)),2);
	char rsecs[100][6],ssecs[100][6],usecs[100][6];
	rsecs[l1][5]='\0';
	ssecs[l1][5]='\0';
	usecs[l1][5]='\0';

	for(int z=0;z<5;z++)
	{
		rsecs[l1][z]=stringreal[l1][z+2];
		usecs[l1][z]=stringuser[l1][z+2];
		ssecs[l1][z]=stringsys[l1][z+2];
	}
	rsec[l1]=atof(rsecs[l1]);
	rdevsumsec=rdevsumsec+pow((rsec[l1]-(rsumsec/100)),2);
	ssec[l1]=atof(ssecs[l1]);
	sdevsumsec=sdevsumsec+pow((ssec[l1]-(ssumsec/100)),2);
	usec[l1]=atof(usecs[l1]);
	udevsumsec=udevsumsec+pow((usec[l1]-(usumsec/100)),2);
	}
for(int l2=0;l2<100;l2++)
	{
	int rmin[100],umin[100],smin[100];
	float rsec[100],ssec[100],usec[100];
	char rch[10],uch[10],sch[10];
	rch[0]=stringreal[l2][0];
	sch[0]=stringsys[l2][0];
	uch[0]=stringuser[l2][0];
	rmin[l2]=atoi(rch);
	umin[l2]=atoi(uch);
	smin[l2]=atoi(sch);

	char rsecs[100][6],ssecs[100][6],usecs[100][6];
	rsecs[l2][5]='\0';
	ssecs[l2][5]='\0';
	usecs[l2][5]='\0';

	for(int z=0;z<5;z++)
	{
		rsecs[l2][z]=stringreal[l2][z+2];
		usecs[l2][z]=stringuser[l2][z+2];
		ssecs[l2][z]=stringsys[l2][z+2];
	}
	rsec[l2]=atof(rsecs[l2]);
	ssec[l2]=atof(ssecs[l2]);
	usec[l2]=atof(usecs[l2]);
	float ruplimit,rlolimit;
	ruplimit=rsummin/100*60+rsumsec/100+sqrt(rdevsummin/100)*60+sqrt(rdevsumsec/100);
	rlolimit=rsummin/100*60+rsumsec/100-sqrt(rdevsummin/100)*60-sqrt(rdevsumsec/100);
	if(rmin[l2]*60+rsec[l2]>rlolimit &&rmin[l2]*60+rsec[l2]<ruplimit)
	rcount++;

	float uuplimit,ulolimit;
	uuplimit=usummin/100*60+usumsec/100+sqrt(udevsummin/100)*60+sqrt(udevsumsec/100);
	ulolimit=usummin/100*60+usumsec/100-sqrt(udevsummin/100)*60-sqrt(udevsumsec/100);
	if(umin[l2]*60+usec[l2]>ulolimit &&umin[l2]*60+usec[l2]<uuplimit)
	ucount++;

	float suplimit,slolimit;
	suplimit=ssummin/100*60+ssumsec/100+sqrt(sdevsummin/100)*60+sqrt(sdevsumsec/100);

	slolimit=ssummin/100*60+ssumsec/100-sqrt(sdevsummin/100)*60-sqrt(sdevsumsec/100);
	if(smin[l2]*60+ssec[l2]>slolimit &&smin[l2]*60+ssec[l2]<suplimit)
	scount++;

}
clrscr();
cout<<"Number of runs : 100";
cout<<"\nAverage Time statistics";
cout<<"\nreal "<<rsummin/100<<"m"<<rsumsec/100<<"s";
cout<<" user "<<usummin/100<<"m"<<usumsec/100<<"s";
cout<<" sys "<<ssummin/100<<"m"<<ssumsec/100<<"s";
cout<<"\nStandard deviation of Time statistics";
cout<<"\nreal "<<sqrt(rdevsummin/100)<<"m"<<sqrt(rdevsumsec/100)<<"s";
cout<<" user "<<sqrt(udevsummin/100)<<"m"<<sqrt(udevsumsec/100)<<"s";
cout<<" sys "<<sqrt(sdevsummin/100)<<"m"<<sqrt(sdevsumsec/100)<<"s";
cout<<"\nNumber of runs within average - standard deviation to average + standard devation\n";
cout<<"real "<<rcount<<" user "<<ucount<<" sys "<<scount;

getch();

}

