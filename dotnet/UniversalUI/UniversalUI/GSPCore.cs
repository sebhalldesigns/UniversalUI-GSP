using System.Runtime.InteropServices;

namespace UniversalUI;

public static class GSPCore {

    // GSPCore.h

    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern int GSPRun(IntPtr app);

    // GLog.h

    public enum GLogLevel {
        INFO,
        WARNING,
        FAIL
    }


    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern void GLog(GLogLevel level, string message);


    // GApplication.h

    public struct GApplicationInfo {
        public string title;
        public string developer;
        public int majorVersion;
        public int minorVersion;
    }

    public delegate void GApplicationLaunchEvent();

    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr GApplication_Init(GApplicationInfo info);

    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern void GApplication_SetLaunchEvent(IntPtr app, GApplicationLaunchEvent launchEvent);



    // GWindow.h

    public struct GWindowInfo {
        public int width;
        public int height;
        public string title;
    }

    public struct GWindowSize {
        public int width;
        public int height;
    }

    public struct GWindowPoint {
        public int x;
        public int y;
    }

    public delegate void GWindowResizeDelegate(IntPtr window, GWindowSize size);

    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr GWindow_Init(GWindowInfo info);


    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern void GWindow_SetResizeDelegate(IntPtr window, GWindowResizeDelegate resizeDelegate);



}