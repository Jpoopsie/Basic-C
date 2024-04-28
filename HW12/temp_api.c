#include <stdio.h>
#include <stdint.h>
#include "temp_api.h"

//выводят температуру в данном месяц данного года если m n заданы
//выводят температуру за  данный год если  n задано m равно 0
//выводят температуру за данный месяц по всем годам если  n равно 0
//выводят температуру за весь период наблюдения если m и n равны 0




float avgtemp (int m, int n, int k,  sensor t[]  ) {
    int  i, j=0, mm, nn ;

    float temp = 0 ;
    mm = m ;
    nn = n ;
    for( i=0; i<k; ++i) {

        if (n==0) nn = t[i].year  ;
        if (m==0) mm = t[i].month ;
        if ((t[i].month == mm) && (t[i].year == nn)) {
             temp += t[i].temperature ;
             j++ ; 
        }
    }
      
    return  temp/j;
}
    
int mintemp (int m, int n, int k,  sensor t[] ) {
    int temp = 100, i, nn, mm;
    
    mm = m ;
    nn = n ;
    for( i=0; i<k; ++i) {
  
       if (n==0) nn = t[i].year ; 
       if (m==0) mm = t[i].month ;
       if ((t[i].month == mm) && (t[i].year == nn))
            if (temp>t[i].temperature) 
                temp = t[i].temperature ;
    }
    return temp ;
}

int maxtemp (int m, int n, int k,  sensor t[] ) {
    int temp = -100, i, nn, mm;
  
    mm = m ;
    nn = n ;
    for( i=0; i<k; ++i) {
       if (n==0) nn = t[i].year  ;
       if (m==0) mm = t[i].month ;
       if ((t[i].month == mm) && (t[i].year == nn)) 
            if (temp<t[i].temperature) 
                temp = t[i].temperature ;
    }
    return temp ;
}

//////////////////////////////////////////////////////

void printhelp(void) {
    
    printf( "\nExample: prog [-f STR] [-m INT] [-y INT] \n\n ") ;
    printf( "-h      help\n ") ;
    printf( "-f STR  file  use for statistic\n ") ;
    printf( "-m INT  month number use for statistic\n ") ;
    printf( "-y INT  year use for statistic\n\n ") ;
    
    
}

//сортировка по дате с выводом отсортированного массива

void sortdate(int k,  sensor t[] ) {
    uint64_t n[k], nn ;
    int i, j, r ;
    sensor mm ;
    
    for( r=0; r<k; ++r) {
    n[r]= ((((t[r].year*100)+t[r].month)*100+ 
         t[r].day)*100+t[r].hour)*100+t[r].min ;
    }
    for ( i=0; i<k; i++ ){
        
        for ( j=k-1; j>i; j-- ){
            
            if ( n[j-1] > n[j] ) {
                nn = n[j-1] ;
                n[j-1] = n[j] ;
                n[j] = nn ;
                {
                mm = t[j-1] ;
                t[j-1] = t[j] ;
                t[j] = mm ;
                } 
            }   
        }
    }
    printf("\n") ;
    for( r=0; r<k; ++r) 
    printf("%d %2d %2d %2d:%2d  %d\n", t[r].year, t[r].month,
         t[r].day, t[r].hour, t[r].min, t[r].temperature );
    printf("\n") ;     
    
    
}