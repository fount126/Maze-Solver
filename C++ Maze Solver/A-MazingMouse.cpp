// Program 4: A-Mazing Mouse
// Gian Fountain
// Following the right wall technique
// Last edited 11/12/2015

#include<stdio.h>
#include<stdlib.h>

int i=2, r, c, x, y, row, col, d;              
//declare and initialize variables
int main (void)  {
char matrix [50][50], m;

    FILE *fp;
fp = fopen("Maze1.dat","r"); //declare and open input and output files
FILE *op=fopen("Result.txt","w");

if( fp == NULL )    {
      printf("Error reading file.\n");
//error if no input file
exit(0);
  }
fscanf(fp, "%d  %d %d %d", &r, &c, &x, &y);
//read in first two rows and store size and start point
fprintf(op,"%d,%d \n", r, c);
printf("%d,%d \n", r, c);
fprintf(op,"%d,%d \n", x, y);
//print first two rows
printf("%d,%d \n", x, y);

for(row=0; row<50; row++){
for(col=0;  col<50; col++){
//fill entire array with Ds to create border
matrix[row][col]='D';
}
}

for (row=0;row<r; row++){
for(col=0;col<c; col++){
//read in maze data to array
do {
m=fgetc(fp);
      } while (m=='\n');
matrix[row+1][col+1]=m;
}
}
for (row=0;row<r+2; row++){
for(col=0;col<c+2; col++){
if(matrix[row][col]=='W')     
printf("%c%c",178,178);

else if (matrix[row][col]=='P')
//print maze to screen with ascii chars
printf("  ");

else if (matrix[row][col]=='D')
printf("%c%c",177,177);
else printf("%c ",matrix[row][col]);
fprintf(op,"%c ",matrix[row][col]);
//print maze to file with no ascii chars
              }
fprintf(op,"\n");
printf("\n");
}
fprintf(op,"\n");
printf("\n");
fprintf(op,"From entrance at (%d,%d)\n",x,y);
//establish entry point
printf("From entrance at (%d,%d)\n",x,y);
fclose(fp);

if (y==0) d=1;
else if (x==0) d=2;
else if (y==c-1) d=3;
else if (x==r-1) d=0;

x=x+1;
y=y+1;
//entry point adjustment for border

int n=x-1, e=y+1, s=x+1, w=y-1;









/*  while (matrix[x][y] == 'E') {
//while at the entry point look for a P in all directions
if (matrix[x-1][y] == 'P') {
d=0;
x=x-1;
break;
//move to first P, set heading and exit loop
}

else{
 
if (matrix[x][y+1] == 'P'){
d=1;
y=y+1;
break;
}
else{

if (matrix[x+1][y] == 'P'){
d=2;
x=x+1;
break;
}

else{
if (matrix[x][y-1] == 'P'){
d=3;
y=y-1;
break;
}
}
}
}
} */
if (matrix[x][y] != 'X') matrix[x][y]='@';
//create a path using @ symbol
fprintf(op,"Move 1 (%d,%d)\n", x-1,y-1);
//print the first move
printf("Move 1 (%d,%d)\n", x-1,y-1);

while (matrix[x][y] != 'X') {
//start looking for the X
//always looking to the right first
while(d==0 && matrix[x][y] !='X') {
//if im facing north i look for a P to the east, north, west, south
if (matrix[x][y+1] != 'W'){
d=1;
//set new heading if i turn
y=y+1;
//move to available P
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
//print move
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
//incriment for move number
if (matrix[x][y] != 'X') matrix[x][y]='@';
//set path
} 

else{
if (matrix[x-1][y] != 'W'){
x=x-1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}
else{

if (matrix[x][y-1] != 'W'){
d=3;
y=y-1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}

else{

if (matrix[x+1][y] != 'W'){
d=2;
x=x+1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}
}
}
}
}


while(d==1 && matrix[x][y] !='X') {
//if i'm facing east look south, east, north, west for P
if (matrix[x+1][y] != 'W'){
//same as above
d=2;
x=x+1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
} 

else{
if (matrix[x][y+1] != 'W'){
y=y+1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}
else{

if (matrix[x-1][y] != 'W'){
d=0;
x=x-1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}

else{

if (matrix[x][y-1] != 'W'){
d=3;
y=y-1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}
}
}
}
}

while(d==2  && matrix[x][y] !='X') {
//if im facing south look west, south, east, north

if (matrix[x][y-1] != 'W'){
//same as above
d=3;
y=y-1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
} 

else{
if (matrix[x+1][y] != 'W'){
x=x+1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}
else{

if (matrix[x][y+1] != 'W'){
d=1;
y=y+1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}

else{

if (matrix[x-1][y] != 'W'){
d=0;
x=x-1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}
}
}
}
}

while(d==3  && matrix[x][y] !='X') {
//if i'm facing west look north, west, south, east

if (matrix[x-1][y] != 'W'){
//same as above
d=0;
x=x-1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
} 

else{
if (matrix[x][y-1] != 'W'){
y=y-1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}
else{

if (matrix[x+1][y] != 'W'){
d=2;
x=x+1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}

else{

if (matrix[x][y+1] != 'W'){
d=1;
y=y+1;
fprintf(op,"Move %d (%d,%d)\n", i,x-1,y-1);
printf("Move %d (%d,%d)\n", i,x-1,y-1);
i++;
if (matrix[x][y] != 'X') matrix[x][y]='@';
}
}
}
}
}
}
if (matrix[x][y]=='X') {
//what to do if i find the X
fprintf(op,"Freedom at last!\n\n");
printf("Freedom at last!\n\n"); 
} 
for (row=0;row<r+2; row++){
for(col=0;col<c+2; col++){
if(matrix[row][col]=='W')
printf("%c%c",178,178);

else if (matrix[row][col]=='P')
//print result maze to screen with ascii chars
printf("  ");

else if (matrix[row][col]=='D')
printf("%c%c",177,177);
else if (matrix[row][col]=='@')
printf("%c ",254);
else printf("%c ",matrix[row][col]);
fprintf(op,"%c ",matrix[row][col]);
//print result maze to file without ascii chars
              }
fprintf(op,"\n");
printf("\n");
}
fclose(op); //close output file
  return 0;
}

