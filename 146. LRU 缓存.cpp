/*请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。*/
struct DLinkedNode{
    int key;
    int value;
    DLinkedNode* pre;
    DLinkedNode* nex;
    DLinkedNode():key(0),value(0),pre(nullptr),nex(nullptr){}
    DLinkedNode(int _key,int _value):key(_key),value(_value),pre(nullptr),nex(nullptr){}
};



class LRUCache {
private:
    map<int,DLinkedNode*>cache;
    DLinkedNode*head;
    DLinkedNode*tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity) : capacity(_capacity),size(0){
        //伪头部和伪尾部节点
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->nex=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        //如果key不存在返回-1
        //如果存在，通过哈希表进行定位，同时将该节点移到头部
        DLinkedNode* node=cache[key];
        moveToHead(node);//将节点一道头部
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            //如果不存在对应值，创建键值对，放入哈希表
            DLinkedNode*node=new DLinkedNode(key,value);
            cache[key]=node;
            //添加到双向链表
            addToHead(node);
            ++size;
            if(size>capacity){
                //如果超出容量，将尾部键值对删除,返回删除的节点值
                DLinkedNode*removed=removeTail();
                //删除哈希表中的键值对
                cache.erase(removed->key);

                //删除缓存，防止内存泄漏
                delete removed;
                --size;
            }
        }else{
            //如果key值存在，将key值对应的value进行修改，并放到头部
            DLinkedNode* node=cache[key];
            node->value=value;
            moveToHead(node);
        }
    }


    void moveToHead(DLinkedNode* node){
        removeNode(node);//将该节点删除
        addToHead(node);//添加到头部
    }

    void removeNode(DLinkedNode* node){//删除节点操作
        node->pre->nex=node->nex;
        node->nex->pre=node->pre;
    } 

    void addToHead(DLinkedNode* node){//更新节点位置操作
        node->pre=head;
        node->nex=head->nex;
        head->nex->pre=node;
        head->nex=node;
    }

    DLinkedNode* removeTail(){//删除尾部节点操作
        DLinkedNode*node=tail->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */