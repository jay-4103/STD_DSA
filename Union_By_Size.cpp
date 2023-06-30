#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    private:
            vector<int> size, parent;
    public:
        DisjointSet(int n)
        {
            size.resize(n+1,1);
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

        void unionbysize(int u,int v)
        {
            int ult_pu = findultipar(u);
            int ult_pv = findultipar(v);

            if(ult_pu==ult_pv)
                return;

            if(size[ult_pu]<size[ult_pv])
            {
                parent[ult_pu]=ult_pv;
                size[ult_pv]+=size[ult_pu];
            }
            else{
                parent[ult_pv]=ult_pu;
                size[ult_pu]+=size[ult_pv];
            }
        }
};
int main()
{
    DisjointSet d(7);

    d.unionbysize(1,2);
    d.unionbysize(2,3);
    d.unionbysize(4,5);
    d.unionbysize(6,7);
    d.unionbysize(5,6);

    if(d.findultipar(1)==d.findultipar(7))
        cout<<"SAME"<<endl;
    else cout<<"NOT SAME"<<endl;

    d.unionbysize(3,7);

    if(d.findultipar(1)==d.findultipar(7))
        cout<<"SAME"<<endl;
    else cout<<"NOT SAME"<<endl;

    return 0;
}