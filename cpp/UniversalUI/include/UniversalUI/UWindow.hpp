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
        
            GWindowResizeDelegate resizeDelegate = reinterpret_cast<GWindowResizeDelegate>(&Subclass::WindowResized);
            GWindow_SetResizeDelegate(GWindowHandle, resizeDelegate);

        // GCC
        #pragma GCC diagnostic pop
        // MSVC
        #pragma warning(pop)



    }

    virtual void WindowResized(GWindow window, GWindowSize size) {
        printf("BASE CLASS WINDOW RESIZED\n");
    }




};


#endif // UWINDOW_HPP