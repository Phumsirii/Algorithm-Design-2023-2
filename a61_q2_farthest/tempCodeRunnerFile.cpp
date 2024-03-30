
            bellford[i][x.second]=min(bellford[i][x.second],bellford[i-1][x.first]+adj[x.first][x.second]);
        }
    }
    int ans=-1;
    for(int i=0;i<n;++i) ans=max(ans,bellford[n-2][i]);
    cout<<ans;
}