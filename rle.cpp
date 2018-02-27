#include <stdio.h>
int main(int argc, char *argv[])
{
  fprintf(stderr,"formate should be rle | input-file | output-file");
  freopen( argv[ 1 ], "rb", stdin );
  freopen( argv[ 2 ], "wb", stdout );
  
  int current_char;
  int previous_char=0;
  while((current_char=getc(stdin))>=0)
  {
    putc(current_char,stdout);
    if(current_char==previous_char)
     {
       int freq=0;
       while(freq<255 and ((current_char=getc(stdin))>=0))
          {
            if(current_char==previous_char)freq++;
            else break;
          }
        
        putc((char)freq,stdout);
        if(freq!=255 and current_char>=0)putc((char)current_char,stdout);
     }
    previous_char=current_char;
    
  } 

 return 1;
}
