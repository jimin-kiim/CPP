#include <algorithm> 
#include <vector> 
#include <iostream>

using namespace std;

class mytype
{
public :    
  int key;    
  int height;    
  int weight;    

  mytype(int k, int h, int w) 
    : key(k) , height(h) , weight(w){}    

  bool operator==(const int a)     
  {        
    if (key==a) return true;        
    return false;    
  }
};

int main() 
{    
  vector<mytype> vec;     
  mytype x1(1,172,70);    
  mytype x2(2,163,50);    
  mytype x3(3,178,74);    
  mytype x4(4,185,80);    
  
  vec.push_back(x1);    
  vec.push_back(x2);    
  vec.push_back(x3);    
  vec.push_back(x4);    

  for (int i=0;i<vec.size();i++) {        
    cout << vec[i].key << " " << vec[i].height 
         << " " << vec[i].weight << endl;    
  }    
  vector<mytype>::iterator p;      
  p=find(vec.begin(),vec.end(),3);    
  cout << "found: " << p->key << " " << p->height
       << " " << p->weight << endl;    
  return 1;
}
