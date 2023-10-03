/*给你一棵 n 个节点的树，编号从 0 到 n - 1 ，以父节点数组 parent 的形式给出，其中 parent[i] 是第 i 个节点的父节点。树的根节点为 0 号节点，所以 parent[0] = -1 ，因为它没有父节点。你想要设计一个数据结构实现树里面对节点的加锁，解锁和升级操作。

数据结构需要支持如下函数：

Lock：指定用户给指定节点 上锁 ，上锁后其他用户将无法给同一节点上锁。只有当节点处于未上锁的状态下，才能进行上锁操作。
Unlock：指定用户给指定节点 解锁 ，只有当指定节点当前正被指定用户锁住时，才能执行该解锁操作。
Upgrade：指定用户给指定节点 上锁 ，并且将该节点的所有子孙节点 解锁 。只有如下 3 个条件 全部 满足时才能执行升级操作：
指定节点当前状态为未上锁。
指定节点至少有一个上锁状态的子孙节点（可以是 任意 用户上锁的）。
指定节点没有任何上锁的祖先节点。
请你实现 LockingTree 类：

LockingTree(int[] parent) 用父节点数组初始化数据结构。
lock(int num, int user) 如果 id 为 user 的用户可以给节点 num 上锁，那么返回 true ，否则返回 false 。如果可以执行此操作，节点 num 会被 id 为 user 的用户 上锁 。
unlock(int num, int user) 如果 id 为 user 的用户可以给节点 num 解锁，那么返回 true ，否则返回 false 。如果可以执行此操作，节点 num 变为 未上锁 状态。
upgrade(int num, int user) 如果 id 为 user 的用户可以给节点 num 升级，那么返回 true ，否则返回 false 。如果可以执行此操作，节点 num 会被 升级 。
 */
 class LockingTree {
private:
    vector<int>parent;//父节点
    vector<int>lockNodeUser;//节点上锁用户
    vector<vector<int>>children;//子节点的情况
public:
    LockingTree(vector<int>& parent) {
        int len=parent.size();
        this->parent=parent;
        this->lockNodeUser.resize(len,-1);
        this->children.resize(len);
        for(int i=0;i<len;++i){
            int p=parent[i];
            if(p!=-1){
                children[p].push_back(i);//构建树,将子节点放入父节点的容器中
            }
        }
    }
    
    bool lock(int num, int user) {
        if(lockNodeUser[num]==-1){//当前节点处于未上锁状态，将上锁用户更改为user，同时返回true，否则返回false
            lockNodeUser[num]=user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(lockNodeUser[num]==user){//只有节点处于上锁状态才能解锁，即当前节点的值不等于-1
            lockNodeUser[num]=-1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        //根据优先性判断，当前两个条件成立时，才会判断第三个条件是否成立
        //此时可以将判断是否存在上锁的子节点和将子节点解锁同时进行
        //因为找到一个上锁子节点代表条件成立，解锁不影响结果
        bool res=(lockNodeUser[num]==-1)&& !(hasLockedAncestor(num)) &&(checkAndUnlockChildren(num));
        if(res){
            lockNodeUser[num]=user;
            return true;
        }
        return false;
    }

    bool hasLockedAncestor(int num){//查找父节点是否存在上锁情况，存在返回true，否则返回false
        num=parent[num];//查找父节点情况
        while(num!=-1){//即当前节点不是根节点
            if(lockNodeUser[num]!=-1){
                return true;
            }
            num=parent[num];//向上查找
        }
        return false;
    }

    bool checkAndUnlockChildren(int num){//递归查找当前子节点并且解锁
        bool res = lockNodeUser[num]!=-1;
        //当前节点是否上锁，上锁即当前值不为-1，则将res置为true
        //当res为true表示至少存在一个上锁的子节点条件成立。
        //满足条件后将所有的节点解锁
        lockNodeUser[num]=-1;
        for(int child:children[num]){
            res |= checkAndUnlockChildren(child);
        }
        return res;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */