#ifndef UAPPLICATION_HPP
#define UAPPLICATION_HPP


// UniversalUI UApplication class
// This is the entrypoint into UniversalUI
//
// UniversalUI classes in C++ use CRTP

#include <string>

extern "C" {
    #include "GSPCore/GSPCore.h"
    #include "GSPCore/GApplication.h"
}

template<typename Subclass>
class UApplication {

private:
    GApplication GApplicationHandle;

public:
    std::string Title;
    std::string Developer;
    int MajorVersion;
    int MinorVersion;

    UApplication() {

        Title = "Application";
        Developer = "Developer";
        MajorVersion = 0;
        MinorVersion = 1;

        GApplicationInfo appInfo = GApplicationInfo {
            Title.c_str(),
            Developer.c_str(),
            MajorVersion,
            MinorVersion
        };

        GApplicationHandle = GApplication_Init(appInfo);
        GApplication_SetUserData(GApplicationHandle, this);

        // Register event callbacks
        // This is implemented using a reinterpret cast but it's a very simple
        // interface intentionally to reduce the overhead of these functions.
        // Supressing the compiler warnings so that it doesn't fill the build
        // output with warnings

        // GCC
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wpmf-conversions"
        // MSVC
        #pragma warning(push)
        #pragma warning(disable: warning-code)
        
            GApplicationLaunchEvent launchEvent = reinterpret_cast<GApplicationLaunchEvent>(&Subclass::LaunchEvent);

        // GCC
        #pragma GCC diagnostic pop
        // MSVC
        #pragma warning(pop)

        GApplication_SetLaunchEvent(GApplicationHandle, launchEvent);
    }

    int Run() {
        return GSPRun(GApplicationHandle);
    }

    // events
    virtual void LaunchEvent() {

    }

};


#endif // UAPPLICATION_HPP