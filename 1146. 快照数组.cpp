/*实现支持下列接口的「快照数组」- SnapshotArray：

SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组 的数据结构。初始时，每个元素都等于 0。
void set(index, val) - 会将指定索引 index 处的元素设置为 val。
int snap() - 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。
 */
 class SnapshotArray {
public:
    map<int,map<int,int>>cnt;//索引值 快照数  值
    int id=0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        cnt[index][id]=val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        if(!cnt.count(index)){//在哈希表中没有找到对应的索引，代表没有进行修改，值为初始值
            return 0;
        }
        auto it=cnt[index].upper_bound(snap_id);
        return it==cnt[index].begin()?0:(--it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */