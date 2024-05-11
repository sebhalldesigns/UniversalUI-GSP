#include <cstdio>
#include <string>

#include "UniversalUI/UApplication.hpp"
#include "UniversalUI/UWindow.hpp"

class MyWindow: public UWindow<MyWindow> {
    public:

    virtual void WindowResized(GWindow window, GWindowSize size) override {
        printf("LAUNCH FROM MYWINDOW C++ CLASS %d %d\n", size.width, size.height);

    }
};

class MyApplication: public UApplication<MyApplication> {
    public:
    virtual void LaunchEvent() override {
        printf("LAUNCH FROM MYAPPLICATION C++ CLASS\n");
        UWindow<MyWindow>* window = new UWindow<MyWindow>();
    }
};

int main() {
    UApplication<MyApplication>* app = new UApplication<MyApplication>();
    return app->Run();

}