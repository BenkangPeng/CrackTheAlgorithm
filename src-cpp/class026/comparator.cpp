#include<iostream>
#include<vector>
#include<algorithm>

class employee{
public:
    int age;
    int company;

    employee(int company , int age): age(age) , company(company){}
};


bool compare(employee o1 , employee o2){
    return o1.age < o2.age;
    //按年龄排序，age越小优先级越高
}


int main()
{
    employee s1(2, 27);
    employee s2(1, 60);
    employee s3(4, 19);
    employee s4(3, 23);
    employee s5(1, 35);
    employee s6(3, 55);
    std::vector<employee> arr = { s1, s2, s3, s4, s5, s6 };

    sort(arr.begin() , arr.end() , compare);

    for(employee it : arr){
        std::cout << it.age << " , " << it.company << std::endl;
    }//按年龄从小到大排序

    //lambda表达式
    std::cout << "======lambda expression======" << std::endl;
    sort(arr.begin() , arr.end() , [](const employee& o1 , const employee& o2) {return o1.age > o2.age; }) ;

    for(employee it : arr){
        std::cout << it.age << " , " << it.company << std::endl;
    }//按年龄从大到小排序


    std::cout << "================" << std::endl;
    // 所有员工，先按照谁的公司编号小，谁在前；如果公司编号一样，谁年龄小谁在前

    sort(arr.begin() , arr.end() , [](const employee& o1 , const employee& o2){
        if(o1.company != o2.company){
            return o1.company < o2.company;
        }
        else return o1.age < o2.age;
    });

    for(employee it : arr){
        std::cout << it.age << " , " << it.company << std::endl;
    }

    return 0;
}