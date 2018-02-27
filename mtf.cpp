#include<stdio.h>
#include<string.h>

void mtf_encode(FILE *in, FILE *out)
{
	unsigned char table[256];
	for(int i=0;i<256;i++)table[i]=(unsigned char)i;
    
    int current_c;
    while((current_c=fgetc(in))!=EOF)
    {
    	int i;
    	for(i=0;i<256;i++)
    		if(table[i]==current_c)
    			break;
    	fputc(i,out);
    	for(int j=i;j>0;j--)table[j]=table[j-1];
    	table[0]=i;	
    }
		
}
int main(int argc, char *argv[])
{
	fprintf(stderr,"file | E/D | input file |output file ");
	FILE *in;FILE *out;
	in=fopen(argv[2],"rb");
	out=fopen(argv[3],"wb");

	if(!in or !out)fprintf(stderr,"Error in in or out");
	//if(!strcmp(argv[1],"E"))
		mtf_encode(in,out);
	//else if(!strcmp(argv[1],"D"))mtf_decode(in,out);

	if(in)fclose(in);
	if(out)fclose(out);
	return 0;
}
