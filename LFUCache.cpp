class LFUCache
{
public:
unordered_map<int,pair<int,int>>keyVal; 
//key, value,freq
unordered_map<int,list<int>>freqList;   
// freq key
unordered_map<int,list<int>::iterator>pos;
// key address_in_freqList
int capacity=0;
int minFreq=0;
    LFUCache(int capcity)
    {
        capacity=capcity;
    }
    void update(int key)
    {
        int currFreq=keyVal[key].second;
        freqList[currFreq].erase(pos[key]);
        freqList[currFreq+1].push_back(key);
        keyVal[key].second++;
        pos[key]=--freqList[currFreq+1].end();
        if(freqList[minFreq].empty())minFreq++;
    }
    int get(int key)
    {
        if(keyVal.find(key)==keyVal.end())return -1;
        update(key);
        return keyVal[key].first;
    }


    void put(int key, int value)
    {
        if(keyVal.find(key)!=keyVal.end())
        {
            keyVal[key].first=value;
            update(key);
            return;
        }
        if(keyVal.size()==capacity)
        {
            int delkey=freqList[minFreq].front();
            keyVal.erase(delkey);
            pos.erase(delkey);
            freqList[minFreq].pop_front();
        }
        keyVal[key]={value,1};
        freqList[1].push_back(key);
        pos[key]=--freqList[1].end();
        minFreq=1;
    }
};
