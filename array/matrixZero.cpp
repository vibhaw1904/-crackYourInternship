#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      unordered_map<int>row;
      unordered_map<int>col;
      for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                row[i]=2;
                col[j]=2;
            }
        }
      }
      for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;
            }
        }
      }
         
   
    }
};