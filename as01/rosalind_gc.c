#include <stdio.h>
#include <assert.h>

int main(void){
    double A=0, C=0, G=0, T=0;
    double total = 0;
    double GC_content = 0;

    for(int i = getchar(); i != EOF; i = getchar())
        switch(i){
            case 'A': A++; total++; break;
            case 'C': C++; total++; break;
            case 'G': G++; total++; break;
            case 'T': T++; total++; break;
        }
        
    GC_content = G+C;
    GC_content /= total;
    GC_content *= 100;
    printf("%f\n", GC_content);
    return 0;
};