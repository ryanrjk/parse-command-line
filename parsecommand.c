#include <stdio.h> // contains I/O operations

#include <unistd.h> // contains getopt() function

#include <stdlib.h> // contains atoi() function

  

// Here main() gets the input commandline options

int main(int argc, char *argv[])  

{

char opt; // variable to store each commandline option given by getopt() function

  

// Looping over the all commandline options using getopt()

// Here 'f:s:cdu' explains that 'f' & 'c' are different type of options (i.e. each option needs its extra argument) and

// 'cdu' explains all c, d, u are optional

// getopt() returns -1 when there are no commandline options

while((opt = getopt(argc, argv, "f:s:cdu")) != -1)  

{  

switch(opt)  

{

// Parsing options [c|d|e]

case 'c':

case 'd':

case 'u':

printf("Given option: %c\n", opt);  

break;  

// Parsing option [-f arg]

case 'f':

printf("No.of first fields to ignore: %d\n", atoi(optarg));  

break;  

// Parsing option [-s arg]

case 's':  

printf("No.of first chars to ignore: %d\n", atoi(optarg));

break;

// In-case of unknown option

case '?':

printf("unknown option: %c\n", optopt);

break;  

}  

}  

  

// Loop prints extra arguments which are not parsed by getopt()

// optind is external variable defined in unistd.h which stores index of last parsed option

for(; optind < argc; optind++){   

printf("Extra arguments: %s\n", argv[optind]);  

}

  

return 0;

}