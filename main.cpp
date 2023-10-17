
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6


using namespace std;


int main()
{
  int con_matrix[SIZE][SIZE];                                                    // connection matrix
  int min_d[SIZE];                                                              // minimum distance
  int v_peaks[SIZE];                                                           // visited peaks
  int t, minindex, min;
  int begin_index = 0;


  // Connection matrix initializing
  for (int i = 0; i<SIZE; i++)
  {
    con_matrix[i][i] = 0;
    for (int j = i + 1; j<SIZE; j++) {
      cout<<"Enter the distance "<<i + 1<<" -> "<<j + 1<<" :";
      cin>>t;
      con_matrix[i][j] = t;
      con_matrix[j][i] = t;
    }
  }
  // Connection matrix printing
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      cout<< con_matrix[i][j]<<" ";
    cout<<endl;
  }


 // Vertices and distances initializing

  for (int i = 0; i<SIZE; i++)
  {
    min_d[i] = 10000;
    v_peaks[i] = 1;
  }
  min_d[begin_index] = 0;



  // Algorithm Step
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<SIZE; i++)
    {                                                               // If the vertex has not been bypassed yet and the weight is less than min
      if ((v_peaks[i] == 1) && (min_d[i]<min))
      {                                                             // Re-assign values
        minindex = i;
      }
    }

   /*Adding the found minimum weight
    to the current vertex weight
    and compare with the current minimum vertex weight */

    if (minindex != 10000)
    {
      for (int i = 0; i<SIZE; i++)
      {
        if (con_matrix[minindex][i] > 0)
        {
          t = min + con_matrix[minindex][i];
          if (t < min_d[i])
          {
            min_d[i] = t;
          }
        }
      }
      v_peaks[minindex] = 0;
    }
  } while (minindex < 10000);


  // Output of shortest distances to vertices

  cout<<"\nOutput of shortest distances to vertices: \n";
  for (int i = 0; i<SIZE; i++){
    cout<<min_d[i]<<"-->";
  }


  // Restoring the path

  int ver[SIZE];                                                                   // matrix of visited peaks
  int end = 4;                                                                     // index of the last peak = 5 - 1
  ver[0] = end + 1;                                                                // initial element - last peak
  int k = 1;                                                                       // index of the previous peak
  int weight = min_d[end];                                                         // weight of the last peak

  while (end != begin_index)                                                        // until we reach the initial peak
  {
    for (int i = 0; i<SIZE; i++)                                                    // looking through all the vertices
      if (con_matrix[i][end] != 0)                                                  // if there is connection
      {
        int t = weight - con_matrix[i][end];                                        // we determine the weight of the path from the previous vertex
        if (t == min_d[i])                                                          // if the weight coincided with the calculated
        {                                                                           // so there was a transition from this vertex
          weight = t;                                                               // we keep the new weight
          end = i;                                                                  // saving the previous vertex
          ver[k] = i + 1;                                                           // and write it to the array
          k++;
        }


 // Path output (the initial vertex was at the end of an array of k elements)
  cout<<"\nOutput of the shortest path\n";
  for (int i = k - 1; i >= 0; i--)
    cout<<ver[i];
  getchar(); getchar();
  return 0;
      }
  }
}
