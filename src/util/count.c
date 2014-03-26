#include <limits.h>

unsigned long long nCr(unsigned long n, unsigned long r){
        unsigned long long result = 1, d = n - r;
 
        /* choose the smaller of r and n - r */
        if (d > r) { r = d; d = n - r; }
 
        while (n > r) {
                if (result >= ULLONG_MAX / n) return 0; /* overflown */
                result *= n--;
 
                /* divide (n - r)! as soon as we can to delay overflows */
                while (d > 1 && !(result % d)) result /= d--;
        }
        return result;
}

 
unsigned long long nPr(unsigned long n, unsigned long r){
     unsigned long long result = 1;

     while (n > r)
     {
                if (result >= ULLONG_MAX / n) return 0; /* overflown */
                result *= n--;
     }
     return result;
}
 
unsigned long long multinomial(unsigned int* n, unsigned int k){
     unsigned long long result = 1;
     unsigned long N=0;
     int i;
     for(i=0;i<k;i++) N+=n[i];
     while (N > 1)
     {
            if (result >= ULLONG_MAX / N) return 0; /* overflown */
            result *= N--;
            for(i=0;i<k;i++)
                while (n[i] > 1 && !(result % n[i])) result /= n[i]--;
     }
     return result;
}

