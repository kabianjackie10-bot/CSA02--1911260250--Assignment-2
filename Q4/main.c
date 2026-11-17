#include <stdio.h>
char grade(int marks){
    if(marks<0 || marks>100) return '?';
    switch(marks/10){
        case 10: case 9: return 'S';
        case 8: return 'A';
        case 7: return 'B';
        case 6: return 'C';
        case 5: return 'D';
        default: return 'F';
    }
}
char grade_ladder(int m){
    if(m<0 || m>100) return '?';
    if(m>=90) return 'S'; else if(m>=80) return 'A';
    else if(m>=70) return 'B'; else if(m>=60) return 'C';
    else if(m>=50) return 'D'; else return 'F';
}
int main(void){
    int marks[]={100,95,83,50,49,-5,90,89,80,79,70,69,60,59,0,101};
    for(unsigned i=0;i<sizeof marks/sizeof marks[0];++i)
        printf("%d:%c/%c ",marks[i],grade(marks[i]),grade_ladder(marks[i]));
    puts("");
    return 0;
}