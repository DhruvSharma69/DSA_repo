#include<iostream>
#include<queue>
using namespace std;

class PetrolPump
{
    public:
    int petrol;
    int distance;

};


class Solution :  public PetrolPump
{
        private:
        int reserved;
        int lacking;
        int start;
        public:
        Solution()
        {
            start = 0;
            reserved = 0;
            lacking = 0;
        }

        int Answer(PetrolPump p[], int n)
        {
            for(int i=0; i<n; i++)
            {
                reserved += p[i].petrol - p[i].distance ;
                if(reserved <0 )
                {
                    lacking += reserved;
                    start = i+1;
                    reserved = 0;
                }
                
            }   
            if(reserved + lacking >= 0)
                {
                    return start;
                }

            else{
                return -1;
            }

            
        }
};


int main()
{
    PetrolPump o[5];
    o[0].petrol = 4 ;
    o[1].petrol =  6;
    o[2].petrol =  7;
    o[3].petrol =  4;
   // o[4].petrol =  ;
    o[0].distance =  6;
    o[1].distance =  5;
    o[2].distance =  3;
    o[3].distance =  5;
    //o[4].distance =  ;
    Solution s;
  cout<<  s.Answer(o,4);
    return 0;
}