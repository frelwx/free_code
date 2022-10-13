#include<iostream>
#include<thread>
#include<vector>
#include<string>
#include<list>
#include <mutex>
class base{
private:
    std::list<int> ls;
    std::mutex my_mutex;
    int n{100};
public:
    void get_request(){
        for(int i = 0; i < n; ++i){
            std::lock_guard<std::mutex> manager_lock(my_mutex);
            ls.push_back(i);
            std::cout << "get_request " << i << '\n';
        }
    }
    void process_request(){
        // int res = -1;
        int res = -1;
        for(int i = 0; i < n; ++i){
            bool tmp = get_data(res);
            if(tmp){
                std::cout << "process_request " << res << '\n';
            } else{
                std::cout << "request empty()\n";
            }
        }
    }
    bool get_data(int &res){
        std::lock_guard<std::mutex> manager_lock(my_mutex);
        if(!ls.empty()){
            res = ls.front();
            ls.pop_front();
            return true;
        } else {
            return false;
        }
    }
};

class tmp{
private:
    int x;
public:
    tmp(int xx): x(xx){}
    class B{
    public:
    void f(const tmp &other) const{
        std::cout << other.x << std::endl;
    }
    };
};
// int tmp::x = 10;
int main(){
    base A;
    std::thread write_obj(&base::process_request, &A);
    std::thread read_obj(&base::get_request, &A);
    read_obj.join();
    write_obj.join();
    
    return 0;
}