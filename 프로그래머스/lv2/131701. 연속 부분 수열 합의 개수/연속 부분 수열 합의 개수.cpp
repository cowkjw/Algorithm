#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {

    set<int> se;
    for(int i = 1;i<=elements.size();i++)
    {
        for(int j = 0;j<elements.size();j++)
        {
            int cnt = 0;
            int sum = 0;
            while(cnt<i)
          {
                int idx = cnt+j;
                idx%=elements.size();
                sum+=elements[idx];
                cnt++;
          }
            se.insert(sum);
        }
    }
    
	return se.size();
}