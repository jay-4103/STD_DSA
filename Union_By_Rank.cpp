#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    private:
            vector<int> rank, parent;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=1;i<=n;i++)
                parent[i]=i;
        }

        int findultipar(int node)
        {
            if(parent[node]==node)
                return node;
            
            return parent[node] = findultipar(parent[node]);
        }

        void unionbyrank(int u,int v)
        {
            int ult_pu = findultipar(u);
            int ult_pv = findultipar(v);

            if(ult_pu==ult_pv)
                return;
            
            if(rank[ult_pu]<rank[ult_pv])
            {
                parent[ult_pu]=ult_pv;
            }

            else if(rank[ult_pv]<rank[ult_pu])
            {
                parent[ult_pv] = ult_pu; 
            }

            else{
                parent[ult_pu]=ult_pv;
                rank[ult_pv]++;
            }
        }
};
int main()
{
    DisjointSet d(7);

    d.unionbyrank(1,2);
    d.unionbyrank(2,3);
    d.unionbyrank(4,5);
    d.unionbyrank(6,7);
    d.unionbyrank(5,6);

    if(d.findultipar(1)==d.findultipar(7))
        cout<<"SAME"<<endl;
    else cout<<"NOT SAME"<<endl;

    d.unionbyrank(3,7);

    if(d.findultipar(1)==d.findultipar(7))
        cout<<"SAME"<<endl;
    else cout<<"NOT SAME"<<endl;

    return 0;
}