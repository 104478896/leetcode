/*请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：

LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量 capacity 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。

当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。

函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。*/
struct Node{
    int cnt;//缓存使用频率
    int time;//缓存使用时间
    int key;//缓存键值
    int value;
    
    Node(int _cnt,int _time,int _key,int _value):cnt(_cnt),time(_time),key(_key),value(_value){}
    //时间比较函数，比较缓存的时间
    bool operator< (const Node &pre) const{
        return cnt==pre.cnt ? time<pre.time : cnt<pre.cnt;
    }

};
class LFUCache {
    int capacity;//容量
    int time;//时间戳
    map<int,Node>key_table;//键值对表
    set<Node>S;//平衡树
public:
    LFUCache(int _capacity) {
        capacity=_capacity;
        time=0;
        key_table.clear();//清除缓存
        S.clear();//清除缓存
    }
    
    int get(int key) {
        //如果容量为0，代表为空，任何键值对都不存在，返回-1
        if(capacity==0){
            return -1;
        }
        
        //如果没有找到对应的键值对，代表不存在，返回-1
        if(key_table.find(key)==key_table.end()){
            return -1;
        }
        auto it=key_table.find(key);
        Node cache=it->second;
        S.erase(cache);//从平衡树S中将旧的数据删除
        cache.cnt+=1;
        cache.time=++time;
        //修改完新数据后存入平衡树和哈希表
        S.insert(cache);
        it->second=cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if(capacity==0){
            return;
        }
        auto it=key_table.find(key);
        if(it==key_table.end()){
            //如果容量满了
            if(key_table.size()==capacity){
                //从哈希表和平衡树中删除最近最少使用的缓存
                key_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            //创建新的缓存数据
            Node cache=Node(1,++time,key,value);
            //将缓存放入哈希表和平衡树
            key_table.insert(make_pair(key,cache));
            S.insert(cache);
        }else{
            //否则于get()函数类似
            Node cache=it->second;
            S.erase(cache);
            cache.cnt+=1;
            cache.time=++time;
            cache.value=value;
            S.insert(cache);
            it->second=cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */