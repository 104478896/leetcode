/*设计一个基于时间的键值数据结构，该结构可以在不同时间戳存储对应同一个键的多个值，并针对特定时间戳检索键对应的值。

实现 TimeMap 类：

TimeMap() 初始化数据结构对象
void set(String key, String value, int timestamp) 存储键 key、值 value，以及给定的时间戳 timestamp。
String get(String key, int timestamp)
返回先前调用 set(key, value, timestamp_prev) 所存储的值，其中 timestamp_prev <= timestamp 。
如果有多个这样的值，则返回对应最大的  timestamp_prev 的那个值。
如果没有值，则返回空字符串（""）。*/
class TimeMap {
    map<string,vector<pair<int,string>>>cnt;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        
        cnt[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto &temp=cnt[key];
        pair<int,string> p={timestamp,string({127})};
        auto it=upper_bound(temp.begin(),temp.end(),p);
        if(it!=temp.begin()){
            return (it-1)->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */