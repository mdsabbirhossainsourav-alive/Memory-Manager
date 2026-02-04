#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int t, m;
    cin >> t >> m;
    vector<int> memory(m, 0); 
    int next_id = 1;
    for (int i = 0; i < t; i++) 
    {
        string cmd;
        cin >> cmd;
        if (cmd == "alloc")
        {
            int n;
            cin >> n;
            bool allocated = false;
            for (int start = 0; start <= m - n; start++)
            {
                bool can_alloc = true;
                for (int j = start; j < start + n; j++) 
                {
                    if (memory[j] != 0) 
                    {
                        can_alloc = false;
                        start = j; 
                        break;
                    }
                }
                if (can_alloc) 
                {
                    for (int j = start; j < start + n; j++) memory[j] = next_id;
                    cout << next_id << endl;
                    next_id++;
                    allocated = true;
                    break;
                }
            }
            if (!allocated) 
            {
                cout << "NULL" << endl;
            }

        } 
        else if (cmd == "erase") 
        {
            int x;
            cin >> x;
            bool found = false;
            for (int j = 0; j < m; j++) 
            {
                if (memory[j] == x) 
                {
                    memory[j] = 0;
                    found = true;
                }
            }
            if (!found)
            {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } 
        else if (cmd == "defragment")
        {
            vector<int> new_mem(m, 0);
            int idx = 0;
            for (int j = 0; j < m; j++) 
            {
                if (memory[j] != 0) 
                {
                    new_mem[idx++] = memory[j];
                }
            }
            memory = new_mem;
        }
    }
    return 0;
}
