//random number generator 
#include <iostream>

 int main(){
   int a=2;
   int b=7;
   int x=3;

   for (int i=0; i<50; i++){
     x=(a*x + b)%71;
     std::cout<<x<< std::endl;
   }
 }

// mod 71 because I chose the max delay to be less than 3 sec = 24 * 3 cycles
// the parameters a = 2 and b = 7 give a nice period of 35 
// output:
/*
13
33
2
11
29
65
66
68
1
9
25
57
50
36
8
23
53
42
20
47
30
67
70
5
17
41
18
43
22
51
38
12
31
69
3
The plan is to store these values in the RAM and use them as values for
branch equal instruction which will help to implement the delay*/