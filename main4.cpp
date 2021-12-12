#include<stdio.h>
#include<iostream>
using namespace std;
///////DYNAMIC PROGRAMMING has been used over Brute force becuause it has improvments regarding speed when the number of nodes get higher
//////The algorithm written below deals with symmetric pathes means the path has same value in either directions
/////The costs of the matrix must be increasing as the number of nodes gets higher since the other nodes are more farther

int completed[5],cost=0;





int ary[10][10] = {                
                    {0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0},
                   
};

//int (*ptr)[10][10] = &ary;		
//ptr = &ary;

int (*ptr)[10][10] = &ary;
 
 
int n = 4;


void deleteInput()

{
int x;
int i,j;


cout<<"\nEnter the number of node you want to delete\n";
for(i=0;i < n;i++)
{
printf("\n\nNode number %d\n ",i+1);
}
cin>>x;	


for(i=0;i < n;i++)
{

for(j=0;j < n;j++)
{
	
	if((i == (x-1))|(j==(x-1)))
	{
	//CRASHES WHEN USING DELETE
	
	//delete[]  ptr[i][j];
	//	try {
	//	  delete[] ptr[i][j];
	//	} catch(exception& e) { 
	//	  cout << "delete failed" << endl;
	//	}
	
	/////ASSIGN DELETED NODE TO -1 in COST ARRAY
	completed[j]=0;
	ary[i][j] = -1;
	
	}
	else
	continue;
	
	
	}
}

	
//n = n-1;
cout<<"\n\nThe cost list is:";
 
for(i=0;i < n;i++)
{
cout<<"\n";
 
for(j=0;j < n;j++)
cout<<"\t"<<ary[i][j];
}

}


void takeInput()
{

int i,j;
n = n+1;

cout<<"\nEnter the Cost Matrix\n";

cout<<"\nEnter Elements of Row: "<<n<<"\n";
 
for( j=0;j < n-1;j++){

cin>>ary[n-1][j];
 
completed[j]=0;
}
cout<<"\nEnter Elements of Column: "<<n<<"\n";
for( j=0;j < n-1;j++)
cin>>ary[j][n-1];




cout<<"\n\nThe cost list is:";
 
for(i=0;i < n;i++)
{
cout<<"\n";
 
for(j=0;j < n;j++)
cout<<"\t"<<ary[i][j];
}

}


int minpath(int c,int n)
{
int i,cc=999;
int min=999,kmin;
 
for(i=0;i < n;i++)
{
	
if(ary[c][i]==-1)continue;
if((ary[c][i]!=0)&&(completed[i]==0))
if(ary[c][i]+ary[i][0] < min)
{

min=ary[c][i]+ary[i][0];
kmin=ary[c][i];
cc=i;
}
}
 

 
if(min!=999)
cost+=kmin;
 
return cc;
}



void mincost(int city,int n)
{
int i,ncity;
 
completed[city]=1;
 
printf("%d--->",city+1);
ncity=minpath(city,n);
 
if(ncity==999)
{
ncity=0;
printf("%d",ncity+1);
cost+=ary[city][ncity];
 
return;
}
 
mincost(ncity,n);
}
 


 
int main()
{



printf("\n\nThe Path is:\n");

mincost(0,n); 
 
printf("\n\nMinimum cost is %d\n ",cost);

printf("\nEnter the Cost Matrix\n");
 
int x; 
printf("\nYou could either insert or delete node \n 1:Insert \n 2:Delete \n");
cin>>x;

//////////////////INSERT NODE 5 
//TEST ARRAY
//int ary[10][10] = {                
//                   {0, 10, 15, 20,15},
//                   {10, 0, 35, 25,20},
//                   {15, 35, 0, 30,30},
//                   {20, 25, 30, 0,40},
//                   {15, 20, 30,40,0}
//};


if (x==1)
{
	
takeInput();
}
else if(x==2){

deleteInput();

}

printf("\n\nThe Path is:\n");
cost = 0;

mincost(0,n); 

printf("\n\nMinimum cost is %d\n ",cost);




return 0;
}
