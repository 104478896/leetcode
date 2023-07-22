/*请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。

请你实现 ParkingSystem 类：

ParkingSystem(int big, int medium, int small) 初始化 ParkingSystem 类，三个参数分别对应每种停车位的数目。
bool addCar(int carType) 检查是否有 carType 对应的停车位。 carType 有三种类型：大，中，小，分别用数字 1， 2 和 3 表示。一辆车只能停在  carType 对应尺寸的停车位中。如果没有空车位，请返回 false ，否则将该车停入车位并返回 true 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-parking-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class ParkingSystem {
public:
    int b,m,s;
    ParkingSystem(int big, int medium, int small):b(big),m(medium),s(small) {
        
    }
    
    bool addCar(int carType) {
        
        if(carType==1){
            if(b>0){
                b--;
                return true;
            }
        }else if(carType==2){
            if(m>0){
                m--;
                return true;
            }            
        }else if(carType==3){
            if(s>0){
                s--;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */