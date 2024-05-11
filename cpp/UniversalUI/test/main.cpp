#include <cstdio>
#include <string>

#include "UniversalUI/UApplication.hpp"
#include "UniversalUI/UWindow.hpp"

GFrame myFrame = nullptr;
int mouseX = 0;
int mouseY = 0;

class MyWindow: public UWindow<MyWindow> {
    public:

    
    

    virtual void Resized(GWindow window, GWindowSize size) override {
        printf("LAUNCH FROM MYWINDOW C++ CLASS %d %d\n", size.width, size.height);

        

    }

    virtual void Draw(GWindow window, GFrame surface) override {
        //printf("MY CLASS WINDOW DRAW\n");

        
        if (myFrame == nullptr) {
            //GFrame_Free(myFrame);

            GFrameInfo frameInfo = { 
                10,
                10
            };
    
            myFrame = GFrame_Alloc(frameInfo);

            printf("MYFRAME %lu\n", myFrame);


            GColor color = { 0.0, 0.0, 1.0, 1.0};
            GRect rect = { 0.0, 0.0, 10.0, 10.0};
            GFrame_Fill(myFrame, rect, color);

        }
        
        for (int x = 0; x < 50; x++) {
            for (int y = 0; y < 50; y++) {
                GRect drawRect = { (float)mouseX + 10.0*x , (float)mouseY + 10.0*y, 10.0, 10.0};
                GFrame_Composite(surface, drawRect, myFrame);
            }
            
        }
        
    

    }

    virtual void PointerMoved(GWindow window, GWindowPoint newLocation) override {
        //printf("POINTER MOVED\n");
        mouseX = newLocation.x;
        mouseY = newLocation.y;

        //printf("%d %d\n", newLocation.x, newLocation.y);
        
        GWindow_Redraw(window);
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