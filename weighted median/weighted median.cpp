/*

For n distinct elements x1, x2... xnwith positive weights w1, w2... wn such that
the weighted (lower) median is the element xk satisfying:
𝑖sum wi(i<k)𝑘< 0.5 and sum wj(i>k)𝑘> 0.5
a) Show how to compute the weighted median of n items in worst-case
time O(n log n) using sorting.
b) Show how to compute the weighted median in worst-case time O(n)
using a linear-time median algorithm
Test your implementations onWeightedMedian.txt file. The file contains
two columns. The first column contains 1000 doubles in the range of
[0:1000], while the second column contains the weights for these elements.
In other words we can view our file as:
x1, w1
x2, w2
x3, w3
….
x1000, w1000
*/

#include <bits/stdc++.h>

using namespace std;
/*
bool myfunction (pair<double,double> i,pair<double,double> j)
{

return ( (i.second < j.second)  );
}
*/
    vector<pair<int ,double> > v_count (9999999) ;

void getmedianTypeOne(vector<pair<double ,double > > v)
{
    double w=0.0 ;
  sort(v.begin(), v.end());
  for(int i=0 ;i<v.size() ;i++)
  {
       w+=v[i].second ;
      if(w>=0.5)
      {
          cout<<"median is "<<v[i].first<<endl ;
          break;
      }


  }

}
void getmedianTypeTwo(vector<pair<double ,double > > v)
{
    int tmp ;
    int n ;
    double w=0.0 ;
      for(int i=0 ;i<v.size() ;i++)
      {
      v[i].first=(v[i].first*1000.0);
      tmp=(int)v[i].first ;
      v_count[tmp].first ++ ;
      v_count[tmp].second=v[i].second ;
          //  cout<<"test: "<< tmp <<"   "<< v[i].second<<endl;

     // countarr[tmp]++ ;
      }
      for(int i=0 ;i<9999999 ;i++)
      {
          if( v_count[i].first!=0)
          {
            w+=v_count[i].second;
           if(w>=0.5)
            {
             cout<<"median linear is "<<i/1000.0<<endl ;
             break;
            }
          }

      }


}

int main()
{

    int i=0  ;
    double col1, col2;
    vector<pair<double ,double > > v ;
    ifstream f("WeightedMedian.txt");
    string line;
   while (getline(f, line)) {
    istringstream ss(line);
    ss >> col1 >> col2;
    v.push_back(make_pair(col1 ,col2)) ;
   // cout<<"coulmn1  "<<v[i].first<<"     coulmn2  " <<v[i].second<<endl ;    i++  ;

   }
   getmedianTypeOne(v) ;
   getmedianTypeTwo(v) ;


    return 0;
}
