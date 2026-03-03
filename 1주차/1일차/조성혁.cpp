#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    queue<long long> q;
    unordered_map<long long,int> visited;
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        q.push(x);
        visited[x]=1;
    }

    int cnt=0;
    long long ans=0;
    while (!q.empty()) {
        long long x=q.front();
        q.pop();

        if (!visited[x-1]) {
            visited[x-1]=visited[x]+1;
            ans+=visited[x];
            cnt++;
            q.push(x-1);
        }

        if (cnt>=k) break;

        if (!visited[x+1]) {
            visited[x+1]=visited[x]+1;
            ans+=visited[x];
            cnt++;
            q.push(x+1);
        }

        if (cnt>=k) break;
    }

    cout<<ans;
}
