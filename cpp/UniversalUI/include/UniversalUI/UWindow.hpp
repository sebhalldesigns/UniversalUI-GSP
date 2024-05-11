#ifndef UWINDOW_HPP
#define UWINDOW_HPP

#include <cstdio>
#include <string>

extern "C" {
    #include "GSPCore/GSPCore.h"
    #include "GSPCore/GWindow.h"
}

template<typename Subclass>
class UWindow {

private:
    GWindow GWindowHandle;

public:

    int Width;
    int Height;
    std::string Title;

    UWindow() {

        Title = "Window";
        Width = 800;
        Height = 600;

        GWindowInfo windowInfo = GWindowInfo {
            Width,
            Height,
            Title.c_str()
        };

        // allocate window
        GWindowHandle = GWindow_Init(windowInfo);
        GWindow_SetUserData(GWindowHandle, this);

        // GCC
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wpmf-conversions"
        // MSVC
        #pragma warning(push)
        #pragma warning(disable: warning-code)

            GWindowDrawDelegate drawDelegate = reinterpret_cast<GWindowDrawDelegate>(&Subclass::Draw);
            GWindow_SetDrawDelegate(GWindowHandle, drawDelegate);
        
            GWindowResizeDelegate resizeDelegate = reinterpret_cast<GWindowResizeDelegate>(&Subclass::Resized);
            GWindow_SetResizeDelegate(GWindowHandle, resizeDelegate);
            
            GWindowPointerMoveDelegate pointerMoveDelegate = reinterpret_cast<GWindowPointerMoveDelegate>(&Subclass::PointerMoved);
            GWindow_SetPointerMoveDelegate(GWindowHandle, pointerMoveDelegate);
            

        // GCC
        #pragma GCC diagnostic pop
        // MSVC
        #pragma warning(pop)

    }

    virtual void Draw(GWindow window, GFrame surface) {
        printf("BASE CLASS WINDOW DRAW\n");
    }

    virtual void Resized(GWindow window, GWindowSize size) {
        printf("BASE CLASS WINDOW RESIZED\n");
    }



    virtual void PointerMoved(GWindow window, GWindowPoint newLocation) {
        printf("POINTER MOVED\n");
    }




};


#endif // UWINDOW_HPP