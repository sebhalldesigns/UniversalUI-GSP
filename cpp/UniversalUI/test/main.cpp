#include <cstdio>
#include <string>

#include "UniversalUI/UApplication.hpp"

class MyApplication: public UApplication<MyApplication> {
    public:
    virtual void LaunchEvent() override {
        printf("LAUNCH FROM MYAPPLICATION C++ CLASS\n");
    }
};

int main() {
    UApplication<MyApplication>* app = new UApplication<MyApplication>();
    return app->Run();

}