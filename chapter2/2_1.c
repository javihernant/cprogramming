#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
    printf("CHAR:%d-%d\n",CHAR_MIN, CHAR_MAX);
    printf("UCHAR:%d-%d\n", 0, UCHAR_MAX);
    printf("INT:%d-%d\n",INT_MIN, INT_MAX);
    printf("UINT:%d-%u\n", 0, UINT_MAX);
    printf("LONG:%ld-%ld\n",LONG_MIN, LONG_MAX);
    printf("ULONG:%d-%lu\n",0, ULONG_MAX);
    printf("SHRT:%d-%d\n",SHRT_MIN, SHRT_MAX);
    printf("USHRT:%d-%d\n", 0, USHRT_MAX);
    printf("FLT:%f-%f\n",FLT_MIN, FLT_MAX);
    printf("DBL:%f-%f\n",DBL_MIN, DBL_MAX);

}
