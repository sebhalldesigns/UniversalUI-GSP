using System.Runtime.InteropServices;

namespace GSPCore;

public struct GApplicationInfo {
    public string title;
    public string developer;
    public int majorVersion;
    public int minorVersion;
}

public delegate void GApplicationLaunchEvent();

public static class GApplication {


    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr GApplication_Init(GApplicationInfo info);

    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern void GApplication_SetLaunchEvent(IntPtr app, GApplicationLaunchEvent launchEvent);
    



}


