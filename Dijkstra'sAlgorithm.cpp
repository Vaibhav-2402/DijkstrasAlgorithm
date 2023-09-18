#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //adj list banao
    unordered_map<int, list< pair<int,int> > >adj;
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    set<pair<int,int> > st;

    st.insert(make_pair(0, source));

    while(!st.empty()) {
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int node = top.second;

        st.erase(st.begin());

        for(auto neighbour : adj[node]) {
            if(nodeDistance + neighbour.second < dist[neighbour.first] ) {
                //set me se delete karo node 
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first)); 
                
                //if record found then erase it
                if(record != st.end()) {
                    st.erase(record);
                }

                //now update the distance
                dist[neighbour.first] = nodeDistance + neighbour.second;

                //now insert the updated 
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
                
            }
        }
    }

    return dist;
}
