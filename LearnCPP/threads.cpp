#include<iostream>
#include<thread>

static bool f = false;


void Dowork(){
    using namespace std::literals::chrono_literals;
    while(!f){
        std::cout<<"Working\n";
        std::this_thread::sleep_for(1s);
    }
}

int main(){
    std::thread worker(Dowork);
    std::cin.get();
    f=true;
    worker.join();

    std::cin.get();
}