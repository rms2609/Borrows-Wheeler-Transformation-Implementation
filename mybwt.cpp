#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MX 2000005
int table[MX];
char *arr;
int fnlid=0;
int ct=0;
// custom comparator fuuction which compare two substrings and evntually wraps arounds iff
//any one of them comes to an end.
int cmp(int* i, int* j)
{
	int initial=*i;
	int a=*i,b=*j;
	if(arr[i]==arr[j])
	{
		do
		{
			a++;b++;
			if(a==fnlid)a=0;  //wrapping up if string is completed
			if(b==fnlid)b=0;
          
                     if(arr[a]!=arr[b])
                   {
			if(arr[a]>arr[b])return 1;
			else return -1;
		   }
		}
		while(a!=initial);
	}
	else
	{

			if(arr[a]>arr[b])return 1;
			else return -1;
	}
  return 0;	
}
//encode function gives the last colomn of sorted strings and index of the last caharacter
void encode(FILE* in, FILE* out)
{
    int i=0,index=MX;
    while(true)
    {
    	fnlid=fread(arr,1,MX,in);
    	if(!fnlid)break;

    	for(int i=0;i<fnlid;i++)table[i]=i;
    	qsort(table,fnlid,sizeof(int),cmp);

        int ans=fnlid;
        for(int i=0;i<fnlid;i++)
        {
        	if(table[i]) putc(arr[table[i]-1],out);
        	else
        	{
        		ans=i;
        		putc(arr[fnlid-1],out);
        	}
        }
        fwrite( &ans, sizeof(int ), 1, out );
    }
}
int main(int argc, char* argv[])
{
	fprintf(stderr,"file | E/D | input file |output file ");
	FILE *in;FILE *out;
	in=fopen(argv[2],"rb");
	out=fopen(argv[3],"wb");

	if(!in or !out)fprintf(stderr,"Error in opening input or output file");
    arr=(char *) malloc( MX * sizeof(char) );
    if(!arr)
    {
    	fprintf(stderr,"Malloc error!!");
    	exit(0);
    }
	if(!strcmp(argv[1],"E"))encode(in,out);
	return 0;
}
