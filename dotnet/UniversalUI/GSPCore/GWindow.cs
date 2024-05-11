using System.Runtime.InteropServices;

namespace GSPCore;

public struct GWindowInfo {
    public int width;
    public int height;
    public string title;
}

public static class GWindow {
    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr GWindow_Init(GWindowInfo info);
}