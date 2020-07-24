#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
int n = 15,c=0,m;
char places[15][20] =
 {"karimnagar","nizamabad","Jagitial","Jangaon","Kamareddy","Khammam","Mahabubnagar","Medak","Medchal","Nalgonda","Nirmal","RangaReddy","Siddipet","hyderabad",
"warangal"};

int a[15][15];
int sum[1000][1000], p = 0;
void
util (int s, int d, bool visited[], int path[], int index)
{
  visited[s] = true;
  path[index] = s;
  index++;
  if (s == d)
    {
     printf("%d",++c);
     
      for (int i = 1; i < index; i++)
{
  printf (" %s -> ",places[path[i - 1]]);
  sum[c][p] += a[path[i - 1]][path[i]];
}
      p++;
      printf ("%s\n",places[d]);
    }
  else
    {
      for (int i = 0; i < n; i++)
{
  if (a[s][i] && !visited[i])
    {
      // printf("s=%d i=%d",s,i);
      util (i, d, visited, path, index);
    }
}
    }
  index--;
  visited[s] = false;
}

void
printAllPaths (int s, int d)
{
  bool visited[30];
  int path[30];
  int index = 0;
  for (int i = 0; i < n; i++)
    {
      visited[i] = false;
    }
  util (s, d, visited, path, index);
  int min = INT_MAX;
  for (int i = 0; i < p; i++)
    {
      if (sum[i+1][i] < min)
{
  min = sum[i+1][i];
  m=i+1;
}
    }
printf(" The minimum cost is for Path-%d\n",m);
printf("Cost of that path is : %d\n\n",min);
 // printf ("The cost when travelled through the shortest path is:%d- %d\n",m, min);
}

void
initializeMatrix ()
{
  memcpy (a, (int[15][15])
  {
  {
  0, 66, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {
  66, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {
  119, 60, 0, 153, 250, 389, 0, 0, 0, 0, 692, 0, 0, 0, 0},
  {
  0, 0, 153, 0, 220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {
  0, 0, 350, 220, 0, 70, 39, 0, 0, 385, 0, 0, 0, 0, 0},
  {
  0, 0, 389, 0, 70, 0, 0, 0, 0, 0, 0, 553, 0, 0, 0},
  {
  0, 0, 0, 0, 39, 0, 0, 113, 0, 0, 0, 0, 0, 0, 0},
  {
  0, 0, 0, 0, 0, 0, 113, 0, 130, 236, 0, 0, 0, 0},
  {
  0, 0, 0, 0, 0, 0, 0, 130, 0, 176, 0, 0, 0, 0, 0},
  {
  0, 0, 0, 0, 385, 0, 0, 236, 176, 0, 206, 0, 200, 0, 0},
  {
  0, 0, 692, 0, 0, 0, 0, 0, 0, 206, 0, 147, 345, 213, 365},
  {
  0, 0, 0, 0, 0, 553, 0, 0, 0, 147, 0, 0, 275, 0, 0},
  {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 345, 275, 0, 0, 0},
  {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 213, 0, 0, 0, 145},
  {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 365, 0, 0, 145, 0}},
  15 * sizeof (int[15]));
  return;
}

int
main ()
{
  int s, d;
  initializeMatrix ();
  printf ("************MAKE YOUR TRIP***********\n");
  printf ("Choose the source and destination from the following:\n");
  for (int i = 0; i < n; i++)
    {
      printf ("%d   %s\n", i, places[i]);
    }
  printf ("Enter source: ");
  scanf ("%d", &s);
  printf ("Enter destination: ");
  scanf ("%d", &d);
  printAllPaths (s, d);
  printf ("****Have a nice trip.........\n*****Visit again*******\n");
  return 0;
}
